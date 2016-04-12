/*************************************************************************
    > File Name: b.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年03月19日 星期六 00时08分27秒
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
int dp[1<<15];
char s[12];
int num[12][12], a[12];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	int t, n, kase = 0;
	cin >> t;
	prln(t);
	while(t--) {
		printf("Case %d: ", ++kase);
		scanf("%d", &n);
		prln(n);
		for(int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		for(int i = 0; i < n; ++i){
			scanf("%s", s);
			prln(s);
			for(int j = 0; j < n; ++j){
				num[i][j] = s[j] - '0';
			}
		}
		int total = 1<<n, ss;
		prln(total);
		for(int i = 0; i < total; ++i) dp[i] = INF;
		dp[0] = 0;
		for(int i = 0; i < total; ++i){
			prln(i);
			for(int j = 0; j < n; ++j) {
				if(i&(1<<j)) continue;
				if(dp[i] == INF) continue;
				pr(i);pr((1<<j));prln(j); prln((i&(1<<j)));
				ss = 0;
				pr(ss);
				ss = i^(1<<j);int  sum = 1;
				pr(ss);
			//	if(dp[i] >= dp[ss]) continue;
				//pns] = min(dp[ns], dp[i] + a[j]);
				for(int k = 0; k < n; ++k){
					if(!(i&(1<<k))) continue;
					if(num[k][j] > sum) sum = num[k][i];
				}
				pr(ss);pr(dp[i]);pr(a[j]);pr(sum);
				dp[ss] = min(dp[ss], dp[i] + (a[j] + sum - 1)/sum);
				prln(dp[ss]);
			}
		}
		prln(n);
		printf("%d\n", dp[total-1]);
	}
	return 0;
}
