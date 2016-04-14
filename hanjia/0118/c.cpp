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
const int maxn = (1<<21)+100;
const int INF = 0x3f3f3f3f;
const int MOD = 1<<16;
const int N = 1<<20;
#define pr(x)       //cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define ll long long
struct Node{
	int s,dis;
	bool operator < (const Node& rhs)const{
		return dis > rhs.dis;
	}
};
inline int build(int x) {
	int ans = 0;
	while(x){
		ans++;
		x -= x&(-x);
	}
	return ans;
}
int dx[]={0, 1, 0, -1};
int dy[]={-1,0,1,0};
int flag[10][10];
int d[maxn], vis[maxn];
int move(int mp, int x,int y) {

	if(x >=0 && x <4 && y >= 0 && y < 4){
		int ans = (mp&(MOD-1)) + (x<<18)+(y<<16);
		return ans;
	}
	return -1;
}
void print(int x) {
	return;
	pr(x);pr(d[x]);int xx = x/(MOD*4); int yy  = (x>>16)%4;
	pr(x%MOD);pr(xx);prln(yy);
	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 4; ++j) {
			if(x &(1<<(i*4+j))) printf("1");
			else printf("0");
		}
		printf("\n");
	}
}

int bfs(int s) {
	for(int i = 0; i < maxn; ++i) {
		d[i] = INF;
		vis[i] = 0;
	}
	d[s] = 0;
	prln(s);print(s);
	priority_queue<Node> q;
	q.push(Node{s,0});
	int x, y, nx, ny,a ;
	while(q.size()) {
		Node xx = q.top(); q.pop();
		int u = xx.s%N;
		if(vis[u]) continue;
		vis[u] = true;
		x = (u >> 18)%4; y = (u >> 16)%4;
		//prln(u);pr(d[u]);pr(x);prln(y);print(u);
		for(int i = 0; i < 4; ++i) {
			nx = x+dx[i];
			ny = y+dy[i];
			a = nx+ny*4;
			int v = move(u,nx,ny);
			if(v == -1 ) continue;
			if(build(v&((1<<16)-1))>=6 ) {
				if((!(v&(1<<a))))
				continue;
			}

			v = (v^(1<<a));
			if(d[u] + 1 < d[v]) {
				d[v] = min(d[v],d[u]+1);
				pr(v);pr(d[v]);print(v);
				q.push(Node{v,d[v]});
			}
		}
	}
	int ans = INF;
	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 4; ++j) {
			int u = (j<<18)+(i<<16);
			ans = min(ans,d[u]);
		}
	}
	return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  	freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int t, x, y, s;
    char mp[10];
    scanf("%d", &t);
    while(t--) {
    	s = 0;
    	x = 0;
    	y = 0;
    	for(int i = 0; i < 4; ++i) {
    		scanf("%s", mp);
    		for(int j = 0; j < 4; ++j) {
    			if(mp[j] == '.') {
    				flag[i][j] = 0;
    			}
    			if(mp[j] == 'X') {
    				flag[i][j] = 1;
    				s = s | 1<<(i*4+j);
    			}
    			if(mp[j] == 'D') {
    				x = j;y = i;
    				flag[i][j] = 0;
    			}
    		}
    	}
    	for(int i = 0; i < 4; ++i){
    		for(int j = 0; j < 4; ++j) {
    			//printf("%d",flag[i][j]);
    		}
    		//printf("\n");
    	}
    	s = s|(x<<18) ;
    	s |= (y<<16);
    	//prln(s);pr(x);prln(y);
    	//print(s);
    	int ans = bfs(s);
    	if(ans == INF) {
    		printf("impossible;\n");
    	} else {
    		printf("%d\n", ans);
    	}
    }

    return 0;
}