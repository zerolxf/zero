/*************************************************************************
    > File Name: c.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年03月17日 星期四 23时45分31秒
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
#include<sstream>
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
int a[20][20];
int dp[2][1<<17];
string str;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	int pre, now, n, total, x;
	char ss[500];
	while(getline(cin,str)){
		stringstream sss(str);
		n = 0;
		while(sss >> x){
			a[0][n++] = x;
		}
		for(int i = 1; i < n; ++i){
			for(int j = 0; j < n; ++j){
				scanf("%d",&a[i][j]);
			}
		}
		total = 1<<(n+1);
		now = 0; pre = 1;
		rep(i,total) dp[now][i] = 0;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j <= n; ++j){
				swap(now, pre);
				rep(s,total) dp[now][s] = 0;
				if(j==0) {
					for(int s = 0; s < total; s++){
						int ns = s&((1<<n)-1);
						ns = ns<<1;
						int ys = ns^1;
						dp[now][ns] = max(dp[now][ns], dp[pre][s]);
						if( ns%8 == 0 ){
							dp[now][ys] = max(dp[now][ys], dp[pre][s]+a[i][j]);
						}
					}
				} else {
					for(int s = 0; s < total; s++){
						int ns = s&(~(1<<j));
						int ys = s^(1<<j);
						dp[now][ns] = max(dp[now][ns], dp[pre][s]);
						int ts = s>>(j-1);
						ts = ts%16;
						if(ts == 0){
							dp[now][ys] = max(dp[now][ys], dp[pre][s] + a[i][j]);
						}
					}
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < total; ++i) ans = max(ans, dp[now][i]);
		printf("%d\n", ans);
		getchar();
		getline(cin,str);
	}
	return 0;
}
