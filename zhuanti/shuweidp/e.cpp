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
ll dp[65][60][60], bit[60];
int dfs(int pos, int cnt1, int cnt, bool flag, bool first) {
	if(pos <= 0) return first || cnt >= cnt1;
	int end = flag?bit[pos]:1;
	ll ans = dp[pos][cnt1][cnt];
	if(!flag&&!first&&ans!=-1) return ans;
	ans = 0;
	for(int i = 0; i <= end; ++i){
		//if(!first) {
		//	ans += dfs(pos-1,cnt1+i,cnt+1-i,flag&&i==end,0);
		//} else ans += dfs(pos-1,i==1,0,flag&&i==end,i==0);
		ans += dfs(pos-1,cnt1+i,cnt+((i==0)&&!first),flag&&i==end,i==0&&first);
	}
	if(!flag&&!first) dp[pos][cnt1][cnt] = ans;
	return ans;
}
ll getans(ll x) {
	int cnt = 0;
	while(x) {
		bit[++cnt] = x&1;
		x/=2;
	}
	ll ans = dfs(cnt,0,0,1,1);
	return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    ll x, y;
    MEM(dp,-1);
    while(cin >> x >> y){
    	cout << getans(y) - getans(x-1) << "\n";
    }
    return 0;
}