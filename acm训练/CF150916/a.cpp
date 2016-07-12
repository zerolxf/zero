
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
    ll x, ans ;
    while(cin >> x){
            ans = 0;
        while(x) {
            ans += (x%2);
            x  = x/2;
        }
        cout << ans << endl;
    }
    return 0;
}
