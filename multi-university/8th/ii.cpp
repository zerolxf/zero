#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<utility>
#include<sstream>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 600010;
#define pr(x) cout << #x <<" = " << x << " ";
#define prln(x) cout << #x <<" = " << x << " " << endl;

const int mod = 998244353;
const int P = 998244353;
ll fac[maxn], inv[maxn], A[maxn], two[maxn];
int ans[maxn];
int a[maxn];
const int G = 3;
ll quick(ll x, ll n) {
    ll ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % P;
        x = x * x % P;
    }
    return ret;
}

ll f[maxn], g[maxn];

void rader(ll* y, int len) {
    for(int i = 1, j = len / 2; i < len - 1; i++) {
        if(i < j) swap(y[i], y[j]);
        int k = len / 2;
        while(j >= k) {j -= k; k /= 2;}
        if(j < k) j += k;
    }
}
void ntt(ll* y, int len, int op) {
    rader(y, len);
    for(int h = 2; h <= len; h <<= 1) {
        ll wn = quick(G, (P - 1) / h);
        if(op == -1) wn = quick(wn, P - 2);
        for(int j = 0; j < len; j += h) {
            ll w = 1;
            for(int k = j; k < j + h / 2; k++) {
                ll u = y[k];
                ll t = w * y[k + h / 2] % P;
                y[k] = (u + t) % P;
                y[k + h / 2] = (u - t + P) % P;
                w = w * wn % P;
            }
        }
    }
    if(op == -1) {
        ll inv = quick(len, P - 2);
        for(int i = 0; i < len; i++) y[i] = y[i] * inv % P;
    }
}


bool cmp(int a, int b) {
    return a > b;
}
const int N = 6e5+100;
int main()
{
    //#ifdef LOCAL
    //freopen("1009.in","r",stdin);
    //freopen("out1.txt","w",stdout);
    //#endif // LOCAL
    int t;
    scanf("%d",&t);

    fac[0] = 1;
    inv[0] = 1;
    two[0] = 1;
    for(int i = 1; i < N; ++i){
        two[i] = two[i-1]*2%P;
        fac[i] = fac[i-1]*i%P;
        inv[i] = inv[i-1]*quick(i,P-2)%P;
    }
    while(t--) {
        int n; 
        scanf("%d",&n);
        for(int i = 0; i < n; i++) scanf("%d",&a[i]);
        sort(a, a + n, cmp);
        for(int i = 0; i < n; i++) A[i] = (ll)a[i] * fac[i]%P * two[n - 1 - i]%P;

        int len = 1;
        while(len <= (n<<1)) len<<=1;
        for(int i = 0; i <= len; i++) f[i] = g[i] = 0;
        for(int i = n - 1; i >= 0; i--) f[i] = A[n - 1 - i];
        for(int i = 0; i < n; i++) g[i] = inv[i];
        ntt(f, len, 1);
        ntt(g, len, 1);
        for(int i = 0; i < len; i++) f[i] = f[i] * g[i] % P;
        ntt(f, len, -1);
        for(int i = 0; i < n; i++) ans[i] = inv[i]* f[n - 1 - i]%P;
        for(int i = 1; i < n; i++) {
            ans[i] = ans[i] + ans[i - 1] ;
            if(ans[i]>=mod) ans[i]-=mod;
        }
        for(int i = 0; i < n; i++) {
            printf("%d ",ans[i]);
               
        }
         printf("\n");
    }
    return 0;
}
