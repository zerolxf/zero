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
const int maxn = 2e5+1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int sum[maxn*4], add[maxn*4];
void pushdown(int rt, int l, int r){
    if(add[rt]){
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        int mid = (l+r) >> 1;
        sum[rt<<1] += (mid-l+1)*add[rt];
        sum[rt<<1|1] += (r-mid)*add[rt];
        add[rt] = 0;
    }
}
void update(int rt, int l, int r, int ql, int qr, int v){
    if(ql <= l && r <= qr){
        sum[rt] += (r-l+1)*v;
        add[rt] += v;
        return;
    }
    pushdown(rt,l,r);
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
const int N = 2e5+100;
typedef pair<int,int> P;
//vector<int> A[N*2], R[N*2];
//vector<P> Q[N*2];
int x[maxn], y[maxn],  x1[N];
int x2[N], y2[N];
int yy[N];
int heada[N], nxta[N], toa[N], edgenuma;
void addedgea(int u, int v){
    nxta[edgenuma] = heada[u];
    toa[edgenuma] = v;
    heada[u] = edgenuma++;
}
int headr[N], nxtr[N], tor[N], edgenumr;
void addedger(int u, int v){
    nxtr[edgenumr] = headr[u];
    tor[edgenumr] = v;
    headr[u] = edgenumr++;
}

int headq[N], nxtq[N], edgenumq;
P toq[N];
void addedgeq(int u, P v){
    nxtq[edgenumq] = headq[u];
    toq[edgenumq] = v;
    headq[u] = edgenumq++;
}

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
        edgenuma = edgenumq = edgenumr = 0;
        rep(i,n){
            scanf("%d%d%d%d", &x1[i], &yy[i], &x2[i], &y2[i]);
            x[cntx++] = x1[i];
            x[cntx++] = x2[i];
            y[cnty++] = yy[i];
            y[cnty++] = y2[i];
        }
        sort(x, x+cntx);
        sort(y, y+cnty);
        cntx = unique(x, x+cntx) - x;
        cnty = unique(y, y+cnty) - y;
        for(int i = 0; i <= cntx; ++i){
            heada[i] = headq[i] = headr[i] = -1;
        }
        rep(i,n){
            if(x1[i] == x2[i]){
                int pos = lower_bound(x,x+cntx,x1[i])-x+1;
                int yid1 = lower_bound(y,y+cnty,yy[i])-y+1;
                int yid2 = lower_bound(y,y+cnty,y2[i])-y+1;
                if(yid1>yid2) swap(yid1,yid2);
                addedgeq(pos, P(yid1,yid2));
                //Q[pos].push_back(P(yid1, yid2));
            }else{
                int pos = lower_bound(y,y+cnty,yy[i])-y+1;
                int xid1 = lower_bound(x,x+cntx,x1[i])-x+1;
                int xid2 = lower_bound(x,x+cntx,x2[i])-x+1;
                if(xid1>xid2) swap(xid1,xid2);
                addedgea(xid1, pos);
                addedger(xid2, pos);
                //A[xid1].push_back(pos);
                //R[xid2].push_back(pos);
            }
        }
        ll ans = 0;
        int _n = 1;
        while(_n < cnty) _n <<= 1;

        for(int i = 0; i <= _n*2; ++i){
            sum[i] = add[i] = 0;
        }
        for(int i = 1; i <= cntx; ++i){
            for(int j = heada[i]; ~j; j = nxta[j]){
                int pos = toa[j];
                //pr("A");pr(i);pr(j);prln(pos);
                update(1, 1, _n, pos, pos, 1);
            }
            for(int j = headq[i]; ~j; j = nxtq[j]){
                int l = toq[j].first, r = toq[j].second;
                //pr("Q");pr(i);pr(j);pr(l);prln(r);
                ans += query(1, 1, _n, l, r);
            }
            for(int j = headr[i]; ~j; j = nxtr[j]){
                int pos = tor[j];
                //pr("R");pr(i);pr(j);prln(pos);
                update(1, 1, _n, pos, pos, -1);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

