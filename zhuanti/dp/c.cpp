/*************************************************************************
    > File Name: c.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月16日 星期六 21时17分15秒
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
ll dp[2][maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	int n, m;
	while(scanf("%d%d",&n, &m) != EOF && (n+m) != 0) {
		if(n*m%2==1){
			printf("0\n");
			continue;
		}
		if(n < m) swap(n,m);
		int M = 1 << m;
		int now = 0;
		memset(dp,0,sizeof dp);
		dp[now][M-1] = 1;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				now = now^1;
				memset(dp[now],0,sizeof dp[now]);
				for(int k = 0; k < M; ++k){
					dp[now][k^(1<<j)] += dp[1-now][k];
					if(j && !(k&(1<<(j-1))) && k&(1<<j)) {
						dp[now][k^(1<<(j-1))] += dp[1-now][k];
					}
				}
			}
		}
		ll ans = dp[now][M-1];
		printf("%lld\n",ans);
	}
	return 0;
}
