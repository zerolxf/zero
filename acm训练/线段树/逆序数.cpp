
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
const int INF = 0x7f7f7f7f;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
int add[maxn], sum[maxn], num[maxn], a[maxn];
void pushdown(int rt, int l, int r) {
    if(add[rt]) {
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        int m = l + r >>1;
        sum[rt<<1] += (m - l +1)*add[rt<<1];
        sum[rt<<1|1] += (r - m)*add[rt<<1|1];
        add[rt] = 0;
    }
}
void update(int rt, int v, int l, int r, int o) {
    if(l > r) return;
    if(l == r) {
        sum[rt] = v;
        return;
    }
    int m = l + r >> 1;
    if(o <= m) update(rt<<1, v, l, m, o);
    else update(rt<<1|1, v, m+1, r, o);
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

int query(int rt, int l, int r, int ql, int qr) {
    if(l > r) return 0;
    if(ql <= l && r <=qr) return sum[rt];
    int m = l + r >> 1;
    int ans = 0;
    if(m >= ql) ans += query(rt<<1, l, m, ql, qr);
    if(m < qr) ans += query(rt<<1|1,m+1,r,ql,qr);
    return ans;
}
void print(int n_) {
    for(int i = 0; i <= n_*2;++i){
        pr(i);prln(sum[i]);
    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int n, x, id;
    map<int,int> mp;
    while(cin >> n) {
        mp.clear();
        int n_ = 1, ans = 0, ans1 = 0;
        while(n_ < n) n_ *=2;
        for(int i = 0; i <= n_*2; ++i) add[i] = sum[i] = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &x);
            num[i] = a[i] = x;
        }
        sort(num+1, num +n+1);
        for(int i = 1; i <= n; ++i) {
            mp[num[i]] = i;
        }
        for(int i = 1; i <= n; ++i) {
            id = mp[a[i]];
            ans1 += query(1,1,n_,id,n);
            update(1,1,1,n_,id);
        }
        ans = ans1;
        for(int i = 1; i <= n; ++i) {
            id = mp[a[i]];
           ans1 += (n-id-id+1);
           ans = min(ans, ans1);
        }
        cout << ans << endl;
    }

    return 0;
}
