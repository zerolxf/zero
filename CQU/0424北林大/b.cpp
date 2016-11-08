/*************************************************************************
    > File Name: b.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月24日 星期日 13时07分02秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
int dx[] = {
	1, 2, 2, 1, -1, -2, -2, -1
};
int dy[] = {
	-2, -1, 1, 2, 2, 1, -1, -2 
};
int fx[] = {
	0, 1, 1, 0, 0, -1, -1, 0
};
int fy[] = {
	-1, 0, 0, 1, 1, 0, 0, -1
};
int dis[150][150];
bool mp[150][150];
bool vis[150][150];
bool in[150][150];
int n, m, dex, dey;
void spfa(int s) {
	memset(in, 0, sizeof in);
	for(int i = 0; i < 150; ++i){
		for(int j = 0; j  < 150; ++j){
			dis[i][j] = INF;
		}
	}
	int srx = s%1000;
	int sry = s/1000;
	dis[sry][srx] = 0;
	in[sry][srx] = true;
	queue<int> q;
	q.push(s);
	int ffx, ffy, nx, ny, v;
	while(q.size()) {
		int u = q.front();q.pop();
		int x = u%1000;
		int y = u/1000;
		in[y][x] = false;
		for(int i = 0; i < 8; ++i){
			ffx = x + fx[i];
			ffy = y + fy[i];
			if(ffx < 0 || ffy <0 || ffx >= m || ffy >= n) continue;
			if(!vis[ffy][ffx]) continue;
			nx = x + dx[i];
			ny = y + dy[i];
			if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if(!vis[ny][nx]) continue;
			if(dis[ny][nx] > dis[y][x] + 1) {
				dis[ny][nx] = dis[y][x] + 1;
				v = ny*1000 + nx;
				if(!in[ny][nx]) {
					q.push(v);
					in[ny][nx] = true;
				}
			}
		}
	}
}
char s[150];
int sx, sy;
void solve(){
	memset(vis, 0, sizeof vis);
	for(int i = 0; i < n; ++i){
		scanf("%s", s);
		for(int j = 0; j < m; ++j){
			if(s[j] == 's'){
				sx = j; sy = i;
				vis[i][j] = true;
			} else if(s[j] == 'e'){
				dex = j; dey = i;
				vis[i][j] = true;
			} else if(s[j] == '.'){
				vis[i][j] = true;
			} else vis[i][j] = false;
		}
	}
	spfa(sy*1000+sx);
	if(dis[dey][dex] >= INF) {
		printf("-1\n");
	} else printf("%d\n",dis[dey][dex]);
}

int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	while(cin >> n >> m){
		solve();
	}
	return 0;
}
