/*************************************************************************
	> File Name: aa.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月22日 星期五 21时49分25秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) //cout << #x << " = " << x << " ";
#define prln(x) //cout << #x << " = " << x <<  endl; 
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
struct Edge{
    int u, v, c;
    bool operator <(const Edge&  rhs)const{
        return c < rhs.c;
    }
}edge[maxn];
int head[maxn], nxt[maxn], to[maxn], cost[maxn];
int edgenum ;
ll n, m;
int p[maxn];
void init(){
    memset(head, -1, sizeof head);
    for(int i = 0; i <= n; ++i){
        p[i] = i;
    }
    edgenum = 0;
}
void addedge(int u, int v, int c){
    nxt[edgenum] = head[u];
    to[edgenum] = v;
    cost[edgenum] = c;
    head[u] = edgenum++;
}
int find(int x){
    return p[x] = (x==p[x]?x:find(p[x]));
}
int siz[maxn];
bool vis[maxn];
void dfs(int u){
    vis[u] = true;
    siz[u] = 1;
    for(int i = head[u]; ~i; i = nxt[i]){
         int v = to[i];
         if(vis[v]) continue;
         dfs(v);
         siz[u] += siz[v];
    }
}
bool is[maxn];
void solve(){
    sort(edge, edge + m);
    memset(vis, 0, sizeof vis);
    memset(is, 0, sizeof is);
    ll ans1 = 0;
    double ans2 = 0;
    for(int i = 0; i < m; ++i){
        int u = edge[i].u;
        int v= edge[i].v;
        pr(u);prln(v);
        u = find(u); v = find(v);
        if(u == v) continue;
        p[u] = v;
        is[i] = true;
        //pr(u);pr(v);prln(edge[i].c);
        ans1 += edge[i].c;
        addedge(edge[i].u, edge[i].v, edge[i].c);
        addedge(edge[i].v, edge[i].u, edge[i].c);
    }
    dfs(1);
    double ans = 0;
    for(int i = 0; i < m; ++i)
    {
        if(!is[i]) continue;
         int u = edge[i].u;
         int v= edge[i].v;
         int mi = min(siz[u], siz[v]);
        pr(u);pr(v);pr(siz[u]);prln(siz[v]);
        prln(mi);
           ans += 1.0*(ll)(n-mi)*(ll)(mi)*(ll)edge[i].c/(1.0*n*(n-1));
    }
    ans2 = ans*2;
    printf("%lld %.2f\n", ans1, ans2);
    
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%lld%lld", &n, &m);
        init();
        int u, v, c;
        for(int i = 0; i < m; ++i){
            scanf("%d%d%d", &u, &v, &c);
            edge[i].u = u;
            edge[i].v = v;
            edge[i].c = c;
            pr(u);pr(v);prln(c);
        }
        solve();
    }
	return 0;
}
