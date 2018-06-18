
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
int getnum(int x){
	int ans = 0;
	for(int i = x; i ; i -= i&(-i)){
		ans++;
	}
	return ans;
}
int rev(int x){
	int num = 0;
	int y = x;
	int ans = 0;
	while(y){
		if(y&1) ans = ans*2+1;
		else ans = ans*2;
		num++,y>>=1;
	}
	return ans;
}
int geth(int x){
	while(x-(x&(-x)) != 0){
		x-=x&(-x);
	}
	return x;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    ll sum = 0;
    ll pre = 0;
    for(int i = 1; i <= 100;++i){
    	ll b = rev(i)+i;
    	int k = getnum(rev(i)+i);
    	if(geth(b) == geth(i)){
    		pr(i);prln(i-pre);
    		pre = i;
    	}
    	sum += k;
    }
    return 0;
}
