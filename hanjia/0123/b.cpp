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
const int maxn = 1e7+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
ll dp[maxn], dp1[maxn];
const int MOD = 1e9+7;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    dp[1] = 0;
    dp1[1] = 1;
    int n;
    cin >> n;
    for(int i = 2; i <= n; ++i){
    	dp1[i] = (2*dp1[i-1]+dp[i-1])%MOD;;
    	dp[i] = (3*dp1[i-1])%MOD;
    }
    cout << dp[n] << "\n";
    return 0;
}