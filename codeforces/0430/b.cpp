/*************************************************************************
    > File Name: b.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月30日 星期六 00时50分03秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
ll a[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	ll c, d, b, sum, n;
	while(cin >> n){
		b = c = d = 0;
		rep(i, n) scanf("%lld", &a[i]);
		sort(a,a+n);
		for(int i = n-1; i >= 0; --i){
			if(b <= c && b <= d){
				b += a[i];
			} else if(c <= d){
				c += a[i];
			} else {
				d += a[i];
			}
		}
		ll ans = 0;
		if(b+c<=d){
			ans = d-(b+c)+1;
		} else if(b+d<=c){
			ans = c-(b+d)+1;
		} else if(c+d<=b){
			ans = b-(c+d)+1;
		} else ans = 1;
		cout << ans << "\n";
	}
	return 0;
}
