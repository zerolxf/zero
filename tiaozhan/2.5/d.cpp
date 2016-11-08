#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
int dp[maxn][maxn], p[maxn], ran[maxn], n, a[400];
void bellford(){
	for(int i = 0; i <= n; ++i) dp[i][i] = 0;
	for(int k = 1; k <= n; ++k)
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(dp[i][k]!=INF && dp[k][j]!=INF)
			dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
		}
	}
}
void init() {
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= n ;++j)
			dp[i][j] = INF;
		
	}
}


int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int m, x, y, num;
    while(scanf("%d%d", &n, &m) != EOF && (n||m)) {
    	init();
    	for(int i = 0; i < m; ++i) {
    		scanf("%d", &num);
    		for(int j = 0; j < num; ++j) {
    			scanf("%d", &a[j]);
    		}
    		for(int j = 0; j < num; ++j) {
    			for(int l = j+1; l < num; ++l) {
    				if(dp[a[j]][a[l]]==INF) dp[a[j]][a[l]] = dp[a[l]][a[j]] = 1;
    			}
    		}
    	}
    	bellford();
    	int ans = INF, sum;
    	for(int i = 1; i <= n; ++i) {
    		sum = 0;
    		for(int j = 1; j <= n; ++j) {
    			//pr(i);pr(j);prln(dp[i][j]);
    			if(i==j||dp[i][j]==INF) continue;

    			sum +=dp[i][j];
    			//pr(sum);
    		}
    		if(sum < ans) ans = sum;
    	}
    	printf("%d\n", (ans*100/(n-1)));
    }
    return 0;
}