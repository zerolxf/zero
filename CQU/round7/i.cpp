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
map<ll,ll> dp;
int n, a[20], b[20], now[20],c[20];
ll dfs(ll x) {
	if(dp.count(x)){
		//if(dp[x]!=-1) return dp[x];
		return -1;
	} 
	dp[x] = -1;
	ll &ans  = dp[x];
	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		now[i] = x%10;
		if(now[i] <= a[i]) cnt++;
		x/=10;
	}
	if(cnt==n) return ans=1;
	bool can = cnt > (n-cnt)?0:1;
	for(int i = 0; i < n; ++i){
		if(now[i] == a[i]) {
			if(can) now[i]++;
		} else {
			now[i]++;
			if(now[i]==a[i]+b[i]+1) {
				now[i] = 1;
			}
		}
	}
	ll xx = 0;
	for(int i = n-1; i >= 0; --i) {
		xx = xx*10+now[i];
	}
	ans = dfs(xx);
	if(ans!=-1) return ++ans;
	return -1;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int kase = 0;
    while(cin >> n&&n){
    	printf("Case %d: ",++kase);
    	dp.clear();
        for(int i = 0; i < n; ++i){
    		cin >> a[i] >> b[i] >> c[i];
	    }
	    ll x = 0;
	    for(int i = n-1; i >= 0; --i) {
	    	x = x*10 + c[i];
	    }
	    ll ans = dfs(x);

	    printf("%lld\n",ans );
	}
    return 0;
}