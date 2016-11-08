/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月01日 星期一 21时19分36秒
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
ll sum[maxn], add[maxn];
int flag[maxn];
struct Q{
    int x, y, type;
    int k, id;
}q[maxn], g[maxn], f[maxn];
void pushdown(int rt, int l, int r){
    if(flag[rt] == -1) {
        add[rt<<1] = 0;
        add[rt<<1|1] = 0;
        sum[rt<<1] = sum[rt<<1|1] = 0;
        flag[rt<<1|1] = flag[rt<<1] = -1;
        flag[rt] = 0;
    }
    if(add[rt]){
        int m = (l+r)>>1;
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        sum[rt<<1] += (m-l+1)*add[rt];
        sum[rt<<1|1] += (r-m)*add[rt];
        add[rt] = 0;
    }
}
void pushup(int rt){
    sum[rt] = sum[rt<<1|1] + sum[rt<<1];
}
void update(int rt, int l, int r, int ql, int qr, int v){
    //pr(l);pr(r);pr(ql);pr(qr);prln(v);
    if(ql <= l && r <= qr){
        if(v == -1){
            flag[rt] = -1;
            add[rt] = 0;
            sum[rt] = 0;
        }else{
            add[rt] += v;
            sum[rt] += (r-l+1)*v;
        }
        return;
    }
    pushdown(rt, l, r);
    int m = (l+r) >> 1;
    if(m >= ql) update(rt<<1, l, m, ql, qr, v);
    if(m < qr) update(rt<<1|1, m+1, r, ql, qr, v);
    pushup(rt);
}
ll query(int rt, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        //pr(l);pr(r);prln(sum[rt]);
        return sum[rt];
    }
    pushdown(rt, l, r);
    int m = (l+r) >> 1;
    ll ans = 0;
    //pr(rt);pr(l);pr(r);pr(ql);prln(qr);
    //pr(ans);
    if(m >= ql) ans += query(rt<<1, l, m, ql, qr);
    //pr(ans);
    if(m < qr) ans += query(rt<<1|1, m+1, r, ql, qr);
    //prln(ans);
    return ans;
}
int ans[maxn], a[maxn];
//int cnta;
//int getid(int x){
    //return lower_bound(a, a+cnta, x) - a + 1;
//}
int _n;
void solve(int l, int r, int ql, int qr){
    if(l>r||ql>qr) return;
    //prln("******************");
    //pr(l);pr(r);pr(ql);prln(qr);
    if(l == r){
        for(int i = ql; i <= qr; ++i){
            if(q[i].type == 2){
                ans[q[i].id] = l;
            }
        }
        return;
    }
    int mid = (l+r) >> 1;
    update(1, 1, _n, 1, _n, -1);
    int gg = 0, ff = 0;
    for(int i = ql; i <= qr; ++i){
        if(q[i].type == 1){
            //pr(q[i].type);pr(q[i].x);pr(q[i].y);prln(q[i].k);
            if(q[i].k > mid){
                //int cnt = query(1, 1, _n, q[i].x, q[i].y);
                //prln(cnt);
                update(1, 1, _n, q[i].x, q[i].y, 1);
                //cnt = query(1, 1, _n, q[i].x, q[i].x);
                //prln(cnt);
                g[gg++] = q[i];
            }else{
                f[ff++] = q[i];
            }
        }else{
            //pr(q[i].id);pr(q[i].type);pr(q[i].x);pr(q[i].y);prln(q[i].k);
            ll cnt = query(1, 1, _n, q[i].x, q[i].y);
            //prln(cnt);
            if(q[i].k <= cnt){
                g[gg++] = q[i];
                //prln(gg);
            }else{
                q[i].k -= cnt;
                f[ff++] = q[i];
                //pr(q[i].k);
                //prln(ff);
            }
        }
    }

    memcpy(q+ql, f, ff*sizeof(Q));
    memcpy(q+ql+ff, g, gg*sizeof(Q));

    solve(l, mid, ql, ql+ff-1);
    solve(mid+1, r, ql+ff, qr);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, m;
    while(cin >> n >> m){
        _n = 1;
        while(_n < n) _n <<= 1;
        update(1, 1, _n, 1, _n, -1);
        int qcnt = 0;
        //int x, y, k, id, type;
        for(int i = 0; i < m; ++i){
            scanf("%d%d%d%d", &q[i].type, &q[i].x, &q[i].y, &q[i].k);
            if(q[i].type == 2){
                q[i].id = qcnt++;
            }
        }
        solve(-60000, 60000, 0, m-1);
        for(int i = 0; i < qcnt; ++i){
            printf("%d\n", ans[i]);
        }

    }
    //int x = 2500000000;
    //cout<<x<<"\n";


	return 0;
}
