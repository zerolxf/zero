
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
inline ll bs(ll x){
	return x <0?-x:x;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    ll n, q, l, m, b1, x;
    set<ll> st, use;
    cin >> b1 >> q >> l >> m;
    rep(i, m){
    	cin >> x;
    	st.insert(x);
    }
    int ans = 0;
    if((q <= 1 &&q>=-1)|| b1 == 0){
    	if(bs(b1)<=l&&st.count(b1) == 0) ans++;
    	if(bs(b1)<=l){
    		if(bs(b1*q)<=l&&st.count(b1*q) == 0) ans += 10000;
    	}
    	if(bs(b1*q)<=l&&bs(b1)<=l){
    		if(bs(b1*q*q)<=l&&st.count(b1*q*q) == 0) ans += 10000;
    	}
    }else{
    	ll now = b1;
    	while(now <= l && now >= -l){
    		if(st.count(now) == 0) ans++;
    		now = now*q;
    		if(ans>=10000) break;
    	}
    }
    if(ans>=10000) cout<<"inf\n";
    else cout<<ans<<endl;
    return 0;
}
