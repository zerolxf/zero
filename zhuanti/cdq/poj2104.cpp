/*************************************************************************
	> File Name: poj2104.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月25日 星期一 09时04分44秒
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
#define pr(x)// cout << #x << " = " << x << " ";
#define prln(x) //cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
struct Bit{
    int n;
    int bit[maxn];
    void init(int _n){
        for(int i = 0; i <= n; ++i){
            bit[i] = 0;
        }
        n = _n;
    }
    void add(int pos, int num){
        for(int i = pos; i <= n; i += i&(-i)){
            bit[i] += num;
        }
    }
    int query(int pos){
        int ans = 0;
        for(int i = pos; i > 0; i -= i&(-i)){
            ans += bit[i];
        }
        return ans;
    }
}bit;
struct Q{
    int x, y;
    int k, id, type;
}q[maxn], q1[maxn], q2[maxn];
int ans[maxn];
void solve(int ql, int qr, int l, int r){
    if(ql>qr) return;
    prln("************");
    pr(ql);pr(qr);pr(l);prln(r);
    if(l == r){
        for(int i = ql; i <= qr; ++i){
            if(q[i].type == 2){
                pr(ql);pr(qr);pr(l);prln(r);
                pr(q[i].x);pr(q[i].y);prln(q[i].k);
                ans[q[i].id] = l;
                pr(q[i].id);prln(l);
            }
        }
        return;
    }
    int mid = (l + r) >> 1;
    int qcnt1 = 0, qcnt2 = 0;
    for(int i = ql; i <= qr; ++i){
        prln(i);
        if(q[i].type == 1){
            prln(q[i].type);
            pr(q[i].x);prln(mid);
            pr(ql);pr(qr);pr(l);prln(r);
            if(q[i].x <= mid){
                prln("<=mid");
                int small = bit.query(q[i].id) - bit.query(q[i].id-1);
                prln(small);
                bit.add(q[i].id, q[i].y);
                small = bit.query(q[i].id) - bit.query(q[i].id-1);
                prln(small);
                pr(q[i].id);prln(q[i].y);
                q1[qcnt1++] = q[i];
            }else{
                prln(">mid");
                q2[qcnt2++] = q[i];
            }
        }else{
            prln(q[i].type);
            int small = bit.query(q[i].y) - bit.query(q[i].x-1);
            pr(ql);pr(qr);pr(l);prln(r);
            pr(small);prln(q[i].k);
            pr(q[i].x);prln(q[i].y);
            if(small >= q[i].k){
                prln("small>=");
                q1[qcnt1++] = q[i];
            }else{
                prln("small<");
                
                q2[qcnt2] = q[i];
                q2[qcnt2++].k -= small;
            }
        }
    }
    for(int i = 0; i < qcnt1; ++i){
        if(q1[i].type == 1){
            bit.add(q1[i].id, -q1[i].y);
        }
    }
    memcpy(q+ql, q1, qcnt1*sizeof(Q));
    memcpy(q+ql+qcnt1, q2, qcnt2*sizeof(Q));

    prln("---------------");
    solve(ql, ql+qcnt1-1, l, mid);
    solve(ql+qcnt1, qr, mid+1, r);

}
int a[maxn], siz;
int b[maxn];
int gethash(int x){
    int pos = lower_bound(a, a+siz, x) - a + 1;
    return pos;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t, n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        bit.init(n);
        siz = 0;
        pr(n);prln(m);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &b[i]);
            q[siz++] = Q{b[i], 1, 0,  i, 1};
            pr(i);prln(b[i]);
        }
        int x, y, k;
        for(int i = 0; i < m; ++i){
             scanf("%d%d%d", &x, &y, &k);
             pr(i);pr(x);pr(y);prln(k);
             q[siz++] = Q{x, y, k, i, 2};
        }
        solve(0, siz-1, -INF, INF);
        for(int i = 0; i < m; ++i){
            printf("%d\n", ans[i]);
        }
    }
	return 0;
}
