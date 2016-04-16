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
int dp[30][20][2][10], bit[30];
int dfs(int pos, int m, int e,bool t, bool flag) {
	if(pos <= 0) return t&&(m==0);
	if(!flag && dp[pos][m][t][e] != -1){
		return dp[pos][m][t][e];
	}
	int end = flag?bit[pos]:9, ans = 0;
	for(int i = 0; i <= end; ++i){
		ans += dfs(pos-1,(m*10+i)%13,i,t||(e==1&&i==3),flag&&i==end);
	}
	if(!flag) dp[pos][m][t][e] = ans;
	return ans;
}
int getans(int x){
	int pos = 0;
	while(x){
		bit[++pos] = x%10;
		x/=10;
	}
	return dfs(pos,0,0,0,1);
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int x;
    MEM(dp,-1);
    while(cin >> x){
    	cout << getans(x) << "\n";
    }
    return 0;
}