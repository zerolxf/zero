/*************************************************************************
    > File Name: i.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月13日 星期六 16时48分44秒
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
const int G = 3, P = 998244353;
const int N = 4e5+100;
ll quick(ll x, ll n) {
    ll ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % P;
        x = x * x % P;
    }
    return ret;
}

ll A[N << 2], B[N << 2];
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

int n, a[N], f[N];
ll two[N];
ll inv[N];
ll fac[N];
ll X[N<<2], Y[N<<2];
void reverse(ll a[], int len){
    int half = len/2;
    ll temp = 0;
    for(int i = 0; i < half; ++i){
        temp = a[i];
        a[i] = a[len-1-i];
        a[len-1-i] = temp;
    }
}
bool cmp(int x, int y){
    return x > y;
}
template <class T>
inline bool scan_d(T &ret) {
char c; int sgn;
if(c=getchar(),c==EOF) return 0; //EOF
while(c!='-'&&(c<'0'||c>'9')) c=getchar();
sgn=(c=='-')?-1:1;
ret=(c=='-')?0:(c-'0');
while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
ret*=sgn;
return 1;
}
inline void out(int x) {
if(x>9) out(x/10);
putchar(x%10+'0');
}

int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    fac[0] = 1;
    inv[0] = 1;
    two[0] = 1;
    for(int i = 1; i < N; ++i){
        two[i] = two[i-1]*2%P;
        fac[i] = fac[i-1]*i%P;
        inv[i] = inv[i-1]*quick(i,P-2)%P;
    }
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            //scan_d(a[i]);
            scanf("%d", &a[i]);
        }
        sort(a+1, a+1+n, cmp);
        int len = 1;
        while(len <= (n<<1)) len<<=1;
        for(int i = 1; i <= n; ++i){
            X[i-1] = two[n-i]*fac[i-1]%P*a[i]%P;
        }
        reverse(X, n);
        for(int i = n; i <= len; ++i) X[i] = 0, Y[i] = 0;
        for(int i = 0; i < n; ++i){
            Y[i] = inv[i];
        }
        ntt(X, len, 1);
        ntt(Y, len, 1);
        for(int i = 0; i < len; ++i){
            X[i] = X[i]*Y[i]%P;
        }
        ntt(X, len, -1);
        for(int i = 1; i <= n; ++i){
            f[i] = inv[i-1]*X[n-i]%P;
        }
        for(int i = 1; i <= n; ++i){
            f[i+1] = (f[i+1] + f[i]);
            if(f[i+1] > P) f[i+1] -= P;
        }
        for(int i = 1; i <= n; ++i){
            //out(f[i]);
            //putchar(' ');
            printf("%d ",f[i]);
        }
        printf("\n");

        
    }

	return 0;
}
