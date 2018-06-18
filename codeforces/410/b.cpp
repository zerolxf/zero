
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
int n;
string str[maxn];
bool geta(string a , string b, int aa, int bb, int len){
	bool ok = true;
	for(int i = 0; i < len; ++i){
		if(a[i+aa]!=b[i+bb]) ok = false;
	}
	return ok;
}
ll getans(int x, int len){
	ll a = 0;
	for(int i = 0; i < n; ++i){
		ll ans = INF;
		for(ll j = 0; j < len; ++j){
			if(geta(str[0], str[i], x, j, len)) ans = min(ans, j);
		}
		// pr(x);pr(i);prln(ans);
		a += ans;
	}
	// prln(a);
	return a;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    cin >> n;
    for(int i = 0; i < n; ++i){
    	cin >> str[i];
    	str[i] += str[i];
    }
    int len = str[0].size();
    len/=2;
    ll ans = INF;
    for(ll i = 0; i < len; ++i){
    	ll res = getans(i, len);
    	ans = min(ans, res);
    }
    if(ans >= INF) cout << "-1\n";
    else cout << ans << "\n";
    return 0;
}
