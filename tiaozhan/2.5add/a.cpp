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
const int maxn = 3e6+2e5;;
const int N = 2e4;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long

char s[2100][10];
int getdis(int x, int y) {
	int ans = 0;
	for(int i = 0; i < 7; ++i){
		if(s[x][i] != s[y][i]) ++ans;
	}
	return ans;
}
struct Edge{
	int u, v, c;
	bool operator < (const Edge& rhs)const{
		return c < rhs.c;
	}
}a[maxn];
int cnt, p[N], ran[N], n;
int find(int x) {
	return p[x] = (p[x]==x?x:find(p[x]));
}
bool same(int x, int y) {
	return find(x)==find(y);
}
void unite(int x, int y) {
	x = find(x); y = find(y);
	if(x == y) return;
	if(ran[x] > ran[y]) p[y] = x;
	else {
		p[x] = y;
		if(ran[x] == ran[y]) ++ran[y];
	}
}
int getmin_tree() {
	sort(a,a+cnt);
	int num = 0, ans = 0, u, v, c;
	for(int i = 0; i < cnt; ++i) {
		u = a[i].u; v= a[i].v; c = a[i].c;
		if(!same(u,v)) {
			ans += c;
			unite(u,v);
			if(++num == n-1) return ans;
		}
	}
	return ans;
}
void init() {
	cnt = 0;
	for(int i = 0; i <= n; ++i) {
		p[i] = i;
		ran[i] = 0;
	}
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    while(scanf("%d", &n) != EOF&& n) {
    	init();
    	for(int i = 0; i < n; ++i) {
    		scanf("%s", s[i]);
    	}
    	for(int i = 0; i < n; ++i) {
    		for(int j = i+1; j < n; ++j) {
    			a[cnt++] = Edge{i,j,getdis(i,j)};
    		}
    	}
    	int ans = getmin_tree();
    	printf("The highest possible quality is 1/%d.\n", ans);
    }
    return 0;
}