
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
void gcd(long long a,long long b,long long& d,long long& x,long long& y)  
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
    	ll t = max((a+p-1)/p, (b+q-1)/q);
    	t = max(t, (q-p+b-a-1)/(q-p));
    	ll ans = q*t-b;
    	cout<<ans<<"\n";

    }
    return 0;
}
