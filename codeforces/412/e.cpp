
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
const int maxn = 1e5+100;
const int INF = 0x3f3f3f3f;
ll base[maxn];
inline ll lowbit(ll x){
	return x&(-x);
}
ll getb(ll x){
	while(x-lowbit(x) != 0){
		x-=lowbit(x);
	}
	return x;
}
const int N = 100;
int least[N];
int n;
ll a[maxn];
int getpos(ll x){
	return lower_bound(base, base+61, x) - base;
}

bool slovefuck(ll x, int num){
	ll b = getb(x);
	ll bp = getpos(b);
	while(bp >= 0){
		if(least[bp]<=0) return false;
		least[bp]-=num;
		bp--;
	}
	return true;
}
int getm(ll x){
	for(int i = 61; i >= 0; --i){
		if(least[i] > 0 && base[i]*2 >= x) return i;
	}
	return -1;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    vector<int> len;
    base[0] = 1;
    rep(i,61) base[i+1] = base[i] * 2;
    MEM(least, 0);
    MEM(a, 0);
    cin >> n;
    rep(i,n) {
    	cin >> a[i];
    	if(getb(a[i]) == a[i]){
    		least[getpos(a[i])]++;
    	}
    }
    bool ok = true;
    int need = 0, fucknum = 0;
    for(int i = n-1; i >= 0; --i){
    	if(a[i]==1) continue;
    	if(a[i] == a[i+1] && a[i] == getb(a[i])) continue;
    	if(a[i] == getb(a[i])){
    		int pos = getpos(a[i]);
	    	while(least[pos]>0){
	    		if(!slovefuck(base[pos], 0)){
	    			if(need<=0) {
	    				ok = false;
	    				break;
	    			}else{
	    				need--;
	    				least[pos]--;
	    			}
	    		}else {
	    			least[pos]--;
	    			if(least[pos]==0) {
	    				need++, least[pos]++;
	    			}
	    			slovefuck(base[pos], 1);
	    			fucknum++;
	    		}
	    	}
    	}else{
    		if(need>0) {
    			need--;
    			continue;
    		}
    		ll np = getm(a[i]);
	    	if(np==-1 || !slovefuck(base[np], 1)) {
	    		ok = false;
	    		break;
	    	}else fucknum++;
    	}
    }
   	int mi = least[0]<=need?0:(least[0]-need+1)/2;
   	int ma = least[0];
    ll l = fucknum + mi;
    ll r = fucknum + ma;
    pr(l);prln(r);
    if(ok) {
    	for(int i = l; i <= r; ++i) cout << i << " ";
    	puts("");
    }else cout << "-1";
    return 0;
}
