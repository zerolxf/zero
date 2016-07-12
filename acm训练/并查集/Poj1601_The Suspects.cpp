
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
const int maxn = 3e4+600;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
int vis[maxn], p[maxn], h[maxn];
vector<int> G[maxn];
int ans, n, m, k, a, kase;
void init() {
    ans = 0;
    for(int i = 0; i <=m+n; ++i) {
        G[i].clear();
    }
}
void bfs(int u) {
    vis[u] = kase;
    if(u < n)++ans;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(vis[v] != kase) {
            bfs(v);
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    while(scanf("%d%d", &n, &m) == 2 && n) {
        kase++;
        init();
        for(int i = 0; i < m; ++i) {
            scanf("%d", &k);
            for(int j = 0; j < k; ++j) {
                scanf("%d", &a);
                G[a].push_back(i+n);
                G[i+n].push_back(a);
            }
        }
        bfs(0);
        printf("%d\n", ans );
    }

    return 0;
}
