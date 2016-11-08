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
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
ll dis[maxn], nxt[maxn], to[maxn], cost[maxn], head[maxn], vis[maxn], num[maxn],in[maxn],cnt,n, pre[maxn];
void addedge(int u, int v, int c) {
	nxt[cnt] = head[u];
	to[cnt] = v;
	cost[cnt] = c;
	head[u] = cnt++;
}
void init() {
	cnt = 0;
	for(int i = 0; i <= n; ++i) {
		head[i] = -1;
		num[i] = 0;
	}
}
struct Node{
	ll u, dis, pre;
	bool operator <(const Node& rhs)const{
		if(dis!=rhs.dis) return dis>rhs.dis;
		return pre > rhs.dis;
	}
};
ll bfs(int s) {
	for(int i = 0; i<= n; ++i) {
		dis[i] = INF;
		pre[i] = INF;
		vis[i] = 0;
	}
	dis[s] = 0;
	pre[s] = 0;
	priority_queue<Node> q;
	q.push(Node{1,0,0});
	while(!q.empty()) {
		Node x = q.top(); q.pop();
		ll u = x.u, d = x.dis, p = x.pre;
		if(num[u] > n) continue;
		if(u==n) return d;
		for(int i = head[u]; ~i; i = nxt[i]) {
			int v = to[i];
			//prln(i);
			if(cost[i] <= p) continue;
			if(dis[v] > d+cost[i] || pre[v] > cost[i]) {
				pre[v] = v;
				dis[v] = d+cost[i];
				//num[v]++;
				q.push(Node{v,dis[v],pre[v]});				
			}
		}
	}
	return -1;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    ll t,u,v,c,m;
    cin >> t;
    while(t--) {
      	cin >> n >> m;
      	init();
    	for(int i = 0; i < m; ++i) {
    		scanf("%lld%lld%lld", &u, &v, &c);
    		addedge(u,v,c);
    		addedge(v,u,c);
    	}
    	//int ans = bfs(1);

   		ll ans = bfs(1);
    	if(ans != -1) printf("%lld\n",ans);
    	else printf("No answer\n");
    }
    return 0;
}





















