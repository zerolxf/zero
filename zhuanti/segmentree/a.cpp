/*************************************************************************
    > File Name: a.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月27日 星期三 18时37分35秒
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
const int maxn = 1100;
const int INF = 0x3f3f3f3f;
int locx[maxn], locy[maxn];
int n;
struct Nodey{
	int l, r, v;
};
struct Nodex{
	int l, r;
	Nodey sty[maxn*3];
	void build(int i, int _l, int _r){
		sty[i].l = _l;
		sty[i].r = _r;
		sty[i].v = 0;
		if(_l == _r) {
			locy[_l] = i;
			return;
		}
		int m = (_l + _r)>>1;
		build(i<<1, _l, m);
		build(i<<1|1, m+1, _r);
	}
	void add(int i, int _l, int _r, int val) {
		if(sty[i].l == _l && sty[i].r == _r) {
			sty[i].v += val;
			return;
		}
		int m = (sty[i].l + sty[i].r) >>1;
		if(m >= _r) add(i<<1, _l, _r, val);
		else if(m < _l) add(i<<1|1, _l, _r, val);
		else {
			add(i<<1, _l, m, val);
			add(i<<1|1, m+1, _r, val);
		}
	}
}stx[maxn*3];
void build(int i, int _l, int _r) {
	stx[i].l = _l;
	stx[i].r = _r;
	stx[i].build(1, 1, n);
	if(_l == _r){
		locx[_l] = i;
		return;
	}
	int m = (_l + _r) >> 1;
	build(i<<1, _l, m);
	build(i<<1|1, m+1, _r);
}
void add(int i, int x1, int x2, int y1, int y2,int val) {
	if(stx[i].l == x1 && stx[i].r == x2) {
		stx[i].add(1,y1,y2,val);
		return;
	}
	int mid = (stx[i].l + stx[i].r) >> 1;
	if(mid >= x2) add(i<<1, x1, x2, y1, y2, val);
	else if(mid < x1) add(i<<1|1, x1, x2, y1, y2, val);
	else {
		add(i<<1, x1, mid, y1, y2, val);
		add(i<<1|1, mid+1, x2, y1, y2, val);
	}
}
int sum(int x, int y) {
	int ret  = 0;
	for(int i = locx[x]; i; i>>=1){
		for(int j = locy[y]; j; j >>= 1){
			ret += stx[i].sty[j].v;
		}
	}
	return ret;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	int t, kase = 0;
	char op[10];
	scanf("%d", &t);
	while(t--) {
		int q;
		if(kase++) printf("\n");
		scanf("%d%d", &n,&q);
		build(1, 1, n);
		int x1, x2, y1, y2, x, y;
		for(int i = 0; i < q; ++i){
			scanf("%s", op);
			if(op[0] == 'C') {
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				add(1, x1, x2, y1, y2, 1);
			} else {
				scanf("%d%d", &x, &y);
				int ans = sum(x,y);
				printf("%d\n",ans%2);
			}
		}
	}
	return 0;
}
