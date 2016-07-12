
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
const int INF = 0x7f7f7f7f;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
struct edge{
    int v,c;
    edge();
    edge(int v, int c):v(v),c(c){}
};
int d[maxn];
vector<edge> G[maxn];
void bfs(int s) {
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < G[u].size(); ++i) {
            edge& e = G[u][i];
            if(d[u] + e.c < d[e.v]) {
                d[e.v] = e.c + d[u];
                q.push(e.v);
            }
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int n, m, u, v, c;
    cin >> m >> n;
    for(int i = 0; i <= n; ++i) d[i] = INF;
    d[1] = 0;
    for(int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &c);
        G[u].push_back(edge(v,c));
        G[v].push_back(edge(u,c));
    }
    bfs(1);
    cout << d[n] << "\n";
    return 0;
}
