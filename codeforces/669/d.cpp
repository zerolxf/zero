/*************************************************************************
    > File Name: d.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月25日 星期一 01时25分06秒
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
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
int ans[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	ll a, b, op, x, n, q;
	a = 1, b = 0;
	cin >> n >> q;
	while(q--){
		scanf("%lld",&op);
		if(op == 2) {
			ll now = ((b + a)%n+n)%n;
			if(now == 0) now = n;
			if(now%2) b++;
			else b--;
		} else{
			scanf("%lld",&x);
			a += x;
		}
	}
	ll now = ((b + a)%n+n)%n;
	if(now == 0) now = n;
	for(int i = 1; i <= n/2; ++i){
		ans[now] = i*2-1;
		now = (now+2)%n;
		if(now == 0) now = n;
	}
	now = ((a - b + 1)%n+n)%n;
	if(now == 0) now = n;
	for(int i = 1; i <= n/2; ++i){
		ans[now] = i*2;
		now = (now+2)%n;
		if(now == 0) now = n;
	}
	for(int i = 1; i <= n; ++i){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}
