
/*************************************************************************
	> File Name: k.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月8日 星期一 11时22分46秒
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
const int maxn = 3e6;
const int INF = 0x3f3f3f3f;
int a[maxn], t[maxn];
int n, m, tot;
int T[maxn], lson[maxn], rson[maxn], c[maxn];
ll cc[maxn];
void inithash(){
    for(int i = 1; i <= n; ++i){
        t[i] = a[i];
    }
    sort(t+1, t+1+n);
    m = unique(t+1,t+1+n)-t-1;
}
int build(int l, int r){
    int root = tot++;
    c[root] = 0;
    if(l!=r){
        int mid = (l+r) >> 1;
        lson[root] = build(l,mid);
        rson[root] = build(mid+1,r);
    }
    return root;
}
int gethash(int x){
    return lower_bound(t+1, t+1+m, x) - t;
}
int update(int root, int pos, int val, ll v){
    int newroot = tot++, tmp  = newroot;
    c[newroot] = c[root] + val;
    cc[newroot] = cc[root] + v;
    int l = 1, r = m;
    while(l < r){
        int mid = (l+r) >> 1;
        //pr(t[pos]);prln(t[mid]);
        //pr(l);prln(r);
        if(pos <= mid){
            lson[newroot] = tot++; rson[newroot] = rson[root];
            newroot = lson[newroot]; root = lson[root];
            r = mid;
            //prln("lson");
        }else{
            rson[newroot] = tot++; lson[newroot] = lson[root];
            newroot = rson[newroot]; root = rson[root];
            l = mid+1;
            //prln("rson");
        }
        c[newroot] = c[root] + val;
        //prln(v);
        cc[newroot] = cc[root] + v;
        //prln(cc[newroot]);
    }
    return tmp;
}
int query(ll &ans, int lr, int rr, int k){
    int l = 1, r = m;
    ans = 0;

    //ll ccc = 0;
    int a = 0, b = 0;
    while(l < r){
        int mid = (l+r) >> 1;
        //pr(l);prln(r);
        //prln(t[mid]);
        if(c[lson[lr]] - c[lson[rr]] >= k){
            r = mid;
            ans += cc[rson[lr]] - cc[rson[rr]];
            //prln(ans);
            a += c[rson[lr]] - c[rson[rr]];
            lr = lson[lr];
            rr = lson[rr];
            //pr(c[rson[lr]]);prln(c[rson[rr]]);
            //prln(a);
        }else{
            l = mid + 1;
            k -= c[lson[lr]] - c[lson[rr]];
            //pr(cc[lson[lr]]);prln(cc[lson[rr]]);
            ans -= cc[lson[lr]] - cc[lson[rr]];
            b += c[lson[lr]] - c[lson[rr]];
            //prln(b);
            //prln(ans);
            lr = rson[lr];
            rr = rson[rr];
        }
    }
    //pr(a);prln(b);
    //prln(ccc);
    ans += (ll)(b-a)*t[l];
    //ans += ccc*t[l];
    //prln(ans);
    //ans += cc[lr] - cc[rr];
    //prln(l);
    return l;
}
ll sum[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int q;
    int tt = 0, kase = 0;
    scanf("%d", &tt);
    while(tt--){
        if(kase) printf("\n");
        printf("Case #%d:\n",++kase);
        scanf("%d",&n);
        tot = 0;
        //pr(n);prln(q);
       sum[0] = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            sum[i] = sum[i-1] + a[i];
            //prln(a[i]);
        }
        inithash();
        T[n+1] = build(1,m);
        for(int i = n; i; --i){
            int pos = gethash(a[i]);
            //prln(a[i]);
            T[i] = update(T[i+1], pos, 1, a[i]);
        }
        ll ans = 0;
        scanf("%d", &q);
        while(q--){
            int l, r, k;
            scanf("%d%d", &l, &r);
            //pr(l);prln(r);
            l++,r++;
            k = (r-l+2)/2;
            //prln("********************");
            //prln(k);
            ll x = t[query(ans, T[l], T[r+1], k)];
            //prln(x);
            //prln(ans);
            printf("%lld\n",ans);
        }
    }
	return 0;
}
