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
const int N = 2e5+100;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
int d1[maxn], d2[maxn], to[N], cost[N], in[maxn],cnt, nxt[N], head[maxn], n, st[N];
void addedge(int u, int v, int c) {
	nxt[cnt] = head[u];
	st[cnt] = u;
	to[cnt] = v;
	cost[cnt] =  c;
	head[u] = cnt++;
}
void spfa(int s, int d[]) {
	queue<int> q;
	for(int i = 0; i <= n; ++i) {
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
int secd_min(int u, int v) {
	int ans = INF, l, r;

	for(int i = 0; i < cnt; i++) {
		l = st[i]; r = to[i];
		//pr(l);prln(r);
		//pr(d1[l]);pr(d2[r]);prln(cost[i]);
		if(d1[l]+d2[r]+ cost[i]>d1[v]) {
			if(d1[l]+d2[r]+ cost[i]<ans) {
				ans = d1[l]+d2[r]+ cost[i];
				//pr(l);prln(r);
			}
			//ans = min(ans,d1[i]+d2[i]+cost1[i]+cost2[i]);
		}
	}
	return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int m, u, v, c;
    while(cin >> n >> m) {
    	cnt = 0;
    	for(int i = 0; i <= n; ++i) {
    		//cost1[i] = cost2[i] = INF;
    		head[i] = -1;
    	}
    	for(int i = 0; i < m; ++i) {
    		scanf("%d%d%d", &u, &v, &c);
    		addedge(u,v,c);
    		addedge(v,u,c);
    		/*if(u == 1) cost1[v] = c;
    		if(v == 1) cost1[u] = c;
    		if(u == n) cost2[v] = c;
    		if(v == n) cost2[u] = c;
    		*/
    	}
    	spfa(1,d1);
    	spfa(n,d2);
    	int ans = secd_min(1,n);
    	printf("%d\n", ans);
    }
    return 0;
}