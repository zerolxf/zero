/*************************************************************************
	> File Name: g.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月22日 星期五 12时38分39秒
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
ll c[110][110];
ll base[110];
const int MOD = 1e9+7;
void calc(){
    c[1][0] = 1;c[1][1] = 1;
    for(int i = 2; i <= 100; ++i){
        c[i][0] = 1;
        for(int j = 1; j <= i; ++j){
            c[i][j] = (c[i-1][j-1]+c[i-1][j])%MOD;
            //pr(i);pr(j);prln(c[i][j]);
        }
    }
    base[0] = 1;
    for(int i = 1; i <= 100; ++i){
        base[i] = (base[i-1]<<1)%MOD;
    }
}
ll dp[11][11][110];
void slove(){
    memset(dp, 0, sizeof dp);
    c[0][0] = 1;
    dp[1][0][0] = dp[0][1][0] = 1;
    for(int i = 1; i <= 10; ++i){
        for(int j = 1; j <= 10; ++j){
            if(i==1||j==1){
                dp[i][j][i+j-1] = 1;
                continue;
            }
            for(int k = 1; k <= i*j; ++k){
                dp[i][j][k] = c[i*j][k];
                for(int ii = 1; ii <= i; ++ii){
                    for(int jj = 0; jj <= j; ++jj){
                        if(i+j==ii+jj) continue;
                        for(int kk = 0; kk <= k; ++kk){
                            ll ret = c[i-1][ii-1]*c[j][jj]%MOD;
                            ret = ret*dp[ii][jj][kk]%MOD;
                            ret = ret*c[(i-ii)*(j-jj)][k-kk]%MOD;
                            dp[i][j][k] = (dp[i][j][k]-ret+MOD)%MOD;
                        }
                    }

                }
            }
        }
    }
}
ll pow(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y&1) ans = ans*x%MOD;
        x = x*x%MOD;
        y >>= 1;
    }
    return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, m;
    calc();
   slove();
    while(scanf("%d%d", &n, &m) != EOF){
        ll ans = 0;
        for(int i = 0; i <= n*m; ++i){
            //prln(i);
            ans = (ans+base[i]*dp[n][m][i])%MOD;
        }
        printf("%lld\n",ans);
    }
	return 0;
}
