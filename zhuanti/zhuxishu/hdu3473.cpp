#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 1e6+5e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
const int N = 1e5+100;
int ls[maxn], c[maxn], rs[maxn];
int T[N];
int tot;
ll sum[maxn];
int a[N];
int b[N], cc[N];
int n, cnta;
void inithash(){
    for(int i = 1; i <= n; ++i){
        a[i] = b[i];
    }
    sort(a+1, a+1+n);
    cnta = unique(a+1, a+1+n) - a-1;
    for(int i = 1; i <= n; ++i){
        cc[i] = lower_bound(a+1, a+1+n, b[i]) - a;
    }
}
int build(int l, int r){
    int newnode = tot++;
    c[newnode] = 0;
    sum[newnode] = 0;
    if(l == r){
        ls[newnode] = rs[newnode] = 0;
        sum[newnode] = 0;
        return newnode;
    }
    int mid = (l+r) >> 1;
    ls[newnode] = build(l, mid);
    rs[newnode] = build(mid+1, r);
    return newnode;
}
int update(int rt, int pos, int l, int r){
    if(l == r){
        int newnode = tot++;
        c[newnode] = c[rt] + 1;
        sum[newnode] = sum[rt] + a[pos];
        return newnode;
    }
    int newnode = tot++;
    c[newnode] = c[rt] + 1;
    sum[newnode] = sum[rt] + a[pos];
    int mid = (l+r) >> 1;
    if(mid >= pos){
        rs[newnode] = rs[rt];
        ls[newnode] = update(ls[rt], pos, l, mid);
    }else{
        ls[newnode] = ls[rt];
        rs[newnode] = update(rs[rt], pos, mid+1, r);
    }
    return newnode;
}
ll ans, qq;
ll ql, qr, qc;
int query(int lt, int rt, int l, int r, int k){
    if(l > r) return 0;
    if(l == r){
        qq = l;
        return c[rt] - c[lt];
    }
    int mid = (l+r) >> 1;
    //pr(l);pr(r);pr(mid);prln(a[mid]);prln(c[ls[rt]] - c[ls[lt]]);prln(k);
    if(c[ls[rt]] - c[ls[lt]] < k){
        return query(rs[lt], rs[rt],  mid+1, r, k-(c[ls[rt]] - c[ls[lt]])) + c[ls[rt]] - c[ls[lt]];
    }else{
        return query(ls[lt], ls[rt], l, mid, k);
    }
}
ll exquery(int rt, int l, int r, int k){
    if(l > r) return 0;
    if(l == r){
        return -sum[rt];
    }
    int mid = (l+r) >> 1;
    if(mid >= k){
        return exquery(ls[rt], l, mid, k) + sum[rs[rt]];
    }else{
        return exquery(rs[rt], mid+1, r, k-c[ls[rt]]) - sum[ls[rt]];
    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    int t;
    int kase = 0;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &b[i]);
        }
        printf("Case #%d:\n",++kase);
        inithash();
        tot = 0;
        T[0] = build(1, n);
        for(int i = 1; i <= n; ++i){
            T[i] = update(T[i-1], cc[i], 1, cnta);
        }
        int m = 0;
        scanf("%d", &m);
        int l = 0,  r = 0;
        for(int i = 1; i <= m; ++i){
            scanf("%d%d", &l, &r);
            l++,r++;
            int k = (r-l+2)/2;
            ll kk = query(T[l-1], T[r], 1, cnta, k);
            ll ans = exquery(T[r], 1, cnta, kk) - exquery(T[l-1], 1, cnta, kk);
            ans += kk*a[qq] - (ll)(r-l+1-kk)*a[qq];
            printf("%lld\n", ans);
        }
    }
    return 0;
}
