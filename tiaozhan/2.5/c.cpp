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
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long

int dp[maxn][maxn], n, a[400];
void bellford(){
	for(int i = 0; i <= 50; ++i) dp[i][i] = 0;
	for(int k = 0; k <= 50; ++k)
	for(int i = 0; i <= 50; ++i) {
		for(int j = 0; j <= n; ++j) {
			if(dp[i][k]!=INF && dp[k][j]!=INF)
			dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
		}
	}
}
vector<int> b;
int vis[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int u, v, c;
    while(scanf("%d", &n)!=EOF&&n){
    	b.clear();
    	for(int i = 0; i <= 50; ++i) {
    		vis[i] = 0;
    		for(int j = 0; j <= 50; ++j)
    			dp[i][j] = INF;
    	}
    	for(int i = 0; i < n; ++i) {
    		scanf("%d%d%d", &u, &v, &c);
    		dp[u][v] = dp[v][u] = c;
    		vis[u] = vis[v] = 1;
    	}
    	bellford();
    	ll ans = 1e18, num;
    	for(int i = 0; i < 50; ++i) {
    		ll sum = 0;
    		if(!vis[i]) continue;
    		for(int j = 0; j < 50; ++j) {
    			if(!vis[j]) continue;
    			sum += dp[i][j];
    		}
    		if(sum < ans) {
    			ans = sum;
    			num = i;
    		}
    	}
    	printf("%lld %lld\n", num, ans);
    }
    return 0;
}