
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
const int maxn = 3e3+100;
const int INF = 0x3f3f3f3f;
ll dp[maxn][maxn];
pair<int,int> node[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    memset(dp, 0x3f, sizeof dp);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
    	scanf("%d%d", &node[i].first, &node[i].second);
    	node[i].first = - node[i].first;
    }
    sort(node+1, node+1+n);
    node[0].first = node[1].first;
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i){
    	//	dp[i][i] = min(dp[i-1][j]+(i-1-j)*dis)
    	// dp[i][j-1] = dp[i][j-1] + (i-1-j)*dis)
    	ll dis = node[i].first - node[i-1].first;
    	for(int j = 0; j < i; ++j){// yao
    		dp[i][i] = min(dp[i-1][j] + dis*(i-1-j)+node[i].second, dp[i][i]);
    		//bu yao
    		dp[i][j] = min(dp[i][j], dp[i-1][j] + dis*(i-1-j));
    	}
    }
    ll ans = dp[n][n];
    cout << ans << "\n";
    return 0;
}
