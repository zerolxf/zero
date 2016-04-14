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
int dp[11][123456], a[20], b[20];
int dfs(int i, int pos, int num, int flag) {
	//prln("");
	//pr(i);pr(num);prln(flag);
	if(num < 0) return 0;
	if(num==0) return 1;
	if(i < 0) return 1;
	if(!flag&&dp[i][num]!=-1) return dp[i][num];
	int ed = flag?b[i]:9;
	int ans = 0;
	//prln(ed);
	for(int j = 0; j <= 9; ++j) {
		int add = dfs(i-1,pos,num-j*(1<<i),flag&&(j==b[i]));
		if(j <= ed) ans += add;
	}

	//pr(i);prln(num);prln(ans);
	if(!flag) dp[i][num] = ans;
	return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int t, a1, b1, a2, cnt,kase = 0;
    cin >> t;
    MEM(dp,-1);
    while(t--) {
    	//MEM(dp,-1);
    	scanf("%d%d", &a1, &b1);
    	cnt = a2 = 0;
    	while(a1) {
    		a[cnt] = a1%10;
    		a2 += a[cnt]*(1<<cnt);
    		a1/=10;
    		cnt++;
    	}
    	//prln(a2);
    	cnt = 0;
    	while(b1) {
    	//	pr(b1%10);
    		b[cnt++] = b1%10;
    		b1/=10;
    	}

    	//prln(cnt-1);
    	int ans = dfs(cnt-1,0,a2,1);
    	printf("Case #%d: %d\n",++kase, ans);
    }
    return 0;
}