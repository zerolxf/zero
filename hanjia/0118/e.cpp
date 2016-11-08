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
ll dp[1100][1100], ;
ll dfs(int x, int y) {
	ll& ans = dp[x][y];
	if(ans != -1) return ans;
	if(x == 0 && y == 0) ans = 1;
	else if(x == 0 && y !=0 ){
		ans = 1<<(y-1);
	} else if(y==0) {
		return ans
	}
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    for(int i = 1; i <= 1000; ++i) {
    	for(int j = 0; j <= 1000; ++j) {
    		dp[i][j] = 
    	}
    }
    return 0;
}