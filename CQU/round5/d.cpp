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
const int maxn = 2e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)      // cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
#define lson rt<<1,l,m
#define rson rt<<1|1,m+1,r 
char s[maxn];
int sum[maxn], add[maxn];
void pushdown(int rt,int l, int r){
	pr(rt);pr(l);prln(r);
	if(add[rt]) {
		prln(add[rt]);
		pr(rt);pr((rt<<1));pr((rt<<1|1));
		pr(add[rt]);pr(add[rt<<1]);prln(add[rt<<1|1]);

		int m = l + r >>1;
		add[rt<<1] +=add[rt];
		add[rt<<1|1] += add[rt];
		sum[rt<<1] += add[rt];
		sum[rt<<1|1] +=add[rt];
		add[rt] = 0;
	}
}
void update(int rt, int l, int r, int ql, int qr, int v) {
	if(ql <= l && r <= qr){
		pr(sum[rt]);
		add[rt] += v;
		sum[rt] += v;
		pr(v);pr(rt);pr(add[rt]);prln(sum[rt]);
		return;
	}
	pushdown(rt,l,r);
	int m = l + r >>1;
	if(m >= ql) update(lson,ql,qr,v);
	if(m < qr) update(rson,ql,qr,v);
	//sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
int query(int rt, int l, int r, int o) {
	pr(rt);pr(l);pr(r);prln(o);
	if(l ==r) {
		return sum[rt];
	}
	pushdown(rt,l,r);
	int ans = 0, m = l + r>>1;
	if(m >= o) ans = query(rt<<1,l,m,o);
	else if(m < o) ans = query(rt<<1|1,m+1,r,o);
	return ans;
}
void init(int n) {
	int _n = 1;
	while(_n < n) _n *= 2;
	for(int i = 0; i <= _n*2; ++i) sum[i] = add[i] = 0;

}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, m, t, kase = 0, op, _n,l, r;
    char ss[10];
    cin >> t;
    while(t--) {
    	printf("Case %d:\n", ++kase);
    	scanf("%d%d",&n,&m);
    	_n = 1;
    	init(n);
    	while(_n < n) _n*=2;
    	s[0] = 0;
    	scanf("%s",s+1);
    	s[n+1] = 0;
    	s[n+2] = 0;
    	rep(i,_n*2) {
    		pr(i);prln(sum[i]);
    	}
    	for(int i = 3; i <= n; ++i) {
    		if(s[i]=='w'&&s[i-1]=='b'&&s[i-2]=='w'){
    			prln(i);
    			update(1,1,_n,i,n,1);
    		}
    	}
    	prln(query(1,1,_n,n));
    	for(int i = 0; i < m; ++i){
    		scanf("%d",&op);
    		if(op==0) {
    			scanf("%d%d",&l,&r);
    			l++;r++;
    			if(r-l+1<3) printf("0\n");
    			else {
    				pr(l);prln(r);
    				pr(query(1,1,_n,r));prln(query(1,1,_n,l+1));
    				int ans = query(1,1,_n,r)-query(1,1,_n,l+1);
    				printf("%d\n",ans);
    			}
    		} else {
    			scanf("%d%s",&l,ss);l++;
    			if(s[l]==ss[0]) continue;
    			if(l > 2){
    				if(s[l]=='w'&&s[l-1]=='b'&&s[l-2]=='w') {
    					update(1,1,_n,l,n,-1);
    				}
    				if(ss[0]=='w'&&s[l-1]=='b'&&s[l-2]=='w') {
    					update(1,1,_n,l,n,1);
    				}
    			}
    			if(l > 1) {
    				if(s[l+1]=='w'&&s[l]=='b'&&s[l-1]=='w') {
    					update(1,1,_n,l+1,n,-1);
    				}
    				if(s[l+1]=='w'&&ss[0]=='b'&&s[l-1]=='w') {
    					update(1,1,_n,l+1,n,1);
    				}
    			}
    			if(s[l+2]=='w'&&s[l+1]=='b'&&s[l]=='w') {
    				update(1,1,_n,l+2,n,-1);
    			}
    			if(s[l+2]=='w'&&s[l+1]=='b'&&ss[0]=='w') {
    				update(1,1,_n,l+2,n,1);
    			}
    			s[l] = ss[0];
    		}
    	}
    }
    return 0;
}