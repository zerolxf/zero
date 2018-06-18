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
const int maxn = 2e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll unsigned long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
ll a, b, c;
    ll n, m;
ll get(ll x){
    return x*(x+1)/2 < n-m;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
 #endif
     //   ll x = 0-1;
  //  cout<<x<<endl;
    while(cin >> n >>m){
        if(n <= m){
            cout << n << endl;
        }else{
            ll ans = m;
            ll l = 1, r = 3e9;
            while(l < r){
                ll mid = (l+r)>>1;
                if(get(mid)) l = mid+1;
                else r = mid;
            }
            //ll i = 1;
            //for(i = 1; i*(i+1)/2 < n+m*(-1); ++i){}
            ans += l;
            ans = min(ans, n);
            cout << ans << endl;
        }
    }

    return 0;
}

