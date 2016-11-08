
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
const int maxn = 1e5+100;
const double ep = 1e-9;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
double p,q,r,s,t,u;
double get(double x) {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    double x, l, r, mid;
    while(scanf("%lf%lf%lf%lf%lf%lf", &p, &q, &r, &s, &t, &u) != EOF) {
        if(abs(p + r - q - s - t)<ep ) {
            cout << "0.0000\n";
            continue;
        }
        double ans1 = get(1e-9), ans2 = get(1.0);
        if((ans1 > ep && ans2 > ep) || (ans1 < -ep && ans2 < -ep)) {
            cout << "No solution\n";
        }
        else {
            l = 0, r = 1.0;
            int t = 100;
            while(t--) {
                mid = (l+r)/2.0;
                if(get(mid) > ep) l = mid;
                else r = mid;
            }
            printf("%.4f\n%.7f\n", l,get(r));

        }
    }
    return 0;
}
