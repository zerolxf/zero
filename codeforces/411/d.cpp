
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
#define pr(x) //cout << #x << " = " << x << " ";
#define prln(x) //cout << #x << " = " << x <<  endl;
const int MOD = 1e9+7;
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
// ll dfs(int x, int y){
// 	if(x==0||y==0) return 0;
// 	if(y<=2 && dp1[x][y] != -1) return dp1[x][y];
// 	if(x<=1 && dp2[x][y]!=-1) return dp2[x][y];
// 	ll ans = dfs(x-1, 2) + dfs(x, y-1) + 1;
// 	ans %= MOD;
// 	if(y<=2) dp1[x][y] = ans;
// 	if(x<=1) dp2[x][y] = ans;
// 	// pr(x);pr(y);
// 	// prln(ans);
// 	return ans;
// }
ll base[maxn];
ll getans(ll x, ll y){
	ll ans = base[x]-1;
	pr(x);pr(y);prln(ans);
	ans = (ans+MOD)%MOD;
	ans = (ans*y)%MOD;
	ans = ans%MOD+MOD;
	ans%=MOD;
	return ans;
}
char s[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    memset(dp1, -1, sizeof dp1);
    memset(dp2, -1, sizeof dp2);
    base[0] = 1;
    for(int i = 1; i < maxn; ++i){
    	base[i] = base[i-1]*2%MOD;
    }
    ll ans = 0;
    vector<int> vt;
    scanf("%s", s);
    int len = strlen(s);
    int a = 0, b = 0;
    for(int i = 0; i < len; ++i){
    	if(s[i]=='a') {
    		if(b) vt.push_back(b);
    		b = 0, a++;
    	}
    	if(s[i]=='b') {
    		if(a) vt.push_back(a);
    		a = 0, b--;
    	}
    }
    if(a) vt.push_back(a);
    if(b) vt.push_back(b);
    int l = 0, r = vt.size();
    if(vt[0] < 0) l++;
    if(vt[r-1] > 0) r--;
    pr(l);prln(r);
    pr(vt[0]);prln(vt[r-1]);
    dp1[1][1] = dp2[1][1] = 1;
    ll sum = 0;
    for(int i = l; i < r-1; i+=2){
    	pr(vt[i]);prln(-vt[i+1]);
    	sum += vt[i];
    	ans+=getans(sum, -vt[i+1]);
    	ans%=MOD;
    }
    cout<<ans<<endl;
    // for(int i = 1; i <= 10; ++i){
    // 	for(int j = 1; j <= 10; ++j){
    // 		pr(i);pr(j);
    // 		ll ans = dfs(i, j);
    // 		prln(ans);
    // 	}
    // }
    return 0;
}
