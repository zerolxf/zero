/*************************************************************************
	> File Name: h.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月05日 星期五 13时06分25秒
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
ll dp[3][1100][3][3];
int a[maxn];
const int MOD = 1e9+7;
int n, m;
void solve(){
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }
    memset(dp,0,sizeof dp);
    int now = 0, pre = 1;
    dp[now][0][0][0] = 1;
    for(int i = 1; i <= n; ++i){
        swap(now,pre);
        memset(dp[now], 0, sizeof dp[now]);
        for(int j = 0; j <= m; ++j){
            rep(k,3){
                rep(p,3){
                    if(j >= a[i]){
                        dp[now][j][k][p] += dp[pre][j-a[i]][k][p];
                        if(k>=1) dp[now][j][k][p] += dp[pre][j-a[i]][k-1][p];
                    }
                    if(p>=1) dp[now][j][k][p] += dp[pre][j][k][p-1];
                    dp[now][j][k][p] += dp[pre][j][k][p];
                    //if(dp[now][j][k][p] > MOD) dp[now][j][k][p] %= MOD;
                    dp[now][j][k][p] %= MOD;
                    //pr(i);pr(j);pr(k);pr(p);prln(dp[i][j][k][p]);
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= m; ++i){
         ans = (ans + dp[now][i][2][2])%MOD;
         //prln(ans);
    }
    ans = ans*4%MOD;
    printf("%lld\n", ans);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        solve();
    }
	return 0;
}
