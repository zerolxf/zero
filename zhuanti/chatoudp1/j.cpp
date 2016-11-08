/*************************************************************************
    > File Name: j.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月18日 星期一 02时44分06秒
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
int dp[maxn], base[20], num[10];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	int kase = 0;
	while(true){
		int sum = 0;
		for(int i = 1; i <= 6;++i) {
			scanf("%d",&num[i]);
			sum += num[i]*i;
		}
		if(sum==0) return 0;
		printf("Collection #%d:\n", ++kase);
		int m = sum/2;
		memset(dp,0,sizeof dp);
		dp[0] = 1;
		for(int i = 1; i <= 6; ++i){
			for(int j = 1; j <= num[i]; j*=2){
				int cnt = i*j;
				for(int k = m; k >= cnt; --k){
					if(dp[k-cnt]) dp[k] = 1;
				}
				num[i] -= j;
			}
			if(num[i]){
				int cnt = num[i]*i;
				for(int k = m; k >= cnt; --k){
					if(dp[k-cnt]) dp[k] = 1;
				}
			}
		}
		if(sum%2==0&&dp[m]) {
			printf("Can be divided.\n");
		} else printf("Can't be divided.\n");
		if(kase) printf("\n");
	}
	return 0;
}
