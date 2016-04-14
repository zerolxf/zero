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
const int maxn = 1e6+100;
const int INF = 0x7f7f7f7f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
ll dp[maxn];
int cc[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, a;
    dp[1] = 2;
    for(int i = 2; i <= 1000003; ++i) {
    	dp[i]  = (dp[i-1]*2*i)%1000003;
    }
    cin >> n;
    while(n--) {
    	cin >> a;
    	if(a >= 1000003) cout << "0\n";
    	else cout << dp[a] << "\n";
    }
    MEM(cc,0x7f);
    prln(cc[0]);
    prln(INF);
    return 0;
}