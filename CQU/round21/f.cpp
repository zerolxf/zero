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
double n, l, a, b, c, d, det, alph, e, f;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    while(cin >> n >> l) {
        a = 2.0*l;
        b = 2.0*(n*n-n*l-(n-l)*(n-l));
        b = 2.0*(n-l)*l;
        c = 2.0*n*(n-l)*(n-l)-n*n*n;
       // pr(a);pr(b);pr(c);
        det = b*b - 4*a*c;
        bool ok = true;
      //  prln(det);
        if(det < 0) ok = false;
        if(ok) {
            if(abs(a) < 1e-8) {
                if(abs(b) < 1e-8){
                    ok = false;
                }
                else e = c/b;
            }
            else{ e = (-b+sqrt(det))/(2*a);
            }
            if(e < 1e-9 || e > n) ok = false;
        }
        if(ok) printf("%.2f\n",e);
        else printf("Oh, my god!\n");
    }
    return 0;
}
