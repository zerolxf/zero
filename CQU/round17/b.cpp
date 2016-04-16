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
const double esp = 1e-6;
double sum, x, y;
ll n, a, b, c;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    while(cin >> n >> a >> b >> c && (n+a+b+c) != 0) {
        sum = 0;
        sum += a*9.0 + b*4.0 + c*4.0;
        x = 9.0/2 + 4.0;y = 0;
        bool ok = true;
        if(a) y += 4.5;
        if(b) y += 2.0;
        if(c) y += 2.0;
      //  prln(y);prln(x);prln(sum);prln(n);
        if((sum - n <= y && sum >= n)||( n - sum < x&& n > sum)) ok = true;
        else ok = false;
        if(ok) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
