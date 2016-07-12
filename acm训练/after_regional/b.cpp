
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
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
ll cost[maxn], cnt[maxn], vis[maxn] ;
vector<int> G[maxn];

void bfs(int u) {
    vis[u] = true;
    for(int i = 0; i < G[u].size(); ++i) {
        if(!vis[G[u][i]]) {
            cnt[G[u][i]]--;
            cnt[u]--;
            if(cnt[G[u][i]] < 2) {
                bfs(G[u][i]);
            }
        }
    }
}
ll dfs(ll u, ll& c) {
    ll ans = cost[u];
    vis[u] = true;
    c++;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(!vis[v]) {
            ans += dfs(v, c);
        }
    }
    return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    ll t, kase = 0, n, m, v, u,  c, x, ans;
    cin >> t;
    while(t--) {
        scanf("%lld%lld", &n, &m);
        for(int i = 1; i <= n; ++i) {
            vis[i] = 0;
            cnt[i] = 0;
            G[i].clear();
        }
        for(int i = 1; i <= n; ++i) scanf("%lld", cost + i);
        for(int i = 0; i < m; ++i) {
            scanf("%lld%lld", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
            cnt[u]++;cnt[v]++;
        }
        ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(cnt[i] < 2 && !vis[i]) {
                bfs(i);
            }
        }
        for(int i = 1; i <= n; ++i) {
            if(cnt[i] >= 2 && !vis[i]) {
                c = 0;
                x = dfs(i, c);
              //  pr(i);pr(x);prln(c);
                if(c&1) ans += x;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
