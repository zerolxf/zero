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
ll dp[20][12345];
int path[15345][2], cnt;
int n, m;

void dfs(int cow, int now, int pre) {
	if(cow > m) return;
	if(cow == m) {
		path[cnt][0] = pre;
		path[cnt++][1] = now;
		return;
	}
	dfs(cow+1,now<<1,pre<<1|1);
	dfs(cow+2,now<<2|3,pre<<2|3);
	dfs(cow+1,now<<1|1,pre<<1);
}




int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    while(cin >> n >> m&&(n+m!=0)) {
    	//pr(n);prln(m);
    	if(m > n) swap(n,m);
    	int sum = (1<<m)-1;
    	//rep(i,sum+1) path[i][0] = path[i][1] = 0;
    	cnt = 0;
    	//rep(i,n+1) rep(j,cnt) dp[i][j] = 0;
    	CLR(dp);
    	dp[0][sum] = 1;
      	dfs(0,0,0);
    	for(int i = 1; i <= n; ++i){
    		for(int j = 0; j < cnt; ++j)
    		{
    			dp[i][path[j][1]] += dp[i-1][path[j][0]]; 
    		}
    	}
    	printf("%lld\n",dp[n][sum]);
    }	
    return 0;
}