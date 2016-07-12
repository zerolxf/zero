
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
#include<vector>

using namespace std;
const int maxn = 4e5+100;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
ll add[maxn], sum[maxn];
void pushdown(int rt, int l, int r) {
    if(add[rt]) {
        add[rt<<1] = add[rt<<1|1] = add[rt];
        sum[rt<<1] = sum[rt<<1|1] = 1<<add[rt];
        add[rt] = 0;
    }
}
void update(int rt, int l, int r, int ql, int qr,int v) {
    if(l > r) return;
    if(ql <= l&& r <= qr) {
        add[rt] = v;
        sum[rt] = 1<<v;
        return;
    }
    pushdown(rt, l, r);
    int m = l + r >> 1;
    if(m >= ql) update(rt<<1, l, m, ql, qr, v);
    if(m < qr) update(rt<<1|1, m+1, r, ql, qr,v);
    sum[rt] = sum[rt<<1] | sum[rt<<1|1];
}
ll query(int rt, int l,int r, int ql, int qr) {
    if(l > r) return 0;
    if(ql <= l && r <= qr) return sum[rt];
    ll m = l + r >>1, ans = 0;
    pushdown(rt, l, r);
    if(m >= ql) ans = ans|query(rt<<1, l, m, ql, qr);
    if(m < qr)  ans = ans|query(rt<<1|1, m+1, r,  ql, qr);
    return ans;
}

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int n, T, o, n_=1, a, b, c;
    char op[10];
    cin >> n >> T >> o;
        while(n_ < n) n_ *= 2;
        update(1, 1, n_, 1, n_, 1);
        for(int i = 0; i <o; ++i) {
            scanf("%s%d%d", op, &a, &b);
            if(a > b) swap(a, b);
            if(op[0] == 'C') {
                scanf("%d",&c);
                update(1, 1, n_, a, b, c);
            } else {
                ll ans = query(1, 1, n_, a, b), cnt = 0;
                for(;ans;ans -= ans&(-ans)) cnt++;
                printf("%lld\n", cnt);
            }
        }
    return 0;
}
