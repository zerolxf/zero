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
const int maxn = 5e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long

struct Edge{
	ll u, v, c;
	bool operator < (const Edge& rhs)const{
		return c < rhs.c;
	}
};
vector<Edge> edge;
int p[maxn], ran[maxn];
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
ll get() {
	ll ans = 0;
	ll num = 0, u, v, c;
	sort(edge.begin(), edge.end());
	for(int i = 0; i < edge.size(); ++i) {
		u = edge[i].u;v=edge[i].v;c=edge[i].c;
		if(!same(u,v)) {
			ans += c;
			unite(u,v);
			if(++num==n-1) return ans;
		}
	}
	return 1;
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
    int m, u, v, c;
    while(cin >> n >> m) {
    	init();
    	for(int i = 0; i < m; ++i) {
    		scanf("%d%d%d", &u, &v, &c);
    		edge.push_back(Edge{u,v,-c});
    	}
    	ll ans = get();
    	printf("%lld\n",-ans);
    }
    return 0;
}