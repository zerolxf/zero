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
#pragma comment(linker, "/STACK:102400000,102400000")
const int maxn = 4e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
ll l[maxn],r[maxn];
int inline ma(int x, int y) {
    if(x >= y) return x;
    return y;
}

map<ll,int> dp;
ll cnt=0;
int dfs(ll x) {
    if(dp.count(x)) return dp[x];
    cnt++;//printf("%d\n",cnt);
    ll i = x/100000, j = x%100000;
    if(i==0||j==0) return 0;
   // pr(i);//prln(j);
    dp[x] = 0;
    int& ans = dp[x];

    if(r[i] == j) ans = ma(dfs((i-1)*100000+j-1)+1,ans);
    else ans = ma(ans, dfs((i-1)*100000+j-1));
    if(r[i] < j) ans = ma(dfs((i-1)*100000+r[i]-1)+1,ans);
    if(l[j] < i) ans = ma(dfs((l[j]-1)*100000+j-1)+1,ans);
    return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    ll n,x, t;
    scanf("%lld",&t);
    while(t--) {
        dp.clear();
        scanf("%lld", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", &x);
            r[i] = x;
            l[x] = i;
        }
        int ans = dfs(n*100000+n);
        printf("%d\n",ans);
    }
    return 0;
}

