
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
const int maxn = 1e5+100;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
int sum[maxn<<2];
void update(int rt, int l, int r, int o, int v) {
    if(l == r) {
        sum[rt] = v;
        return;
    }
    //pr(rt);
    int m = l + r >> 1;
    if(m >= o) update(rt<<1, l, m, o, v);
    else update(rt<<1|1, m+1, r, o, v);
    sum[rt] = max(sum[rt<<1|1], sum[rt<<1]);
}
int query(int rt, int l, int r, int ql, int qr) {
   // pr(rt);
    if(ql <= l && r <= qr) return sum[rt];
    int ans = 0;
    int m = l + r >> 1;
    if(m >= ql) ans = query(rt<<1, l, m, ql, qr);
    if(m < qr) ans = max(ans, query(rt<<1|1, m+1, r, ql, qr));
    return ans;
}
void init(int n_) {
    n_ = n_*2;
    for(int i = 0; i <= n_;++i) sum[i] = 0;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int t, ql, qr, x, n, n_, k;
    cin >> t;
    while(t--) {
        cin >> n;
        n_ = 1;
        while(n_ < n) n_ = n_<<1;
        init(n_);
       // prln(n);
        for(int i = 1; i <=n; ++i) {
            scanf("%d", &x);
            update(1,1,n_,i,x);
        }
        cin >> k;
        //pr(k);
        for(int i = 0; i < k; ++i) {
            scanf("%d%d", &ql, &qr);
           // pr(i);
            cout << query(1, 1, n_, ql, qr) << "\n";
        }
    }
    return 0;
}
