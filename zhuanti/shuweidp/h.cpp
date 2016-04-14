
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
int dp[20][200100], bit[30];
int F(int x){
	int pos = 0;
	int ans = 0;
	while(x){
		ans += (x%10)*(1<<pos);
		x/=10;++pos;
	}
	return ans;
}
int dfs(int pos, int m, bool flag){
	if(pos < 0) return m >= 0;
	if(m < 0) return 0;
	if(!flag && dp[pos][m] != -1) return dp[pos][m];
	int end = flag?bit[pos]:9;
	int ans = 0;
	for(int i = 0; i <= end; ++i){
		ans += dfs(pos-1,m-(1<<pos)*i,flag&&i==end);
	}
	if(!flag) dp[pos][m] = ans;
	return ans;
}
int A, B;
int getans(){
	int ma = F(A);
	int pos = 0;
	while(B){
		bit[pos++] = B%10;
		B/=10;
	}
	int ans = dfs(pos-1,ma,1);
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    MEM(dp,-1);int  kase = 0;
    int t;
    cin >> t;
    while(t--){
    	printf("Case #%d: ",++kase);
    	scanf("%d%d",&A,&B); 
    	int ans = getans();
    	cout << ans << "\n";
    }
    return 0;
}