/*************************************************************************
    > File Name: g.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月30日 星期六 15时10分01秒
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
int sum[maxn];
int query(int rt, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr){
		return sum[rt];
	}
	int ans = 0;
	int m = l + r >> 1;
	if(m >= ql) ans = max(ans, query(rt<<1, l, m, ql, qr));
	if(m < qr) ans = max(ans, query(rt<<1|1, m+1, r, ql,qr));
	return ans;
}
int a[maxn];
void init(int n){
	int _n = 1;
	while(_n < n) _n <<=1;
	memset(sum, 0,_n*2*sizeof(int));
	for(int i = n-1; i >= 0; --i){
		sum[i+_n] = a[i];
	}
	for(int i = _n-1; i; --i){
		sum[i] = max(sum[i<<1], sum[i<<1|1]);
	}
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	int n, q, _n;
	int kase = 0;
	scanf("%d", &kase);
	while(kase--){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		_n = 1;
		while(_n < n) _n <<=1;
		init(n);
		int l, r;
		scanf("%d", &q);
		for(int i = 0; i < q; ++i){
			scanf("%d%d", &l, &r);
			int ans = query(1, 1, _n, l, r);
			printf("%d\n", ans);
		}
	}
	return 0;
}
