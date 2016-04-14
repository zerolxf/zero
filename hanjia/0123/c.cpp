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
const int MOD = 1e8;
const int INF = 0x3f3f3f3f;
#define pr(x)       //cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
ll dp[200][200][3], n, m, k1,k2, a[4];
ll dfs(int n1, int n2, int c) {
	ll& ans = dp[n1][n2][c];
	int k = a[c];
	if(~ans) return ans;
	if(n1==0&&n2==0) return ans = 1;
	ans = 0;
	//pr(n1);pr(n2);
	if(c==0)
		for(int i = 1; i <= k; ++i){  
			if(i<=n1) {
				ll x = dfs(n1-i,n2,1);
				ans += x;
			}
		}
	else
	{
		for(int i = 1; i <= k; ++i){
			if(i<=n2) ans += dfs(n1,n2-i,0);
		}
	}
	ans %= MOD;
	pr(n1);pr(n2);pr(c);prln(ans);
	return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    MEM(dp,-1);
    while(cin >> n >> m >> a[0] >> a[1]) {
    	cout << (dfs(n,m,0)+dfs(n,m,1))%MOD << "\n";
    }
    return 0;
}