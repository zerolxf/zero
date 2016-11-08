/*************************************************************************
    > File Name: i.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月30日 星期六 15时31分08秒
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
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
int x[maxn], y[maxn], z[maxn], a[maxn], b[maxn], c[maxn];
int dp[1234567];
int getdp2	(int p, int m, int *v, int *cost, int *num){
	int ma = 0;
	ma = 50000;
	for(int i = 0; i <= ma+200; ++i) dp[i] = 0;
	dp[0] = 0;
	for(int i = 0; i < m; ++i){
		int base = 1;
		while(base <= num[i]){
			for(int j = ma+110; j >= base*cost[i]; --j){
				dp[j] = max(dp[j], dp[j-base*cost[i]] + base*v[i]);
			}
			num[i] -= base;
			base <<=1;
		}
		if(num[i] > 0){
			for(int j = ma+110; j >= num[i]*cost[i]; --j){
				dp[j] = max(dp[j], (dp[j-num[i]*cost[i]] + num[i]*v[i]));
			}
		}
	}
	int ans = INF;
	for(int i = 0; i <= ma+110; ++i){
		if(dp[i] >= p) ans = min(i,ans);
	}
	return ans;
}
int getdp(int p, int m, int *v, int *cost, int *num){
	int ma = 0;
	ma = p;
	for(int i = 0; i <= ma+200; ++i) dp[i] = INF;
	dp[0] = 0;
	for(int i = 0; i < m; ++i){
		int base = 1;
		while(base <= num[i]){
			for(int j = ma+110; j >= base*v[i]; --j){
				dp[j] = min(dp[j], dp[j-base*v[i]] + base*cost[i]);
			}
			num[i] -= base;
			base <<=1;
		}
		if(num[i] > 0){
			for(int j = ma+110; j >= num[i]*v[i]; --j){
				dp[j] = min(dp[j], (dp[j-num[i]*v[i]] + num[i]*cost[i]));
			}
		}
	}
	int ans = INF;
	for(int i = ma; i <= ma+110; ++i){
		ans = min(ans,dp[i]);
	}
	return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
#endif
	int n, m, p;
	int kase = 0;
	scanf("%d", &kase);
	while(kase--){
		scanf("%d%d%d", &n, &m, &p);
		for(int i = 0; i < n; ++i){
			scanf("%d%d%d", &x[i], &y[i], &z[i]);
		}
		for(int i = 0; i < m; ++i){
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
		}
		bool ok = true;
		p = getdp(p, n, x, y, z);
		if(p >= INF) ok = false;
		if(ok) p = getdp2(p, m, a, b, c);
		if(p >= INF) ok = false;
		if(ok) printf("%d\n",p);
		else printf("TAT\n");
	}
	return 0;
}
