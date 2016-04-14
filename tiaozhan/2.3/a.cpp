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
const int maxn = 500;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
ll dp[maxn][maxn], a[maxn][maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n;
    while(cin >> n) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= i; ++j) {
                scanf("%lld", &dp[i][j]);
            }
        }
        for(int i = n-1; i; --i) {
            for(int j = 1; j <= i; ++j) {
                dp[i][j] += max(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        printf("%lld\n",dp[1][1]);
    }
    return 0;
}
