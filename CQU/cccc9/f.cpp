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
const int maxn = 1e6+1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
bool isprime[maxn];
bool vis[maxn];
int prime[maxn];
int cnt;
const int N = 1e6+100;
void getprime() {
    cnt = 0;
    for(ll i = 2; i <= N; ++i){
        if(vis[i]) continue;
        isprime[i] = true;
        prime[cnt++] = i;
        for(ll j = i*i; j <= N; j+=i){
            vis[j] = true;
        }
    }
}
int ans[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    getprime();
    ll a, d, n;
    while(cin >> a >> d >> n && (a+d+n)!=0){
        int c = 0;
        a-=d;
      //  pr(a);pr(d);prln(n);
        while(c < n){
            a+=d;
         //   prln(a);
            while(!isprime[a]) a+=d;
            c++;
        }
        printf("%lld\n",a);
    }
    return 0;
}
