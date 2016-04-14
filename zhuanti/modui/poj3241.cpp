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
const int maxn = 1e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
struct Point{
	int x, y, id;
	bool operator < (const Point& rhs)const{
		return x!=rhs.x?x<rhs.x:y<rhs.y;
	}
}p[maxn];
struct Bit{
	int mi, pos;
	void init() {
		mi = (1<<30);
		pos = -1;
	}
}bit[maxn];
struct Edge{
	int u, v, d;
	bool operator <(const Edge& e)const{
		return d < e.d;
	}
}edge[maxn];
int n, cnt, pa[maxn];
int find(int x) {
	return pa[x]=(pa[x]==x?x:find(pa[x]));
}
int dist(int i, int j) {
	return abs(p[i].x-p[j].x) + abs(p[i].y-p[j].y);
}
void addegde(int u, int v, int d) {
	edge[cnt++] = Edge{u,v,d};
}
inline int lowbit(int x){
	return x&(-x);
}
int ask(int x, int m) {
	int mi = (1<<30), pos = -1;
	for(int i = x; i <= m; i+= lowbit(i))
		if(mi > bit[i].mi) mi = bit[i].mi, pos = bit[i].pos;
	return pos;
}
void update(int x, int mi, int pos) {
	for(int i = x; i >= 1; i-=lowbit(i)) {
		if(mi < bit[i].mi) bit[i].mi = mi,bit[i].pos = pos;
	}
}
int k;
int Manhattan(int n, Point* p) {
	int a[maxn], b[maxn];
	for(int dir = 1; dir <= 4; ++dir) 
	{
		if(dir==2||dir==4) rep(i,n) swap(p[i].x,p[i].y);
		else if(dir == 3) rep(i,n) p[i].x = -p[i].x;
		sort(p,p+n);
		rep(i,n) a[i] = b[i] = p[i].y-p[i].x;
		sort(b,b+n);
		int m = unique(b,b+n)-b;
		for(int i = 1; i <= m; ++i) bit[i].init();
		for(int i = n-1; i >=0; --i) {
			int pos = lower_bound(b,b+m,a[i]) - b+1;
			int ans = ask(pos,m);
			if(ans!=-1) {
				addegde(p[i].id,p[ans].id,dist(i,ans));
			}
			update(pos,p[i].x+p[i].y,i);
		}
	}
	sort(edge,edge+cnt);
	int ans = n-k;
	rep(i,n) pa[i] = i;
	for(int i = 0; i < cnt; ++i) {
		int u = edge[i].u, v = edge[i].v;
		u = find(u); v = find(v);
		if(u==v) continue;
		pa[u] = v;
		if(--ans==0) return edge[i].d;
	}
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out2.txt","w",stdout);
 #endif
    while(scanf("%d%d", &n, &k)!=EOF&&n) {
    	cnt = 0;
    	rep(i,n) {
    		scanf("%d%d", &p[i].x, &p[i].y);
    		p[i].id = i;
    	}
    	printf("%d\n", Manhattan(n,p));
    }
    return 0;
}






















