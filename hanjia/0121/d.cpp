#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 1e2+100;
const int INF = 0x3f3f3f3f;
#define pr(x)      // cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int cost[maxn][maxn], flag, vis[maxn], n;
vector<int> G[maxn];
int cnt;
int dfs(int pa,int s) {
	cnt++;
	int ans = 0;
	for(int i = 0; i < G[s].size(); ++i) {
		int v = G[s][i];
		if(v == pa) continue;
		if(cost[s][v]*flag > 0) {
			ans += flag*cost[s][v];
		}
		if(cnt!=n) ans +=dfs(s,v);
			pr(v);pr(pa);prln(s);prln(ans);
		return ans;
	}
	return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int  u, v, c;
    cin >> n;

    for(int i = 1; i <= n; ++i) {
    	cin >> u >> v ;
    	G[u].push_back(v);
    	G[v].push_back(u);
    	cin >> cost[u][v];
    	cost[v][u] = -cost[u][v];
    }
    CLR(vis);
    flag = -1;
    //vis[u] = vis[v] = 1;
    int ans = 0;
    cnt = 0;
    ans = dfs(u,v);
    prln(ans);
    CLR(vis);
    //flag = 1;
    //vis[u] = vis[v] = 1;
    cnt = 0;
    int k= dfs(v,u);
    prln(k);
    ans = min(k,ans);
    printf("%d\n", ans);
    return 0;
}