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
const int maxn = 3e4+100;
const int INF = 0x3f3f3f3f;
const int N = 6e5+200;
#define pr(x)       //cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define ll long long
int d1[maxn], d2[maxn], to[N], cost[N], in[maxn],cnt, nxt[N], head[maxn],  n, add, vis[N],cost2[N],pre[N];
void addedge(int u, int v, int c, int d) {
	nxt[cnt] = head[u];
	to[cnt] = v;
	cost[cnt] =  c;
	cost2[cnt] = d;
	head[u] = cnt++;
}

int last[maxn];
void spfa(int s, int d[]) {
	queue<int> q;
	for(int i = 0; i <= n; ++i) {
		d[i] = INF;
		in[i] = 0;
		last[i] = INF;
	}
	d[s] = 0;
	q.push(s);
	in[s] = true;
	while(q.size()) {
		int x = q.front(); q.pop();in[x] = false;
		for(int i = head[x]; ~i; i = nxt[i]) {
			int v = to[i];
			if(d[x] + cost[i] == d[v] && last[v] > cost2[i]) last[v] = cost2[i]; 
			else if(d[x]+cost[i]<d[v]){
				d[v] = d[x] + cost[i];
				last[v] = cost2[i];
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
	for(int i = 0; i <= n; ++i) head[i] = -1;
}

ll getmin_tree() {
	ll ans1 = 0;
	for(int i = 1; i <= n; ++i) {
		if(last[i] != INF)
		ans1 += last[i];
	}
	return ans1;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int m, u, v, d, c;
    while(scanf("%d%d", &n, &m) !=EOF && (n||m)) {
    	init();
    	for(int i = 0; i < m; ++i) {
    		scanf("%d%d%d%d", &u, &v, &d, &c);
    		addedge(u,v,d,c);
    		addedge(v,u,d,c);
    	}
    	spfa(1,d1);
    	ll ans = getmin_tree();
    	printf("%lld\n", ans);
    }
    return 0;
}