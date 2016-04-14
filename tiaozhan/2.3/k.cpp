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
const long long INF = 1e18;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
ll a[maxn], b[maxn], dp[5010];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n;
    while(cin >> n) {
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
            b[i] = a[i];
        }
        sort(b+1,b+n+1);
        ll ret, ans=INF;
        for(int i = 1; i <= n; ++i) {
            ret = INF;
            for(int j = 1; j <= n; ++j) {
                ret = min(ret,dp[j]);
                dp[j] = ret + abs(b[j]-a[i]);
            }
        }
        for(int i = 1; i <= n; ++i) {
            ans = min(ans,dp[i]);
        }
        for(int i = 1; i <= n; ++i) {
            ret = INF;
            for(int j = 1; j <= n; ++j) {
                ret = min(ret,dp[n-j+1]);
                dp[j] = ret + abs(b[n-j+1]-a[i]);
            }
        }
        for(int i = 1; i <= n; ++i) {
            ans = min(ans,dp[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
