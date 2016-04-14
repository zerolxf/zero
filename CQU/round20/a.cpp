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
const int N = 2;
int m;
struct Ret{
    ll a[N][N];
    Ret(){
        memset(a,0,sizeof a);
        rep(i,N) a[i][i] = 1;
    }
    Ret operator *(const Ret& rhs){
        Ret ans;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                ll temp = 0;
                for(int k = 0; k < N; ++k){
                    temp = (temp + a[i][k]*rhs.a[k][j])%m;
                }
                ans.a[i][j] = temp;
            }
        }
        return ans;
    }
    void reduce(){

    }
};

Ret get(Ret x, int y){
    Ret ans;
    if(y == 0) return ans;
    if(y%2 == 1) ans = ans*x;
    ans = ans*get(x*x,y/2);
    return ans;
}

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    ll a, b, n;
    while(scanf("%lld%lld%lld%lld",&a,&b,&n,&m) != EOF){
        Ret now;
        ll t1 = a*2%m, t2 = (2*a*a + 2*b+m)%m;
        if(n == 1){
            printf("%lld\n",(t1+m)%m);
            continue;
        }
        now.a[0][0] = (m+a*2)%m;
        now.a[0][1] = (b-a*a+m)%m;
        now.a[1][0] = 1;
        now.a[1][1] = 0;
        now = get(now,n-2);
        ll ans = ((now.a[0][0]*t2 + now.a[0][1]*t1)%m+m)%m;
        printf("%lld\n",ans);
    }
    return 0;
}
