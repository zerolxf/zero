#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
#include<vector>

using namespace std;
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
int dp[maxn][35][2], v;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int t, w;
    scanf("%d%d", &t, &w);
    for(int i = 0; i <= w; ++i) {
        dp[0][i][1] = -INF;
        dp[0][i][0] = 0;
    }
    for(int i = 1; i <= t; ++i) {
        scanf("%d", &v);
        dp[i][0][v-1] = dp[i-1][0][v-1]+1;
        dp[i][0][2-v] = dp[i-1][0][2-v];
        for(int j = 1; j <= w; ++j) {
            dp[i][j][v-1] = max(dp[i-1][j-1][2-v],dp[i-1][j][v-1])+1;
            dp[i][j][2-v] = max(dp[i-1][j][2-v],dp[i-1][j-1][v-1]);
        }
    }
    int ans = 0;
    for(int i = 0; i <= w; ++i) {
        ans = max(ans, dp[t][i][0]);
        ans = max(ans, dp[t][i][1]);
    }
    printf("%d\n", ans);
    return 0;
}
