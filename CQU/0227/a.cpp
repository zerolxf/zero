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
bool vis[50][50];
int mp[100][100];
int n, m, n1, m1;
int ans, x;
void getvisr(int x, int y) {
	ans++;
	if(x<0) x = 0;
	if(y<0) y =0;
	for(int i = x; i < x+n1; ++i) {
		for(int j = y; j < y+m1; ++j)
		{
			vis[i][j] = false;
		}
	}
}

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    while(cin >> n >> m) {
    	CLR(vis);
    	ans = 0;
    	for(int i = 0; i < n; ++i){
    		for(int j = 0; j < m; ++j){
    			scanf("%d",&x);
    			if(x==1) vis[i][j] = true;
    			else vis[i][j] = false;
    		}
    	}
    	cin >> n1 >> m1;
    	int cnt = (m+1)/2;
    	for(int k = 0; k < cnt; ++k) {
    		for(int i = 0; i < n-1; ++i) {
    			if(vis[i][k]) getvisr(i,k);
    			if(vis[i][m-1-k]) getvisr(i,m-m1-k);
    		}
    		if(vis[n-1][k]) getvisr(n-n1,k);
    		if(vis[n-1][m-1-k]) getvisr(n-n1,m-m1-k);
    	}
    	printf("%d\n", ans);
    }
    return 0;
}