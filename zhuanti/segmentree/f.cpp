/*************************************************************************
	> File Name: f.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年07月13日 星期三 14时57分16秒
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
#define pr(x) //cout << #x << " = " << x << " ";
#define prln(x) // cout << #x << " = " << x <<  endl; 
const int maxn = 8e5+100;
const int INF = 0x3f3f3f3f;
int a[maxn], b[maxn], id[maxn], nxt[maxn], last[maxn];
int mi[maxn];
bool vis[maxn];
ll add[maxn], sum[maxn];
int ma[maxn];
void pushdown(int rt, int l, int r){
    if(add[rt]!=-1){
        add[rt<<1] = add[rt<<1|1] = add[rt];
        ma[rt<<1] = ma[rt<<1|1] = add[rt];
        int m = (l+r) >> 1;
        sum[rt<<1] = add[rt<<1]*(m-l+1);
        sum[rt<<1|1] = add[rt<<1|1]*(r-m);
        add[rt] = -1;
    }
}
void update(int rt, int l, int r, int ql, int qr, int v) {
    if(ql <= l && r <= qr){
        add[rt] = v;
        sum[rt] = add[rt]*(r-l+1);
        ma[rt] = v;
        return;
    }
    pushdown(rt, l, r);
    int m = (l+r)>>1;
    if(m >= ql) update(rt<<1, l, m, ql, qr, v);
    if(m < qr) update(rt<<1|1, m+1, r, ql, qr, v);
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    ma[rt] = max(ma[rt<<1], ma[rt<<1|1]);
}
ll query(int rt, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return sum[rt];
    }
    pushdown(rt, l, r);
    int m = (l+r) >> 1;
    ll ans = 0;
    if(m >= ql) ans += query(rt<<1, l, m, ql, qr);
    if(m < qr) ans += query(rt<<1|1, m+1, r, ql, qr);
    return ans;
}
int getl(int rt, int l, int r, int x){
    if(l == r) return l;
    pushdown(rt, l, r);
    int m = (l+r) >> 1;
    if(ma[rt<<1] >= x) return getl(rt<<1, l, m, x);
    return getl(rt<<1|1, m+1, r, x);
}
const int N = 2e5+100;
int _n;
int getl(int l, int r,int x){
    while(l < r){
        int m = (l+r) >> 1;
        int mx = query(1, 1, _n, m, m);
        if(mx < x) l = m+1;
        else r = m;
    }
    return l;
}

inline bool scan_d(int &num)  
{
        char in;bool IsN=false;
        in=getchar();
        if(in==EOF) return false;
        while(in!='-'&&(in<'0'||in>'9')) in=getchar();
        if(in=='-'){ IsN=true;num=0;}
        else num=in-'0';
        while(in=getchar(),in>='0'&&in<='9'){
                num*=10,num+=in-'0';
        }
        if(IsN) num=-num;
        return true;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    while(scanf("%d", &n) != -1&& n){
        _n = 1;
        int temp = 0;
        ll ans = 0;
        while(_n < n) _n <<= 1;
        for(int i = 0; i <= _n*2; ++i) add[i] = -1, sum[i] = 0, ma[i] = 0;
        for(int i = 0; i <= N;++i){
            vis[i] = false;
        }
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            b[i] = a[i];
        }    
        sort(b+1, b+n+1);
        int len = unique(b+1, b+1+n) - b-1;
        for(int i = 1; i <= n; ++i){
            int pos = lower_bound(b+1, b+1+len, a[i]) - b-1;
            id[i] = pos;
        }
        for(int i = 0; i <= n; ++i) last[i] = n+1;
        for(int i = n; i; --i){
            nxt[i] = last[id[i]];
            last[id[i]] = i;
        }
        for(int i = 1; i <= n; ++i){
            if(b[id[i]+1]<=N)vis[b[id[i]+1]] = true;
            while(vis[temp]) temp++;
            update(1, 1, _n, i, i, temp);
            ans += temp;
        }
        ll addans;
        for(int i = 2; i <= n; ++i){
            if(ma[1] >= b[id[i-1]+1]){
                int ql = getl(1, 1, _n, b[id[i-1]+1]);
                if(nxt[i-1]-1>=ql)
                update(1, 1, _n, ql, nxt[i-1]-1, b[id[i-1]+1]);
            }
            addans = query(1, 1, _n, i, n);
            ans += addans;
        }
        cout << ans << "\n";

    }
	return 0;
}
