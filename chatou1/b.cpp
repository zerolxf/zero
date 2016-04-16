/*************************************************************************
    > File Name: b.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年03月17日 星期四 23时05分23秒
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
int a[30][30];
ll dp[2][1<<20];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	int n, m, total, now, pre;
	while(cin >> n){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				scanf("%d",&a[i][j]);
			}
		}
		now = 0, pre = 1;
		total = 1<<n;
		memset(dp[0], 0, sizeof dp[0]);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				swap(now,pre);
				memset(dp[now], 0, sizeof dp[now]);
				for(int s = 0; s < total; s++){
					int no = s&(~(1<<j));
					dp[now][no] = max(dp[now][no], dp[pre][s]);
					if(j && !(s&(1<<j)) && !(s&(1<<(j-1)))){
						dp[now][s ^ (1<<j)] = max(dp[now][s ^ (1<<j)], dp[pre][s] + a[i][j]);
					} 
					if(!j && !(s&(1<<j)) ){
						dp[now][s ^ (1<<j)] = max(dp[now][s ^ (1<<j)], dp[pre][s] + a[i][j]);
					} 
				}
			}
		}
		ll ans = 0;
		for(int i = 0; i < total; ++i) ans = max(ans, dp[now][i]);
		printf("%lld\n",ans);
	}
	return 0;
}
