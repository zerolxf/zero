
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
const int maxn = 6e5+100;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
ll mod;
ll sum[maxn];
void update(int rt, int l, int r, int ql, int qr, ll o) {
    if(l > r) return;
    if(l ==r) {
        sum[rt] = o;
        return;
    }
    int m = l + r >> 1;
    if(m >= ql) update(rt<<1, l, m, ql, qr, o);
    if(m < qr) update(rt<<1|1, m+1, r, ql, qr, o);
    sum[rt] = (sum[rt<<1]*sum[rt<<1|1])%mod;
}
ll query(int rt, int l, int r, int ql, int qr) {
    if(l > r) return 1;
    if(ql <= l && r <= qr) return sum[rt];
    int m = l + r >> 1;
    ll ans = 1;
    if(m >= ql) ans = query(rt<<1, l, m, ql, qr);
    if(m < qr) ans = (ans*query(rt<<1|1, m +1, r, ql, qr))%mod;
    return ans%mod;
}

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int n, op, t, kase = 0;
    ll x, ans;
    cin >> t;
    while(t--) {
        printf("Case #%d:\n", ++kase);
        scanf("%d%lld", &n, &mod);
        int n_ = 1;
        while(n_ < n) n_ *=2;
        for(int i = 1; i <= n; ++i) {
            scanf("%d%lld", &op, &x);
            if(op == 1) {
                update(1, 1, n_, i, i, x);
                ans = query(1, 1, n_, 1, i);
            } else {
                update(1, 1, n_, x, x, 1);
                update(1, 1, n_, i, i, 1);
                ans = query(1, 1, n_, 1, i);
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
