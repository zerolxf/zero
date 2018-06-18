
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
#define pr(x) //cout << #x << " = " << x << " ";
#define prln(x)// cout << #x << " = " << x <<  endl;
const int MOD = 1e9+7;
const int INF = 1e9;
const int maxn = 1e5+100;
int dp[2][2][1100];
int v[maxn], bit[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    int t;
    cin >> t;
    while(t--){
    	int n, m, s;
    	cin >> n >> m;
    	for(int i = 1; i <= n; ++i){
    		cin >> v[i] >> s;
    		int bsum = 0, x;
    		for(int j = 0; j < s; ++j){
    			cin >> x;
    			bsum |= (1<<(x-1));
    		}
    		bit[i] = bsum;
    	}
    	memset(dp, -1, sizeof dp);
    	int state = (1<<m);
    	for(int i = 0; i < 2; ++i){
    		for(int j = 0; j < 2; ++j){
    			for(int k = 0; k <= state; ++k){
    				dp[i][j][k] = -INF;
    			}
    		}
    	}
    	int now = 0, pre = 1;
    	dp[now][0][0] = 0;
    	for(int i = 1; i <= n; ++i){
    		prln(bit[i]);
    		swap(now, pre);
    		// memset(dp[now], -1, sizeof dp[now]);
    		for(int j = 0; j < 2; ++j){
    			for(int k = 0; k <= state; ++k){
    				dp[now][j][k] = -INF;
    			}
    		}
    		for(int j = 0; j < state; ++j){
    			dp[now][0][j] = max(dp[pre][1][j], dp[pre][0][j]);
    			dp[now][1][j^bit[i]] = max(dp[now][1][j^bit[i]], dp[now][0][j]+v[i]);
    			// pr(i);pr(j);pr((int)(j^bit[i]));pr(dp[now][0][j]);prln(dp[now][1][j^bit[i]]);
    		}
    	}
    	prln(state-1);
    	int ans = max(dp[now][0][state-1], dp[now][1][state-1]);
    	cout << ans << endl;
    }
    return 0;
}
