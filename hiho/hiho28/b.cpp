
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
int num[100];
inline ll lowbit(ll x){
	return x&(-x);
}
inline int getnum(ll x){
	int ans = 0;
	while(x){
		x-=lowbit(x);
		ans++;
	}
	return ans;
}
void setnum(int x, int y){
	if(num[x] == 2) num[x] = y;
	else if(num[x] != y) num[x] = -1;
}
ll a[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    int n;
    for(int i = 0; i < 100; ++i) num[i] = 2;
    ll a[maxn];
    cin >> n;
    rep(i,n) cin >> a[i];
    for(int i = 0; i < n-1; ++i){
    	ll x = a[i]^a[i+1];
    	while(x - lowbit(x) != 0){
    		x-= lowbit(x);
    	}
    	int cnt = 0;
    	for(int j = 0; j < 60; ++j){
    		if((x>>j)&1) cnt = j;
    	}
    	x = a[i]^a[i+1];
    	if(x==0) continue;
    	else{
    		if((a[i]>>cnt)&1){
    			 setnum(cnt, 0);
    		}
    		else {
    			setnum(cnt, 1);
    		}
    	}
    }
    ll ans = 1;
    for(int i = 0; i < 60; ++i){
    	if(num[i] == 2) ans <<= 1;
    	else if(num[i] == -1) ans = 0;
    }
    cout<<ans<<"\n";
    return 0;
}
