
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
    int d,u;
    bool operator < (const node& rhs)const {
        return d > rhs.d;
    }
};
int n, m;
vector<Edge> edge;
vector<int> G[maxn];
bool done[maxn];
int d[maxn];
int x[maxn], y[maxn];
void init() {
    for(int i = 0; i <= n; ++i) G[i].clear();
    edge.clear();
}
int getdis(int i,int j) {
    return (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
}
void addedge(int u, int v, int c) {
    int m = edge.size();
    edge.push_back((Edge){u,c});
    G[v].push_back(m);
    edge.push_back((Edge){v,c});
    G[u].push_back(m+1);
}

void dijkstra(int s) {
    priority_queue<node> q;
    for(int i = 0; i <= n; ++i) d[i] = INF;
    d[s] = 0;
    memset(done, 0, sizeof done);
    q.push((node){0,s});
    while(!q.empty()) {
        node x = q.top();q.pop();
        int u = x.u;
        if(done[u]) continue;
        done[u] = true;
        for(int i = 0; i < G[u].size(); ++i) {
            Edge &e = edge[G[u][i]];
          //  pr(e.v);pr(e.c);pr(d[e.v]);prln(d[u]);
            if(max(d[u], e.c) < d[e.v]) {
                d[e.v] = max(d[u], e.c);
               // prln(d[e.v]);
                q.push((node){d[e.v], e.v});
            }
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int kase = 0;
    while(cin >> n && n) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", x+i, y+i);
        }
        int dis;
        init();
        for(int i = 1; i <= n; ++i) {
            for(int j = i+1; j <= n; ++j) {
                dis = getdis(i,j);
                addedge(i,j,dis);
               // pr(i);pr(j);prln(dis);
            }
        }
        dijkstra(1);
        double ans = sqrt(d[2]);
        printf("Scenario #%d\nFrog Distance = %.3f\n\n", ++kase, ans);
    }
    return 0;
}
