/*************************************************************************
    > File Name: d.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月29日 星期六 14时55分37秒
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
const int maxn = 2e5+100;
const int INF = 0x3f3f3f3f;
int unit;
ll cnt[maxn], cntp[maxn];
int head[maxn];
int to[maxn*50], nxt[maxn*50];
int edgenum = 0;
inline void addedge(int u, int v){
    nxt[edgenum] = head[u];
    to[edgenum] = v;
    head[u] = edgenum++;
}
void getp(){
    edgenum = 0;
    memset(head,-1,sizeof head);
    for(int i = 1; i < maxn; ++i){
        for(int j = i; j < maxn; j += i){
            addedge(j,i);
        }
    }
}
struct Q{
    int l, r, id;
    bool operator < (const Q& rhs)const{
        return l/unit < rhs.l/unit || (l/unit==rhs.l/unit&&r<rhs.r);
    }
}q[maxn];
int n, m;
int a[maxn];
ll num[maxn];
inline void ADD(ll& ans, int pos){
    ans += cntp[a[pos]];
    cnt[a[pos]]++;
    for(int i = head[a[pos]]; ~i; i = nxt[i]){
        int v = to[i];
        ans += cnt[v];
        cntp[v]++;
    }
}
inline void Remove(ll& ans, int pos){
    for(int i = head[a[pos]]; ~i; i = nxt[i]){
        int v = to[i];
        ans -= cnt[v];
        cntp[v]--;
    }
    ans -= cntp[a[pos]];
    cnt[a[pos]]--;
}
void modui(){
    sort(q, q+m);
    ll ans = 0;
    int L = 1, R = 0;
    for(int i = 0; i < m; ++i){
        while(R < q[i].r) ADD(ans,++R);
        while(R > q[i].r) Remove(ans, R--);
        while(L > q[i].l) ADD(ans,--L);
        while(L < q[i].l) Remove(ans,L++);
        num[q[i].id] = ans;
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
    getp();
    //memset(cnt, 0, sizeof cnt);
    //memset(cntp, 0, sizeof cntp);
    //scanf("%d%d", &n, &m);
    n = io.xuint();
    m = io.xuint();
    unit = sqrt(n+0.5);
    repp(i,n,1){
        a[i] = io.xuint();
    }
    //repp(i,n,1) scanf("%d", &a[i]);
    rep(i,m) {
        q[i].l = io.xuint();
        q[i].r = io.xuint();
        //scanf("%d%d", &q[i].l, &q[i].r);
        q[i].id = i;
    }
    modui();
    for(int i = 0; i < m; ++i){
        io.wint(num[i]);
        io.wchar('\n');
        //puts();
        //printf("%I64d\n",num[i]);
        //cout << num[i] << "\n";
    }




	return 0;
}
