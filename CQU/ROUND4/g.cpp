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
const int maxn = 2e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
double dp[maxn], t[maxn];
int c[maxn], n;
double dfs(int x) {
    pr(x);
    double &ans = dp[x];
    if(ans > 0) return ans;
    ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(x >= c[i]) ans += t[i];
        else ans += dfs(x+c[i]);
    }
    ans /= n;
    return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int f;
    for(int i = 0; i < maxn; ++i) dp[i] = -1;
    cin >> n >> f;
    for(int i = 1; i <= n; ++i) {
        cin >> c[i];
        t[i] = (ll)((1+sqrt(5))/2*c[i]*c[i]);
    }
    double ans = dfs(f);
    printf("%.3d\n", ans);
    return 0;
}