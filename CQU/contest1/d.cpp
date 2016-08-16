/*************************************************************************
	> File Name: d.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月18日 星期一 21时14分50秒
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
int sccno[maxn], dfn[maxn], low[maxn], p[maxn], head[maxn], nxt[maxn], to[maxn], v[maxn], edgenum, dfnnum;
int q[maxn], vis[maxn];
int scc;
int edge[maxn][2];
int m, n;
void addedge(int u, int v){
    nxt[edgenum] = head[u];
    to[edgenum] = v;
    head[u] = edgenum++;
}
void init(){
    memset(head, -1, sizeof head);
    edgenum = 0;
    scc = 0;
    dfnnum = 0;
}
int qcnt;
void tarjan(int u, int fa){
    int v;
    dfn[u] = ++dfnnum;
    low[u] = dfnnum;
    vis[u] = true;
    q[qcnt++] = u;
    for(int i = head[u]; ~i; i = nxt[i]){
        v = to[i];
        if(v == fa) continue;
        if(!vis[v]){
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }else if(vis[v]){
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(low[u] == dfn[u]) {
        scc++;
        do{
            v = q[--qcnt];
            sccno[v] = scc;
            vis[v] = false;
        }while(u != v);
    }
}
void sccno_slove(){
    memset(dfn, 0, sizeof dfn);
    memset(vis, 0, sizeof vis);
    qcnt = 0; 
    dfnnum = 0;
    scc = 0;
    for(int i = 1; i <= n; ++i){
        if(!dfn[i]) tarjan(i, i);
    }
}
int ma[maxn];
void dfs(int u, int fa){
    ma[u] = v[u];
    for(int i = head[u]; ~i; i = nxt[i]){
        int v = to[i];
        if(v == fa) continue;
        dfs(v, u);
        ma[u] = max(ma[u], ma[v]);
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        init();
        for(int i  = 0; i < m; ++i){
            scanf("%d%d", &edge[i][0], &edge[i][1]);
            addedge(edge[i][0], edge[i][1]);
            addedge(edge[i][1], edge[i][0]);
        }
        sccno_slove();

        memset(v, 0, sizeof v);
        int root = 0;
        for(int i = 1; i <= n; ++i){
            int sc = sccno[i];
            v[sc] = max(v[sc], i);
            if(v[sc] == n) root = sc;
        }
        memset(head, -1, sizeof head);
        edgenum = 0;
        for(int i = 0; i < m; ++i){
            int u = sccno[edge[i][0]];
            int v = sccno[edge[i][1]];
            if(u == v) continue;
            addedge(u, v);
            addedge(v, u);
        }
        dfs(root, root);

        for(int i = 0; i < m;++i){
            int u = sccno[edge[i][0]];
            int v = sccno[edge[i][1]];
            if(u == v) printf("0 0\n");
            else{
                int x = min(ma[u], ma[v]);
                printf("%d %d\n", x, x+1);
            }
        }

    }
	return 0;
}
