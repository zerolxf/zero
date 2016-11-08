
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
const int INF = 0x3f3f3f3f;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
int maxv[maxn*2];
int n;
void push_up(int rt) {
    maxv[rt] = max(maxv[rt<<1], maxv[rt<<1|1]);
}
void update(int o, int v,int l,int r,int rt) {
   // prln(o);
    if(l == r) {
        maxv[rt] = v;
     //   push_up(rt);
        return;
    }
    if(l > r) return;
    int m = l + r >> 1;
    if(o <= m) update(o, v, l, m, rt<<1);
    else update(o, v, m+1, r, rt <<1|1);
    push_up(rt);
}
void init(int n) {
   int n_ = 1;
   while(n_ < n) n_ = n_ * 2;
   for(int i = 0; i < n_; ++i) maxv[i] = 0;

}
void build(int l, int r, int rt) {
    if(l > n) return;
   // pr(l);pr(r);prln(rt);
    if(l == r) {
        int x;
        scanf("%d", &x);
        maxv[rt] = x;
      //  push_up(rt>>1);
        //pr(rt);prln(x);
        return;
    }
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m+1, r, rt<<1|1);
    push_up(rt);
}
int query(int L, int R, int l, int r, int rt) {
   // prln(L);
    if(l > r) return 0;
    if(L <= l && r <= R) {
        return maxv[rt];
    }
    int m = l + r >> 1;
    int ans = 0;
    if(m >= L){
        ans = query(L, R, l, m, rt<<1);
       // pr(rt*2);prln(ans);
    }

    if(R > m){
            int tt = query(L, R, m+1, r, rt<<1|1);
        ans = max(ans, tt);
      //  pr(rt*2+1);prln(tt);
    }
    return ans;
}
void print(int n) {
    for(int i = 1; i <= n*3; ++i) {
        pr(i);prln(maxv[i]);
    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
   int k;
    while(cin >> n) {
        cin >> k;
        init(n);
        int n_ = 1;
        while(n_ < n) n_ = n_ *2;
        build(1, n_, 1);
        int  b, c;
        char a[10];
        while(k--) {
            scanf("%s%d%d", &a, &b, &c);
            if(a[0] == 'U') {
                update(b, c, 1, n_, 1);
            } else {
                if(b >= c) swap(b, c);
               // pr(b);prln(c);
                int ans1 = query(b, c, 1, n_, 1);
              //  int ans2 = query(1, b, 1, n_, 1);
               // prln(ans2);
              //  ans2 = max(ans2, query(c, n, 1, n_, 1));
               // prln(ans2);
             //   int ans = min(ans1, ans2);
                printf("%d\n", ans1);
               // print(n);
            }
        }
    }
    return 0;
}
