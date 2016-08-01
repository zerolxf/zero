/*************************************************************************
	> File Name: d.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月01日 星期一 19时38分54秒
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
double dp[1234][1234][2];

int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, m;
    while(cin >> n >> m){
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= n; ++i){
            dp[i][0][0] = dp[i][0][1] = 1;
        }
        for(int i = 0; i <= m; ++i){
            dp[0][i][0] = 0;
            dp[0][i][1] = 1;
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                dp[i][j][0] = (i*1.0)/(i+j) + (j*1.0)/(i+j)*(1.0-dp[i][j-1][1]);
                if(j>=2)dp[i][j][1] = (i*1.0)/(i+j) + (j*1.0)/(i+j)*(  (j-1)*1.0/(i+j-1)*(1-dp[i][j-2][0])  + (i*1.0)/(i+j-1)*(1-dp[i-1][j-1][0]) );
                else {
                    dp[i][j][1] = (i*1.0)/(i+j) + (j*1.0)/(i+j)*( (i*1.0)/(i+j-1)*(1-dp[i-1][j-1][0]) );

                }
            }
        }
        printf("%.9f\n", dp[n][m][0]);

    }

	return 0;
}
