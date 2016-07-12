
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
int sum[maxn];
void update(int rt, int l, int r, int o, int v) {
    if(l > r) return;
    if(l == r) {
        sum[rt] = v;
        return;
    }
    int m = l + r >> 1;
    if(m >= o) update(rt<<1, l, m, o, v);
    else update(rt<<1|1, m+1, r, o, v);
    sum[rt] = max(sum[rt<<1], sum[rt<<1|1]);
}
int query(int rt, int l, int r, int v) {
    if(l > r) return -1;
    if(l == r) {
        sum[rt] -= v;
        return l;
    }
    int m = l + r >>1;
    int ans;
    if(sum[rt<<1] >= v) ans = query(rt<<1, l, m, v);
    else if(sum[rt<<1|1] >= v) ans = query(rt<<1|1, m+1, r, v);
    else ans = -1;
    sum[rt] = max(sum[rt<<1], sum[rt<<1|1]);
    return ans;
}

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int n, h, w, t, x, ans;
    //cin >> t;
    t = 1;
    //while(t--) {
        while(scanf("%d%d%d", &h, &w, &n) == 3){
        h = min(h, n);
        int h_ = 1;
        while(h_ < h) h_ = h_ << 1;
        for(int i = 1; i <= h_; ++i) {
            if(i <= h) x = w;
            else x = 0;
            update(1, 1, h_, i, x);
        }
        for(int i = 0; i < n; ++i) {
            scanf("%d", &x);
            if(sum[1] < x) ans = -1;
            else ans = query(1, 1, h_, x);
            printf("%d\n", ans);
        }
    }
    return 0;
}
