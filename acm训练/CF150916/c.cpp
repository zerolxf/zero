
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
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long

int main(){
#ifdef LOCAL
   // freopen("C:\\Users\\User Soft\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\User Soft\\Desktop\\out.txt","w",stdout);
 #endif
    int a, b; double ans;
    while(cin >> a >> b) {
        ans = 1e9+1.1;
        if(a < b) {
            cout << "-1\n";
            continue;
        } else if(a == b) {
            cout << a << "\n";
            continue;
        }
        int k = (a/b+1)/2;
        if(k != 0) {
            ans = min(ans, (a+b)*1.0/(2.0*k));
        }
        k = (a/b - 1)/2;
        if(k > 0) {
            ans = min(ans, (a-b)*1.0/(2.0*k));
        }
        printf("%.12f", ans);
    }
return 0;
}
