/*************************************************************************
    > File Name: i.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月24日 星期日 13时51分00秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
ll c[200][200];
void getc() {
	rep(i,160) {
		c[i+1][0] = 1;
		c[i+1][i+1] = 1;
	}
	for(int i = 2; i <= 160; ++i){
		for(int j = 1; j <= 160; ++j){
			c[i][j] = (c[i-1][j] + c[i-1][j-1])%MOD;
		}
	}
}
ll dp[160][160];
ll dfs(int a, int b) {
	ll &ans = dp[a][b];
	if(ans >= 0) return ans;
	ans = 0;
	for(int i = 1; i <= a-1; ++i){
		ans = (ans + dfs(a-1,b))%MOD;
	}
	for(int j = 1; j <= b-1; ++j){
		ans = (ans + dfs(a,b-1))%MOD;
	}
	return ans;
}
ll n, m;
void slove(){
	ll ans = 0;
	memset(dp, -1 , sizeof dp);
	for(int i = 1; i <= 150; ++i) {
		dp[i][1] = 1;
		dp[1][i] = 1;
	}
	dfs(150,150);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			ans = (ans + (n-i+1)*(n-j+1)*2*dp[i][j] - 1)%MOD;
		}
	}
	ans = (ans%MOD + MOD)%MOD;
	printf("%lld\n",ans);
}

int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	while(cin >>  n >> m){
		slove();
	}
	return 0;
}
