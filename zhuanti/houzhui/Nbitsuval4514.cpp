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
ll dp[50][50], a[50];
ll dfs(int pos, int num){
	if(num==0) return 1;
	if(pos == num-1) return 1;
	if(pos < 0) return 0;
	ll& ans = dp[pos][num];
	if(~ans) return ans;
	ans = dfs(pos-1,num-1) + dfs(pos-1,num);
	return ans;
}
ll getans(int pos, int num, int flag) {
	if(num==0) return 1;
	if(pos < 0) return 0;
	ll ans = 0;
	if(flag) {
		if(a[pos]==0) ans += getans(pos-1,num,flag);
		if(a[pos]==1) {
			ans += getans(pos-1,num-1,flag);
			ans += dfs(pos-1,num);
		}
	} else ans += dfs(pos,num);
	return ans;
}
int getbinaery(ll k) {
	int cnt = -1;
	do{
		a[++cnt] = k%2;
		k/=2;
	}while(k);
	return cnt;
}
ll work(ll a, ll b, ll num) {
	ll ans1 = 0, ans2 = 0, cnt = 0;
	if(a){
		cnt = getbinaery(a-1);
		ans1 = getans(cnt,num,1);
	}
	cnt = getbinaery(b);
	ans2 = getans(cnt,num,1);
	return ans2-ans1;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    MEM(dp,-1);
    ll a, b, n;
    int kase = 0;
    ll base = 1;
    for(int i = 0; i < 32; ++i) {
    	base *=2;
    }
    while(cin >> a >> b >> n&&(a||b||n)) {
    	ll ans = work(a+base,b+base,n+1);
    	printf("Case %d: %lld numbers\n\n",++kase,ans);
    }
    return 0;
}