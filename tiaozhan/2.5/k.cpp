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
const int maxn = 6e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
struct Edge{
	int u, v;
	double c;
	bool operator < (const Edge& rhs)const{
		return c < rhs.c;
	}
};

vector<Edge> edge;
int p[maxn], ran[maxn], x[maxn], y[maxn];
double getdis(int u, int v) {
	return (x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]);	
}
ll n;
int find(int x) {
	return p[x]=(x==p[x]?x:find(p[x]));
}
void unite(int x, int y) {
	x = find(x); y = find(y);
	if(x == y) return;
	if(ran[x] > ran[y]) p[y] = x;
	else {
		p[x] = y;
		if(ran[x]==ran[y]) ++ran[x];
	}
}
 bool same(int x, int y){
	return find(x)==find(y);
}
double get() {
	double ans = 0;
	ll num = 0, u, v;
	double c;
	sort(edge.begin(), edge.end());
	for(int i = 0; i < edge.size(); ++i) {
		u = edge[i].u;v=edge[i].v;c=edge[i].c;
		if(!same(u,v)) {
			ans += c;
			unite(u,v);
			//if(++num==n-1) return ans;
		}
	}
	return ans;
}
void init() {
	edge.clear();
	for(int i = 0; i <= 2*n; ++i) {
		p[i] =i;
		ran[i] = 0;
	}
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int m, u, v;
    double dd;
    while(scanf("%lld%d", &n, &m)!=EOF) {
    	init();
    	for(int i = 1; i <= n; ++i) {
    		scanf("%d%d", &x[i], &y[i]);
    	}
    	double ans = 0;
    	for(int i = 0; i < m; ++i) {
    		scanf("%d%d", &u, &v);
    		dd = sqrt(getdis(u,v));
    		ans += dd;
    		edge.push_back(Edge{u,v,-dd});
    	}
    	//prln(ans);prln(get);
    	ans =ans + get();
    	printf("%.6f\n", ans);
    }
    return 0;
}