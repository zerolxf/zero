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
const int maxn = 3e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
int p[maxn], ran[maxn];
void init(int n) {
	n = n*2;
	for(int i = 0; i <= n; ++i) {
		p[i] = i;
		ran[i] = 1;
	}
}
int find(int x) {
	return x == p[x]?x:find(p[x]);
} 
bool same(int x, int y) {
	x = find(x);  y = find(y);
	return x==y;;
}
void unite(int x, int y) {
	x = find(x); y = find(y);
	if(x == y) return;
	if(ran[x] > ran[y]) {
		p[y] = p[x];
	} else {
		p[x] = y;
		if(ran[x] == ran[y]) ++ran[y];
	}
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, m, t, x, y;
    char op[10];
    scanf("%d", &t);
    while(t--) {
    	scanf("%d%d", &n, &m);
    	init(n);
    	for(int i = 1; i <= m; ++i) {
    		scanf("%s%d%d",op,&x,&y);
    		if(op[0] == 'D') {
    			unite(x,y+n);
    			unite(y,x+n);
    		} else {
    			if(same(x,y)&&same(x+n,y+n)) {
    				printf("In the same gang.\n");
    			} else if(same(x,y+n)&&same(x+n,y)) {
    				printf("In different gangs.\n");
    			} else printf("Not sure yet.\n");
    		}
    	}
    }
    return 0;
}