
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
const int maxn = 1024+100;
const int INF = 0x3f3f3f3f;
int dp[maxn][maxn];
int a[123456];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
	int n, m, t;
	cin >> t;
	while(t--){
		cin >> n;
		rep(i,n){
			scanf("%d",&a[i]);
			int l = a[i]>>10, r = a[i]&(1024-1);
			dp[l][r]++;
			dp[l][1024]++;
		}
		sort(a,a+n);
		// ll ans = 0;
		// for(int i = 0; i < n; ++i){
		// 	ll tt = a[i]&a[i-1];
		// 	tt = tt*a[i]*a[i-1];
		// 	ans = max(tt,ans);
		// }
		ll ans = 0;
		rep(i,n){
			int l = a[i]>>10, r = a[i]&(1024-1);
			dp[l][r]--;dp[l][1024]--;
			ll index = 0, ma = l&0;
			for(int j = 0; j < 1024; ++j){
				if(dp[j][1024]<=0) continue;
				if((j&l)>=ma) {
					for(int k = 0; k < 1024; ++k){
						ll c = (j<<10)|k;
						ll temp = a[i]*c*(c&a[i]);
						prln(temp);
						if(temp>ans) ans = temp;
					}
				}
			}
			dp[l][r]++;dp[l][1024]++;
		}
		cout<<ans<<endl;
	}
    return 0;
}
