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
int num[10];
int vis[maxn];
int getnxt(int x) {
    int xx = x*x;
    for(int i = 0; i <= 5; ++i){
        num[i] = xx%10;
        xx/=10;
    }
    int ans = 0;
    for(int i = 5; i >= 2; --i){
        ans = ans*10+num[i];
    }
    return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n;
    int x, kase = 0;
    while(cin >> x && x){
        int ans = 0;
        kase++;
        while(vis[x] != kase) {
            ans++;
            vis[x] = kase;
            x = getnxt(x);
        }
        cout << ans << "\n";
    }
    return 0;
}
