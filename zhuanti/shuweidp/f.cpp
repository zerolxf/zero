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
ll dp[21][21][2000], bit[30];
ll dfs(int pos, int m, int center, bool flag) {
	if(pos <= 0) return m == 0;
	if(m < 0) return 0;
	if(!flag && dp[pos][center][m] != -1) return dp[pos][center][m];
	int end = flag?bit[pos]:9;
	ll ans = 0;
	//prln(end);
	for(int i = 0; i <= end; ++i){
		//pr(i);prln(m+i*(pos-center));
		ans += dfs(pos-1,m+i*(pos-center),center,flag&&i==end);
		//prln(ans);
	}
	if(!flag) dp[pos][center][m] = ans;
	return ans;
}

ll getans(ll x){
	//if(x < 0) return 0;
	int pos = 0;
	ll ans = 0;
	while(x) {
		bit[++pos] = x%10;
		x/=10;
	}
	for(int i = pos; i; --i){
		ans += dfs(pos,0,i,1);
	}
	return ans - pos+1;
}

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    MEM(dp,-1);
    int t;
    ll x, y;
    cin >> t;
    while(t--){
    	cin >> x >> y;
    	ll ans = getans(y) - getans(x-1);
    	printf("%lld\n", ans);
    }
    return 0;
}