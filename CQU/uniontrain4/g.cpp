/*************************************************************************
	> File Name: g.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年06月16日 星期四 21时50分32秒
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
#define pr(x) //cout << #x << " = " << x << " ";
#define prln(x)// cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
ll sum[maxn<<1], add[maxn<<1], d[maxn<<1], num[maxn<<1];
void pushdown(int rt, int l, int r){
    int m = l + r >> 1;
    if(num[rt] != -1){
        add[rt] = 0, d[rt] = 0;
        num[rt<<1] = num[rt<<1|1] = num[rt];
        sum[rt<<1] = (m-l+1)*num[rt];
        sum[rt<<1|1] = (r-m)*num[rt];
        num[rt] = -1;
    }else{
        if(num[rt<<1] != -1 && m>l) pushdown(rt<<1, l, m);
        if(num[rt<<1|1] != -1 && r>m+1) pushdown(rt<<1|1,m+1,r);
        if(d[rt]) {
            ll x = (m+1-l)*d[rt];
            ll y = m-l;
            sum[rt<<1] += y*(y+1)/2*d[rt];
            y = r-m-1;
            sum[rt<<1|1] += y*(y+1)/2*d[rt];

            add[rt<<1|1] += x;
            sum[rt<<1|1] += (r-m)*x;
            d[rt<<1] += d[rt];
            d[rt<<1|1] += d[rt];
            d[rt] = 0;
        }
        if(add[rt]){
            add[rt<<1] += add[rt];
            add[rt<<1|1] += add[rt];
            sum[rt<<1] += (m-l+1)*add[rt];
            sum[rt<<1|1] += (r-m)*add[rt];
            add[rt] = 0;
        }
    }
}
void update1(int rt, int l, int r, int ql, int qr, int v){
    if(ql <= l && r <= qr){
        num[rt] = v;
        add[rt] = d[rt] = 0;
        sum[rt] = (r-l+1)*v;
        return ;
    }
    pushdown(rt, l, r);
    int m = l + r >> 1;
    if(m >= ql) update1(rt<<1, l, m, ql, qr, v);
    if(m < qr) update1(rt<<1|1, m+1, r, ql, qr, v);
    if(r>l)sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    pr(l);pr(r);prln(sum[rt]);
}
void update(int rt, int l, int r, int ql, int qr, int a, int dd){
    if(ql <= l && r <= qr){
        pr(l);pr(r);prln(sum[rt]);
        d[rt] += dd;
        add[rt] += (l-ql+1)*dd+a;
        ll x = r - l;
        sum[rt] += x*(x+1)/2*dd + (x+1)*(l-ql+1)*dd+(x+1)*a;
        pr(l);pr(r);prln(sum[rt]);
        return;
    }
    pushdown(rt, l, r);
    int m = l + r >> 1;
    if(m >= ql) update(rt<<1, l, m, ql, qr, a, dd);
    if(m < qr) update(rt<<1|1, m+1, r, ql, qr, a, dd);
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    pr(l);pr(r);prln(sum[rt]);
}
ll query(int rt, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return sum[rt];
    }
    pushdown(rt, l, r);
    int m = l + r >> 1;
    ll ans = 0;
    if(m >= ql) ans = query(rt<<1, l, m, ql, qr);
    if(m < qr) ans += query(rt<<1|1, m+1, r, ql, qr);
    return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, m, t, x, l, r, c, op;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        int _n = 1;
        while(_n < n) _n <<= 1;
        for(int i = 1; i <= _n*2; ++i){
            sum[i] = add[i] = d[i] = 0;
            num[i] = -1;
        }
        for(int i = 1; i <= n; ++i){
            scanf("%d", &x);
            sum[i+_n-1] = x;
        } 
        for(int i = _n-1; i; --i){
            sum[i] = sum[i<<1] + sum[i<<1|1];
        }
        for(int i = 0; i < m; ++i){
            scanf("%d", &op);
            if(op == 4){
                scanf("%d%d", &l, &r);
                ll ans = query(1, 1, _n, l, r);
                printf("%lld\n",ans);
            }else{
                scanf("%d%d%d", &l, &r, &x);
                if(op == 1) update(1, 1, _n, l, r, x, 0);
                else if(op == 2) update(1, 1, _n, l, r, 0, x);
                else if(op == 3) update1(1, 1, _n, l, r, x);
            }
        }
    }
	return 0;
}
