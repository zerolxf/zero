/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月19日 星期二 21时28分13秒
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
int dp[maxn][4];
int a[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    while(cin >> n){
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            for(int j = 0; j < 4; ++j){
                dp[i][j] = INF;
            }
        }
        dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 0;
        for(int i = 1; i <= n; ++i){
            if(a[i] != 1 && a[i]){
                dp[i][2] = min(dp[i][2], min(dp[i-1][0], dp[i-1][1]));
            }else dp[i][2] = min(dp[i][2], INF);
            if(a[i] != 2 && a[i]){
                dp[i][1] = min(dp[i][1], min(dp[i-1][0], dp[i-1][2]));
            }else dp[i][1] = min(dp[i][1], INF);
            dp[i][0] = min(dp[i][0], min(min(dp[i-1][0], dp[i-1][1]), dp[i-1][2])+1);
        }
        int ans = INF;
        ans = min(dp[n][0], ans);
        ans = min(dp[n][1], ans);
        ans = min(dp[n][2], ans);
        cout << ans << "\n";
    }
	return 0;
}
