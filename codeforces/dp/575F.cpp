
/*
* @author:  liangxianfeng
* @mail: liangxianfeng96@qq.com
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define repp(i,n,x) for(int i =x; i < n+x; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl;
const int MOD = 1e9+7;
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
ll dp[2][maxn];
ll a[maxn], b[maxn], c[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    ll n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; ++i){
    	scanf("%lld%lld", &a[i], &b[i]);
    	c[i*2] = a[i];
    	c[i*2+1] = b[i];
    }
    c[2*n] = x;
    sort(c, c+2*n+1);
    int m = unique(c, c+2*n+1) - c;
    int p = lower_bound(c, c+m, x) - c + 1;
    int now = 0, pre = 1;
    memset(dp[now], 0x3f, sizeof (dp[now]));
    dp[now][p] = 0;
    for(int i = 1; i <= n; ++i){
    	swap(now, pre);
	    memset(dp[now], 0x3f, sizeof (dp[now]));
	    for(int j = 1; j <= m; ++j){
	    	dp[now][j] = 
	    }
    }
    return 0;
}
