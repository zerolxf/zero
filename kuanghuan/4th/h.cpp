/*************************************************************************
    > File Name: h.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月07日 星期日 12时42分20秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
ll v[2][1100];
char s[1100][1100];
ll dp[2][1100][1100];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, m, l, r;
    while(scanf("%d%d%d%d", &n, &m, &l, &r) != EOF){
        for(int i = 1; i <= n; ++i){
            scanf("%s", s[i]+1);
        }
        memset(v, 0, sizeof v);
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(s[i][j] == '.') v[0][j]++;
                else v[1][j]++;
            }
        }
        for(int i = 0; i < 2; ++i){
            for(int j = 0; j <= 1000; ++j){
                for(int k = 0; k <= 1000; ++k){
                    dp[i][j][k] = 1e10;
                }
            }
        }
        dp[0][0][0] = dp[1][0][0] = 0;
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= i; ++j){
                dp[0][i][j] = min(dp[0][i][j], dp[0][i-1][j-1] + v[0][i]);
                dp[1][i][j] = min(dp[1][i][j], dp[1][i-1][j-1] + v[1][i]);
            }
            for(int j = l; j <= r; ++j){
                dp[0][i][0] = min(dp[0][i][0], dp[1][i][j]);
                dp[1][i][0] = min(dp[1][i][0], dp[0][i][j]);
            }
        }
        ll ans = min(dp[0][m][0], dp[1][m][0]);
        cout << ans << "\n";
    }
	return 0;
}
