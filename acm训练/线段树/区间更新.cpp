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
const int maxn = 1e6+100;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
int num[maxn], add[maxn], sum[maxn];
void pushdown(int rt,int l, int r) {
    if(add[rt]) {
        int m = r +l >>1;
        sum[rt<<1] = (m - l + 1)*add[rt];
        add[rt<<1] = add[rt];
        add[rt<<1|1] = add[rt];
        sum[rt<<1|1] = (r - m)*add[rt];
        add[rt] = 0;
    }
}
void update(int rt, int v, int l, int r, int ql, int qr) {
    if(l > r) return;
    if(ql <= l && r <= qr) {
        add[rt] = v;
        sum[rt] = (r - l + 1)*add[rt];
        return;
    }
    pushdown(rt, l, r);
    int m = l + r >> 1;
    if(m >= ql) update(rt<<1, v, l, m, ql, qr);
    if(m < qr) update(rt<<1|1, v, m+1, r, ql, qr);
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
int query(int rt, int l, int r, int ql, int qr) {
    if(l > r) return 0;
    if(ql <= l && r <= qr) return sum[rt];
    pushdown(rt, l, r);
    int m = l + r >>1;
    int ans = 0;
    if(m >= ql) ans += query(rt<<1, l , m, ql, qr);
    if(m < qr) ans += query(rt<<1|1, m+1, r, ql, qr);
    return ans;
}
void init(int n) {
    n*=2;
    for(int i = 0; i <= n; ++i) sum[i] = add[i] = 0;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int n, t, k, l, r, x;
    cin >> t;
    int kase = 0;
    while(t--) {
        cin >> n >> k;
        int n_ = 1;
        while(n_ < n) n_ *=2;
        init(n_);
        update(1,1,1,n_,1,n);
        for(int i = 0; i < k; ++i) {
            scanf("%d%d%d", &l, &r, &x);
            update(1,x,1,n_,l,r);
        }
        int ans = query(1,1,n_,1,n);
        printf("Case %d: The total value of the hook is %d.\n", ++kase, ans);
    }
    return 0;
}
