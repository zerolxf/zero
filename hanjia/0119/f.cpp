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
const int maxn = (1<<16)+100;
const int INF = 0x3f3f3f3f;
#define pr(x)      // cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define ll long long
int n, m;
int dx[] = {1,2,2,1,-1,-2,-2,-1,   1,1,-1,-1,  1,0,-1,0};
int dy[] = {-2,-1,1,2,2,1,-1,-2,   -1,1,1,-1,  0,1,0,-1};
//0~8ma,8~12xiang,12~16che,8~16guowang
struct Node{
	bool chi[17][17];
}state[maxn];
char s[maxn];
bool vis[maxn<<8];
int cnt, hashpos[4000], idx[20], xx[20], yy[20], qizi[200];
inline bool ok(int nx, int ny) {
	if(nx >= 0 && ny >= 0 && nx < m && ny < n) return true;
	return false;
}
inline bool cango(const int& x,const int& y, const Node& sta) {
	if(ok(x,y) && sta.chi[y][x] == false) return true;
	return false;
}
//1che
void rook(int x, int y, Node& s,int sta) {
	int nx, ny, num;
	for(int i = 12; i < 16; ++i) {
		nx = x+dx[i]; ny = y+dy[i];
		while(ok(nx,ny)) {
			s.chi[ny][nx] = true;
			num = nx*16+ny;
			if(hashpos[num]!=-1&&(sta&(1<<hashpos[num]))) break;
			nx = nx+dx[i]; ny = ny+dy[i];
		}
	}
}
//2ma
void knight(int x, int y, Node& s,int sta) {
	for(int i = 0; i < 8; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(ok(nx,ny)) s.chi[ny][nx] = true;
	}
}
//3xiang
void bishop(int x, int y,Node& s, int sta) {
	int nx, ny, num;
	for(int i = 8; i < 12; ++i) {
		nx = x+dx[i]; ny = y+dy[i];
		while(ok(nx,ny)) {
			s.chi[ny][nx] = true;
			num = nx*16+ny;
			if(hashpos[num]!=-1&&(sta&(1<<hashpos[num]))) break;
			nx = nx+dx[i]; ny = ny+dy[i];
		}
	}
}
//1che,2ma,3xiang
void init() {
	memset(vis,0,sizeof vis);
	int N = 1<<cnt;
	int num;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < cnt; ++j) {
			if((i >> j)&1) {
				num = idx[j];
				if(num == 1) rook(xx[j],yy[j],state[i],i);
				if(num == 2) knight(xx[j],yy[j],state[i],i);
				if(num == 3) bishop(xx[j],yy[j],state[i],i);
			}
		}
	}
}

//8~16
typedef pair<int,int>  st;
//first 24:	(0~3:y,4~7:x,8~:step)	second state

int bfs(int x, int y, int sta) {
	queue<st> q;
	if(sta == 0) return 0;
	q.push(st{(x*16+y),sta});
	int nx, ny, step, xy, nxy, nsta, hashvis;
	while(q.size()) {
		st now = q.front(); q.pop();
		x = (now.first/16)%16;y = now.first%16;sta = now.second; 
		hashvis = (x<<20)+(y<<16)+sta;
		if(vis[hashvis]) continue;
		vis[hashvis] = true;
		step = (now.first)>>8;
		if(sta == 0) return step;
		for(int i = 8; i < 16; ++i) {
			nx = x + dx[i]; ny = y + dy[i];
			if(cango(nx,ny,state[sta])) {
				nxy = nx*16+ny;
				if(hashpos[nxy]!=-1) {
					nsta = sta&(~(1<<hashpos[nxy]));
					q.push(st{(step+1)*256+nx*16+ny,nsta});
				} else q.push(st{(step+1)*256+nx*16+ny,sta});
			}
		}
	}
	return -1;
}

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
 // freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    cnt = 0;
    int x, y, sta;
    memset(qizi,0,sizeof qizi);
    qizi['B'] = 3;qizi['K'] = 2;qizi['R'] = 1;
    memset(hashpos,-1,sizeof hashpos);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i) {
    	scanf("%s", s);
    	for(int j = 0; j < m; ++j) {
    		if(s[j] == '*') {
    			x = j;y = i;
    		}
    		if(qizi[s[j]]) {
    			hashpos[j*16+i] = cnt;
    			xx[cnt] = j;
    			yy[cnt] = i;
    			idx[cnt] = qizi[s[j]];
    			cnt++;
    		}
    	}
    }
    sta = (1<<cnt)-1;
    init();
    int ans = bfs(x,y,sta);
    printf("%d\n", ans);
    return 0;
}