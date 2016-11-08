
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
const int maxn = 5e5+100;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
#define lson 1, m, rt<<1
#define rson m+1, r, rt<<1|1
#define root 1, n_, 1
typedef pair<int, int> Interval;
int a[maxn];
struct node {
    int l,r;
    int preR, sufL;
    Interval sub;
}dat[maxn<<1];
int sum(const Interval& x) {
    return a[x.second] - a[x.first - 1];
}
Interval getmax(const Interval& x, const Interval& y) {
    int sx = sum(x), sy = sum(y);
    if(sx != sy) return sx > sy? x:y;
    int dx = x.second - x.first, dy = y.second - y.first;
    if(dx != dy) return dx < dy? x:y;
    return x < y? x:y;
}

node pushup(const node& x, const node& y) {
    node ans;
    ans.l = x.l; ans.r = y.r;
    ans.preR = getmax(Interval(x.l,x.preR), Interval(x.l,y.preR)).second;
    ans.sufL = getmax(Interval(x.sufL,y.r), Interval(y.sufL, y.r)).first;
    ans.sub =  getmax(Interval(x.sufL,y.preR), getmax(x.sub,y.sub));
    return ans;
}
void update(int rt, int l, int r) {
    //if(l > r) return;
    if(l == r) {
        dat[rt].l = dat[rt].r = l;
        dat[rt].preR = dat[rt].sufL = l;
        dat[rt].sub = Interval(l,l);
        return;
    }
    int m = l + r >> 1;
    update(rt<<1, l, m);
    update(rt<<1|1, m+1, r);
    dat[rt] = pushup(dat[rt<<1], dat[rt<<1|1]);
}
node query(int rt, int ql, int qr) {
    if(ql <= dat[rt].l && dat[rt].r <= qr) {
        return dat[rt];
    }
    node ans;
    int m = dat[rt].l + dat[rt].r >> 1;
    if(ql <= m && m < qr) return pushup(query(rt<<1,ql,qr), query(rt<<1|1,ql,qr));
    else if(ql <= m) ans = query(rt<<1,ql,qr);
    else if(m < qr) ans = query(rt<<1|1, ql, qr);
    return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int n, m, len;
    while(cin >> n >> m) {
        len = m + n;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a+i);
            a[i+n] = a[i];
        }
        Interval ans(1,1);
        n <<= 1;
        for(int i = 1; i <= n; ++i) a[i] += a[i-1];
        update(1, 1, n);
        n >>=1;
        for(int i = 1; i <= n; ++i) ans = getmax(ans, query(1, i, i+m-1).sub);
        cout << sum(ans) << " "<< (ans.first-1)%n+1 << " " << (ans.second-1)%n+1 << "\n";
    }
    return 0;
}
