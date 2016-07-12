
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
const int maxn = 1e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
struct Edge{
    int v, c;
};
struct node{
    int d, u;
    bool operator < (const node& rhs) const {
        return d > rhs.d;
    }
};
vector<int> G1[maxn], G2[maxn];
vector<Edge> edge1, edge2;
bool done[maxn];
int  d1[maxn], d2[maxn];
int n, m;
void dijkstra(int s, int d[], vector<int>* G, vector<Edge> edge) {
    priority_queue<node> q;
    q.push((node){0, s});
    for(int i = 0; i <= n; ++i) {
        done[i] = 0;
        d[i] = INF;
    }
    d[s] = 0;
    while(!q.empty()) {
        node x = q.top();q.pop();
        int u = x.u;
        if(done[u]) continue;
        done[u] = true;
        for(int i = 0; i < G[u].size(); ++i) {
            Edge& e = edge[G[u][i]];
            if(d[u] + e.c < d[e.v]) {
                d[e.v] = d[u] + e.c;
                q.push((node){d[e.v], e.v});
            }
        }
    }
}
void addedge(int u, int v, int c) {
    int m = edge1.size();
    edge1.push_back((Edge){v,c});
    G1[u].push_back(m);
    m = edge2.size();
    edge2.push_back((Edge){u,c});
    G2[v].push_back(m);
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int t, kase = 0, u, v, c, x;
    scanf("%d%d%d", &n, &m, &x);
    for(int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &c);
        addedge(u, v, c);
    }
    dijkstra(x, d1, G1, edge1);
    dijkstra(x, d2, G2, edge2);
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans = max(ans, d1[i]+d2[i]);
    }
    cout << ans << "\n";
    return 0;
}
