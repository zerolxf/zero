/*************************************************************************
	> File Name: a.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月02日 星期二 17时37分38秒
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
double dp[2200][20];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, m;
    n = 2010, m = 15;
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= 15; ++j){
                dp[i][j] = 1e8;
                //pr(i);pr(j);prln(dp[i][j]);
            }
        }
        for(int i = 3; i <= n; ++i){
            //dp[i][1] = (((i+1)*i+2*i-2)*1.0/(i*2));
            dp[i][1] = (i-1)*(i+2)*1.0/(2*i);
        }
        //dp[2][1] = 1;
        //dp[2][2] = 1;
        for(int i = 0; i <= 15; ++i){
            dp[1][i] = 0;
            dp[0][i] = 0;
        }
        //dp[2][2] = 1;
        //prln(dp[2][1]);
        for(int i = 2; i <= n+1; ++i){
            for(int j = 1; j <= m; ++j){
                for(int k = 2; k <= i; ++k){
                    //pr(i);pr(j);prln(k);
                    //pr(k-1);pr(j-1);
                    //prln(dp[k-1][j-1]);
                    //pr(i-k+1);pr(j);
                    //prln(dp[i-k+1][j]);
                    //prln(((dp[k-1][j-1]*(k-1) + (i-k+1)*dp[i-k+1][j])*1.0/i)+1);
                    //prln(dp[i][j]);
                    dp[i][j] = min(dp[i][j], (dp[k-1][j-1]*(k-1) + (i-k+1)*dp[i-k+1][j])*1.0/i+1);
                    //prln(dp[i][j]);
                }
            }
        }
    for(int i = 1; i <= 10; ++i){
        for(int j = 1; j <= 10; ++j){
            //pr(i);prln(j);prln(dp[i][j]);
        }
    }
    while(cin >> n >> m){
        m = min(15,m);
        m = min(m,n);
        double ans = dp[n+1][m]*1.0;
        printf("%.6f\n",ans);

    }
	return 0;
}
