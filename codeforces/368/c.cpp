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
ll qq[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    int cntq = 0;
    memset(qq,0x3f,sizeof qq);
    for(ll i = 1; i < 4e5; ++i){
        qq[cntq++] = i*i;
    }
    ll n;
    while(cin>>n){
        bool ok = false;
        ll m, k;
        if(n%2==0){
            n/=2;
            m = n*n-1;
            k = n*n+1;
            ok = true;
        }else{
            ll ma = cntq;
            for(ll i = 0; i < ma; ++i){
                //if(qq[i] > ma) break;
                if(ok) break;
                ll a = qq[i];
                ll b = n-qq[i];
                if(b<=0) continue;
                //ll pos = lower_bound(qq,qq+cntq,b)-qq;
                ll bb = sqrt(b+0.5);

                if(bb*bb==b){
                    m = a-b;
                    if(m<0) m=-m;
                    k = (bb)*(i+1)*2;
                 //   prln(k);prln(bb);
                    ok = true;
                }
            }
            if(!ok){
                for(ll i = 0; i < ma; ++i){
                    if(ok) break;
                    ll a = qq[i];
                    ll b = n-qq[i];
                    if(b>0&&b%((i+1)*2)==0){
                        ll nn = b/((i+1)*2);
                        ll mm = nn*nn+n;
                        ll mmm = sqrt(mm+0.5);
                        if(mmm*mmm==mm){
                            m = mm + nn*nn;
                            k = mmm*nn*2;
                            if(m>1e18||k>1e18||m<=0||k<=0) continue;
                            ok = true;
                        }
                    }
                }
            }
        }
        if(m<=0||k<=0) ok = false;
        if(ok) {
            cout<<m << " " << k<<"\n";
        }else{
            cout<<"-1\n";
        }

    }
    return 0;
}
