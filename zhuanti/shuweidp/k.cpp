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
ll dp[30][60000], bit[30], p[100];
ll dfs(int pos, int s, bool flag,  bool first) {
	if(pos <= 0){
		//int ok = 1;
		for(int i = 0; i <= 9; ++i){
			int ns = (s/p[i])%3;
			if(i%2==0){
				if(ns==2) return 0;
			} else {
				if(ns==1) return 0;
			}
		}
		return 1;
	}
	if(!flag && dp[pos][s] != -1) return dp[pos][s];
	int end = flag?bit[pos]:9;
	ll ans = 0;
	for(int i = 0; i <= end; ++i){
		int ss = s,ns = (s/p[i])%3;
		ss -= ns*p[i];
		if(ns==0) ns = 1;
		else if(ns==1) ns = 2;
		else ns = 1;
		ss += ns*p[i];
		ans += dfs(pos-1,first&&i==0?0:ss,flag&&i==end,first&&i==0);
	}
	if(!flag) dp[pos][s] = ans;
	return ans;
}
ll getans(ll x){
	int pos = 0;
	ll ans = 0;
	//if(x==0) return 1;
	while(x){
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
    MEM(dp,-1);
    p[0] = 1;
    for(int i = 1; i <= 10; ++i) p[i] = p[i-1]*3;
    ll t, x, y;
    cin >> t;
    while(t--){
    	cin >> x >> y;
    	ll ans = getans(y) - getans(x-1);
    	printf("%lld\n", ans);
    }
    return 0;
}