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
#define pr(x)      // cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int dp[2][8200][8200];
char vis[8200][8200];
const int total = 8192;
int a[100];
struct Node{
	int i,j;
}q[64000000];

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int now = 0, pre = 1, n;
    dp[now][0][total-1] = 1;
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i) {
    	scanf("%d",&a[i]);
    }
    int ntail = 0, ii, jj, qi, qj, ptail = 0;
    q[ntail++] = Node{0,total-1};
    for(int i = 1; i <= n; ++i) {
    	swap(now,pre);
    //	swap(ptail, ntail);
    	//memset(dp[now],0, sizeof dp[now]);
    	ptail = ntail;
    	prln(ptail);
    	for(int j = 0; j < ptail; ++j) {
    		qi = q[j].i;
    		qj = q[j].j;
    		dp[now][qi][qj] = dp[pre][qi][qj];
    		vis[qi][qj] = i;
    	}
    	for(int j = 0; j < ptail; ++j) {
    		qi = q[j].i;
    		qj = q[j].j;
    		ii = qi^a[i];
    		jj = qj&a[i];
    		//pr(qi);pr(qj);pr(ii);prln(jj);
    		if(!vis[ii][jj] ) {
    			q[ntail++] = Node{ii,jj};
    			vis[ii][jj] = -1;
    		}
    		if(vis[ii][jj] != i){
    			vis[ii][jj] = i;
    			dp[now][ii][jj] = 0;
    		}
    		dp[now][ii][jj] += dp[pre][qi][qj];
    		//dp[now][qi][qj] += dp[pre][qi][qj];
    		//pr(dp[now][ii][jj]);prln(dp[now][qi][qj]);
    	}
    }
    ll ans = 0;
    for(int i = 0; i < total; ++i) {
    	ans += dp[now][i][i];
    }
    cout << ans << "\n";
    return 0;
}