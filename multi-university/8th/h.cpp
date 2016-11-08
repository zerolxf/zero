/*************************************************************************
    > File Name: h.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月11日 星期四 19时52分29秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
int add[maxn], flag[maxn];
ll sum[maxn];
int a[maxn];
void push(int rt, int l, int r, int f, int ad){
    if(f != -1){
        sum[rt] = (ll)(r-l+1)*(f);
        flag[rt] = f;
        add[rt] = 0;
        return;
    }
    if(ad){
        sum[rt] += (ll)(r-l+1)*(ad);
        add[rt] += ad;
    }
    return;
}
void pushdown(int rt, int l, int r){
    if(flag[rt] != -1){
        int mid = (l+r) >> 1;
        sum[rt<<1] = (ll)(mid-l+1)*flag[rt];
        sum[rt<<1|1] = (ll)(r-mid)*flag[rt];
        add[rt<<1] = add[rt<<1|1] = 0;
        flag[rt<<1] = flag[rt<<1|1] = flag[rt];
        return;
    }
    if(add[rt]){
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        int mid = (l+r) >> 1;
        sum[rt<<1] += (ll)(mid-l+1)*add[rt];
        sum[rt<<1|1] += (ll)(r-mid)*add[rt];
        if(flag[rt<<1] != -1) flag[rt<<1] += add[rt];
        if(flag[rt<<1|1] != -1) flag[rt<<1|1] += add[rt];

        add[rt] = 0;
    }
}
void pushup(int rt){
     sum[rt] = sum[rt<<1] + sum[rt<<1|1];
     flag[rt] = (flag[rt<<1] != flag[rt<<1|1])?-1:flag[rt<<1];
     add[rt] = 0;
}

void build(int rt, int l, int r){
    add[rt] = 0;
    flag[rt] = -1;
    if(l == r){
        sum[rt] = a[l];
        flag[rt] = a[l];
        add[rt] = 0;
        return;
    }
    int mid = (l+r) >> 1;
    build(rt<<1, l, mid);
    build(rt<<1|1, mid+1, r);
    pushup(rt);
}
void update(int rt, int l, int r, int ql, int qr, int v){
    //prln("up");
     if(ql <= l && r <= qr){
         //prln(sum[rt]);
         sum[rt] += (ll)(r-l+1)*v;
         //add[rt] += v;
         if(flag[rt] != -1) flag[rt] += v, add[rt] = 0;
         else add[rt] += v;
         //pr(l);pr(r);pr(ql);pr(qr);prln(sum[rt]);
         return;

     }
     pushdown(rt, l, r);
     int mid = (l+r) >> 1;
     if(mid >= ql) update(rt<<1, l, mid, ql, qr, v);
     if(mid < qr) update(rt<<1|1, mid+1, r, ql, qr, v);
     pushup(rt);
}
void ex_update(int rt, int l, int r, int ql, int qr){
    //prln("ex");
    if(ql <= l && r <= qr && flag[rt] != -1){
        flag[rt] = sqrt(flag[rt]+0.5);
        sum[rt] = (ll)flag[rt]*(r-l+1);
        //pr(l);pr(r);pr(ql);pr(qr);prln(sum[rt]);
        add[rt] = 0;
        return;
    }
    pushdown(rt, l, r);
    int mid = (l+r) >> 1;
    if(mid >= ql) ex_update(rt<<1, l, mid, ql, qr);
    if(mid < qr) ex_update(rt<<1|1, mid+1, r, ql, qr);
    pushup(rt);
}
ll query(int rt, int l, int r, int ql, int qr){
    //prln("qu");
    if(ql <= l && r <= qr){
        //pr(l);pr(r);pr(ql);pr(qr);prln(sum[rt]);
        return sum[rt];
    }
    pushdown(rt, l, r);
    int mid = (l+r) >> 1;
    ll ans = 0;
    if(mid >= ql) ans += query(rt<<1, l, mid, ql, qr);
    if(mid < qr) ans += query(rt<<1|1, mid+1, r, ql, qr);
    //pr(l);pr(r);pr(ql);pr(qr);prln(ans);
    return ans;
}
template <class T>
inline bool scan_d(T &ret) {
char c; int sgn;
if(c=getchar(),c==EOF) return 0; //EOF
while(c!='-'&&(c<'0'||c>'9')) c=getchar();
sgn=(c=='-')?-1:1;
ret=(c=='-')?0:(c-'0');
while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
ret*=sgn;
return 1;
}
inline void out(int x) {
if(x>9) out(x/10);
putchar(x%10+'0');
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t, n, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i){
            scan_d(a[i]);
            //scanf("%d", &a[i]);
        }
        build(1,1,n);
        int op, l, r, x;
        for(int i = 0; i < m; ++i){
            scan_d(op);
            scan_d(l);
            scan_d(r);
            //scanf("%d%d%d", &op, &l, &r);
            if(op == 1){
                scan_d(x);
                //scanf("%d", &x);
                update(1, 1,  n, l, r, x);
            }else if(op == 2){
                ex_update(1, 1, n, l, r);
            }else{
                ll ans = query(1, 1, n, l, r);
                printf("%lld\n", ans);
            }
            //pr(l);prln(r);

                //ll ans = query(1, 1, n, l, r);
                //printf("%lld\n", ans);
        }


    }

	return 0;
}
