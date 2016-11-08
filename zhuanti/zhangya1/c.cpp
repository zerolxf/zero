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
int dp[1<<18], a[18][18];
inline int getbit(int x){
	int ans = 0;
	while(x){
		ans++;
		x-=x&(-x);
	}
	return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int t, n, kase = 0;
    cin >> t;
    while(t--){
    	scanf("%d",&n);
    	for(int i = 0; i < n; ++i){
    		for(int j = 0; j < n; ++j){
    			scanf("%d",&a[i][j]);
    		}
    	}
    	int total = 1<<n;
    	//rep(i,n+1)
    		rep(j,total) dp[j] = 0;
    	for(int j = 0; j < total; ++j){
    		int i = getbit(j);
    		
    			//if(getbit(j) != i) continue;
    			for(int k = 0; k < n; ++k){
    				if(j&(1<<k)) continue;
    				dp[j^(1<<k)] = max(dp[j^(1<<k)], dp[j] + a[i][k]);
    			}
    		//}
    	}
    	printf("Case %d: %d\n",++kase, dp[total-1]);
    }
    return 0;
}