#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
#include<vector>

using namespace std;
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
const int MOD = 1e6;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
ll num[maxn], dp[maxn], sum[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int v, t, s, a, b, sumnum;
    while(scanf("%d%d%d%d", &t, &a, &s, &b) != EOF) {
        memset(num, 0, sizeof num);
        memset(dp, 0, sizeof dp);
        for(int i = 0; i < a; ++i) {
            scanf("%d", &v);
            num[v]++;
        }
        sum[0] = 1;
        for(int j = 0; j <= a; ++j) {
            if(j <= num[1]) dp[j] = 1;
            else dp[j] = 0;
            if(j>0) sum[j] = sum[j-1] + dp[j];
        }
        for(int i = 2; i <= t; ++i) {
            for(int j = 1; j <= a; ++j) {
                if(j <= num[i]) dp[j] = sum[j];
                else {
                    dp[j] = (sum[j] - sum[j-num[i]-1]+MOD)%MOD;
                }
               // sum[j] = sum[j-1] + dp[j];
                //pr(i);pr(j);prln(sum[j]);
            }
            for(int i = 1;i <= a; ++i) sum[i] = (sum[i-1] + dp[i])%MOD;
        }
        ll ans = 0;
        for(int i = s; i <= b; ++i){
            ans += dp[i];
            ans = ans%MOD;
           // pr(i);prln(dp[i]);
        }
        ans = ans%MOD;
        printf("%lld\n", ans);
    }
    return 0;
}

