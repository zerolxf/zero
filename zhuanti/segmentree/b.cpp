/*************************************************************************
    > File Name: b.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月27日 星期三 20时06分03秒
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
struct Node{
	int mi, ma;
}init;
Node get(const Node& a, const Node& b){
	return Node{min(a.mi, b.mi), max(a.ma, b.ma)};
}
struct Nodey{
	Node v;
	int l, r;
};
int n;
int locx[maxn], locy[maxn];
struct Nodex{
	int l, r;
	Nodey sty[maxn*3];
	void build(int i, int _l, int _r) {
		sty[i].l = _l; sty[i].r = _r;
		sty[i].v = init;
		if(_l == _r) {
			locy[_l] = i;
			return;
		}
		int m = (_l+_r)>>1;
		build(i<<1,_l,m);
		build(i<<1|1, m+1, _r);
	}
	Node getans(int i, int _l, int _r) {
		if(sty[i].l == _l && sty[i].r == _r) {
			return sty[i].v;
		}
		int m = (sty[i].l + sty[i].r) >> 1;
		Node ans = init;
		if(m >= _r) ans = get(ans, getans(i<<1, _l, _r));
		else if(m < _l) ans = get(ans, getans(i<<1|1, _l, _r));
		else {
			ans = get(getans(i<<1, _l, m), getans(i<<1|1, m+1, _r));
		}
		return ans;
	}
}stx[maxn*3];
void build(int i, int x1, int x2) {
	stx[i].l = x1; stx[i].r = x2;
	stx[i].build(1,1,n);
	if(x1 == x2) {
		locx[x1] = i;
		return;
	}
	int m = (x1+x2) >> 1;
	build(i<<1, x1, m);
	build(i<<1|1, m+1, x2);
}
Node getans(int i, int x1, int x2, int y1, int y2) {
	if(stx[i].l == x1 && stx[i].r == x2) {
		return stx[i].getans(1, y1, y2);
	}
	Node ans = init;
	int m = (stx[i].l + stx[i].r) >> 1;
	if(m >= x2) ans = get(ans, getans(i<<1, x1, x2, y1, y2));
	else if(m < x1) ans = get(ans, getans(i<<1|1, x1, x2, y1, y2));
	else {
		ans = get(getans(i<<1, x1, m, y1, y2), getans(i<<1|1, m+1, x2, y1, y2));
	}
	return ans;
}

void update(int x, int y, int val) {
	x = locx[x], y = locy[y];
	stx[x].sty[y].v = Node{
		val,val
	};
	for(int i = x; i; i >>=1){
		for(int j = y; j; j >>=1){
			if(i==x&&j==y) continue;
			if(j==y){
				stx[i].sty[j].v = get(stx[i<<1].sty[j].v, stx[i<<1|1].sty[j].v);
			} else {
				stx[i].sty[j].v = get(stx[i].sty[j<<1].v, stx[i].sty[j<<1|1].v);
			}
		}
	}
}



int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	int t,kase = 0, q, x, y, l;
	init.mi = INF; init.ma= -INF;
	scanf("%d", &t);
	while(t--){
		printf("Case #%d:\n",++kase);
		scanf("%d", &n);
		build(1, 1, n);
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				scanf("%d", &x);
				update(i,j,x);
			}
		}
		scanf("%d",&q);
		for(int i = 0; i < q; ++i){
			Node ans = init;
			scanf("%d%d%d",&x, &y, &l);
			int x1 = max(1, x-n/2);
			int x2 = min(n, x+n/2);
			int y1 = max(1, y-n/2);
			int y2 = min(n, y+n/2);
			ans = get(ans, getans(1, x1, x2, y1, y2));
			printf("%d\n", (ans.mi+ans.ma)/2);
			update(x, y, (ans.mi+ans.ma)/2);
		}
	}
	return 0;
}
