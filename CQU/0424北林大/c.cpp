/*************************************************************************
    > File Name: c.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月24日 星期日 15时00分00秒
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
int a[400], b[400];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	int n;
	while(cin >> n){
		a[0] = a[n+1] = 0;
		b[0] = b[n+1] = 0;
		for(int i = 1; i <= n; ++i) a[i] = 1;
		for(int i = 1; i <= n; ++i){
			scanf("%d",&b[i]);
		}
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(b[j] > b[j+1]) a[j] = max(a[j], a[j+1]+1);
				if(b[j] > b[j-1]) a[j] = max(a[j], a[j-1]+1);
			}
		}
		ll ans = 0;
		for(int i = 1; i <= n; ++i){
			ans += a[i];
		}
		cout << ans  << "\n";
	}
	return 0;
}
