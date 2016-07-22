/*************************************************************************
	> File Name: h.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月15日 星期五 19时45分35秒
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
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
int n, m;
int sum[maxn], add[maxn];
void Update_sum(int rt, int l, int r, int a){
    sum[rt] = (r-l+1)*a;
    add[rt] = a;
}
void pushdown(int rt, int l, int r){
    if(add[rt] != -1){
        int m = (l+r)>>1;
        Update_sum(rt<<1, l, m, add[rt]);
        Update_sum(rt<<1|1, m+1, r, add[rt]);
        add[rt] = -1;
    }
}
void update(int rt, int l, int r, int ql, int qr, int v){
    if(ql <= l && r <= qr){
        Update_sum(rt, l, r, v);
        return;
    }
    pushdown(rt, l, r);
    int m = (l+r)>>1;
    if(m>=ql) update(rt<<1, l, m, ql, qr, v);
    if(m<qr) update(rt<<1|1, m+1, r, ql, qr, v);
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
int ansl, ansr;
int query(int rt, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return sum[rt];
    }
    pushdown(rt, l, r);
    int m = (l+r)>>1;
    int ans = 0;
    if(m>=ql) ans+=query(rt<<1, l, m, ql, qr);
    if(m<qr) ans+=query(rt<<1|1, m+1, r, ql, qr);
    return ans;
}
void get(int rt, int l, int r, int ql, int qr, int x, int flag){
    pr(rt);pr(l);pr(r);pr(ql);pr(qr);prln(flag);
    if(l == r){
        if(sum[rt]>=1 && (flag&1)) ansl = min(ansl,l);
        if(sum[rt]>=1 && (flag&2)) ansr = max(ansr,l);
        return ;
    }
    pushdown(rt, l, r);
    int m = (l+r)>>1;
    int lnum = query(rt<<1, l, m, ql, qr);
    int rnum = query(rt<<1|1, m+1,r,ql, qr);
    pr(l);pr(m);pr(m+1);prln(r);
    pr(lnum);prln(rnum);
    if(x>lnum+rnum) x = lnum+rnum;
    if(lnum>=x){
        if(flag&3) get(rt<<1, l, m, ql, qr, x, flag&3);
    }else if(lnum==0){
        if(flag&3) get(rt<<1|1, m+1, r, ql, qr, x, flag&3);
    }else {
        if(flag&1) get(rt<<1, l, m, ql, qr, lnum, flag&1);
        if(flag&2) get(rt<<1|1, m+1, r, ql, qr, x-lnum, flag&2);
    }
    
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    int n,m;
    cin >> t;
    while(t--){
        scanf("%d%d",&n, &m);
        int op, l, r;
        int _n = 1;
        while(_n < n) _n <<= 1;
        prln(_n);
        update(1, 1, _n, 1, _n, 1);
        prln(_n);
        for(int i = 0; i < m; ++i){
            scanf("%d%d%d", &op, &l, &r);
            pr(op);pr(l);pr(r);
            if(op == 1){
                ansl = _n+1;
                ansr = 0;
                get(1, 1, _n, l+2, n, r, 3);
                prln(op);
                cout << ansl-1 << " " << ansr-1 << "\n";
            }else{
                int ans = query(1, 1, _n, l+1, r+1);
                prln(op);
                cout << ans << "\n";
                update(1, 1, _n, l+1, r+1, 1);
            }
        }
    }
	return 0;
}
