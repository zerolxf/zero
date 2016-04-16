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
const int maxn = 1e6;
const int INF = 0x3f3f3f3f;
const int mod = 1000000007;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
ll c[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    ll m,n;
    scanf("%lld%lld",&m,&n);
    for(ll i = 1;i <= n;i++)
        scanf("%lld",&c[i]);
    ll ans = 0;
    for(ll i = 1;i <= n;i++)
    {
        if(c[i]%m == 0)
        {
            ll temp = c[i]/m;
            ans = (ans + ((m*(m - 1)/2)%mod)*temp)%mod;
        }
        else
        {
            ll temp = c[i]/m;
            ll num1 = c[i]%m;
            ll num2 = m - num1;
            ans = (ans + ((num1*(num1 - 1)/2)%mod)*(temp + 1))%mod;
            ans = (ans + ((num2*(num2 - 1)/2)%mod)*temp)%mod;
            ans = (ans + ((num1*num2)%mod)*temp)%mod;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
