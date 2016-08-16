/*************************************************************************
	> File Name: g.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月18日 星期一 14时21分10秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 3e6+100;
const int INF = 0x3f3f3f3f;
int a[maxn], use[maxn];
int T[maxn], n, m, tot;
int c[maxn];
int lson[maxn], rson[maxn];
int h[maxn];
void inithash(){
    sort(h, h+m);
    m = unique(h, h+m) -h;
}
int gethash(int x){
    int pos = lower_bound(h, h+m, x) - h;
    return pos;
}
int update(int root, int pos, int val){
    int l = 0, r = m-1;
    int newnode = tot++, tmp = newnode;
    c[newnode] = c[root] + val;
    while(l < r){
        int mid = (l+r) >> 1;
        if(pos <= mid){
            lson[newnode] = tot++; rson[newnode] = rson[root];
            newnode = lson[newnode]; root = lson[root];
            r = mid;
        }else{
            rson[newnode] = tot++; lson[newnode] = lson[root];
            newnode = rson[newnode]; root = rson[root];
            l = mid+1;
        }
        c[newnode] =c[root] + val;
    }
    return tmp;
}
int build(int l, int r){
     int root = tot++;
     if(l == r) return root;
     int mid = (l + r) >> 1;
     build(l, mid);
     build(mid+1, r);
     return root;
}
int lowbit(int x){
    return x&(-x);
}
void add(int x, int pos, int val){
    for(int i = x; i <= n; i += lowbit(i)){
        T[i] = update(T[i], pos, val);
    }
}
int sum(int x){
    int ret = 0;
    for(int i = x; i; i -= lowbit(i)){
        ret += c[lson[use[i]]];
    }
    return ret;
}
int query(int lr, int rr, int k){
    int l = 0, r = m-1;
    for(int i = lr-1; i; i -= lowbit(i)) use[i] = T[i];
    for(int i = rr; i; i -= lowbit(i)) use[i] = T[i];
    while(l < r){
        int tmp = sum(rr) - sum(lr-1);
        int mid = (l+r) >> 1;
        if(tmp >= k){
            r = mid;
            for(int i = lr-1; i; i-= lowbit(i)) use[i] = lson[use[i]];
            for(int i = rr; i; i -= lowbit(i)) use[i] = lson[use[i]];
            
        }else{
            l = mid+1;
            k -= tmp;
            for(int i = lr-1; i; i-= lowbit(i)) use[i] = rson[use[i]];
            for(int i = rr; i; i -= lowbit(i)) use[i] = rson[use[i]];
        }
    }
    return l;
}
void inittree(){
    T[0] = build(0, m-1);
    for(int i = 1; i <= n; ++i){
        T[i] = T[0];
    }
    for(int i = 1; i <= n; ++i){
        add(i, gethash(a[i]), 1);
    }
}
struct Question{
    int op, l, r, k;
    Question(){}
    Question(int _op, int _l, int _r, int _k){
        op = _op;
        l = _l;
        r = _r;
        k = _k;
    }
}Q[123456];
template<class TT>
inline bool read(TT &n)
{
    TT x = 0, tmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
int main(){
#ifdef LOCAL
freopen("/home/zeroxf/桌面/in.txt","r",stdin);
//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t = 1;
    int q;
    //scanf("%d", &t);
    while(scanf("%d", &n) != EOF){
        tot = 0; m = 0;
        //scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; ++i){
            //scanf("%d", &a[i]);
            read(a[i]);
            h[m++] = a[i];
        }
        scanf("%d", &q);
        int  l, r, k;
        int op;
        for(int i = 0; i < q; ++i){
            read(op);
            if(op == 2){
                //scanf("%d%d%d", &l, &r, &k);
                read(l);read(r);read(k);
                Q[i] = Question(0, l, r, k);
            }else{
                //scanf("%d%d", &l, &k);
                read(l);read(k);
                Q[i] = Question(1, l, 0, k);
                h[m++] = k;
            }
        }
        inithash();
        inittree();
        for(int i = 0; i < q; ++i){
            if(Q[i].op == 0){
                printf("%d\n", h[query(Q[i].l, Q[i].r, Q[i].k)]);
            }else{
                add(Q[i].l, gethash(a[Q[i].l]), -1);
                add(Q[i].l, gethash(Q[i].k), 1);
                a[Q[i].l] = Q[i].k;
            }
        }

    }
    return 0;
}
