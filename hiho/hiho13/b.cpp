
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
const int maxn = 1e5+100;
const int INF = 0x3f3f3f3f;
ll sum[330][330];
ll a[330][330], col[330][330], b[330];
ll n, m, k;
int getans(int r1, int r2){
	memset(b, 0, sizeof 330);
	for(int i = 1; i <= m; ++i){
		b[i] = col[r2][i] - col[r1-1][i];
		// pr(i);prln(b[i]);
	}
	int row = r2-r1+1;
	int l1 = 1, l2 = 0;
	ll ret = 0;
	int ans = 0;
	while(l2 < m){
		while(l2 < m &&ret + b[l2+1] <= k){
			ret += b[l2+1];
			l2++;
			ans = max(ans, l2-l1+1);
			// prln(ans);
		}
		ret -= b[l1];
		l1++;
		// pr(l1);prln(l2);
	}
	ans *= (r2-r1+1);
	return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
	memset(sum, 0, sizeof sum);
	memset(col, 0, sizeof col);
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			scanf("%lld", &a[i][j]);
			col[i][j] = col[i-1][j] + a[i][j];
		}
	}    
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			sum[i][j] = a[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}
	int ans = 0;
	// int ret = getans(1, 2);
	// ans = max(ans, ret);
	for(int i = 1; i <= n; ++i){
		for(int j = i; j <= n; ++j){
			int ret = getans(i, j);
			// prln(ret);
			ans = max(ans, ret);
		}
	}
	cout << ans << endl;
    return 0;
}
