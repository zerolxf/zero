
/*
* @author:  liangxianfeng
* @mail: liangxianfeng96@qq.com
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define repp(i,n,x) for(int i =x; i < n+x; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl;
const int MOD = 1e9+7;
const int maxn = 1e5+100;
const int INF = 0x3f3f3f3f;
int a[maxn];

int dp[maxn][2];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    int n;
    cin >> n;
    for(int i = 0; i <= n+1;++i) dp[i][0] = dp[i][1] = INF;
    int g = 0;
    for(int i = 1; i <= n; ++i) {
    	scanf("%d",&a[i]);
    	g = __gcd(g, a[i]);
    }
    int ans = INF;
    if(g<=1){
    	if(a[1]&1){
    		dp[1][0] = INF;
    		dp[1][1] = 0;
    	}else{
    		dp[1][0] = 0;
    		dp[1][1] = INF;
    	}
    	for(int i = 2; i <= n; ++i){
    		if(a[i]&1){
    			dp[i][1] = min(dp[i-1][0], dp[i][1]);
    			dp[i][0] = min(dp[i-1][1]+1, dp[i][0]);
    			dp[i][0] = min(min(dp[i-1][1],dp[i-1][0])+2, dp[i][0]);
    		}else{
    			//dp[i][1] = min(dp[i-1][1]+1, dp[i][1]);
    			dp[i][0] = min(dp[i-1][0], dp[i][0]);
    			dp[i][0] = min(min(dp[i-1][1],dp[i-1][0])+2, dp[i][0]);
    		}
    		// pr(i);pr(dp[i][0]);prln(dp[i][1]);
    	}
    	ans = min(dp[n][1]+2, dp[n][0]);
    }else ans = 0;
    if(ans<INF)printf("YES\n%d\n",ans);
    else printf("NO\n");

    return 0;
}
