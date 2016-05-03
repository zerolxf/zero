/*************************************************************************
    > File Name: e.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年05月01日 星期日 13时37分40秒
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
struct Node{
	int l, r, c;
	Node(){

	}
	Node(int _l , int _r, int _c){
		l = _l;
		r = _r;
		c = _c;
	}
}node[maxn], a[maxn<<2];
int dfn[maxn];
int dfncnt;
vector<int> G[maxn];
void dfs(int u) {
	dfn[u] = ++dfncnt;
	int id = dfncnt;
	node[dfncnt].l = dfncnt;
	for(int i = 0; i < G[u].size(); ++i){
		int v = G[u][i];
		dfs(v);
	}
	node[id].r = dfncnt;
}
void build(int rt, int l, int r) {
	a[rt].l = l; a[rt].r = r;
	a[rt].c = -1;
	int m = l + r >> 1;
	if(l==r) return;
	build(rt<<1, l, m);
	build(rt<<1|1, m+1, r);
}
void pushdown(int rt) {
	if(a[rt].c != -2){
		a[rt<<1|1].c = a[rt].c;
		a[rt<<1].c = a[rt].c;
	}
}
void update(int rt, int l, int r, int v) {
	if(a[rt].l == l && a[rt].r == r){
		a[rt].c = v;
		return;
	}
	push(rt);
	if(r <= a[rt<<1].r) update(rt<<1, l, r, v);
	else if(l >= a[rt<<1|1].l) update(rt<<1|1, l, r, v);
	else {
		update(rt<<1, l, a[rt<<1].r, v);
		update(rt<<1|1, a[rt<<1|1].l, r, v);
	}
	if(a[rt<<1].c != a[rt<<1|1].c){
		a[rt].c = -2;
	}
	else {
		a[rt].c = a[rt<<1].c;
	}
}
int query(int rt, int o){
	if(a[rt].l == a[rt].r){
		return a[rt].c;
	}
	pushdown(rt);
	if(o <= a[rt<<1].r) return query(rt<<1, o);
	return query(rt<<1|1, o);
}
int p[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	int n, t, u, v, x, y;
	char op[10];
	scanf("%d", &t);
	int kase = 0;
	while(t--){
		printf("Case #%d:\n", ++kase);
		scanf("%d", &n);
		for(int i = 0; i <= n; ++i) {
			p[i] =  -1;
			G[i].clear();
		}
		dfncnt = 0;
		for(int i = 0; i < n-1; ++i){
			scanf("%d%d", &u, &v);
			p[u] = v;
			G[v].push_back(u);
		}
		int root = 0;
		for(int i = 1; i <= n; ++i){
			if(p[i] == -1) root = i;
		}
		dfs(root);
		build(1, 1, n);
		int m;
		scanf("%d", &m);
		for(int i = 0; i < m; ++i){
			scanf("%s", op);
			if(op[0] == 'C'){
				scanf("%d", &x);
				int ans = query(1, dfn[x]);
				printf("%d\n", ans);
			} else {
				scanf("%d%d", &x, &y);
				x = dfn[x];
				update(1, node[x].l, node[x].r, y);
			}
		}
	}
	return 0;
}
