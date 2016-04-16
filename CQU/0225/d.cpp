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
const int maxn = 2e6+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
ll a[maxn], n, b[maxn];
ll dp[2654321];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    while(cin >> n&&n>=0) {
    	ll sum = 0;
    	for(int i = 0; i < n; ++i){
    		scanf("%lld%lld",&a[i],&b[i]);
    		sum += a[i]*b[i];
    	}
    	ll ma = sum/2;
    	for(int i = 0; i <= sum; ++i) dp[i] = 0;
    	for(int i = 0; i < n; ++i){
    		ll base = 1;
    		while(base < b[i]) {
    			b[i] -= base;
    			for(int j = sum; j >= a[i]*base; --j) {
    				dp[j] = max(dp[j], dp[j-a[i]*base]+a[i]*base);
    			}
    			base *= 2;
    		}
    		base = b[i];
    		for(int j = sum; j >= a[i]*base; --j) {
    			dp[j] = max(dp[j], dp[j-a[i]*base]+a[i]*base);
    		}
    	}
    	ll l = sum-dp[ma], r= dp[ma];
    	if(l < r) swap(l,r);
    	printf("%lld %lld\n",l,r);
    }
    return 0;
}