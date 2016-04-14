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
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)      // cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int dp[41230][2], sum[maxn], num[maxn], cost[maxn];
int main(){

    freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

    int n, a, b;
    while(cin >> n >> a >> b) {
    	num[0] = 0;
    	for(int i = 1; i <= n; ++i) {
    		cin >> num[i];
    		sum[i] = sum[i-1] + num[i];
    		cost[i] = min(num[i], num[i-1]);
    	}
    	if(a < b) swap(a,b);
    	MEM(dp,0x3f);
    	dp[0][0] = 0;
    	dp[0][1] = 0;
    	for(int i = 1; i <= n; ++i) {
    		
    		for(int j = a; j >=  0; --j) {
    			//if(dp[j][0] != INF) {
    				int x = dp[j][0], y = dp[j][1];
    				if(j >= num[i] && j -num[i] >= sum[i-1]-b) dp[j][0] = min(dp[j-num[i]][0],dp[j-num[i]][1]+cost[i]);
    				else dp[j][0] = INF;
    			prln((j >= sum[i] - b));prln((j+num[i] <= sum[i]));
    				if(j+num[i] <= sum[i] && j >= sum[i] - b) {
    					pr(i);prln(j);
    					prln(dp[1][0]);
    					pr(dp[j][1]);pr(cost[i]);pr(dp[j][0]);prln(dp[j][0]+cost[i]);
    					dp[j][1] = min(dp[j][1],x+cost[i]);
    				} else dp[j][1] = INF;
    				pr(i);pr(j);pr(num[i]);pr(sum[i]);
    				pr(dp[j][0]);prln(dp[j][1]);
    				prln(dp[1][0]);
    			}
    			prln("*************************\n");
    	}
    	int ans = INF;
    	//for(int i = 1; i <= n; ++i) {
    		for(int j = 1; j <= a; ++j) {
    			ans = min(ans,dp[j][0]);
    			ans = min(ans,dp[j][1]);
    			pr(j);pr(dp[j][0]);prln(dp[j][1]);
    		}

    	if(ans != INF){
    		cout << ans << "\n";
    	} else cout << "-1\n";
    }
    return 0;
}