/*************************************************************************
    > File Name: a.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月05日 星期三 18时48分06秒
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
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
int c[maxn*100],  ls[maxn*100], rs[maxn*100];
int tcnt = 0;
int build(int l, int r){
    if(l == r){
        int rt = tcnt++;
        c[rt] = 0;
        return rt;
    }
    int rt = tcnt++;
    int mid = (l + r) >> 1;
    ls[rt] = build(l, mid);
    rs[rt]= build(mid+1, r);
    c[rt] = 0;
    return rt;
}
int getnode(int rt){
    int newnode = tcnt++;
    ls[newnode] = ls[rt];
    rs[newnode] = rs[rt];
    c[newnode] = c[rt];
    return newnode;
}

int n;
int update(int rt,int l, int r, int pos){
    if(pos > n) return rt;
    if(l == r){
        int newnode = getnode(rt);
        c[newnode] += 1;
        return newnode;
    }
    int mid = (l+r) >> 1;
    int newnode = getnode(rt);
    c[newnode] += 1;
    if(mid >= pos) {
        ls[newnode] = update(ls[rt], l, mid, pos);
    }else if(mid < pos){
        rs[newnode] = update(rs[rt], mid+1, r, pos);
    }
    return newnode;
}
int query(int &rt, int l, int r, int ql, int qr){
    if(qr < ql) return 0;
    if(l == ql && r == qr){
        return c[rt];
    }
    int mid = (l+r) >> 1;
    if(mid >= qr) return query(ls[rt], l, mid, ql, qr);
    else if(mid < ql){
        return query(rs[rt], mid+1, r, ql, qr);
    }else{
        int ans = query(ls[rt], l, mid, ql, mid);
        ans += query(rs[rt], mid+1, r, mid+1, qr);
        return ans;
    }
}
char s[maxn];
int T[maxn][5];
int ly[maxn][5];
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
    freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

    int m;
    tcnt = 0;
    scanf("%s", s+1);
    n = strlen(s+1);
    scanf("%d",&m);
    T[n+1][0] = build(1, n);
    for(int i = 0; i < 4; ++i){
        T[n+1][i] = T[n+1][0];
        ly[n+1][i] = n+1;
    }
    for(int i = n; i > 0; --i){
        for(int j = 0; j < 4; ++j){
            T[i][j] = T[i+1][j];
            ly[i][j] = ly[i+1][j];
        }
        if(s[i] == 'y'){
            ly[i][1] = i;
            T[i][1] = T[i+1][0];
        }else if(s[i] == 's'){
            ly[i][2] = ly[i+1][1];
            T[i][2] = T[i+1][1];
        }else if(s[i] == 'a'){
            ly[i][3] = ly[i+1][2];
            T[i][3] = T[i+1][2];
        }else{
            T[i][0] = T[i+1][3];
            if(ly[i+1][3] > n) continue;
            T[i][0] = update(T[i][0], 1, n, ly[i+1][3]);
        }
    }
    int l, r, ans = 0;
    for(int i = 0; i < m; ++i){
        scanf("%d%d", &l, &r);
        ans = query(T[l][0], 1, n, l, r);
        printf("%d\n", ans);
    }
	return 0;
}
