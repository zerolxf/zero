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
const int maxn = 3e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
bool vis[maxn];
int n, m;
struct Edge{
    int u, v, h, c;
    bool operator < (const Edge& rhs)const {
        return h > rhs.h || (h==rhs.h&&c < rhs.c);
    }
};
int p[maxn], edgenum;
int find(int x) {
    return p[x] =(p[x]==x?x:find(p[x]));
}
void unit(int x, int y) {
    x = find(x); y = find(y);
    if(x == y) return;
    p[x] = y;
    return;
}
int dis[maxn];
void init() {
    for(int i = 0; i <= n; ++i) {
       // head[i] = -1;
       dis[i] = INF;
        p[i] = i;
    }
}
vector<Edge> edge;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int kase = 0;
    int u, v, c, s, t, h, hh;
    while(cin >> n >> m && (n+m) != 0) {
           // pr(n);prln(m);
        if(kase) printf("\n");
        init();
        edge.clear();//ee.clear();
        for(int i = 0;i < m; ++i){
            cin>> u >> v >> h >> c;
            if(h == -1) h = INF;
            edge.push_back(Edge{u,v,h,c});
        }
        sort(edge.begin(), edge.end());
        cin >> s >> t >> h;
        hh = h;
   // pr(s);pr(t);prln(h);
        vector<Edge> ee;
        for(int i = 0; i < edge.size(); ++i) {
            Edge e = edge[i];
            //pr(i);
            if(e.h >= hh || find(s) != find(t)) {
                hh = min(hh, e.h);
                ee.push_back(e);
                unit(e.u,e.v);
            } else break;
        }
        dis[s] = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < ee.size(); ++j) {
                Edge& e = ee[j];
               //pr(i);
                if(dis[e.u] + e.c < dis[e.v]) {
                    dis[e.v] = dis[e.u] + e.c;
                }
                if(dis[e.v] + e.c < dis[e.u]){
                    dis[e.u] = dis[e.v] +e.c;
                }
            }
        }
        printf("Case %d:\n",++kase);
        if(dis[t] == INF) {
            printf("cannot reach destination\n");
            continue;
        }
        printf("maximum height = %d\n",hh);
        printf("length of shortest route = %d\n",dis[t]);
    }
    return 0;
}
