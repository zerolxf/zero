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
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
inline int ma(const int& x, const int& y) {
	return x >y ? x:y;
}
int dp[110][11110], v[110][110], suml[110], sumr[110], num[110], a[110];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
    	scanf("%d", &num[i]);
    	suml[0] = sumr[num[i]+1] = 0;
    	for(int j = 1; j <= num[i]; ++j) {
    		scanf("%d", &a[j]);
    	}
    	for(int j = 1; j <= num[i]; ++j) suml[j] = suml[j-1] + a[j];
    	for(int j = num[i]; j >= 1; --j) sumr[j] = sumr[j+1] + a[j];
    	for(int j = 0; j <= num[i]; ++j){
    		v[i][j] = 0;
    		for(int l = 0; l <= j; ++l) {
    			v[i][j] = ma(v[i][j],suml[l]+sumr[num[i]-(j-l)+1]);
    			//pr(i);pr(j);pr(l);pr(suml[l]);pr(sumr[num[i]-(j-l)+1]);prln(v[i][j]);
    		}
    	}
    }
   // MEM(dp,0);
   // CLR(dp[0]);
    for(int i = 1; i <= n; ++i){
    	for(int j = 0; j <= num[i]; ++j) {
    		for(int l = m; l >= 0; --l) {
    			if(l >= j) dp[i][l] = ma(dp[i][l],dp[i-1][l-j]+v[i][j]);
    			else dp[i][l] = ma(dp[i][l],dp[i-1][l]);
    		} 
    	}
    }
    int ans = 0;
    for(int j = 0; j <= n; ++j)
    for(int i = 0; i <= m; ++i) {
    	if(dp[j][i] > ans) ans = dp[j][i];
    }
    cout << ans << "\n";
    return 0;
}