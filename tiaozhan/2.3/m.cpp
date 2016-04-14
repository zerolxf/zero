#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
const int ADD = 1e6;
const int L = 1e6-1e5;
const int R = 1e6+1e5;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
int dp[1110000];
inline int ma(const int& x, const int& y){
    return x >= y?x:y;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n;
    while(scanf("%d", &n) !=EOF) {
        int lf, rf, lll, rrr;
        memset(dp, -0x7f,sizeof dp);
        dp[ADD] = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d",&lf,&rf);
            if(lf<=0&&rf<=0) continue;
            lll = ADD - i*1000;
            rrr = ADD + i*1000;
            if(lf >= 0) {
                for(int j = rrr; j-lf>=lll; --j) {
                    dp[j] = ma(dp[j], dp[j-lf]+rf);
                }
            } else {
                for(int j = lll; j+lf <= rrr; ++j) {
                    dp[j] = ma(dp[j], dp[j-lf]+rf);
                }
            }
        }
        int ans = 1e6;
        for(int i = ADD; i <= R; ++i) {
            if(dp[i] >= 0 && dp[i] + i > ans ){
                //pr(i);prln(dp[i]);
                ans = dp[i] + i;
            }
        }
        ans -= 1e6;
        printf("%d\n", ans);
    }
    return 0;
}