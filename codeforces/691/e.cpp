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
#define pr(x)    //   cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int n;
const int MOD= 1e9+7;
struct Rec{
    ll num[110][110];
    Rec(){
        memset(num,0,sizeof num);
        for(int i = 1; i <= n; ++i) num[i][i] = 1;
    }
    Rec operator * (const Rec& rhs)const{
        Rec ans;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                ans.num[i][j] = 0;
                for(int k = 1; k <= n; ++k){
                    ans.num[i][j] = (ans.num[i][j]+num[i][k]*rhs.num[k][j])%MOD;
                }
                ans.num[i][j] = ans.num[i][j]%MOD;
                pr(i);pr(j);prln(ans.num[i][j]);
            }
        }
        return ans;
    }
};
void print(Rec &x){
    return;
    for(int i = 1; i <= n;++i){
        for(int j = 1; j <= n; ++j){
            cout << x.num[i][j] << " ";
        }
        cout << "\n";
    }
}
ll ret(Rec& x, ll y){
    Rec ans;
    prln("x");
    print(x);
    while(y){
        if(y&1) ans = ans*x;
        x = x*x;
        y>>=1;
        prln(y);
        print(x);
        prln("ans");print(ans);

    }
    ll cnt = 0;
    for(int i = 1; i <= n;++i){
        for(int j = 1; j <= n; ++j){
            cnt = (cnt + ans.num[i][j])%MOD;
        }
    }
    return cnt;
}

ll a[maxn];
int get(ll x){
    int ans = 0;
    for(int i = 0; i < 64; ++i){
        if((x>>i)&1) ans++;
    }
    return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif

    ll y;
    while(cin >> n >> y){
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        Rec ans;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(get(a[i]^a[j])%3==0) {
                        ans.num[i][j] = 1;
                        pr(i);prln(j);
                }
                else ans.num[i][j] = 0;
            }
        }
        prln("ans");
        print(ans);
        ll cnt = ret(ans, y-1);
        cout <<cnt <<"\n";
    }
    return 0;
}
