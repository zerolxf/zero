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
const int maxn = 4e5+1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int sum[maxn], add[maxn];
void pushdown(int rt, int l, int r){
    if(add[rt]){
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        int mid = (l+r) >> 1;
        sum[rt<<1] += (mid-l+1);
        sum[rt<<1|1] += (r-mid);
        add[rt] = 0;
    }
}
void update(int rt, int l, int r, int ql, int qr, int v){
    if(ql <= l && r <= qr){
        sum[rt] += (r-l+1)*v;
        add[rt] += v;
        return;
    }
    int mid = (l+r) >> 1;
    if(mid >= ql) update(rt<<1, l, mid, ql, qr, v);
    if(mid < qr) update(rt<<1|1, mid+1, r, ql, qr, v);
    sum[rt]  = sum[rt<<1] + sum[rt<<1|1];
}
int query(int rt, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return sum[rt];
    }
    pushdown(rt, l, r);
    int mid = (l+r) >> 1;
    int ans = 0;
    if(mid >= ql) ans += query(rt<<1, l, mid, ql, qr);
    if(mid < qr) ans += query(rt<<1|1, mid+1, r, ql, qr);
    return ans;
}
typedef pair<int,int> P;
vector<int> A[maxn], R[maxn];
vector<P> Q[maxn];
int x[maxn], y[maxn],  x1[maxn], y1[maxn], x2[maxn], y2[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    int t, n;
    scanf("%d", &t);
    int cntx = 0, cnty = 0;
    while(t--){
        scanf("%d", &n);
        cntx = cnty = 0;
        for(int i = 0; i < maxn; ++i){
            Q[i].clear();
            A[i].clear();
            R[i].clear();
        }
        rep(i,n){
            scanf("%d%d%d%d", &x1[i], &y1[i],&x2[i],&y2[i]);
            x[cntx++] = x1[i];
            x[cntx++] = x2[i];
            y[cnty++] = y1[i];
            y[cnty++] = y2[i];
        }
        sort(x, x+cntx);
        sort(y, y+cnty);
        cntx = unique(x, x+cntx) - x;
        cnty = unique(y, y+cnty) - y;
        rep(i,n){
            if(x1[i] == x2[i]){
                int pos = lower_bound(x,x+cntx,x1[i])-x+1;
                int yid1 = lower_bound(y,y+cnty,y1[i])-y+1;
                int yid2 = lower_bound(y,y+cnty,y2[i])-y+1;
                if(yid1>yid2) swap(yid1,yid2);
                Q[pos].push_back(P(yid1, yid2));
            }else{
                int pos = lower_bound(y,y+cnty,y1[i])-y+1;
                int xid1 = lower_bound(x,x+cntx,x1[i])-x+1;
                int xid2 = lower_bound(x,x+cntx,x2[i])-x+1;
                if(xid1>xid2) swap(xid1,xid2);
                A[xid1].push_back(pos);
                R[xid2].push_back(pos);
            }
        }
        ll ans = 0;
        int _n = 1;
        while(_n < cnty) _n <<= 1;
        for(int i = 0; i <= _n*2; ++i){
            sum[i] = add[i] = 0;
        }
        for(int i = 1; i <= cntx; ++i){
            for(int j = 0; j <= A[i].size(); ++j){
                int pos = A[i][j];
                update(1, 1, _n, pos, pos, 1);
            }
            for(int j = 0; j <= Q[i].size(); ++j){
                int l = Q[i][j].first, r = Q[i][j].second;
                ans += query(1, 1, _n, l, r);
            }
            for(int j = 0; j <= R[i].size(); ++j){
                int pos = R[i][j];
                update(1, 1, _n, pos, pos, -1);
            }

        }
    }
    return 0;
}
