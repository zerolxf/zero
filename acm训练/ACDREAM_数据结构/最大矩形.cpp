
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
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
ll dpl[maxn], dpr[maxn], h[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int n;
    while(cin >> n) {
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", h + i);
            dpl[i] = dpr[i] = i;
        }
        for(int i = 1; i <= n; ++i) {
            ll ans = dpl[i];
            while(ans - 1 > 0 && h[ans-1] >= h[i]) {
                ans = dpl[ans - 1];
            }
            dpl[i] = ans;
        }
        for(int i = n; i > 0; --i) {
            ll ans = dpr[i];
            while(ans + 1 <= n&& h[ans+1] >= h[i]) {
                ans = dpr[ans + 1];
            }
            dpr[i] = ans;
        }
        ll ans = 0;
        for(int i = 1;i <= n; ++i) {
            ans = max(ans, (dpr[i] - dpl[i] + 1)*h[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
