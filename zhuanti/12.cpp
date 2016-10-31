#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>
#include <bitset>
using namespace std;
const int maxn = 4e5+1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
ll t[maxn], cost[maxn], v[maxn], num[maxn];
ll c[maxn], tt[maxn];

int n, m;
bitset<220> shop[220];

const int MAXN = 500;
const int MAXM = maxn;
struct Edge{
    ll to, next, cap;
    ll  flow, cost;
}edge[MAXM];
ll head[MAXM], tot;
ll pre[MAXM];
ll dis[MAXM];
bool vis[MAXM];
ll N;
void init(ll n){
    N = n;
    tot = 0;
    memset(head, -1, sizeof head);
}
void addedge(ll u, ll v, ll cap,ll cost){
    edge[tot].to = v;
    edge[tot].cap = cap;
    edge[tot].cost = cost;
    edge[tot].flow = 0;
    edge[tot].next = head[u];
    head[u] = tot++;

    edge[tot].to = u;
    edge[tot].cap = 0;
    edge[tot].cost = -cost;
    edge[tot].flow = 0;
    edge[tot].next = head[v];
    head[v] = tot++;
}

bool spfa(ll s, ll t){
    queue<int> q;
    for(int i = 0; i < N; ++i){
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[s] = 0;
    vis[s] = true;
    q.push(s);
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        vis[u] = false;
        for(ll i = head[u]; ~i; i=edge[i].next){
            ll v = edge[i].to;
            if(edge[i].cap > edge[i].flow && dis[v] > dis[u] + edge[i].cost){
                dis[v] = dis[u] + edge[i].cost;
                pre[v] = i;
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    if(pre[t] == -1) return false;
    else return true;
}

ll minCostMaxflow(ll s, ll t, ll &cos){
    ll flow = 0;
    cos = 0;
    while(spfa(s,t)){
        ll Min = 1e13;
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to]){
            if(Min > edge[i].cap - edge[i].flow){
                Min = edge[i].cap - edge[i].flow;
            }
        }
        for(int i = pre[t]; ~i; i= pre[edge[i^1].to]){
            edge[i].flow += Min;
            edge[i^1].flow -= Min;
            cos += edge[i].cost*Min;
        }
        flow += Min;
    }
    return flow;
}
ll check(ll x){
    bitset<220> cai;
    cai.reset();
   // prln("*******************");
  //  prln(x);
    for(int i = 1; i <= n; ++i){
        if(t[i] <= x){
            cai[i] = false;
        }else{
            cai[i] = true;
        }
    }
    ll ans = 0;
    tot = 0;
    init(n+m+3);
    for(int i = 1; i <= n; ++i){
      //  pr(i+m);prln(n+m+1);
        addedge(i+m, n+m+1, cost[i], 0);
    }
    int cap = 0;
    for(int i = 1; i <= m; ++i){
        bool ook = true;
        for(int j = 1; j <= n; ++j){
            if(cai[j]&shop[i][j]) {
                ook= false;
            }
        }
        if(!ook) continue;
        ans += v[i];
        cap = 0;
        for(int j = 1; j <= n; ++j){
            if(shop[i][j]){
                cap++;
              //  pr(i);prln(j+m);
                addedge(i,j+m,INF,0);
            }
        }
       // pr(0);prln(i);
        addedge(0,i, v[i], 0);
    }
    ll cost = 0;
    ans -= minCostMaxflow(0, n+m+1,cost);
    return ans;
}

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    int ttt;
    ll L;
    scanf("%d", &ttt);
    int kase = 0;
    while(ttt--){
        printf("Case #%d: ",++kase);
        ll l = 1, r = 1;
        scanf("%d%d%lld", &n, &m, &L);
        for(int i = 1; i <= n; ++i){
            scanf("%lld%lld", &cost[i], &t[i]);
        }
        ll a;
        for(int i = 1; i <= m; ++i){
            ll ma = 0;
            shop[i].reset();
            scanf("%lld%lld", &v[i], &num[i]);
            c[i] = 0;
            for(int j = 1; j <= num[i]; ++j){
                scanf("%d", &a);
                shop[i][a] = true;
                c[i] += cost[a];
            }
        }
        l = 1;
        for(int i = 1; i <= n; ++i){
            r = max(r, t[i]);
        }
        while(l < r){
            ll mid = (l+r) >>1;
            ll mm = check(mid);
            if(mm < L) l = mid+1;
            else r = mid;
        }
        ll ans = check(l);
        if(ans >= L){
            printf("%lld %lld\n", l, ans);
        }else{
            printf("impossible\n");
        }

    }
    return 0;
}
