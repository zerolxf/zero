#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
#include<vector>

using namespace std;
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
#define pr(x)     //  cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define ll long long
#define rep(i,n) for(int i = 0; i < n; ++i)
ll dpl[17][51234], dpr[17][51234], cntl[17], cntr[17];
ll v[33];
int L, R;
int getbit(int x) {
    int ans = 0;
    while(x) {
        x -= x&(-x);
        ans++;
    }
    return ans;
}
ll getvalue(int x, int l, int r) {
    ll ans = 0;
    for(int i = l; i < r; ++i) {
        if(x%2==1) ans += v[i];
        x/=2;
    }
    return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n;
    while(scanf("%d",&n)!=EOF) {
        ll sum = 0;
        for(int i = 0; i <= 16; ++i){
            cntl[i] = 0;cntr[i] = 0;
        }
        for(int i = 0; i < n; ++i){
            scanf("%lld",&v[i]);
            sum += v[i];
        }
        //sort(v,v+n);
        L = (n+1)/2;
        R = n - L;
        L = (1<<L); R = (1<<R);
        int l = 0, r = (n+1)/2;
        int bitnum = 0;
        for(int i = 0; i < L; ++i) {
            bitnum = getbit(i);
            pr(i);prln(bitnum);
            dpl[bitnum][cntl[bitnum]++] = getvalue(i,l,r);
        }
        bitnum = getbit(L-1);
        for(int i = 0; i <= bitnum; ++i){
            sort(dpl[i],dpl[i]+cntl[i]);
        }
        l = r;r = n;
        for(int i = 0; i < R; ++i){
            bitnum = getbit(i);
            dpr[bitnum][cntr[bitnum]++] = getvalue(i,l,r);
        }
        bitnum = getbit(R-1);
        for(int i = 0; i <= bitnum; ++i){
            sort(dpr[i],dpr[i]+cntr[i]);
        }
        ll ans = 0;ll ssum = sum;
        sum /= 2;
        l = (n+1)/2;r = n-l;
        int lnum;
        for(int i = 0; i <= bitnum; ++i) {
            for(int j = 0; j < cntr[i]; ++j) {
                ll x = dpr[i][j];
                if(x > sum) continue;
                 lnum = r - i;
                 int pos = upper_bound(dpl[lnum],dpl[lnum] + cntl[lnum], sum-x) - dpl[lnum] - 1;
                 if(pos >= 0) {
                    ll temp = dpl[lnum][pos] + x;
                    if(temp > ans && temp <= sum) {
                            ans = temp;
                    }
                 }
                 if(l == r) continue;
                 lnum = l - i;
                 pos = upper_bound(dpl[lnum],dpl[lnum] + cntl[lnum], sum-x) - dpl[lnum] - 1;
                 if(pos >= 0) {
                    ll temp = dpl[lnum][pos] + x;
                    if(temp > ans && temp <= sum) {
                            ans = temp;
                    }
                 }
            }
        }
        ans = ssum - ans*2;
        cout << ans << "\n";
    }
    return 0;
}
