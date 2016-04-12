/*************************************************************************
    > File Name: c.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年03月11日 星期五 12时08分45秒
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
ll dp[30][4];
int num[30];
int cnt;
void getnum(ll x) {
	cnt = 0;
	while(x) {
		num[++cnt] = x%10;
		x/=10;
	}
	prln(cnt);
	num[cnt+1] = 0;
}
ll getans() {
	bool flag = 0;
	ll ans = 0;
	for(int i = cnt; i; --i) {
		ans += dp[i-1][2]*num[i];
		if(!flag &&num[i]>6){
			ans += dp[i-1][1];
		}
		if(flag) ans += num[i]*dp[i-1][0];
		if(!flag && num[i+1]==6&&num[i]==2) flag = true;
	}
	prln(ans);
	return ans;
}
int main(){
#ifdef LOCAL
//	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
#endif
	dp[0][0] = 1;
	for(int i = 1; i <= 19; ++i) {
		dp[i][0] = 10*dp[i-1][0] - dp[i-1][1];
		dp[i][1] = dp[i-1][0];
		dp[i][2] = 10*dp[i-1][2] + dp[i-1][1];
	}
	ll ans = 0, l = 0, r = 0;
	while(cin >> l >> r&& l + r != 0) {
		ans = r-l+1;
		getnum(l+7);
		ans += getans();
		getnum(r+8);
		ans -= getans();
		printf("%lld\n",ans);
	}
	return 0;
}
