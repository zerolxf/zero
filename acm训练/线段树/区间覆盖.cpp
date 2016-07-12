
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
#include<set>
using namespace std;
const int maxn = 6e5+100;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
int  add[maxn];
ll a[40000], b[40000], c[40000], ID[40099];
void pushdown(int rt, int l, int r) {
    if(add[rt]) {
        int m = l + r >> 1;
        add[rt<<1|1] = add[rt<<1] = add[rt];
        add[rt] = 0;
    }
}
void update(int rt, int l, int r, int ql, int qr, int v) {
    if(l > r) return;
    if(ql <= l && r <= qr) {
        add[rt] = v;
        return;
    }
    int m = l + r >>1;
    pushdown(rt, l, r);
    if(m >= ql) update(rt<<1, l, m, ql, qr, v);
    if(m < qr)  update(rt<<1|1, m+1, r, ql, qr, v);
}
int query(int rt, int l, int r, int o) {
   // if(l > r) return 0;
    if(l == r) return add[rt];
    int m = l + r >> 1;
    pushdown(rt, l, r);
    if(m >= o) return query(rt<<1, l, m, o);
    if(m < o) return query(rt<<1|1, m+1, r, o);
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int n, l, r, x, t;
    set<int> st;
    cin >> t;
    while(t--) {
        cin >> n;
        st.clear();
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%lld%lld", a+i, b+i);
            ID[cnt++] = a[i];ID[cnt++] = b[i];
        }
        sort(ID, ID + cnt);
        int size = unique(ID, ID + cnt) - ID;
        cnt = 0;
        int n_ = 1;
        while(n_ < size) n_ = n_ <<1;
        update(1, 1, n_, 1, size, -1);
        for(int i = 0; i < n; ++i) {
            l = lower_bound(ID, ID + size, a[i]) - ID + 1;
            r = lower_bound(ID, ID + size, b[i]) - ID + 1;
            update(1, 1, n_, l, r, i+1);
        }
        for(int i = 1; i <= size; ++i) {
            x = query(1, 1, n_, i);
         //   pr(i);prln(x);
            if(x == -1) continue;
            st.insert(x);
        }
        cout << st.size() << "\n";
    }
    return 0;
}
