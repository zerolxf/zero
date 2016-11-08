/*************************************************************************
	> File Name: 我要长高.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月13日 星期五 14时33分06秒
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

int dp[2][200], n, x, c;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(scanf("%d%d", &n, &c) != EOF){
        memset(dp, 0, sizeof dp);
        int now = 1;
        scanf("%d", &x);
        for(int i = 1; i <= 100; ++i) {
            if(i < x) dp[now][i] = INF;
            else dp[now][i] = (i-x)*(i-x);
        }
        for(int i = 1; i < n; ++i){
            now = now^1;
            scanf("%d", &x);
            int qnum = INF;
            for(int j = 1; j <= 100; ++j){
                qnum = min(qnum,dp[now^1][j] - c*j);
                if(j >= x) dp[now][j] = qnum + c*j + (x - j)*(x - j);
                else dp[now][j] = INF;
            }
            qnum = INF;
            for(int j = 100; j >= 1; --j){
                qnum = min(qnum, dp[now^1][j] + c*j);
                if(j >= x) dp[now][j] = min(dp[now][j], qnum - c*j + (x-j)*(x-j));
            }
        }
        int ans = INF;
        for(int i = 1; i <= 100; ++i){
            ans = min(ans, dp[now][i]);
        }
        printf("%d\n", ans);
    }
	return 0;
}
