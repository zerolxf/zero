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
double dp[1234][1234], p[1234];
ll base[30], num[30];
ll getans(ll x){
	int pos = 0;
	ll xx = x, ans = 0;
	if(x==0) return 0;
	while(x){
		num[pos++] = x%10;
		x/=10;
	}
	pos--;//prln(pos);
	if(num[pos] == 1){
		ans += xx-(num[pos]*base[pos]) + 1;
		//prln(ans);
	} else{
		ans += base[pos];
	}
	for(int i = 0; i < pos; ++i){
		ans += base[i];
	}
	//prln(pos);prln(ans);
	return ans;
}
ll l[maxn], r[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, k;
    base[0] = 1;
    for(int i = 1; i <= 19; ++i){
    	base[i] = base[i-1]*10;
    }
    cin >> n;
    for(int i = 1; i <= n; ++i){
    	cin >> l[i] >> r[i];
    	//prln((r[i]-l[i]+1));prln(getans(r[i]));prln(getans(l[i]-1));
    	p[i] = (getans(r[i])-getans(l[i]-1))*1.0/(r[i]-l[i]+1);
    	//cout << p[i] << "\n";
    }
    cin >> k;
    dp[0][0] = 1;

    for(int i = 1; i <= n; ++i){
    	for(int j = 0; j <= n; ++j){
    		dp[i][j] = 0;
    		if(dp[i-1][j] >= 0) dp[i][j] += dp[i-1][j]*(1-p[i]);
    		if(dp[i-1][j-1]>=0) dp[i][j] += +dp[i-1][j-1]*p[i];
    	}
    }
    double ans = 0;
    for(int i = 0; i <= n; ++i){
    	if(100*i>=k*n){
    		ans += dp[n][i];
    	}
    }
    printf("%.15f\n",ans );
    return 0;
}