/*************************************************************************
    > File Name: a.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年03月17日 星期四 22时34分25秒
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
ll dp[2][1<<12];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	int n, m, now, pre, total;
	while(cin >> n >> m && n + m != 0){
		if(n*m%2){
			cout << "0\n";
			continue;
		}
		if(n < m) swap(n,m);
		total = 1<<m;
		memset(dp[0],0, sizeof dp[0]);
		dp[0][0] = 1;
		now = 0; pre = 1;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				swap(now,pre);
				memset(dp[now],0, sizeof dp[now]);
				for(int s = 0; s < total; s++){
					dp[now][s^(1<<j)] += dp[pre][s];
					if(j && s&(1<<(j-1)) && !(s&(1<<j))){
						dp[now][s^(1<<(j-1))] += dp[pre][s];
					}
				}
			}
		}
		printf("%lld\n", dp[now][0]);
	}
	return 0;
}
