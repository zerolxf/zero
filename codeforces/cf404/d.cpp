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
const int MOD = 1e9+7;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
ll lsum[maxn], rsum[maxn];

char s[maxn];
ll dfs(int m, int n){
	if(m == 0 || n == 0) return 0;
	int mi = min(m,n), ma = max(m,n);
	ll ans = (1<<mi)%MOD;
	return
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
 #endif
    scanf("%s", s+1);
    int len = strlen(s+1);
    memset(dp, 0, sizeof dp);
    memset(lsum, 0, sizeof lsum);
    memset(rsum, 0, sizeof rsum);
    for(int i = 1; i <= len; ++i){
    	if(s[i] == '('){
    		lsum[i] = lsum[i-1] + 1
    	}else lsum[i] = lsum[i-1];
    	if(s[n+1-i] == ')') rsum[n+1-i] = rsum[n+2-i] + 1;
    	else rsum[n+1-i] = rsum[n+2-i]; 
    }

    return 0;
}

