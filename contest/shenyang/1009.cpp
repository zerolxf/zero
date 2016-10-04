/*************************************************************************
    > File Name: 1009.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月18日 星期日 12时40分38秒
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
const int N = 400;
const int INF = 0x3f3f3f3f;
ll dp[N][N][2];
ll v[N], key[N];
ll gcd(ll x, ll y){
    if(y==0) return x;
    return gcd(y, x%y);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%lld",&key[i]);
        }
        for(int i = 1; i <= n; ++i){
            scanf("%lld", &v[i]);
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                dp[i][j][0] = -1;
                dp[i][j][1] = 0;
            }
        }

        for(int i = 1; i <= n; ++i){
            dp[i+1][i][0] = 0;
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; i+j-1<=n; ++j){
                for(int k = j+1; k < i+j-1; k +=2){
                    if(i%2==0){
                        if(dp[j][k][0] >= 0&&dp[k+1][i+j-1][0]>=0)   dp[j][i+j-1][0] = max(dp[j][k][0]+dp[k+1][i+j-1][0], dp[j][i+j-1][0]);
                    }

                }
                if(i%2==0){
                    if(gcd(key[j], key[i+j-1]) != 1) {
                        if(dp[j+1][i+j-2][0] >= 0)   dp[j][i+j-1][0] = max(dp[j+1][i+j-2][0]+v[j]+v[i+j-1], dp[j][i+j-1][0]);
                    }
                }
                dp[j][i+j-1][1] = max(dp[j][i+j-1][1], dp[j][i+j-1][0]);
                for(int k = j; k < i+j-1; ++k){
                    dp[j][i+j-1][1] = max(dp[j][i+j-1][1], dp[j][k][1]+dp[k+1][i+j-1][1]);
                }
            }
        }
        cout << dp[1][n][1] << "\n";
    }


	return 0;
}
