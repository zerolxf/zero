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
const int maxn = 1e3+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long

vector<int> G[2][maxn];
int in[2][maxn];
int cnt = 0;
bool vis[maxn];

void dfs(int v, int x, int id) {
    vis[v] = 1;
    in[x][v] = id;
    for (int i = 0; i < G[x][v].size(); ++i) {
        if (!vis[G[x][v][i]]) dfs(G[x][v][i], x, id);
    }
}

int dfsans(int u, int &len, int xx) {
    vis[u] = 1;
    len += (in[1][u] == xx);
    for (int i = 0; i < G[0][u].size(); ++i) {
        int v = G[0][u][i];
        if (!vis[v]) dfsans(v, len, xx);
    }
    return len;
}

int main(){
    #ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, m, u, v; scanf("%d", &n);
    scanf("%d", &m);
    while (m --) {
        scanf("%d%d", &u, &v);
        G[0][u].push_back(v);
        G[0][v].push_back(u);
    }
    cnt = 0;
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) dfs(i, 0, ++cnt);
    }

    scanf("%d", &m);
    while (m --) {
        scanf("%d%d", &u, &v);
        G[1][u].push_back(v);
        G[1][v].push_back(u);
    }
    cnt = 0;
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) dfs(i, 1, ++cnt);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof vis);
        int x = 0;
        ans = max(ans, dfsans(i, x, in[1][i]));
    }
    printf("%d\n", ans);
    return 0;
}
