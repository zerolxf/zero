/*************************************************************************
	> File Name: k.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月02日 星期二 20时34分20秒
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
ll dp[1100][1100];
const int MOD = 1e9+7;
int a[maxn], b[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, m;
    while(cin >> n >> m){
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= m; ++i){
            scanf("%d", &b[i]);
        }
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= m; ++j){
                dp[i][j] = 0;
            }
        }
        //dp[0][0] = 1;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(a[i] == b[j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
                dp[i][j] %= MOD;
            }
        }
        dp[n][m] %= MOD;
        dp[n][m] = (dp[n][m] + MOD)%MOD;
        cout<<dp[n][m]<<"\n";
    }
	return 0;
}
