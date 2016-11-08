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
ll dp[20][10], a[maxn], base[30];
ll dfs(int pos, int num) {
	ll& ans = dp[pos][num];
	if(~ans) return ans;
	ans = 0;
	if(num==4) ans += base[pos-1];
	else ans += dfs(pos-1,9);
	for(int j = 0; j <= 8; ++j) {
		ll add = dfs(pos-1,j);
		ans += add;
	}
	return ans;
}
ll getans(int pos, int num, int flag) {
	if(!flag) {
		ll ans = dfs(pos,num);
		return ans;
	}
	if(pos < 1) return 0;
	ll ans = 0;
	if(num==4&&a[pos-1]==9) {
		ans += 1;
		for(int j = 0; j < pos-1; ++j)
			ans += a[j]*base[j];
	}
	else ans += getans(pos-1,a[pos-1],1);
	for(int i = 0; i < a[pos-1]; ++i) {
		ans += getans(pos-1,i,0);
	}
	return ans;
}
int getk(ll k){
	int cnt = 0;
    while(k) {
    	a[cnt++] = k%10;
    	k/=10;
    }
    return cnt;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    MEM(dp,-1);
    base[0] = 1;
    for(int i = 1; i <= 20; ++i){
    	base[i] = base[i-1]*10;
    }
    rep(i,10) dp[0][i] = 0;
    ll t, k; cin >> t;
    while(t--) {
    	scanf("%lld", &k);
    	ll ans = 0, last = 0;
  		//do{
    		last = ans;
    		int cnt = getk(k);
    		ans = getans(cnt,0,1);
    		//k += ans-last;
    	//}while(ans > last);
    	printf("%lld\n",ans);
    }
    return 0;
}