/*************************************************************************
	> File Name: i.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月29日 星期日 14时25分30秒
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
int dfn[maxn], low[maxn];
int head[maxn];
int ans;
int dfnnum, edgenum = 0;
struct Edge{
    int v, nxt;
}edge[maxn];
void addedge(int u, int v){
    edge[edgenum].nxt = head[u];
    edge[edgenum].v = v;
    head[u] = edgenum++;
}
int vis[maxn];
int in[maxn];
void tarjan(int fa, int u) {
    dfn[u] = ++dfnnum;
    low[u] = dfn[u];
    for(int i = head[u]; ~i; i = edge[i].nxt){
        int v = edge[i].v;
        if(in[i]) continue;
        in[i^1] = in[i] = true;
        if(!dfn[v]){
            tarjan(i|1,v);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]){ 
                 ans++;
            }
        }else low[u] = min(low[u], dfn[v]);
    }
}
void clear(){
    MEM(head,-1);
    MEM(dfn,0);
    MEM(in,0);
    MEM(vis,0);
    edgenum = 0;
    dfnnum  = 0;
    ans = 0;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t, n, m;
    int kase = 0;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        int u, v, root;
        clear();
        for(int i = 0; i < m; ++i){
            scanf("%d%d", &u, &v);
            addedge(u,v);
            addedge(v,u);
        }
        for(int i = 1; i <= n; ++i){
            if(!dfn[i]) tarjan(-1,i);
        }
        printf("Case %d: ",++kase);
        printf("%d\n",ans);
    }
	return 0;
}
