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
const int MOD = 1e9;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
ll dp[maxn];
int main(){
#ifdef LOCAL
   // freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n;
    dp[1] = 1;dp[2] = 2;
    for(int i = 3; i < maxn; ++i) {
        if(i&1) dp[i] = dp[i-1];
        else dp[i] = (dp[i-1] + dp[i/2])%MOD;
    }
    while(cin >> n) {
        printf("%lld\n", dp[n]);
    }
    return 0;
}
