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
typedef pair<ll, ll> P;
const int inf = 0x3f3f3f3f;
const int maxn = 400010;

#define pr(x) cout << #x <<" = " << x << " ";
#define prln(x) cout << #x <<" = " << x << " " << endl;
const int MOD = 110119;
const int mod = 110119;
ll x[maxn], y[maxn];
vector<ll> pre[110];
ll dp[110];

ll fac[120119];
ll inv[120119];
ll pow_mod(ll a, ll n) {
    if(n == 0) return 1;
    ll ans = pow_mod(a, n / 2);
    ans = ans * ans % mod;
    if(n & 1) ans = ans * a % mod;
    return ans;
}


//ll pow_mod(ll a, ll n) {
    //if(n == 0) return 1;
    //ll ans = pow_mod(a, n / 2);
    //ans = ans * ans % mod;
    //if(n & 1) ans = ans * a % mod;
    //return ans;
//}

ll mul(ll a, ll b) {
    return a * b % mod;
}

void initf() {
    fac[0] = 1;
    for(ll i = 1; i <= mod; i++) fac[i] = fac[i - 1] * i % mod;
    //for(ll i = 0; i < mod; i++) inv[i] = pow_mod(fac[i], mod - 2);
}

ll exgcd(ll a, ll b, ll& x, ll& y) {
    ll d = a;
    if(b != 0) {
        d = exgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else {
        x = 1; y = 0;
    }
    return d;
}

ll mod_inverse(ll a, ll m) {
    ll x, y;
    exgcd(a, m, x, y);
    return (m + x % m) % m;
}

ll mod_fact(ll n, ll p, ll& e) {
    e = 0;
    if(n == 0) return 1;
    ll res = mod_fact(n / p, p, e);
    e += n / p;
    if(n / p % 2 != 0) return res * (p - fac[n % p]) % p;
    return res * fac[n % p] % p;
}

ll mod_comb(ll n, ll k, ll p) {
    if(n < 0 || k < 0 || n < k) return 0;
    ll e1, e2, e3;
    ll a1 = mod_fact(n, p, e1);
    ll a2 = mod_fact(k, p, e2);
    ll a3 = mod_fact(n - k, p, e3);
    if(e1 > e2 + e3) return 0;
    return a1 * mod_inverse(a2 * a3 % p, p) % p;
}
ll PowMod(ll a,ll b,int MOD){  
    ll ret=1;  
    while(b){  
        if(b&1) ret=(ret*a)%MOD;  
        a=(a*a)%MOD;  
        b>>=1;  
    }  
    return ret;  
}  
void Get_Fact(int p){  
    fac[0]=1;  
    for(int i=1;i<=p;i++)  
        fac[i]=(fac[i-1]*i)%p;  
}  
ll Lucas(ll n,ll m,int p){  
    ll ret=1;  
    while(n&&m){  
        ll a=n%p,b=m%p;  
        if(a<b) return 0;  
        ret=(ret*fac[a]*PowMod(fac[b]*fac[a-b]%p,p-2,p))%p;  
        n/=p;  
        m/=p;  
    }  
    return ret;  
}  
//j -> i
bool link(int i, int j){
    //pr(i);pr(x[i]);prln(y[i]);
    //pr(j);pr(x[j]);prln(y[j]);
    ll xx = x[i]-x[j];
    ll yy = y[i]-y[j];
    if(xx<=0||yy<=0) return false;
    ll xxx = 2*xx-yy;
    ll yyy = 2*yy-xx;
    //pr(i);pr(j);pr(xxx);prln(yyy);
    if(xxx%3||yyy%3) return false;
    return true;

}

ll cal(int i, int j){
    ll xx = x[i] - x[j];
    ll yy = y[i] - y[j];
    ll xxx = 2*xx-yy;
    ll yyy = 2*yy-xx;
    if(xxx<0){
        xxx = -xxx;
        yyy = -yyy;
    }
    xxx/=3;
    yyy/=3;
    ll ans = mod_comb(xxx+yyy,xxx,MOD);
    //ll ans = Lucas(xxx+yyy,xxx,MOD);
    //ll ans = 0;
    //pr(i);pr(j);pr(xxx);prln(yyy);
   // prln(ans);
    return ans;

}


void dfs(int u){
    dp[u] = cal(u, 0);
    for(int i = 0; i < pre[u].size(); ++i){
        int v = pre[u][i];
        dfs(v);
        ll uv = cal(u,v);
        dp[u] = (dp[u] - mul(dp[v], uv))%MOD;
    }
}
P node[maxn];
int main()
{

#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    //initf();
    ll n, m, r;
    int kase = 0;
    Get_Fact(MOD);
    while(scanf("%lld%lld%lld", &n, &m, &r) != EOF){
        n--,m--;
        memset(dp, 0, sizeof dp);
        printf("Case #%d: ", ++kase);
        for(int i = 1; i <= r; ++i) scanf("%lld%lld", &x[i], &y[i]);
        if(n == 0 && m == 0) {
            printf("1\n"); continue;
        }
        ll xx = 2*n-m;
        ll yy = 2*m-n;
        bool ok = false;
        if(xx<0||yy<0||xx%3||yy%3){
            printf("0\n"); continue;
        }
        for(int i = 1; i <= r; i++) {
                x[i]--, y[i]--;
                if(x[i]==n&&y[i]==m){
                    ok=  true;
                }
                node[i] = P(x[i], y[i]);
        }
        if(ok){
            printf("0\n"); continue;
        }
        sort(node+1, node+1+r);
        r = unique(node+1, node+1+r)-node-1;
        for(int i = 1; i <= r; i++) x[i] = node[i].first, y[i] = node[i].second;
        for(int i = 0; i <= r+1; ++i) pre[i].clear();
        x[0] = 0; y[0] = 0;
        x[r+1] = n; y[r+1] = m;
        for(int i = 1; i <= r+1; ++i){
            for(int j = 1; j <= r+1; ++j){
                if(i==j) continue;
                if(link(i,j)){
                    pre[i].push_back(j);
                }
            }
        }
        /*
        for(int i = r + 1; i >= 0;i--) {
            pr(i);
            for(int j = 0; j < pre[i].size(); j++)
                cout<<pre[i][j]<<" ";
            cout<<endl;
        }*/
        dfs(r+1);
       // for(int i = 0; i <= r + 1; i++) cout<<dp[i]<<" ";cout<<endl;
        dp[r+1] = (dp[r+1]%MOD+MOD)%MOD;
        printf("%lld\n", dp[r+1]);
    }
    return 0;
}
