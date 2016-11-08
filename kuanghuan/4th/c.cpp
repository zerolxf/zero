/*************************************************************************
    > File Name: c.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月07日 星期日 09时53分23秒
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
#define rep(i,n) for(ll i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const ll maxn = 6e5+100;
const ll INF = 1e10;
ll sum[maxn], add[maxn];
void pushdown(ll rt, ll l, ll r){
    if(add[rt]){
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        ll m = (l+r) >> 1;
        sum[rt<<1] += (ll)(m-l+1)*add[rt];
        sum[rt<<1|1] += (ll)(r-m)*add[rt];
        add[rt] = 0;
    }
}
void update(ll rt, ll l, ll r, ll ql, ll qr, ll v){
    //pr(l);pr(r);pr(ql);pr(qr);prln(v);
    if(ql <= l && r <= qr){
        add[rt] += v;
        sum[rt] += (ll)(r-l+1)*v;
        //prln(sum[rt]);
        return;
    }
    pushdown(rt, l, r);
    ll m = (l+r) >> 1;
    if(m >= ql) update(rt<<1, l, m, ql, qr, v);
    if(m < qr) update(rt<<1|1, m+1, r, ql, qr, v);
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    //pr(l);pr(r);pr(ql);pr(qr);pr(v);prln(sum[rt]);
}
ll query(ll rt, ll l, ll r, ll ql, ll qr){
    if(ql <= l && r <= qr){
        return sum[rt];
    }
    pushdown(rt, l, r);
    ll m = (l+r) >> 1;
    ll ans = 0;
    if(m >= ql) ans += query(rt<<1, l, m, ql, qr);
    if(m < qr) ans += query(rt<<1|1, m+1, r,ql, qr);
    //pr(l);pr(r);pr(ql);pr(qr);prln(ans);
    return ans;
}
ll ans[maxn];
ll a[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    ll n, k;
    while(cin >> n >> k){
        ll _n = 1;
        while(_n < n) _n <<= 1;
        for(ll i=0; i <= _n*2; ++i){
            sum[i] = add[i] = 0;
        }
        for(ll i = 1; i <= n; ++i){
            scanf("%I64d", &a[i]);
            //cin >> a[i];
        }
        sort(a+1, a+n+1);
        for(ll i = 1; i <= n; ++i){
            ans[i] = INF;
        }
        ans[1] = a[1];
        for(ll i = 2; i <= n; ++i){
            update(1, 1, _n, 1, i-1, a[i]-a[i-1]);
            ll ma = (ll)a[i]-a[i-1];
            if(ma > k) continue;
            ll l = 1, r = i;
            while(l < r){
                ll mid = (l+r) >> 1;
                ll q = query(1, 1, _n, mid, i);
                if(q > k) l = mid+1;
                else r = mid;
            }
            l = i-l+1;
            if(a[i]-a[i-1]<=k)
            ans[l] = min(ans[l], a[i]);
        }
        for(ll i = n; i; --i){
            if(ans[i] != INF){
                printf("%lld %lld\n", i, ans[i]);
                break;
            }
        }


    }

	return 0;
}
