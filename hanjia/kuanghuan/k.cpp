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
const int maxn = 1e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)      // cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define pt()// cout << "******************************\n\n";
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int dp[maxn], prime[maxn], vis[maxn],  cnt, a[maxn], n, last[maxn];
void getprime() {
	cnt  = 0;
	for(ll i = 2 ; i < maxn; ++i) {
		if(!vis[i]) {
			prime[cnt++] = i;
			for(ll j=i*i; j < maxn; j+=i) {
				vis[j] = true;
			}
		}
	}
}


int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    cin >> n;
    MEM(last,-1);
    for(int i = 1; i <= n; ++i) dp[i] = 1;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    getprime();
	for(int i = 1; i <= n; ++i) {
		int x = a[i];
		for(int j = 0; j < cnt; ++j) {
			if(x%prime[j]==0) {
				if(last[j] != -1)	dp[i] = max(dp[last[j]] + 1,dp[i]);
				last[j] = i;
				while(x%prime[j]==0) {
					x/=prime[j];
				}
			}
			if(x==1) break;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) ans = max(ans,dp[i]);
	cout << ans << "\n";
    return 0;
}