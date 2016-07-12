#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 4e5+1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
ll m, ans, dp[maxn];
ll getans(ll x){
    ll ans = 0;
    for(ll i = 2; ; ++i){
        ll xx = i*i*i;
        if(xx>x) return ans;
        ans += x/(xx);
        if(ans>1e15) return 1e15+100;
    }
    return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    while(cin >> m){
        ll l = 1, r = 1e16;
        while(l < r){
            ll mid = l + r >> 1;
          //  pr(l);prln(r);
         //  prln(mid);
        //   prln(getans(mid));
            if(getans(mid) > m) r = mid-1;
            else if(getans(mid) == m) {
                r = mid;

            }
            else l = mid+1;
        }
        if(getans(l)!=m) printf("-1\n");
        else cout << l << "\n";
    }
    return 0;
}
