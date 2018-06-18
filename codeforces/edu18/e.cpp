
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
const ll INF = ((ll)1<<61);
int a[maxn];
int n;
ll juedge(int x){
	if(x <= 0) return INF;
	ll res = 0;
	for(int i = 0; i < n; ++i){
		int p = a[i]/x, q = a[i]%x;
		if(q>p) return INF;
		p = (p-q)%(x+1);
		q = (a[i]-p*x)/(x+1);
		res += p+q;
	}
	return res;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    cin >> n;
    rep(i, n) cin >> a[i];
    sort(a,a+n);
    ll ans = INF;
    int sq = sqrt(a[0])+2;
    for(int i = 1; i <= sq; ++i){
    	ll res = juedge(a[0]/i);
    	ans = min(res, ans);
    	res = juedge(a[0]/i-1);
    	ans = min(res, ans);
    }
    for(int i = sq; i > 0; --i){
    	ll res = juedge(i);
    	ans = min(res, ans);
    }
    cout<<ans<<endl;
    return 0;
}
