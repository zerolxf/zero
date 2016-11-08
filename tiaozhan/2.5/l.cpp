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
	int u, v, c;
	bool operator < (const Edge& rhs)const{
		return c < rhs.c;
	}
};

vector<Edge> edge;
int p[maxn], ran[maxn], n;

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
	ans = 0;
	for(int i = 0; i < edge.size(); ++i) {
		u = edge[i].u;v=edge[i].v;c=edge[i].c;
		if(!same(u,v)) {
			if(c > ans) ans = c;
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
    int m, u, v, d;
    while(scanf("%d%d", &n, &m)!=EOF) {
    	init();
    	int ans = 0;
    	for(int i = 0; i < m; ++i) {
    		scanf("%d%d%d", &u, &v, &d);
    		//dd = sqrt(getdis(u,v));
    		//ans += dd;
    		edge.push_back(Edge{u,v,d});
    	}
    	//prln(ans);prln(get);
    	ans =get();
    	printf("%d\n", ans);
    }
    return 0;
}