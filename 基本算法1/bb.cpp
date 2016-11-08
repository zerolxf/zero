
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
const int MOD = 1e9;
long long dp[maxn], a[100];
void init() {
    ll base = 1;
    for(int i = 0; i < 62; ++i) {
        a[i] = base;
        base = base*2;
    }
}
long long dfs(long long x) {
    long long& ans = dp[x];
    if(ans != -1) return ans;
    int pos = upper_bound(a,a+62,x) - a -1;
    ans = dfs(x-a[pos]);
   // prln(x);pr(pos);pr(a[pos]);pr(ans);
    if(pos >= 1 && x >= a[pos-1]*3) ans += dfs(x-a[pos-1]*3);
   // pr(ans);
    ll half = dfs(x/2);
    ans = (ans + half*(half+1)/2)%MOD;
   // prln(ans);
    return ans;
}
int main(){
#ifdef LOCAL
  //  freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    ll n;
    init();
    memset(dp, -1, sizeof dp);
    dp[0] = 1; dp[1] = 1;dp[3]=2;dp[2]=2;
    while(cin >> n){
        ll ans = dfs(n);
        printf("%lld\n", ans);
    }
    return 0;
}
