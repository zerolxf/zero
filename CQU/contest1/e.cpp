/*************************************************************************
	> File Name: e.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月18日 星期一 08时42分20秒
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
int dp[maxn];
int a[maxn], b[maxn], c[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, t, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &m, &n);
        for(int i = 1; i <= n; ++i){
            scanf("%d%d%d", &c[i], &a[i], &b[i]);
        }
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= n; ++i){
            int ma = m/c[i];
            for(int j = m; j >= c[i]; --j){
                dp[j] = max(dp[j], dp[j-c[i]]+a[i]+b[i]);
            }
            ma--;
            for(int k = 1; k <= ma; k<<=1){
                for(int j = m; j >= k*c[i]; --j){
                    dp[j] = max(dp[j], dp[j-k*c[i]]+k*a[i]);
                }
                ma -= k;
            }
            if(ma){
                for(int j = m; j >= ma*c[i]; --j){
                    dp[j] = max(dp[j], dp[j-ma*c[i]]+ma*a[i]);
                }
            }
        }
        cout << dp[m] << "\n";
    }
	return 0;
}
