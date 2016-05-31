/*************************************************************************
	> File Name: h.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月29日 星期日 16时27分56秒
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
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
struct Edge{
    ll v,  dis, nxt;
    ll c;
    Edge(){}
    Edge(ll _v, ll _c, ll _dis, ll _nxt){
        v = _v;
        c = _c;
        dis = _dis;
        nxt = _nxt;
    }
}edge[maxn];
int head[maxn], edgenum;
void addegde(int u, int v, ll c, ll dis) {
    edge[edgenum] = Edge(v, c, dis, head[u]);
    head[u] = edgenum++;
}
int des, src, n, m, k;
ll dis[maxn], vis[maxn];
bool spfa(ll cap) {
    for(int i = 0; i <= n; ++i){
        vis[i] = false;
        dis[i] = INF;
    }
    queue<int> q;
    q.push(src);
    vis[src] = true;
    dis[src] = 0;
    while(q.size()){
        int u = q.front(); q.pop();
        vis[u] = false;
        for(int i = head[u]; ~i; i = edge[i].nxt){
            int v = edge[i].v;
            ll d = edge[i].dis;
            if(edge[i].c < cap) continue;
            if(dis[v] > dis[u] + d){
                dis[v] = dis[u] + d;
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    return dis[des] <= k;
}
void init(){
    MEM(head,-1);
    edgenum = 0;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t, u, v, d;
    ll c;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &n, &m, &k);
        src = 1, des = n;
        init();
        for(int i = 0; i < m; ++i){
            scanf("%d%d%lld%d", &u, &v, &c, &d);
            addegde(u, v, c, d);
            addegde(v, u, c, d);
        }
        ll l = 0, r = 2e9+1;
        while(l < r) {
            ll m = (l + r + 1) >> 1;
            if(spfa(m)) l = m;
            else r = m-1;
        }
        if(l)printf("%lld\n", l);
        else printf("Poor RunningPhoton!\n");
    }
	return 0;
}
