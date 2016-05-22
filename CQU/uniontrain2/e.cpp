/*************************************************************************
	> File Name: e.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月14日 星期六 03时07分49秒
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
int dp[2][250010];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
//	freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t, n, h;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < 250010; ++i) dp[0][i] = dp[1][i] = -INF;
        int now = 1;
        dp[now][0] = 0;
        for(int i = 0; i < n; ++i){
            scanf("%d", &h);
            now = now^1;
            for(int j = 0; j < 250010; ++j){
                dp[now][j] = max(dp[now][j], dp[1-now][j]);
                if(dp[1-now][j] < j) continue;
                if(h>=250010) continue;
                if(j+h<250010) dp[now][j+h] = max(dp[now][j+h],dp[1-now][j]+h);
                dp[now][abs(h-j)] = max(dp[now][abs(h-j)], max(dp[1-now][j]-j+h, dp[1-now][j]));
//                pr(abs(h-j));pr(h);pr(j);prln(dp[now][abs(h-j)]);
            }
        }
        int ans = dp[now][0];
        if(ans > 0) printf("%d\n",ans);
        else printf("GG\n");
    }
	return 0;
}
