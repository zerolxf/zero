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
#define MN(a,b,n) memset(a,b,(n)*sizeof(int))
int x1[maxn], x2[maxn], y1[maxn], y2[maxn], head[maxn], nxt[maxn], to[maxn], cnt, n;
void addegde(int u, int v) {
	nxt[cnt] = head[u];
	head[u] = cnt;
	to[cnt++] = v;
}
bool judge1(int id, int o) {
	if(x1[id] == x2[id]) {
		if(y1[id] <= y1[o] && y2[id] >= y2[o] && x1[id] <= x2[o] && x1[id] >= x1[o]) return true;
	}
	if(y1[id] == y2[id]) {
		if(x1[id] <= x1[o] && x2[id] >= x2[o] && y1[o] <= y1[id] && y2[o] >= y2[id]) return true;
	}
	return false;
}
bool vis[maxn];
int bfs() {
	//queue<int> q;
	int ans = 0;
	//prln(ans);
	for(int i = n; i >= 1; --i) {
		//pr(i);prln(vis[i]);
		if(vis[i]) {
			ans++;
			for(int j = 1; j < i; ++j) {
				if(judge1(i,j)) vis[j] = true;
			}
		}
	}
	return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int  q, lx, rx, ly, ry;
    while(cin >> lx >> ly >> rx >> ry) {
    	cin >> n >> q;
    	for(int i = 1; i <= n; ++i) {
    		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    		if(x1[i] > x2[i]) swap(x1[i], x2[i]);
    		if(y1[i] > y2[i]) swap(y1[i], y2[i]);
    	}
    	for(int i = 0; i < q; ++i) {
    		cin >> x1[0] >> y1[0] >> x2[0] >> y2[0];
    		if(x1[0] > x2[0]) swap(x1[0], x2[0]);
    		if(y1[0] > y2[0]) swap(y1[0], y2[0]); 
    		MN(vis,0,n+2);
    		for(int j = 1; j <= n; ++j) {
    			if(judge1(j,0)) {
    				vis[j] = true;
    				//prln(j);
    			}
    		}
    		//prln(vis[1]);
    		int ans = bfs();
    		printf("%d\n", ans);
    		//prln(ans);
    	}
    }
    return 0;
}