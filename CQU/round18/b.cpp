#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
#include<vector>

using namespace std;
const int maxn = 6e5+100;
const int INF = 0x3f3f3f3f;
const int N = 6e5+1;
#define pr(x)      // cout << #x << " = " << x << " ";
#define prln(x)  //   cout << #x << " = " << x <<endl;
#define ll long long
#define rep(i,n) for(int i = 0; i < n; ++i)
ll prime[maxn];
bool vis[maxn];
ll cnt[maxn], pcnt;
    int n, m;
ll ret(ll base, int x) {
    ll ans = 1;
    pr(base);pr(x);
    if(x==0) return 1;
    if(x%2==1) ans*=base;
    ll t = ret(base*base,x/2);
    pr(base);pr(x);pr(t);prln(ans);
    return ans*t%m;
}
void getprime(){
    pcnt = 0;
    for(ll i = 2; i <= N; ++i){
        if(!vis[i]) {
            prime[pcnt++] = i;
            for(ll j = i*i; j <= N; j+=i){
                vis[j] = true;
            }
        }
    }
}
void addcnt(int x) {
    int qx = sqrt(x+0.5);
    for(int i = 0; i < pcnt; ++i){
        if(x == 1) return;
        if(prime[i] > qx) {
            int pos = lower_bound(prime,prime+pcnt,x) - prime;
            cnt[pos]++;
            break;
        }
        if(x%prime[i] == 0) {
            while(x%prime[i]==0){
                cnt[i]++;
                x/=prime[i];
            }
        }
    }
}
void delcnt(int x) {
    int qx = sqrt(x+0.5);
    for(int i = 0; i < pcnt; ++i){
        if(x == 1) return;
        if(prime[i] > qx) {
            int pos = lower_bound(prime,prime+pcnt,x) - prime;
            cnt[pos]--;
            break;
        }
        if(x%prime[i] == 0) {
            while(x%prime[i]==0){
                cnt[i]--;
                x/=prime[i];
            }
        }
    }
}
ll dp[maxn], c[maxn];
int head[maxn], edgenum;
struct Edge{
    int v, nxt;
}edge[maxn];

void addedge(int u, int v){
    edge[edgenum].nxt = head[u];
    edge[edgenum].v = v;
    head[u] = edgenum++;
}
int dfs(int x) {
    ll& ans = dp[x];
    ans = 1;
    for(int i = head[x]; ~i; i = edge[i].nxt){
        ans += dfs(edge[i].v);
    }
    return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int t, x;
    cin >> t;
    getprime();
    while(t--){
        cin >> n >> m;
        int pos = upper_bound(prime,prime+pcnt,n) - prime;
        edgenum = 0;

        for(int i = 0; i <= n; ++i){
            dp[i] = 0;
            head[i] = -1;
        }
        for(int i = 2; i <= n; ++i){
            scanf("%d",&x);
            addedge(x,i);
        }
        dfs(1);
        for(int i = 1; i <= n; ++i) {
            cnt[dp[i]]--;
        }
        ll ans = 1;
        for(int i = 0; i <= pos;  ++i){
            if(cnt[i] == 0) continue;
            int temp = ret(prime[i],cnt[i]);
            ans = (ans*temp)%m;
        }
        cout << ans << "\n";
    }
    return 0;
}
