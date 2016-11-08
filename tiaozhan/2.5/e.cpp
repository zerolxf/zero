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
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
const int N = 4e5+100;
//const int add = 2000;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
ll d1[maxn], d2[maxn], to[N], cost[N], in[maxn],cnt, nxt[N], head[maxn], st[N], n, add;
void addedge(int u, int v, int c) {
	nxt[cnt] = head[u];
	st[cnt] = u;
	to[cnt] = v;
	cost[cnt] =  c;
	head[u] = cnt++;
}
void spfa(int s, ll d[]) {
	queue<int> q;
	for(int i = add; i <= n+add; ++i) {
		d[i] = INF;
		in[i] = 0;
	}
	d[s] = 0;
	q.push(s);
	in[s] = true;
	while(q.size()) {
		int x = q.front(); q.pop();in[x] = false;
		for(int i = head[x]; ~i; i = nxt[i]) {
			int v = to[i];
			if(d[x] + cost[i] < d[v]) {
				d[v] = d[x] + cost[i];
				if(!in[v]) {
					q.push(v);
					in[v] = true;
				}
			}
		}
	}
}
void init() {
	cnt = 0;
	for(int i = 0; i <= 3100; ++i){
		head[i] = -1;
	}
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int m, x, u, v, c;
    while(scanf("%d%d%d", &n, &m, &x) !=EOF) {
    	init();
    	add = 2000;
    	for(int i = 0; i < m; ++i) {
    		scanf("%d%d%d", &u, &v, &c);
    		addedge(u,v,c);
    		addedge(v+add,u+add,c);
    	}
    	add = 0;
    	spfa(x,d1);
    	add = 2000;
    	spfa(x+add,d2);
    	ll ans = 0;
    	for(int i = 1; i <= n; ++i){
    		//pr(d1[i]);prln(d2[i+add]);
    		if(i == x) continue;
    		if(d1[i]+d2[i+add] > ans) {
    			ans = d1[i] + d2[i+add];
    		}
    	}
    	printf("%lld\n", ans);
    }
    return 0;
}