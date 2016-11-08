
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
    int v,c;
};
struct node{
    int d, u;
    bool operator <(const node& rhs)const {
        return d < rhs.d;
    }
};
vector<int> G[maxn];
vector<Edge> edge;
bool done[maxn];
int d[maxn];
int n, m;
void init() {
    for(int i = 0; i <= n; ++i){
        G[i].clear();
        d[i] = done[i] = 0;
    }
    edge.clear();
}
void addedge(int u, int v, int c) {
    int m = edge.size();
    edge.push_back((Edge){u,c});
    edge.push_back((Edge){v,c});
    G[v].push_back(m);
    G[u].push_back(m+1);
}
void dijkstra(int s) {
    priority_queue<node> q;
    q.push((node){INF,s});
    d[s] = INF;
    while(!q.empty()) {
        node x= q.top();q.pop();
        int u = x.u;
        if(done[u]) continue;
        done[u] = true;
        for(int i = 0; i < G[u].size(); ++i) {
            Edge &e = edge[G[u][i]];
            if(min(d[u], e.c) > d[e.v]) {
                d[e.v] = min(d[u], e.c);
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
    int t, kase = 0, u, v, c;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        init();
        for(int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &c);
            addedge(u,v,c);
        }
        dijkstra(1);
        printf("Scenario #%d:\n%d\n\n", ++kase, d[n]);
    }
    return 0;
}
