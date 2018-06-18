
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
#define pr(x)// cout << #x << " = " << x << " ";
#define prln(x) //cout << #x << " = " << x <<  endl;
const int MOD = 1e9+7;
const int maxn = 1e5+100;
const ll INF = 1e18;
ll a[3][maxn], b[maxn], c[maxn];
ll getans(int a0, int a1, int a2){
	pr(a0);pr(a1);prln(a2);
	int s0 = a[a0][0], s1 = a[a1][0], s2 = a[a2][0];
	int p0 = 1, p1 = 1,p2 = 1;
	ll ans = INF;
	while(p0 <= s0){
		while(p1 <= s1 && a[a1][p1] < a[a0][p0]) p1++;
		if(p1>s1) break;
		while(p2 <= s2 && a[a2][p2] < a[a1][p1]) {
			// pr(a[a2][p2]);prln(a[a1][p2]);
			p2++;
		}
		if(p2 > s2) break;
		pr(p0);pr(p1);prln(p2);
		if(a[a0][p0]<=a[a1][p2]&&a[a1][p1] <= a[a2][p2]){
			ll res = 0;
			res += abs(a[a0][p0] - a[a1][p1]);
			res += abs(a[a0][p0] - a[a2][p2]);
			res += abs(a[a2][p2] - a[a1][p1]);
			prln(res);
			ans = min(ans, res);
		}
		p0++;
	}
	return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    int n, m, l;
    cin >> n >> m >> l;
    a[0][0] = n, a[1][0] = m, a[2][0] = l;
    rep(i,n) scanf("%lld", &a[0][i+1]);
    rep(i,m) scanf("%lld", &a[1][i+1]);
    rep(i,l) scanf("%lld", &a[2][i+1]);
    sort(a[0]+1,a[0]+n+1);
    sort(a[1]+1,a[1]+m+1);
    sort(a[2]+1,a[2]+l+1);
    ll ans = INF;
    for(int i = 0; i < 3; ++i){
    	for(int j = 0; j < 3; ++j){
    		for(int k = 0; k < 3; ++k){
    			if((i^j)&&(i^k)&&(j^k)){
    				ans = min(ans, getans(i,j,k));
    			}
    		}
    	}
    }
    cout << ans << "\n";
    return 0;
}
