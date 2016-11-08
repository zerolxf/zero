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
int dp[3][100010], sum[maxn];
int n, m, c[maxn], v[maxn], num[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int t;
    cin >> t;
    while(t--) {
    	cin >> n;
    	sum[0] = 0;
    	for(int i = 1; i <= n; ++i){
    		scanf("%d%d",&num[i], &v[i]);
    		sum[i] = sum[i-1] + num[i];

    	}
    	rep(i,100010) dp[0][i] = dp[1][i] = INF;
    	dp[0][0] = 0;
    	int p = 0;
    	for(int i = 1; i <= n; ++i) {
    		for(int j = 0; j <= sum[i]; ++j){
    			if(dp[p][j] != INF) {
    				dp[1-p][j] = min(dp[1-p][j],dp[p][j]);
    				dp[1-p][sum[i]] = min(dp[1-p][sum[i]], dp[p][j] + 10*v[i] + num[i]*v[i] + (sum[i]-j-num[i])*v[i]);
    			}
    		}
    		p = 1-p;
    	}
    	int ans = dp[p][sum[n]];
    	printf("%d\n", ans);
    }
    return 0;
}