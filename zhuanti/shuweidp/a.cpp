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
const int MOD = 2520;

ll dp[30][3100][55], index[500], bit[40];
void init() {
	MEM(dp,-1);
	int cnt = 0;
	for(int i = 1; i <= MOD; ++i){
		if(MOD%i==0) index[i] = ++cnt;
	}
}
int gcd(int x, int y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int getlcm(int x, int y){
	return x/gcd(x,y)*y;
}
ll dfs(int pos, int m, int lcm, bool flag){
	if(pos <= 0) return (m%lcm==0);
	if(!flag && dp[pos][m][index[lcm]] != -1) {
		return dp[pos][m][index[lcm]];
	}
	int end = flag?bit[pos]:9;
	ll ans = 0;
	for(int i = 0; i <= end; ++i){
		int mm = (m*10+i)%MOD;
		int llcm = lcm;
		if(i) llcm = getlcm(llcm,i);
		ans += dfs(pos-1,mm,llcm,i==end&&flag);
	}
	if(!flag) dp[pos][m][index[lcm]] = ans;
	return ans;
}
ll getans(ll x) {
	int pos = 0;
	ll ans = 0;
	while(x) {
		bit[++pos] = x%10;
		x/=10;
	}
	ans = dfs(pos,0,1,1);
	return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    ll x, y, t;
    cin >> t;
    init();
    while(t--){
    	cin >> x >> y;
    	ll ans = getans(y) - getans(x-1);
    	printf("%I64d\n", ans);
    }
    return 0;
}