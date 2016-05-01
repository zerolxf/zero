/*************************************************************************
    > File Name: c.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月29日 星期五 16时52分12秒
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
ll num[maxn<<2], sum[maxn<<2];
int add[maxn<<2], flag[maxn<<2];
void pushdown(int rt, int l, int r) {
	if(sum[rt] == 0) {
		sum[rt<<1] = sum[rt<<1|1] = 0;
		add[rt] = 0;
	}
	if(add[rt]) {
		int m = l + r >> 1;
		sum[rt<<1] += (m -l + 1)*add[rt];
		sum[rt<<1|1] += (r-m)*add[rt];
		add[rt<<1|1] = add[rt<<1] = add[rt];
		add[rt] = 0;
	}
}
void update(int rt, int l, int r, int ql, int qr) {
	if(ql <= l && r <= qr) {
//		flag[rt] = 1;
		sum[rt] = 0;
		return;
	}
	int m = l + r >> 1;
	pushdown(rt, l, r);
	if(m >= ql) update(rt<<1, l, m, ql, qr);
	if(m < qr) update(rt<<1|1, m+1, r, ql, qr);
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void edit(int rt, int l, int r, int ql, int qr, int v) {
	pushdown(rt,l,r);
	if(ql <= l && r <= qr){
		add[rt] += v;
		sum[rt] += (r-l+1)*v;
		return;
	}
	int m = l + r >> 1;
	if(m >= ql) edit(rt<<1, l, m, ql, qr, v);
	if(m < qr) edit(rt<<1|1, m+1, r, ql, qr, v);
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
ll query(int rt, int l, int r, int ql, int qr) {
	if(ql <= l && r <= qr) {
		return sum[rt];
	}
	ll ans = 0;
	int m = l + r >> 1;
	if(m >= ql) ans += query(rt<<1, l, m, ql, qr);
	if(m < qr) ans += query(rt<<1|1, m+1, r, ql, qr);
	return ans;
}
void npushdown(int rt, int l, int r) {
	if(num[rt] == 0) {
		num[rt<<1] = num[rt<<1|1] = 0;
		flag[rt] = 0;
	}
	if(flag[rt]) {
		int m = l + r >> 1;
		num[rt<<1] += (m -l + 1)*flag[rt];
		num[rt<<1|1] += (r-m)*flag[rt];
		flag[rt<<1|1] = flag[rt<<1] = flag[rt];
		flag[rt] = 0;
	}
}
void nupdate(int rt, int l, int r, int ql, int qr) {
	if(ql <= l && r <= qr) {
//		flag[rt] = 1;
		num[rt] = 0;
		return;
	}
	int m = l + r >> 1;
	npushdown(rt, l, r);
	if(m >= ql) nupdate(rt<<1, l, m, ql, qr);
	if(m < qr) nupdate(rt<<1|1, m+1, r, ql, qr);
	num[rt] = num[rt<<1] + num[rt<<1|1];
}
void nedit(int rt, int l, int r, int ql, int qr, int v) {
	npushdown(rt,l,r);
	if(ql <= l && r <= qr){
		flag[rt] += v;
		num[rt] += (r-l+1)*v;
		return;
	}
	int m = l + r >> 1;
	if(m >= ql) nedit(rt<<1, l, m, ql, qr, v);
	if(m < qr) nedit(rt<<1|1, m+1, r, ql, qr, v);
	num[rt] = num[rt<<1] + num[rt<<1|1];
}
ll nquery(int rt, int l, int r, int ql, int qr) {
	npushdown(rt,l,r);
	if(ql <= l && r <= qr) {
		return num[rt];
	}
	ll ans = 0;
	int m = l + r >> 1;
	if(m >= ql) ans += nquery(rt<<1, l, m, ql, qr);
	if(m < qr) ans += nquery(rt<<1|1, m+1, r, ql, qr);
	return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	ll n, t, c, x, _n;
	char op[100];
	_n = 1;
	while(_n < 1e6+10) _n*=2;
	update(1, 1, _n, 1, _n);
	nupdate(1, 1, _n, 1, _n);
	while(scanf("%s", op) != EOF) {
		scanf("%lld%lld",&n, &x);
		int l = 1, r =  _n;
		if(op[0] == 'A') {
			nedit(1, 1, _n, x, x, n);
			edit(1, 1, _n, x, x, x*n);
		} else {
			while(l < r) {
				int m = (l+r)>>1;
				if(nquery(1, 1, _n, 1, m) > n) r = m;
				else l = m+1;
			}
			if(nquery(1, 1, _n, 1, r) < n){
				printf("UNHAPPY\n");
			} else {
				int now = nquery(1, 1, _n, 1, r-2);	

			}
		}
	}
	return 0;
}
