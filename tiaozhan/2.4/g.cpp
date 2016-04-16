#include<stdio.h>
const int maxn = 1e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)      // cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define ll long long
int head[maxn], nxt[maxn], to[maxn], dfsn, cnt, id[maxn], r[maxn], _n, sum[maxn<<2], dep[maxn];
void addedge(int u, int v) {
	nxt[cnt] = head[u];
	head[u] = cnt;
	to[cnt++] = v;
}
void init(int n) {
	cnt = dfsn = 0;
	_n = 1;
	while(_n < n) _n = _n*2;
	int _nn = _n*2;
	for(int i = 0; i <= _nn; ++i) sum[i] = -1;
	for(int i = 0; i <= n;++i) {
		head[i] =-1;
	}
}

void dfstree(int fa,int u) {
	id[u] = ++dfsn;
	dep[u] = dep[fa]+1;
	for(int i = head[u]; ~i; i = nxt[i]){
		dfstree(u,to[i]);
	}
	r[u] = dfsn;
}
inline void getans(int* ans, const int* v2){
	if(*ans == -1 || dep[*ans] < dep[*v2]) *ans = *v2;
}
void pushdown(int rt) {
	if(sum[rt] != -1) {
		getans(&sum[rt<<1], &sum[rt]);
		getans(&sum[rt<<1|1],&sum[rt]);
	}
}
void update(int rt, int l, int r, int ql, int qr, int v) {
	if(ql <= l && r <= qr) {
		getans(&sum[rt], &v);
		return;
	}
	pushdown(rt);
	int m = l + r >> 1;
	if(m >= ql) update(rt<<1, l, m, ql, qr, v);
	if(m < qr) update(rt<<1|1, m+1, r, ql, qr, v);
}
int query(int rt) {
	rt += _n-1;
	int ans = 0;
	while(rt>=1) {
		getans(&ans,&sum[rt]);
		rt = rt>>1;
	}
	return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, m, x;
    char op[10];
    while(scanf("%d%d",&n, &m) != EOF&& (n||m)) {
    	ll ans = 0;
    	init(n);
    	for(int i = 2; i <= n; ++i) {
    		scanf("%d", &x);
    		addedge(x,i);
    	}
    	dep[0] = 0;
    	dfstree(0,1);
    	update(1, 1, _n, id[1], r[1], 1);
    	for(int i = 0; i < m; ++i) {
    		scanf("%s%d", op, &x);
    		if(op[0] == 'M')	update(1, 1, _n, id[x], r[x], x);
    		else	ans += query(id[x]);
    	}
    	printf("%lld\n", ans);
    }
    return 0;
}