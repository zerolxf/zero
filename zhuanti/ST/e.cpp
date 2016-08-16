/*************************************************************************
	> File Name: e.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月30日 星期六 20时17分13秒
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
const int maxn = 1e5+100;
const int INF = 0x3f3f3f3f;
int p[maxn][18];
int head[maxn], nxt[maxn], to[maxn], dep[maxn];
int edgenum;
int n;
void addedge(int u, int v){
    nxt[edgenum] = head[u];
    to[edgenum] = v;
    head[u] = edgenum++;
}
void init(){
    memset(head, -1, sizeof head);
    memset(p,-1,sizeof p);
    memset(dep, 0, sizeof dep);
    edgenum = 0;
}
void dfs(int u){
    for(int i = head[u]; ~i; i = nxt[i]){
        int v = to[i];
        if(!dep[v]){
            dep[v] = dep[u] + 1;
            //p[v][0] = u;
            dfs(v);
        }
    }
}
void ST(){
    for(int j = 1; (1<<j) <= n; ++j){
        for(int i = 1; i<=n; ++i){
            if(p[i][j-1]!=-1)
            p[i][j] = p[p[i][j-1]][j-1];
            //pr(i);pr(j);prln(p[i][j]);
        }
    }
}
int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    int du = 0;
    
    for(du=0;(1<<du)<=dep[u];++du);
    --du;
    //while((1<<(du+1)) <= dep[u]) du++;
    for(int i = du; i >= 0; --i) 
        if(dep[u] - (1<<i) >= dep[v]) 
        {
            u = p[u][i];
        }
    if(u == v) return u;
    for(int i = du; i >= 0; -- i){
        if(p[u][i] != -1 && p[u][i] != p[v][i]){
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[u][0];
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--){
        init();
        int u, v;
        int root = 0;
        scanf("%d", &n);
        for(int i = 0; i <= n; ++i){
            p[i][0] = -1;
        }
        for(int i = 0; i < n-1; ++i){
            scanf("%d%d", &u, &v);
            addedge(u, v);
            p[v][0] = u;
        }
        for(int i = 1; i <= n; ++i) if(p[i][0]==-1) root = i;
        dfs(root);
        ST();
        scanf("%d%d", &u, &v);
        int ans = lca(u, v);
        cout << ans << "\n";

    }
	return 0;
}
