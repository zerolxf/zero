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
int num[40];
void getnum(ll x) {
    for(int i = 0; i < 33; ++i){
        num[i] = x&1;
        x >>= 1;
    }
}
ll dp[110][110];
ll getans(int pos, int num1, int num0, int first, int flag) {
    if(pos == -1) return first && num0 >= num1;
    ll ans = dp[pos][num0-num1+50];
    if(!flag && first && ans != -1) return ans;
    ans = 0;
    int ma = flag?num[pos]:1;
    ans += getans(pos-1, num1, num0+first, first, flag&&(num[pos]==0));
    if(ma) ans += getans(pos-1, num1+1, num0, 1, flag&&(num[pos]==1));
    if(first && !flag) dp[pos][num0-num1+50] = ans;
    return ans;
}

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    memset(dp, -1, sizeof dp);
    ll l, r;
    while(cin >> l >> r){
        getnum(l-1);
        ll ansl = getans(33, 0, 0, 0, 1);
        getnum(r);
        ll ansr = getans(33, 0, 0, 0, 1);
        cout << ansr - ansl << "\n";

    }
    return 0;
}
