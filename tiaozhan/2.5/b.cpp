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
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
int dis[maxn], head[maxn], nxt[maxn], to[maxn], cost[maxn], qcnt[maxn], n, L, D, cnt,in[maxn];
void addedge(int u, int v, int c) {
	nxt[cnt] = head[u];
	to[cnt] = v;
	cost[cnt] = c;
	head[u] = cnt++;
}
bool spfa(int s, int d[]) {
	queue<int> q;
	for(int i = 0; i <= n; ++i) {
		d[i] = INF;
		in[i] = 0;
		qcnt[i] = 0;
	}
	d[s] = 0;qcnt[s] = 1;
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
					if(qcnt[v] < n) qcnt[v]++;
					else return true;
				}
			}
		}
	}
	return false;
}
void init() {
	for(int i = 0; i <= n; ++i) {
		head[i] = -1;
		cnt = 0;
	}
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int u, v, c;
    while(scanf("%d%d%d", &n, &L, &D) != EOF) {
    	init();
    	for(int i = 0; i < L; ++i) {
    		scanf("%d%d%d", &u, &v, &c);
    		addedge(u,v,c);
    	}
    	for(int i = 0; i < D; ++i) {
    		scanf("%d%d%d", &u, &v, &c);
    		addedge(v,u,-c);
    	}
    	if(spfa(1,dis)) {
    		printf("-1\n");
    	} else if(dis[n] == INF) {
    		printf("-2\n");
    	} else printf("%d\n",dis[n]);
    }
    return 0;
}