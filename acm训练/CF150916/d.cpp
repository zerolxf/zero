
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
const int maxn = 2e5+100;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
int cnt[70];
ll a[maxn];
void getcnt(ll x) {
    for(int i  = 0;;++i) {
        if(x%2 == 1) cnt[i]++;
        x=x/2;//prln(x);
      //  prln(i);
        if(x == 0) return;

    }
}
void getcnt2(ll x) {
    for(int i  = 0;;++i) {
        if(x%2) cnt[i]--;
        x=x/2;
        if(x == 0) break;
      //  prln(x+1);
    }
}
ll getans() {
    ll ans = 0, base = 1;
    for(int i = 0; i < 70; ++i) {
        if(cnt[i]) ans +=base;
        base*=2;

      //  prln(ans);
    }
    return ans;
}
int main(){
#ifdef LOCAL
   // freopen("C:\\Users\\User Soft\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\User Soft\\Desktop\\out.txt","w",stdout);
 #endif
    int n, k, x;
    ll ans = 0, t , c = 1;
    cin >> n >> k >> x;
  //  prln(n);prln(k);prln(x);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        getcnt(a[i]);
    }
    for(int j = 0; j < k; ++j) c*=x;
    for(int i = 0; i < n; ++i) {
        getcnt2(a[i]);
        t = getans();
        getcnt(a[i]);
       // pr(t);prln(a[i]*c);
        t = t|(a[i]*c);
        ans = max(ans, t);
      //  prln(ans+1);
    }
    cout << ans << endl;
return 0;
}
