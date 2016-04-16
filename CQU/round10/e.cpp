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
const int maxn = 2e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
double p[maxn];
int head[maxn], nxt[maxn], to[maxn], ecnt, cnt[maxn];
void addegd(int u, int v) {
	nxt[ecnt] = head[u];
	to[ecnt] = v;
	head[u] = ecnt++;
}
void init(int n){
	int _n = n*n*2+1;
	ecnt = 0;
	for(int i = 0; i <= n; ++i) cnt[i] = 0;
	for(int i = 0; i <= _n; ++i){
		head[i] = -1;
	}
}
double dp[11000][60];
double dfs(int u, int step, int pos) {
	double &ans = dp[step][pos];
	if(ans != -1) return ans;
	if(step==0)  {
		if(pos==u) return ans = 0;
		return ans = 1;
	}
	ans = 0;
	for(int i = head[pos]; ~i; i = nxt[i]) {
		int v = to[i];
		if(v==u) continue;
		ans += dfs(u,step-1,v)*p[v];
	}
	return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int t, n, m,u, v, d;
    scanf("%d",&t);
    while(t--){
    	scanf("%d%d%d",&n,&m,&d);
    	init(n);
    	for(int i = 0; i < m; ++i){
    		scanf("%d%d",&u,&v);
    		//pr(u);prln(v);
    		addegd(u,v);
    		addegd(v,u);
    		cnt[u]++;cnt[v]++;
    	}
    	for(int i = 1; i <= n; ++i){
    		p[i] = 1.0/cnt[i];
    	}
    	for(int i = 1; i <= n; ++i){
    		double ans = 0;
    		for(int j = 1; j <= n; ++j){
    			for(int k = 1; k <= d; ++k){
    				dp[k][j] = -1;
    			}
    			if(i==j) dp[0][i] = 0;
    			else dp[0][j] = 1.0/n;
    		}
    		for(int j = 1; j <= n; ++j){
    			if(i==j) continue;
    			ans += dfs(i,d,j);
    		}	
    		printf("%.10f\n", ans);
    	}
    }
    return 0;
}