/*************************************************************************
    > File Name: 1766.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月31日 星期一 14时42分59秒
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
#include <ctime>


using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define repp(i,n,x) for(int i =x; i < n+x; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
int dp[maxn][30];
int dis[maxn];
struct Node{
    int l, r, dis;
    Node(){}
    Node(int _l, int _r){
        l = _l, r = _r;
    }

}node[maxn];
int head[maxn], to[maxn], nxt[maxn], cost[maxn];
int dep[maxn];
int edgenum;
void addedge(int u, int v, int c){
    nxt[edgenum] = head[u];
    to[edgenum] = v;
    cost[edgenum] = c;
    head[u] = edgenum++;
}
int n, m;
int tot;
int fir[maxn];
int id[maxn];
int bit[maxn];
void dfs(int u, int fa, int d, int len){
    dep[u] = d, id[++tot] = u, fir[u] = tot, dis[u] = len;
    for(int i = head[u]; ~i; i = nxt[i]){
        int v = to[i];
        if(v == fa) continue;
        dfs(v, u, d+1, len+cost[i]);
        id[++tot] = u;
    }
}
void ST(){
    for(int i = 0; i < 20; ++i) bit[i] = 1<<i;
    for(int i = 1; i <= tot; ++i) dp[i][0] = id[i];
    for(int j = 1; j < 20; ++j){
        for(int i = 1; i <= tot; ++i){
            if(i+bit[j-1]<=tot) {
                dp[i][j] = dep[dp[i][j-1]]<dep[dp[i+bit[j-1]][j-1]]?dp[i][j-1]:dp[i+bit[j-1]][j-1];
            }else dp[i][j] = dp[i][j-1];
        }
    }
}
int lca(int x, int y){
    if(fir[x] < fir[y]) swap(x,y);
    int dis = fir[x] - fir[y] + 1;
    int k = log2(dis+0.1);
    if(k<0) k = 0;
    int v1 = dp[fir[y]][k], v2 = dp[fir[x]-bit[k]+1][k];
    return dep[v1] < dep[v2] ? v1:v2;
}
int getdis(int x, int y){
    int u = lca(x,y);
    return dis[x] + dis[y] - 2*dis[u];
}
int flag = 0;
void merge(const Node& a, const Node& b, Node& ans){
    ans = Node(a.l, b.l);
    int d = getdis(a.l, b.l);
    int dd = getdis(a.l,b.r);
    if(dd>d) ans = Node(a.l,b.r), d = dd;
    dd = getdis(a.r, b.r);
    if(dd > d) ans = Node(a.r, b.r), d = dd;
    dd = getdis(a.r, b.l);
    if(dd > d) ans = Node(a.r, b.l), d = dd;
    if(flag) return;
    dd = getdis(a.l, a.r);
    if(dd>d) ans = a, d = dd;
    dd = getdis(b.l, b.r);
    if(dd>d) ans = b, d = dd;
}
void build(int rt, int l, int r){
    if(l == r){
        node[rt] = Node(l, r);
        return;
    }
    int mid = (l + r) >> 1;
    build(rt<<1, l, mid);
    build(rt<<1|1, mid+1, r);
    merge(node[rt<<1], node[rt<<1|1], node[rt]);
}
Node query(int rt, int l, int r, int ql, int qr){
    //printf("rt = %d l = %d  r = %d ql = %d qr = %d\n", rt, l, r, ql, qr);
    //pr(rt);pr(l);pr(r);pr(ql);prln(qr);
    if(ql <= l && r <= qr){
        return node[rt];
    }
    int mid = (l + r) >> 1;
    if(qr <= mid) return query(rt<<1, l, mid, ql, qr);
    if(ql > mid) return query(rt<<1|1, mid+1, r, ql, qr);
    else{
        Node ans = Node(0,0);
        Node lans = query(rt<<1, l, mid, ql, mid);
        Node rans = query(rt<<1|1, mid+1, r, mid+1, qr);
        merge(lans, rans, ans);
        return ans;
    }
}

struct FastIO {
  static const int S = 1310720;
  int wpos; char wbuf[S];
  FastIO() : wpos(0) {}
  inline int xchar() {
    static char buf[S];
    static int len = 0, pos = 0;
    if (pos == len)
      pos = 0, len = fread(buf, 1, S, stdin);
    if (pos == len) return -1;
    return buf[pos ++];
  }
  inline int xuint() {
    int c = xchar(), x = 0;
    while (c <= 32) c = xchar();
    for (;'0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
    return x;
  }
  inline int xint() {
    int s = 1, c = xchar(), x = 0;
    while (c <= 32) c = xchar();
    if (c == '-') s = -1, c = xchar();
    for (; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
    return x * s;
  }
  inline void xstring(char *s) {
    int c = xchar();
    while (c <= 32) c = xchar();
    for(; c > 32; c = xchar()) *s++ = c;
    *s = 0;
  }
  inline void wchar(int x) {
    if (wpos == S) fwrite(wbuf, 1, S, stdout), wpos = 0;
    wbuf[wpos ++] = x;
  }
  inline void wint(ll x) {
    if (x < 0) wchar('-'), x = -x;

    char s[24];
    int n = 0;
    while (x || !n) s[n ++] = '0' + x % 10, x /= 10;
    while (n--) wchar(s[n]);
  }
  inline void wstring(const char *s) {
    while (*s) wchar(*s++);
  }
  ~FastIO() {
    if (wpos) fwrite(wbuf, 1, wpos, stdout), wpos = 0;
  }
} io;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
    //freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    memset(dp, -1, sizeof dp);
    memset(dep, 0, sizeof dep);
    edgenum = 0;
    memset(head, -1, sizeof head);
    int a, b, c, d;
    n = io.xuint();
    //while(scanf("%d", &n) != EOF)
    {
        edgenum = 0;
        int u, v, cc;
        rep(i,n-1){
            u = io.xuint();
            v = io.xuint();
            cc = io.xuint();
            //scanf("%d%d%d", &u, &v, &cc);
            addedge(u, v, cc);
            addedge(v, u, cc);
        }
        dfs(1, 0, 1, 0);
        ST();
        build(1, 1, n);
        m = io.xuint();
        //scanf("%d",&m);
        rep(i,m){
            a = io.xuint();
            b = io.xuint();
            c = io.xuint();
            d = io.xuint();
            //scanf("%d%d%d%d", &a, &b, &c, &d);
            Node lans = query(1, 1, n, a, b);
            Node rans = query(1, 1, n, c, d);
            Node ans(0,0);
            flag = 1;
            merge(lans, rans, ans);
            flag = 0;
            int d = getdis(ans.l,ans.r);
            io.wint(d);
            io.wchar('\n');
            //printf("%d\n",d); 
        }
    }
	return 0;
}
