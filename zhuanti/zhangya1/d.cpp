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
char dp[16][16][1<<16];
int x[20], y[20];
bool line[17][17][17];
inline bool ok (int i, int j, int k){
	if((y[j]-y[i])*(y[k]-y[i]) < 0 || (x[j]-x[i])*(x[k]-x[i]) < 0) return false;
	return (y[j]-y[i])*(x[k]-x[i])==(y[k]-y[i])*(x[j]-x[i]);
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int t = 2, n, kase = 0;
    cin >> t;
    while(t--){
    	scanf("%d",&n);
    	for(int i = 0; i < n; ++i){
    		scanf("%d%d",x+i,y+i);
    	}
    	int total = 1<<n;
    	rep(i,n) rep(j,n) rep(k,n) line[i][j][k] = ok(i,j,k);
    	rep(i,n) rep(j,n) rep(k,total) dp[i][j][k] = INF;
    	rep(i,n){
    		rep(j,n){
    			if(i==j) continue;
    			dp[i][j][(1<<i)^(1<<j)] = 1;
    		}
    	}
    	for(int i = 0; i < total; ++i){
    		if((i&(-i)) == i) continue;
    		
    	}

    }
    return 0;
}