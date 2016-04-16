#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int maxn = (1<<23)+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
#define lson rt<<1
#define rson rt<<1|1
int sum[maxn], add[maxn];
bool vis[maxn];
    char s[maxn];
    char str[maxn];
    char op[10];
    void pushdown(int rt, int l, int r);
void push(int rt, int l, int r, int v) {
	if(v == 0 || v == 1) {
		add[rt] = v;
		sum[rt] = (r-l+1)*v;
	} else {
		sum[rt] = (r-l+1) - sum[rt];
		if(add[rt] == -1) add[rt] = INF;
		if(add[rt] == 0 || add[rt] == 1) add[rt] = 1 - add[rt];
		if(add[rt] == INF) {
			add[rt] = -1;
			pushdown(rt,l,r);
			add[rt] =INF;
		}
	}
}
void pushdown(int rt, int l, int r) {
	if(add[rt] != INF) {
		int m = l + r >> 1;
		push(lson, l, m, add[rt]);
		push(rson, m+1, r, add[rt]);
		add[rt] = INF;
	}
}
void update(int rt, int l, int r, int ql, int qr, int v) {
	if(l > r) return;
	if(ql <= l && r <= qr) {
		push(rt,l,r,v);
		return;
	}
	int m = l + r >> 1;
	pushdown(rt,l,r);
	if(m >= ql) update(lson,l,m,ql,qr,v);
	if(m < qr) update(rson,m+1,r,ql,qr,v);
	sum[rt] = sum[lson] + sum[rson];
	//pr(rt);pr(l);pr(r);pr(ql);pr(qr);prln(sum[rt]);
}
int query(int rt, int l, int r, int ql, int qr) {
//	prln(rt);
	if(ql <= l && r <= qr) {
		return sum[rt];
	}	
	pushdown(rt,l,r);
	int ans = 0;
	int m = l + r >> 1;
	if(m >= ql) ans += query(rt<<1,l,m,ql,qr);
	if(m < qr) ans += query(rt<<1|1,m+1,r,ql,qr);
	//pr(rt);pr(l);pr(r);pr(ql);pr(qr);prln(ans);
	return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif

    int t, kase = 0, m, n, q,  lens, ti, len, cnt, x, y, qnum;
    cin >> t;
    while(t--) {
    	qnum = 0;
    	printf("Case %d:\n",++kase);
    	scanf("%d", &m);
    	cnt = 0;
    	for(int i = 0; i < m; ++i) {
    		scanf("%d", &ti);
    		scanf("%s", str);
    		len = strlen(str);
    		for(int j = 0; j < ti; ++j) {
    			for(int l = 0; l < len; ++l) {
    				vis[++cnt] = str[l]-'0';
    			}
    		}
    	}
    	int _n = 1;
    	while(_n < cnt) _n = _n*2;
    	int nn = _n*2, ed = cnt+_n-1, pos = _n-1;
    	for(int i = 0; i <= nn; ++i) {
    		add[i] = INF;
    		sum[i] = 0;
    	}
    	for(int i = _n; i <= ed; ++i) sum[i] = vis[i-_n+1];
   		while(pos) {
   			sum[pos] = sum[pos<<1] + sum[pos<<1|1];--pos;
   		}
		scanf("%d", &q);
		for(int i = 0; i < q; ++i) {
			scanf("%s%d%d", op, &x, &y);
			x++;y++;
			if(op[0] == 'F') update(1,1,_n,x,y,1);
			if(op[0] == 'E') update(1,1,_n,x,y,0);
			if(op[0] == 'I') update(1,1,_n,x,y,-1);
			if(op[0] == 'S') {
				int ans = query(1,1,_n,x,y);
				printf("Q%d: ",++qnum);
				printf("%d\n", ans);
			}
		}    	
    }
    prln("lxf");
    return 0;
}