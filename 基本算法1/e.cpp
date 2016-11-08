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
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    ll s, d, ans;
    while(cin >> d >> s) {
        ans = s*(-12);
        if(d*4 < s) {
            ans = max(ans, 10*d-2*s);
        }
        if(d*3 < s*2) {
            ans = max(ans, 8*d-4*s);
        }
        if(d*2 < s*3) {
            ans = max(ans, 6*d-6*s);
        }
        if(d < s*4) {
            ans = max(ans, 3*d-9*s);
        }
        if(ans> 0) {
            cout << ans << "\n";
        } else cout << "Deficit\n";
    }
    return 0;
}
