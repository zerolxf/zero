/*************************************************************************
    > File Name: d.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月16日 星期六 22时54分20秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 1<<12;
const int INF = 0x3f3f3f3f;
ll dp[2][25][maxn];
const ll MOD = 1e9+7;
char mp[120][12];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	int n, m, c, d;
	while(cin >> n >> m >> c >> d){
		for(int i = 0; i < n; ++i){
			scanf("%s", mp[i]);
		}
		int now = 0;
		int M = 1 << m;
		for(int i = 0; i <= 21; ++i){
			memset(dp[now][i], 0, sizeof dp[now][i]); 
		}
		dp[now][0][M-1] = 1;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				now = now^1;
				rep(k,21) memset(dp[now][k], 0, sizeof dp[now][k]);
				for(int u = 0; u <= d; ++u){
					for(int k = 0; k < M; ++k){
						if(mp[i][j] == '1'){
							dp[now][u][k^(1<<j)] = (dp[now][u][k^(1<<j)] + dp[1-now][u][k])%MOD;
							if(j && (k&(1<<j)) && !(k&(1<<(j-1)))){
								dp[now][u][k^(1<<(j-1))] =  (dp[now][u][k^(1<<(j-1))] + dp[1-now][u][k])%MOD;
							}
							if(u && (k&(1<<j))) dp[now][u][k] = (dp[now][u][k] + dp[1-now][u-1][k])%MOD; 
						} else {
							if(k&(1<<j)) dp[now][u][k] = (dp[now][u][k] + dp[1-now][u][k])%MOD;
						}

					}
				}
			}
		}
		ll ans = 0;
		for(int i = c; i <= d; ++i){
			ans += dp[now][i][M-1];
		}
		ans%=MOD;
		printf("%lld\n",ans);
	}
	return 0;
}
