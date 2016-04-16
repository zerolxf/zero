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
struct Node{
	int l, r;
	bool operator <(const Node& rhs)const{
		return l < rhs.l || (l==rhs.l && r < rhs.r);
	}
};
int girl[maxn], n;
bool  used[50], vis[1100];
int link[110][110];
bool find(int x) {
	int i, j;
	for(int i = 1; i <= n; ++i) {
		if(link[x][i] !=0 && used[i] == false) {
			used[i] = true;
			if(girl[i]==0 || find(girl[i])) {
				girl[i] = x;
				//id[link[x][i]] = 
				return true;
			}
		}
	}
	return false;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int  m, x, y;
    while(cin >> n >> m) {
    	CLR(vis);
    	CLR(girl);
    	rep(i,n+1) rep(j,n+1) link[i][j] = false;
    	for(int i = 1; i <= m; ++i) {
    		scanf("%d%d", &x, &y);
    		link[x][y] = i;
    	}
    	int ans = 0;
    	for(int i = 1; i <= n; ++i) {
    		CLR(used);
    		if(find(i)) ans++;
    	}
    	for(int i = 1; i <= n; ++i) {
    		vis[link[girl[i]][i]] = true;
    		vis[link[i][girl[i]]] = true;
    	}
    	//ans = m-ans;
    	ans  = 0;
    	for(int i = 1; i <= m; ++i) if(vis[i]) ans++;
    	ans = m-ans;
    	printf("%d\n", ans);
    	int cnt = 0;
    	for(int i = 1; i <= m; ++i) {
    		if(!vis[i]) {
    			printf("%d", i); 
	    		if(++cnt == ans) printf("\n");
	    		else printf(" ");
    		}
    	}
    	//printf("\n");
    }
    return 0;
}