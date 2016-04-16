/*************************************************************************
    > File Name: a.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年03月18日 星期五 23时15分35秒
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
ll dp[1<<17][21];
int base;
char s[20];
int num[20];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	int t, k, kase = 0;
	cin >> t;
	while(t--){
		printf("Case %d: ",++kase);
		scanf("%d%d", &base, &k);
		scanf("%s", s);
		int len = strlen(s);
		ll total = 1<<len;
		for(int i = 0; i < len; ++i){
			if(s[i] <= '9' && s[i] >= '0') num[i] = s[i] - '0';
			else num[i] = s[i] - 'A' + 10;
		}
		for(int i = 0; i < total; ++i){
			for(int j = 0; j < k; ++j){
				dp[i][j] = 0;
			}
		}
		dp[0][0] = 1;
		for(int i = 0; i < total; ++i) {
			for(int j = 0; j < len; ++j){
				if((i&(1<<j))) continue;
				for(int q  = 0; q < k; ++q){
					if(!dp[i][q]) continue;
				//	pr((i^(1<<j)));pr(j);prln(i);
					dp[i^(1<<j)][(q*base+num[j])%k] += dp[i][q];
				}
			}
		}
		for(int i = 0; i < total; ++i){
			for(int j = 0; j < k; ++j){
		//		pr(i);pr(j);prln(dp[i][j]);
			}
		}
		ll ans = dp[total-1][0];
		printf("%lld\n",ans);
	}
	return 0;
}
