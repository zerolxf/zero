/*************************************************************************
    > File Name: 5932.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月06日 星期四 18时34分36秒
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
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
short pa[maxn][520];
int fa[maxn];
int head[maxn], nxt[maxn], to[maxn];
int uu[maxn], vv[maxn];
int st[maxn];
//inline short find(int x, short p[]){
    //int cnt = 0;
    //while(p[x] != x){
        //st[cnt++] = x;
        //x = p[x];
    //}
    //while(cnt > 0){
        //p[st[--cnt]] = x;
    //}
    //return x;
//}
short find(int x, short p[]){
    return p[x] = p[x]==x?x:find(p[x],p);
}
int n, m;
int edgenum;
inline void addedge(int u, int v){
    to[edgenum] = v;
    nxt[edgenum] = head[u];
    head[u] = edgenum++;
}
typedef pair<int,int> P;
P qq[maxn];
void dfs(int u, int pre){
    int cnt = 0;
    int hd = 0;
    qq[cnt++] = P(u, pre);
    while(hd < cnt){
        P qx = qq[hd++];
        u = qx.first, pre = qx.second;
        int l = uu[u], r = vv[u];
        l = find(l, pa[u]); r = find(r, pa[u]);
        if(l != r) pa[u][l] = r;
        for(int i = head[u]; ~i; i = nxt[i]){
            int v = to[i];
            if(v == pre) continue;
            for(int j = 1; j <= n; ++j){
                pa[v][j] = pa[u][j];
            }
            qq[cnt++] = P(v,u);
        }
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
short p[550];
int vis[550];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
    freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t, q, kase = 0;
    t = io.xuint();
    while(t--){
        io.wstring("Case #");
        io.wint(++kase);
        io.wstring(":\n");
        n = io.xuint(); m = io.xuint();
        rep(i,n+1) pa[1][i] = i;
        for(int i = 0; i <= m; ++i) head[i] = -1;
        int u;
        edgenum = 0;
        for(int i = 2; i <= m; ++i){
            u = io.xuint();
            addedge(u, i);
        }
        for(int i = 1; i <= m; ++i){
            uu[i]= io.xuint();
            vv[i] = io.xuint();
        }
        dfs(1, 1);
        q = io.xuint();
        for(int i = 0; i < q; ++i){
            int k, x, ans = 0;
            k = io.xuint();
            for(int j = 0; j <= n; ++j){
                p[j] = j;
                vis[j] = 0;
            }
            for(int j = 0; j < k; ++j){
                x = io.xuint();
                for(int l = 1; l <= n; ++l){
                    int u = find(l, pa[x]);
                    int v = find(u, p);
                    u = find(l, p);
                    if(u != v) p[v] = u;
                }
            }
            for(int j = 1; j <= n; ++j){
                int pj = find(j, p);
                if(!vis[pj]) ans++;
                vis[pj] = true;
            }
            io.wint(ans);
            io.wchar('\n');
        }
    }
	return 0;
}
