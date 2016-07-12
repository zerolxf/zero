
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
const int maxn = 1e5+100;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
int dp[2][12345];
struct node{
    int s,t;
    bool operator < (const node& rhs)const{
        return s*rhs.t > t*rhs.s;
    }
}a[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif

    int n, T;
    while(cin >> n >> T) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", &a[i].t, &a[i].s);
        }
        sort(a+1, a+n+1);
        memset(dp,0,sizeof dp);
       // for(int i = 0;i <= T; ++i) dp[0][i] = 0;
       // for(int i = 0; i <= n; ++i) dp[i][0] = 0;
        int now = 0;
        for(int i = 1; i <= n; ++i) {
            now = 1 - now;
            for(int j = T; j >= 0; --j) {
                if(j >= a[i].t)
                dp[now][j] = max(dp[1-now][j-a[i].t]+(T-j+a[i].t)*a[i].s, dp[1-now][j]);
                else dp[now][j] =dp[1-now][j];
            }
        }
        int ans = 0;
        for(int i = 0; i <= T; ++i) {
            ans = max(ans, dp[now][i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
