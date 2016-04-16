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
const ll MOD = 1e9+7;
struct Node{
	ll cnt, sum, qsum;
	void reduce(){
		cnt = cnt%MOD;
		sum = sum%MOD;
		qsum=qsum%MOD;
	}
}dp[30][10][10];
ll bit[30], p[20];
Node dfs(int pos, int presum, int mod, bool flag) {
	if(pos <= 0){
		Node tmp ;
		tmp.cnt = (presum!=0&&mod!=0);
		tmp.qsum = tmp.sum = 0;
		return tmp;
	}
	if(!flag && dp[pos][presum][mod].cnt!=-1) return dp[pos][presum][mod];
	int end = flag?bit[pos]:9;
	Node ans={0,0,0},tmp;
	for(int i = 0; i <= end;++i){
		if(i==7) continue;
		tmp = dfs(pos-1,(presum+i)%7,(mod*10+i)%7,flag&&i==end);
		ans.cnt += tmp.cnt;
		ans.sum += (tmp.sum+(((p[pos-1]*i)%MOD)*tmp.cnt)%MOD)%MOD;

		ans.qsum += (tmp.qsum + ((2*p[pos-1]*i)%MOD*tmp.sum%MOD)%MOD);
		ans.sum%=MOD;
		ans.qsum += ((tmp.cnt*p[pos-1])%MOD*p[pos-1]%MOD*i%MOD*i%MOD);
		ans.reduce();
	}
	if(!flag) dp[pos][presum][mod] = ans;
	return ans;
}
ll getans(ll x){
	int pos = 0;
	ll ans = 0;
	while(x){
		bit[++pos] = x%10;
		x/=10;
	}
	ans = dfs(pos,0,0,1).qsum;
	return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
   	for(int i = 0; i <= 20; ++i){
   		for(int j = 0; j < 8; ++j){
   			for(int k = 0; k < 8; ++k){
   				dp[i][j][k].cnt = -1;
   			}
   		}
   	}
   	p[0] = 1;
   	for(int i = 1; i <= 19; ++i){
   		p[i] = p[i-1]*10%MOD;
   	}
   	int t;
   	ll l, r;
   	cin >> t;
   	while(t--){
   		cin >> l >> r;
   		ll ans = getans(r)-getans(l-1);
   		ans = (ans%MOD+MOD)%MOD;
   		printf("%lld\n",ans );
   	}
    return 0;
}