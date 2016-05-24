/*************************************************************************
	> File Name: d.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月23日 星期一 15时24分52秒
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
const int maxn = 1<<14;
const int INF = 0x3f3f3f3f;
int dp[2][maxn];
int a[maxn], b[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, kase = 0, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%d%d", &a[i], &b[i]);
        }
        int now = 0, pre = 1;
        memset(dp[now], 0x3f, sizeof dp[now]);
        dp[now][6000] = 0;
        for(int i = 1; i <= n; ++i){
            int aa = a[i], bb = b[i];
            swap(now,pre);
            memset(dp[now],0x3f,sizeof dp[now]);
            for(int j = 0;j + aa <= 12000; ++j){
                //如果a比b多j-6000
                if(j>=6000) dp[now][aa+6000] = min(dp[now][aa+6000], dp[pre][j]+aa);
                //如果b比a多6000-j
                else dp[now][j+aa] = min(dp[now][j+aa], dp[pre][j]+max(aa+j-6000,0));
                if(dp[pre][j] < INF){
                   //pr(i); pr(j);pr(j+aa-3000);pr(dp[pre][j]);prln(dp[now][j+aa]);
                }
            }
            for(int j = 12000; j-bb>=0; --j){
                //如果a比b多j-6000
                if(j>=6000) dp[now][j-bb] = min(dp[now][j-bb], dp[pre][j]+max(bb-j+6000,0));
                //如果b比a多6000-j
                else dp[now][6000-bb] = min(dp[now][6000-bb], dp[pre][j]+bb);
                if(dp[pre][j] < INF){
                   //pr(i); pr(j);pr(j-bb-3000);pr(dp[pre][j]);prln(dp[now][j-bb]);
                }
            }
        }
        int ans = INF;
        for(int i = 0; i <= 12000; ++i){
            ans = min(dp[now][i],ans);
        }
        printf("%d\n",ans);
    }
	return 0;
}
