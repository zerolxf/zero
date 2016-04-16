
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
#define pr(x) //cout << #x << " = " << x << " ";
#define prln(x) //cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
int dp[1<<16];
char s[16];
int num[16][16], a[16];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
	int t, n, kase = 0;
	cin >> t;
	prln(t);
	while(t--) {
		printf("Case %d: ", ++kase);
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d", a+i);
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				scanf("%1d",&num[i][j]);
			}
		}
		int total = 1<<n;
		for(int i = 0; i < total; ++i) dp[i] = INF;
		dp[0] = 0;
		for(int i = 0; i < total; ++i){
			for(int j = 0; j < n; ++j) {
				int ns = i^(1<<j), sum = 1;
				if(i&(1<<j) || dp[i] >= dp[ns]) continue;
				for(int k = 0; k < n; ++k){
					if((i&(1<<k)) && num[k][j] > sum) sum = num[k][j];
				}
				dp[ns] = min(dp[ns], dp[i] + (a[j] + sum - 1)/sum);
			}
		}
		printf("%d\n", dp[total-1]);
	}
	return 0;
}