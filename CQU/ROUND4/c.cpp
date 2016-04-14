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
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
ll sum[maxn], add[maxn];
void pushdown(int rt, ll l, ll r) {
	if(add[rt] != 0) {
		add[rt<<1] += add[rt];
		add[rt<<1|1] += add[rt];
		int m = l + r >> 1;
		sum[rt<<1] += (m-l+1)*add[rt];
		sum[rt<<1|1] += (r-m)*add[rt];
		add[rt] = 0;
	}
}
void update(int rt, ll l, ll r, ll ql, ll qr, ll v) {
	if(ql <= l && r <= qr) {
		add[rt] += v;
		sum[rt] += (r-l+1)*v;
		return ;
	}
	pushdown(rt,l,r);
	ll m = l + r >> 1;
	if(m >= ql) update(rt<<1,l,m,ql,qr,v);
	if(m < qr) update(rt<<1|1,m+1,r,ql,qr,v);
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
ll query(int rt, ll l, ll r, ll ql, ll qr) {
	if(ql <= l && r <= qr) {
		return sum[rt];
	}
	ll m = (l+r) >> 1;
	ll ans = 0;
	pushdown(rt,l,r);
	if(m >= ql) ans += query(rt<<1,l,m,ql,qr);
	//pr(ans);
	if(m < qr) ans += query(rt<<1|1, m+1, r, ql, qr);
	//pr(ans);
	return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, q;
    scanf("%d%d",&n, &q);
    ll x, _n = 1;
    while(_n < n) _n*=2;
    for(int i = 0; i <= _n*2; ++i) {
    	add[i] = 0;
    	sum[i] = 0;
    }
    for(int i = 1; i <= n; ++i) {
    	scanf("%lld", &x);
    	update(1,1,_n,i,i,x);
    }
    ll l, r, v;
    char op[10];
    for(int i = 0; i < q; ++i) {
    	scanf("%s",op);
    	if(op[0] == 'C') {
    		scanf("%lld%lld%lld", &l, &r, &v);
    		update(1,1,_n,l,r,v);
    	} else {
    		scanf("%lld%lld",&l,&r);
    		ll ans = query(1,1,_n,l,r);
    		printf("%lld\n", ans);
    	}
    }
    return 0;
}