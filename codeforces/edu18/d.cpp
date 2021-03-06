
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
char s[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    ll x, n, q;
    scanf("%lld%lld",&n,&q);
    n++;
    rep(i,q){
    	scanf("%lld%s", &x, s);
    	for(int i = 0; s[i]; ++i){
    		if(s[i] == 'L'){
    			x -= (x&(-x))>>1;
    		}else if(s[i] == 'R'){
    			x += (x&(-x))>>1;
    		}else{
    			if(((n+1)>>1)==x) continue;
    			ll nx = x + (x&(-x));
    			if((nx-((nx&(-nx))>>1))==x) x = nx;
    			else x -= x&(-x);
    		}
    	}
    	printf("%lld\n",x);	
    }

    return 0;
}
