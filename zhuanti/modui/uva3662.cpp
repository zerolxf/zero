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
const int maxn = 5e5+100;
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
	bool operator <(const Point& rhs)const{
		return x!=rhs.x?x<rhs.x:y<rhs.y;
	}
}P[maxn];
struct Bit{
	int mi, pos;
	void init(){mi = (1<<30);pos = -1;}
}bit[maxn];
int p[maxn], n,  ecnt;
int find(int x){
	return p[x]=(x==p[x]?x:find(p[x]));
}

struct Edge{
	int u, v, d;
	bool operator < (const Edge& rhs)const{
		return d < rhs.d;
	}
}edge[maxn];
int getdist(int x, int y) {
	return abs(P[x].x-P[y].x) + abs(P[x].y-P[y].y);
}

void addedge(int u, int v, int d) {
	//prln(ecnt);
	edge[ecnt++] = Edge{u,v,d};
}

int lowbit(int x){ return x&(-x);}

void update(int x, int mi, int pos) {
	for(int i = x; i >= 1; i-=lowbit(i)) {
		if(mi < bit[i].mi) bit[i].mi = mi,bit[i].pos = pos;
	}
}


int query(int x, int m) {
	int mi = (1<<30), pos = -1;
	for(int i = x; i <= m; i+= lowbit(i))
		if(mi > bit[i].mi) mi = bit[i].mi, pos = bit[i].pos;
	return pos;
}
ll Mahatton() 
{
	int a[maxn], b[maxn];
	rep(i,n) {
			pr(i);pr(P[i].x);prln(P[i].y);
		}
	for(int dir = 1; dir <= 4; ++dir)
	{
		if(dir==2||dir==4) rep(i,n) swap(P[i].x,P[i].y);
		else if(dir==3) rep(i,n) P[i].x = -P[i].x;
		sort(P,P+n);
		rep(i,n) a[i] = b[i] = P[i].y - P[i].x;
		sort(b,b+n);
		int bcnt = unique(b,b+n)-b;
		rep(i,bcnt+1) bit[i].init();
		for(int i = n-1; i >= 0; --i) {
			int pos = lower_bound(b,b+bcnt,a[i]) - b +1;
			int ans = query(pos,bcnt);
			if(ans!=-1) addedge(P[i].id, P[ans].id, getdist(i,ans));
			update(pos, P[i].x+P[i].y, i);
		}
	}
	sort(edge,edge+ecnt);
	rep(i,n) p[i] = i;
	ll ans = 0, last = n-1;
	rep(i,ecnt) {
		int u = edge[i].u, v = edge[i].v, d = edge[i].d;
		u = find(u); v = find(v);
		if(u==v) continue;
		p[u] = v;
		ans += d;
		if(--last==0) return ans;
	}
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
 // freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int t, kase = 0;
   // cout << "sss\n";
    while(scanf("%d", &n)!=EOF && n) {
    	ecnt = 0;
    	rep(i,n) {
    		scanf("%d%d", &P[i].x, &P[i].y);
    		P[i].id = i;
    	}
    	ll ans = Mahatton();
    	printf("Case %d: Total Weight = %lld\n",++kase, ans);
    }
    return 0;
}








