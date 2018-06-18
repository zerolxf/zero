
/*
* @author:  liangxianfeng
* @mail: liangxianfeng96@qq.com
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define repp(i,n,x) for(int i =x; i < n+x; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl;
const int MOD = 1e9+7;
const int maxn = 1e5+100;
const int INF = 0x3f3f3f3f;
ll a[maxn], b[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    int n;
    cin >>n;
    rep(i,n) cin >> a[i+1];
    rep(i,n-1) {
    	b[i+1] = abs(a[i+2] - a[i+1]);
    }
    ll ans = 0, misum = 0, sum = 0;
    for(int i = 1; i < n; ++i){
    	ll num = -1;
    	if(i&1) num *= -1;
    	sum += num*b[i];
    	ans = max(ans, sum-misum);
    	misum = min(misum, sum);
    }
    misum = 0, sum = 0;
    for(int i = 2; i < n; ++i){
    	ll num = 1;
    	if(i&1) num *= -1;
    	sum += num*b[i];
    	ans = max(ans, sum-misum);
    	misum = min(misum, sum);
    }
    cout<<ans<<endl;
    return 0;
}
