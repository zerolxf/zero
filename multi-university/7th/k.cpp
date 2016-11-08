/*************************************************************************
    > File Name: k.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月10日 星期三 17时15分22秒
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
const int MOD = 1e9+7;
const int N = 1024;
ll ret(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y&1) ans = ans*x%MOD;
        x = x*x%MOD;
        y >>= 1;
    }
    return ans;
}
ll fac[N];
void init(){
    fac[0] = 1;
    ll rev = ret(2, MOD-2);
    for(int i = 1; i < 1024; ++i){
        fac[i] = fac[i-1]*rev%MOD;
    }
}
ll dp[N][N];
int a[N];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    init();
    int t, n;
    scanf("%d", &t);
    int kase = 0;
    while(t--){
        scanf("%d", &n);
        //prln(n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        if(n==1){
            printf("Case #%d: 1\n", ++kase);
            continue;
        }

        memset(dp,0,sizeof dp);
        dp[1][1] = 1;
        //pr(fac[1]);
        for(int i = 2; i <= n-1; ++i){
            if(!a[i]){
                for(int j = i; j >= 1; --j){
                    
                    dp[i][j] = (dp[i-1][j] + dp[i][j+1])*fac[1]%MOD;
                    //pr(i);pr(j);prln(dp[i][j]);
                    if(j==1){
                        for(int k = 1; k < i; ++k)
                        dp[i][j] = (dp[i][j] + dp[i-1][k]*fac[k])%MOD;
                    }
                    //pr(i);pr(j);prln(dp[i][j]);
                }
            }else{
                for(int j = 1; j <= i; ++j){
                    dp[i][j] = dp[i-1][j-1];
                    //pr(i);pr(j);prln(dp[i][j]);
                }
            }
            
        }
        ll ans = 0;
        for(int i = 1; i < n; ++i){
            //pr(i);prln(fac[i]);
            ans = (ans + dp[n-1][i]*fac[i])%MOD;
        }
        printf("Case #%d: %lld\n", ++kase, ans);
    }


	return 0;
}
