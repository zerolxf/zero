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
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
#define rep(i,n) for(int i = 0; i < n; ++i)
ll c[1100][1100];
const int MOD = 20090818;
int n, m;
void getc() {
    for(int i = 1; i <= 1000; ++i){
        c[i][0] = 1;
        c[i][i] = 1;
    }
    for(int i = 2; i <= 1000; ++i) {
        for(int j = 1; j < i; ++j){
            c[i][j] = (c[i-1][j] + c[i-1][j-1])%MOD;
            //pr(i);pr(j);prln(c[i][j]);
        }
    }
}
ll dp[maxn];
int main(){
#ifdef LOCAL
  // freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    getc();
    dp[1] = 0;dp[2] = 1;dp[0] = 1;
    for(ll i = 3; i <= 1000; ++i){
        dp[i] = ((i-1)*(dp[i-1] + dp[i-2]))%MOD;
       // pr(i);prln(dp[i]);
    }
    while(scanf("%d%d",&n,&m) != EOF){
        ll ans = 0;
        for(int i = 0;i <= m; ++i) {
            ans  =(ans + c[n][i]*dp[n-i]%MOD)%MOD;
          //  pr(i);prln(c[n][i]);prln(dp[n-i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
