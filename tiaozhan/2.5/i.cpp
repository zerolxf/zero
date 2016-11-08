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
    while(cin >> n){
    	int x;
    	edge.clear();
    	init();
    	for(int i = 0; i < n; ++i) {
    		for(int j = 0; j < n; ++j) {
    			scanf("%d", &x);
    			edge.push_back(Edge{i,j,x});
    		}
    	}
    	ll ans = get();
    	printf("%lld\n", ans);
    }
    return 0;
}