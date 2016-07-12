
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
const int maxn = 1e5+100;
const int INF = 0x7f7f7f7f;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
ll a[maxn], g[maxn],  b[maxn], d[maxn];
int main(){
#ifdef LOCAL
  //  freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    ll t, n, m, kase = 0, k;cin >> t;
    while(t--) {
       cin >> n >> m;
       printf("Case #%d: ", ++kase);
        for(int i = 0; i < n; ++i) {
            scanf("%lld", a + i);
            b[i] = -a[i];
        }
        for(int i = 0; i <= n; ++i) g[i] = INF;
        for(int i = n-1; i >= 0; --i) {
            k = lower_bound(g+1, g+n, b[i]) - g;
            g[k] = b[i];
            d[i] = k;
        }
        ll ans = 0;
        for(int i = 0; i <= n; ++i) g[i] = INF;
        for(int i = m; i < n; ++i) {
            k = lower_bound(g+1, g+n, a[i]) - g;
            //pr(i);prln(k);
            ans = max(ans,k+d[i]-1);
            k = lower_bound(g+1, g+n, a[i-m]) - g;
            g[k] = a[i-m];
        }
        k = lower_bound(g+1, g+n, INF-1) - g;
        ans = max(ans,k-1);
        cout << ans << "\n";
    }
    return 0;
}
