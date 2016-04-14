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
const int maxn = 6e3+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
ll dp[maxn], a[maxn], b[maxn];
ll labs(ll x, ll y) {
	return x>y?x-y:y-x;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n;
    while(cin >> n && n){
    	for(int i = 0; i < n; ++i){
    		scanf("%lld", &a[i]);
    		b[i] = a[i];
    	}
    	sort(b,b+n);

    	for(int i = 0; i < n; ++i){
    		dp[i] = labs(a[i]-a[0]); 
    	}
  		for(int i = 0; i < n; ++i) {
  			ll ret = 1e18;
  			for(int j = 0; j < n; ++j) {
  				ret = min(ret,dp[j]);
  				dp[j] = ret + labs(a[i]-b[j]);
  			}
  		}
  		ll ans = 1e18;
  		for(int i = 0; i < n; ++i) {
  			ans = min(ans, dp[i]);
  		}
  		printf("%lld\n", ans);
    }
	    return 0;
}