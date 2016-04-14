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
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
#define rep(i,n) for(int i = 0; i < n; ++i)
ll m, pri, n;
ll a[10];
ll getsum(ll x) {
    ll sum = 0;
    for(int i = 0; i < n; ++i){
        sum += a[i];sum*=x;
    }
    return sum+a[n];
}
void fun() {
  //  prln(pri);
    for(ll i = 0; i < pri; ++i) {
        if(getsum(i)%pri == 0) {
            for(ll j = i; j < i + pri*pri; j+=pri){
                if(getsum(j)%(pri*pri) == 0) {
                    printf("%lld\n",j);
                    return;
                }
            }
        }
    }
    printf("No solution!\n");
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int t;
    int kase = 0;
    scanf("%d",&t);
    while(t--) {
        scanf("%lld",&n);
        for(int i = 0; i <= n; ++i){
            scanf("%lld",&a[i]);
        }
        scanf("%lld",&pri);
        printf("Case #%d: ",++kase);
        fun();
    }
    return 0;
}
