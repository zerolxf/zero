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
const int maxn = 5e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
struct Edge{
    int u, v, c;
    bool operator < (const Edge& e)const{
        return c > e.c;
    }
}edge[maxn];
int n, k;
bool vis[maxn];
int p[maxn];
int find(int x) {
    return p[x] = (p[x] == x?x:find(p[x]));
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int t, u, v, c;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        ll sum = 0;
     //   edge.clear();
        for(int i = 0; i <= n; ++i) vis[i] = false;
        for(int i = 0; i < n-1; ++i){
            scanf("%d%d%d",&u,&v,&c);
            edge[i] = Edge{u,v,c};
            sum += c;
        }
        while(k--) {
            scanf("%d",&u);
            vis[u] = true;
        }
        sort(edge, edge+n-1);
        for(int i = 0; i <= n; ++i){
            p[i] = i;
        }
        ll ans = 0;
        for(int i = 0; i < n-1; ++i) {
            Edge& e = edge[i];
            u = find(e.u), v = find(e.v);
            if(vis[u] && vis[v]) continue;
            if(vis[v]) swap(u,v);
            p[v] = u;
            ans += e.c;
        }
        ans = sum - ans;
        printf("%lld\n",ans);
    }
    return 0;
}
