/*************************************************************************
    > File Name: b.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月11日 星期日 17时00分03秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
vector<int> G[maxn];
int a[maxn];
int path[maxn];
int cnt;
int vis[maxn];
void dfs(int u){
    int usiz = G[u].size();
    vis[u] = true;
    for(int i = 0; i < usiz; ++i){
        int v = G[u][i];
        if(v == u) continue;
        if(vis[v]) continue;
        path[cnt++] = v;
        dfs(v);
        path[cnt++] = u;
        a[u] = -a[u];
        a[v] = -a[v];
        if(a[v] == -1){
            path[cnt++] = v;
            path[cnt++] = u;
            a[u] = -a[u];
            a[v] = -a[v];
        }
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    while(cin>>n){
        cnt = 0;
        path[cnt++] = 1;
        bool ok = true;
        rep(i,n){
            scanf("%d", &a[i+1]);
            if(a[i+1]==-1) ok = false;
        }
        if(ok){
            printf("1\n");
            return 0;
        }
        int u, v;
        for(int i = 1; i < n; ++i){
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1);
        if(a[1] == -1) {
            int v = G[1][0];
            path[cnt++] = v;
            path[cnt++] = 1;
            path[cnt++] = v;
        }
        rep(i,cnt){
            printf("%d ", path[i]);
        }
        cout<<"\n";
    }

	return 0;
}
