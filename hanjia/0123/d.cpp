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
#define pr(x)       //cout << #x << " = " << x << " ";
#define prln(x)     //cout << #x << " = " << x <<endl;
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
ll dp[100], mi[100];
ll dfs(ll x) {
	if(x/10==0) return x;
	if(x/100==0){
		int a = x%10;
		int b = x/10;
		if(a >= b) return b+9;
		return b+8;
	}
	ll cnt = 0, _x = 1;
	//get weishu
	while(_x < x) {
		_x = _x*10;
		cnt++;
	}
	ll ans = 0;
	ll a = x/(_x/10);
	ll b = x%10;
	pr(a);pr(b);prln(_x);
	if(a <= b) {
		ans += (x-a*(_x/10)-b)/10+1; 
	} else ans += (x-a*(_x/10)-b)/10;
	prln(ans);
	ll base = mi[cnt-2];
	ans += (a-1)*base;
	prln(ans);
	for(int i = 1; i <= cnt-1; ++i) {
		pr(i);prln(dp[i]);
		ans += dp[i];
	}
	prln(ans);
	return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    mi[0] = 1;
    for(int i = 1; i <= 20; ++i){
    	mi[i] = mi[i-1]*10;
    }
    dp[0] = 0;
    dp[1] = 9;
    dp[2] = 9;
    ll base = 10;
    for(int i = 3; i <= 20; ++i) {
    	dp[i] = base*9;
    	pr(i);prln(dp[i]);
    	base = base*10;
    }
    ll l, r;
    cin >> l >> r;
    cout << dfs(r)-dfs(l-1)<< "\n";
    return 0;
}