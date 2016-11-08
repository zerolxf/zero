#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 2e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
ll p[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    p[0] = 1;
    for(int i = 1; i <= 32; ++i){
    	p[i] = p[i-1]*2;
    }
    ll n, h, w;
    while(cin >> h >> w){
    	int posh = upper_bound(p,p+31,h) - p;
    	ll ans = 0, ansh = 0, answ;
    	for(int i =0; i < posh; ++i){
    		ll hh = p[i];
    		ll w1 = (p[i]*4+4)/5;
    		ll w2 = (p[i]*5)/4;
    		if(w < w1) continue;
    		if(w >= w1 && w <= w2){
    			if(w*hh>=ans){
    				ans = w*hh;
    				ansh = hh;
    				answ = w;
    			}
    		} else if(w > w2){
    			if(w2*hh>=ans){
    				ans = w2*hh;
    				ansh=hh;
    				answ = w2;
    			}
    		}
    	}
    	int posw = upper_bound(p,p+31,w) - p;

    	for(int i =0; i < posw; ++i){
    		ll ww = p[i];
    		ll h1 = (p[i]*4+4)/5;
    		ll h2 = (p[i]*5)/4;
    		if(h < h1) continue;
    		if(h >= h1 && h <= h2){
    			if(h*ww>=ans){
    				ans = h*ww;
    				ansh = h;
    				answ = ww;
    			}
    		} else if(h > h2){
    			if(h2*ww>ans||(h2*ww==ans&&h2>ansh)){
    				ans = ww*h2;
    				ansh= h2;
    				answ = ww;
    			}
    		}
    	}
    	printf("%lld %lld\n",ansh,answ);
    }
    return 0;
}