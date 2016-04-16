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
unsigned long long dp[30][4], num[30];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    dp[0][0] = 1;
    for(int i = 1; i <= 22; ++i) {
    	dp[i][0] = dp[i-1][0]*10 - dp[i-1][1];
    	dp[i][1] = dp[i-1][0];
    	dp[i][2] = 10*dp[i-1][2] + dp[i-1][1];
    }
    int t;
    cin >> t;
    while(t--){
	   	ll n, len = 0, ans = 0;
	   	cin >> n;
	    bool flag = 0;
	    n++;
	    while(n) {
	    	num[++len] = n%10;
	    	n/=10;
	    }
	    num[len+1] = 0;
	    for(int i = len; i; --i) {
	    	ans += (num[i])*dp[i-1][2];
	    	if(flag) ans += dp[i-1][0]*num[i];
	    	if(!flag && num[i] > 4) ans += dp[i-1][1];
	    	if(num[i+1] == 4 && num[i] == 9) flag = 1; 
	    }
	    cout << ans << "\n";
	}
    return 0;	
}