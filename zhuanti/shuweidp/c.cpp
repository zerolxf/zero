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
ll dp[30][4], num[30],cnt ;
ll get(ll x) {
	ll temp = x;
	cnt = 0;
	while(x) {
		num[++cnt] = x%10;
		x/=10;
	}
	num[cnt+1] = 0;
	bool flag = 0;
	ll ans = 0;
	for(int i = cnt; i ; --i) {
		ans += num[i]*dp[i-1][2];
		if(!flag) {
			if(num[i] > 4) {
				ans += dp[i-1][0];
			}
			if(num[i] > 6) {
				ans += dp[i-1][1];
			}
			if(num[i+1]==6&&num[i] > 2) {
				ans += dp[i][1];
			}
		} else ans += num[i]*dp[i-1][0];
		if(num[i]==4 || (num[i+1]==6&&num[i]==2)) flag = true;
	}
	//prln(ans);
	return temp -ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    dp[0][0] = 1;
    for(int i = 1; i <= 19; ++i) {
    	dp[i][0] = 9*dp[i-1][0] - dp[i-1][1];
    	dp[i][1] = dp[i-1][0];
    	dp[i][2] = dp[i-1][2]*10 + dp[i-1][1] + dp[i-1][0];
    }
    ll l, r;
    while(cin >> l >> r && l + r!=0){
    	ll ans = get(r+1)-get(l);
    	printf("%lld\n",ans );
    }
    return 0;
}