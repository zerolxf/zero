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
const  double eps = 1e-15;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
bool small(double alpha, double k,double a, double newlen){
    return sin(alpha)*newlen<=a*alpha+eps;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    double a, b, c, ans, l, r, newlen, k;
    while(cin >> a >> b >> c ){
        if(a<0||b<0||c<0) break;
        newlen = a*(1+b*c);
        k = a/newlen;
        l = 0, r = acos(-1)/2;
        while(r-l > eps) {
            double m = (l+r)/2;
            if(small(m, k, a, newlen)) r = m;
            else l = m;
        }
        a = a/2.0;
        l = l/2.0;
        ans = a*tan(l);
        printf("%.3lf\n",ans);
    }
    return 0;
}
