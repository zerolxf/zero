/*************************************************************************
    > File Name: d.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月09日 星期二 08时55分07秒
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
const int maxn = 3e6+100+5e5;
const int INF = 0x3f3f3f3f;
ll c[maxn];
int ls[maxn], rs[maxn];
ll add[maxn];
int tot;
int a[123456];
int newnode(int rt){
    int tmp = tot++;
    ls[tmp] = ls[rt];
    rs[tmp] = rs[rt];
    c[tmp] = c[rt];
    add[tmp] = add[rt];
    return tmp;
}
int build(int l, int r){
    if(l>r) return 0;;
    int root = tot++;
    if(l<r){
        int mid = (l+r) >> 1;
        ls[root] = build(l, mid);
        rs[root] = build(mid+1, r);
        c[root] = c[ls[root]] + c[rs[root]];
        add[root] = 0;
    }else{
        c[root] = a[l];
        add[root] = 0;
        ls[root] = rs[root] = 0;
    }
    return root;
}
//int build(int l, int r){
    //if(l>r) return 0;;
    //int rt = tot++;
    //if(l != r){
        //int mid = (l+r) >> 1;
        //ls[rt] = build(l, mid);
        //rs[rt] = build(mid+1, r);
        //add[rt] = 0;
        //c[rt] = c[ls[rt]] + c[rs[rt]];
    //}else{
        //c[rt] = a[l];
        //add[rt] = 0;
        //ls[rt] = rs[rt] = 0;
    //}
    //return rt;
//}
int n;
int Update(int rt, int l, int r, int v){
    int nt = tot++;
    add[nt] = add[rt] + v;
    c[nt] = c[rt] + 1ll*(r-l+1)*v;
    ls[nt] = ls[rt];
    rs[nt] = rs[rt];
    return nt;
}
int update(int rt, int l, int r, int ql, int qr, int v){
    if(l>r) return 0;
    if(ql == l && r == qr){
        //int nt = newnode(rt);
        //add[nt] += v;
        //c[rt] += (ll)(qr-ql+1)*v;

        return Update(rt, l, r, v);
    }
    int mid = (l+r)>>1;
    int nt = tot++;
    ls[nt] = ls[rt], rs[nt] = rs[rt];
    add[nt] = add[rt];
    c[nt] = c[rt];
    if(mid >= qr) ls[nt] = update(ls[rt], l, mid, ql, qr, v);
    else if(mid < ql) rs[nt] = update(rs[rt], mid+1, r, ql, qr, v);
    else{
        ls[nt] = update(ls[rt], l, mid, ql, mid, v);
        rs[nt] = update(rs[rt], mid+1, r, mid+1, qr, v);
    }
    c[nt] += 1ll*(qr-ql+1)*v;
    return nt;
}
//int update(int rt, int l, int r, int ql, int qr, int v){
    //if(l>r) return 0;
    //int nt = newnode(rt);
    //c[nt] += 1ll*(qr-ql+1)*v;
    //if(ql == l && r == qr){
        //add[nt] += v;
        //return nt;
    //}
    //int mid = (l+r)>>1;
    //if(mid >= qr) ls[nt] = update(ls[rt], l, mid, ql, qr, v);
    //else if(mid < ql) rs[nt] = update(rs[rt], mid+1, r, ql, qr, v);
    //else{
        //ls[nt] = update(ls[rt], l, mid, ql, mid, v);
        //rs[nt] = update(rs[rt], mid+1, r, mid+1, qr, v);
    //}
    //return nt;
//}
ll query(int rt, int l, int r, int ql, int qr){
    if(l>r) return 0;
    if(ql == l && r == qr){
        return c[rt];
    }
    int mid = (l+r) >> 1;
    ll ans = 0;
    if(mid >= qr) {
        ans += query(ls[rt], l, mid, ql, qr);
    }
    else if(mid < ql) {
        ans += query(rs[rt], mid+1, r, ql, qr);
    }else {
        ans += query(ls[rt], l, mid, ql, mid);
        ans += query(rs[rt], mid+1, r, mid+1, qr);
    }
    ans += 1ll*(qr-ql+1)*add[rt];
    return ans;
}
const int N = 2e5+100;
int T[N];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int m;
    int kase = 0;
    while(scanf("%d%d", &n, &m) != EOF){
        tot = 0;
        //if(kase++) printf("\n");
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        T[0] = build(1, n);
        int l, r, t, v;
        char op[10];
        int nowt = 0;
        for(int i = 0; i < m; ++i){
            scanf("%s", op);
            if(op[0] == 'C'){
                nowt++;
                scanf("%d%d%d", &l, &r, &v);
                T[nowt] = update(T[nowt-1], 1, n, l, r, v);
            }else if(op[0] == 'Q'){
                scanf("%d%d", &l, &r);
                ll ans = query(T[nowt], 1, n, l, r);
                printf("%lld\n", ans);
            }else if(op[0] == 'H'){
                scanf("%d%d%d", &l, &r, &t);
                ll ans = query(T[t], 1, n, l, r);
                printf("%lld\n", ans);
            }else{
                scanf("%d", &t);
                nowt = t;
            }
        }
    }
	return 0;
}
