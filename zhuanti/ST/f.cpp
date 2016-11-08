/*************************************************************************
	> File Name: f.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月30日 星期六 22时48分13秒
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
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
int head[maxn], nxt[maxn], to[maxn], dep[maxn];
int dp[maxn][22];
int edgenum;
void addedge(int u, int v){
    nxt[edgenum] = head[u];
    to[edgenum] = v;
    head[u] = edgenum++;
}
int n;
void dfs(int u){
    for(int i = head[u]; ~i; i = nxt[i]){
        int v = to[i];
        if(!dep[v]){
            dep[v] = dep[u] + 1;
            //dp[v][0] = u;
            dfs(v);
        }
    }
}

int ans[maxn];
void init(){
    memset(ans, 0, sizeof ans);
    memset(dp, -1, sizeof dp);
    memset(head, -1, sizeof head);
    memset(dep, 0, sizeof dep);
    edgenum = 0;
}
int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    int du = 0;
    while(1<<(du+1) <= dep[u]) du++;
    for(int i = du; i >= 0; --i){
        if(dep[u] - (1<<i) >= dep[v]){
            u = dp[u][i];
        }
    }
    if(u==v) return u;
    for(int i = du; i >= 0; --i){
        if(dp[u][i] != -1 && dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return dp[u][0];
}
void ST(){
    for(int j = 1; (1<<j) <= n; ++j){
        for(int i = 1; i <= n; ++i){
            if(dp[i][j-1] != -1){
                dp[i][j] = dp[dp[i][j-1]][j-1];
            }
        }
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(cin >> n){
        int u, v, m;
        int root = 0;
        init();
        for(int i = 0; i < n; ++i){
            scanf("%d:(%d)", &u, &m);
            for(int j = 0; j < m; ++j){
                scanf("%d", &v);
                addedge(u, v);
                dp[v][0] = u;
            }
        }
        for(int i = 1; i <= n; ++i){
            if(dp[i][0] == -1) root = i;
        }
        dfs(root);
        ST();
        scanf("%d", &m);
        for(int i = 0; i < m; ++i){
            scanf(" (%d %d)", &u, &v);
            int x = lca(u,v);
            ans[x]++;
        }
        for(int i = 1; i <= n; ++i){
            if(ans[i]){
                printf("%d:%d\n", i, ans[i]);
            }
        }
        
    }
	return 0;
}
