/*************************************************************************
	> File Name: i.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月01日 星期一 09时57分14秒
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
const int maxn = 2e5+100;
const int INF = 0x3f3f3f3f;
int sa[maxn], t1[maxn], t2[maxn], c[maxn], ran[maxn], h[maxn];
int add[412345];
struct Node{
    int num, sum;
    Node(){
        num = 0;
        sum = 0;
    }
    Node(int _num, int _sum){
        num = _num;
        sum = _sum;
    }
    Node operator + (const Node& rhs)const{
        Node ans;
        ans.num = rhs.num+num;
        ans.sum = rhs.sum+sum;
        return ans;
    }
}node[412345];
void pushdown(int rt) {
    if(add[rt] != 0){
        add[rt<<1] = add[rt<<1|1] = add[rt];
        node[rt<<1] = node[rt<<1|1] = Node(0,0);
        add[rt] = 0;
    }
}
void update(int rt, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        add[rt] = 1;
        node[rt] = Node(0,0);
        return;
    }
    pushdown(rt);
    int m = (l+r) >> 1;
    if(m >= ql) update(rt<<1, l, m, ql, qr);
    if(m < qr) update(rt<<1|1, m+1, r, ql, qr);
    node[rt] = node[rt<<1] + node[rt<<1|1];
}
void update_add(int rt, int l, int r, ll o, ll v){
    if(l>r) return;
    if(l == r){
        node[rt] = node[rt] + Node(v, o*v);
        return;
    }
    pushdown(rt);
    int m = (l+r) >> 1;
    if(m >= o) update_add(rt<<1, l, m, o, v);
    else update_add(rt<<1|1, m+1, r, o, v);
    node[rt] = node[rt<<1] + node[rt<<1|1];
}
Node query(int rt, int l, int r, int ql, int qr){
    if(l>r) return Node(0,0);
    if(ql <= l && r <= qr){
        return node[rt];
    }
    pushdown(rt);
    int m = (l+r) >> 1;
    Node ans = Node(0,0);
    if(m >= ql) ans = ans + query(rt<<1, l, m, ql, qr);
    if(m < qr) ans = ans + query(rt<<1|1, m+1, r, ql, qr);
    return ans;
}
int n;
void getSa(int m){
    int *x = t1, *y = t2;
    n++;
    for(int i = 0; i < m; i++) c[i] = 0;
    for(int i = 0; i < n; ++i) c[x[i]]++;
    for(int i = 0; i < m; ++i) c[i+1] += c[i];
    for(int i = n-1; i >= 0; --i) sa[--c[x[i]]] = i;
    for(int k = 1; k <= n; k <<= 1){
        int p = 0;
        for(int i = n-k; i < n; ++i) y[p++] = i;
        for(int i = 0; i < n; ++i) if(sa[i] >= k) y[p++]=sa[i]-k;
        for(int i = 0; i < m; ++i) c[i] = 0;
        for(int i = 0; i < n; ++i) c[x[y[i]]]++;
        for(int i = 0; i < m; ++i) c[i+1] += c[i];
        for(int i = n-1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for(int i = 1; i < n; ++i){
            x[sa[i]] = (y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+k] == y[sa[i]+k])?p-1:p++;
        }
        if(p >= n) break;
        m = p;
    }
    n--;
}
char s[maxn];
void getHeight(){
    for(int i = 0; i <= n; ++i) ran[sa[i]] = i;
    int k = 0;
    for(int i = 0; i < n; ++i){
        if(k) --k;
        int j = sa[ran[i]-1];
        while((i+k < n) && t1[i+k] == t1[j+k]) {
            k++;
        }
        h[ran[i]] = k;
    }
}
int k;
struct Q{
    int pos, num;
    ll ans;
    Q(){}
    Q(int _pos, int _num, ll _ans){
        pos = _pos;
        num = _num;
        ans = _ans;
    }
    bool operator < (const Q& rhs)const{
        return num < rhs.num;
    }
}q[maxn];
ll cal(char* str, int len){
    for(int i = 0; i <= len; ++i) t1[i] = str[i];
    t1[len] = 0;
    n = len;
    getSa(130);
    for(int i = 0; i <= len; ++i) t1[i] = str[i];
    getHeight();
    ll ans = 0;
    int qcnt;
    ll last = 0;
    for(int i = 1; i <= n; ++i){
        if(h[i] < k){
            qcnt = 0;
            last = i+1;
            continue;
        }
        while(qcnt > 0 && q[qcnt-1].num >= h[i]){
            qcnt--;
        }
        if(qcnt == 0){
            ll addans = (ll)(h[i]-k+1)*(i-last+1);
            ans += addans;
            q[qcnt++] = Q(i, h[i], addans);
            continue;
        }
        ll addans = (ll)(h[i]-k+1)*(i-q[qcnt-1].pos) + q[qcnt-1].ans;
        ans += addans;
        q[qcnt] = Q(i, h[i], (ll)(h[i]-k+1)*(i-q[qcnt-1].pos) + q[qcnt-1].ans);
        qcnt++;
    }
    //int _n = 1;
    //while(_n < len) _n <<= 1;
    //update(1, 1, _n, 1, _n);
    //ll ans = 0, num = 0;
    //for(int i = 1; i <= len; ++i){
        //if(h[i] < k){
            //update(1, 1, _n, 1, _n);
            //continue;
        //}
        //num = query(1, 1, _n, h[i]+1-k+1, _n).num;
        //update(1, 1, _n, h[i]+1-k+1, _n);
        //update_add(1, 1, _n, h[i]-k+1, num+1);
        //ans = ans + query(1, 1, _n, 1, h[i]-k+1).sum;
    //}
    return ans;
}
void solve(){
    int lena = 0, lenb = 0;
    scanf("%s", s);
    lena = strlen(s);
    //pr(lena);
    ll ans = 0;
    ans = ans - cal(s, lena);
    s[lena] = 1;
    scanf("%s", s+lena+1);
    lenb = strlen(s+lena+1);
    //prln(lenb);
    ans = ans - cal(s+lena+1, lenb);
    ans = ans + cal(s, lena+lenb+1);
    printf("%lld\n", ans);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(scanf("%d", &k) != EOF){
        if(k == 0) break;
        solve();
    }
    
	return 0;
}
