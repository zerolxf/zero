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
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
#define rep(i,n) for(int i = 0; i < n; ++i)
int ans[maxn], acnt;
struct Edge{
    int v, nxt,vis;
}edge[maxn];
int head[maxn], edgenum;
void addedge(int u, int v){
    edge[edgenum].v = v;
    edge[edgenum].nxt = head[u];
    edge[edgenum].vis = false;
    head[u] = edgenum++;
}
void dfs(int u, int fa){
    for(int i = head[u]; ~i; i = edge[i].nxt){
        if(edge[i].vis) continue;
        edge[i].vis = true;
        dfs(edge[i].v, u);
    }
    printf("%d\n",u);
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, m, u, v;
    while(cin >> n >> m){
        for(int i = 0; i <= n; ++i) head[i] = -1;
        for(int i = 0; i < m; ++i){
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        dfs(1,-1);
    }

    return 0;
}
