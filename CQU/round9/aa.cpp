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
const int maxn = 2e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    ll ans, n, t;
    cin>>t;
    while(t--){
    	cin >> n;
    	ans = 0;
    	ans = ans + n*n*(n+1)*(2*n+1)/6 -n*n*(n+1)*(n+1)/4+n*(n+1)*(2*n+1)/6;
    	ans = ans - (n*n*(n+1)*(n+1)+n*(n+1)-n*(n+1)*(2*n+1))/12;
    	ans = ans + n*n*(n+1)*(2*n+1)/6;
    	ans = ans + n*(n+1)*(2*n+1)/6 + n*n*(n+1)*(n+1)/4;
    	ans = ans + n*n*n*(n+1)/2;
    	cout << ans << "\n";
    	ans = 0;

    }
    return 0;
}