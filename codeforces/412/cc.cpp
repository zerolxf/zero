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
void gcd(ll a,ll b,ll& d,ll& x,ll& y)  
{  
    if(!b){d=a,x=1,y=0;}  
    else{gcd(b,a%b,d,y,x);y-=x*(a/b);}  
} 

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    ll a, b, c, d, p, q, x, y;
    int t;
    cin>>t;
    while(t--){
    	cin>>a>>b>>p>>q;
    	if((p==0||p==q) && (a*q!=b*p)){
    		cout << "-1\n";
    		continue;
    	}
    	if(a*q==b*p){
    		cout << "0\n";
    		continue;
    	}
        prln(q*a);prln(p*b);
    	c = q*a-p*b;
    	q = -q;
    	// pr(p);pr(q);prln(c);
    	gcd(p, q, d, x, y);
    	// if(d<0) x=-x,y=-y;
    	// d = d>0?d:-d;
    	// pr(x);prln(y);
    	// prln(d);
    	// prln(d);
    	// if(d==0||c%d!=0){
    	// 	cout << "-1\n";
    	// 	continue;
    	// }
        prln(d);
        prln(c);
        prln(c/d);
        prln(x);prln(y);
    	x*=c/d, y*=c/d;
    	 pr(x);prln(y);
    	prln(p*x);
        prln(q*y);
    	ll dx = -q/d, dy = -p/d;
    	pr(dx);prln(dy);
    	if(dy>0)	dx=-dx,dy=-dy;
    	ll mint = (y-x+dx+dy-1)/(dx+dy);
    	if(y-x<=0) mint = (y-x)/(dx+dy);
    	ll tt = (-y-dy-1)/(-dy);
    	if(-y<=0) tt = (-y)/(-dy);
    	mint = max(tt, mint);
    	ll ans = x+mint*dx;
    	cout<<ans<<"\n";

    }
    return 0;
}