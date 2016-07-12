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
//#define pr(x) cout << #x << " = " << x << " ";
//#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
typedef pair<int,int> Interval;
int add[maxn];
struct node{
    int preR, sufL;
    Interval sub, mid;
}sum[maxn];
void print(int rt,int l, int r) {
   // pr(rt);pr(l);prln(r);pr(sum[rt].sub.first);pr(sum[rt].sub.second);pr(sum[rt].preR);prln(sum[rt].sufL);
}
int getlen(const Interval& x) {
    return (x.second - x.first)+1;
}
Interval getmax(const Interval& x, const Interval& y) {
    int dx = getlen(x), dy = getlen(y);
    if(dx != dy) return dx > dy? x:y;
    return x;
}
void push_up(int rt,int l, int r) {
    int lson = rt<<1, rson = rt<<1|1, m = l + r >> 1;
    if(sum[lson].preR == m) sum[rt].preR = sum[rson].preR;
    else sum[rt].preR = sum[lson].preR;
    if(sum[rson].sufL == m+1) sum[rt].sufL = sum[lson].sufL;
    else sum[rt].sufL = sum[rson].sufL;
    Interval mid(sum[lson].sufL, sum[rson].preR);
    sum[rt].sub = getmax(sum[lson].sub,getmax(mid, sum[rson].sub));
}
void push(int rt, int l, int r,int v) {
    if(v) {
            sum[rt].preR = r;
            sum[rt].sufL = l;
            sum[rt].sub = Interval(l,r);
    } else {
            sum[rt].preR = l-1;
            sum[rt].sufL = r + 1;
            sum[rt].sub = Interval(r+1, l-1);
    }
}
void pushdown(int rt, int l, int r) {
    if(add[rt] != -1) {
        add[rt<<1] = add[rt<<1|1] = add[rt];
        int m = l + r >> 1;
        push(rt<<1, l, m, add[rt]);
        push(rt<<1|1, m+1, r, add[rt]);
        push_up(rt, l, r);
        add[rt] = -1;
    }
}
void update(int rt, int l, int r, int ql, int qr, int v) {
    if(l > r) return ;
    if(ql <= l && r <= qr) {
        add[rt] = v;
        push(rt, l, r, v);
        return;
    }
    pushdown(rt, l, r);
    int m = l + r >> 1;
    if(m >= ql) update(rt<<1, l, m, ql, qr, v);
    if(m < qr) update(rt<<1|1, m+1, r, ql, qr, v);
    push_up(rt, l, r);
    //print(rt,l,r);
}
int query(int rt, int l, int r,int v) {
   // cout << "\nquery\n" ;
    //pr(l);pr(r);prln(v);
    if(l == r) return l;
    pushdown(rt, l, r);
    int m = l + r >> 1, lson = rt<<1, rson = rt<<1|1;
    int ans;
    int len = getlen(sum[rt].sub),llen = getlen(sum[lson].sub), rlen = getlen(sum[rson].sub);
   // prln(rt);print(rt,l,r);
   // prln(lson);print(lson,l,m);
    ////prln(rson);print(rson,m+1,r);
   // pr(v);pr(len);pr(llen);prln(rlen);
    if(len < v) return 0;
    if(llen >= v) return query(rt<<1, l, m, v);
    if(rlen < v) return sum[rt].sub.first;
    ans = query(rt<<1|1, m+1, r, v);
   // prln(ans);
    ans = min(ans, sum[rt].sub.first);

    return ans;
}

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int n, n_, k, v, x, y, op, ans;
    cin >> n >> k;
        n_ = 1;
        while(n_ < n) n_ *= 2;
        update(1, 1, n_, 1, n, 1);
        //pr(n);prln(n_);
        update(1, 1, n_, n+1, n_, 0);
        //print(1);
        for(int i = 0; i < k; ++i) {
            scanf("%d%d", &op, &x);
            if(op == 1) {
                ans = query(1, 1, n_, x);
                cout << ans << "\n";
                if(ans) update(1, 1, n_, ans, ans+x-1, 0);
            } else {
                scanf("%d", &y);
                update(1, 1, n_, x, y+x-1, 1);
            }
        }

    return 0;
}
