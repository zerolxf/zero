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
#define ll long long
const int maxn = 1e6+100;
const ll INF = 1e18;
#define pr(x)     //  cout << #x << " = " << x << " ";
#define prln(x)     //cout << #x << " = " << x <<endl;
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
struct Edge{
	ll u, v, c;
	bool operator <(const Edge& rhs)const{
		return c < rhs.c;
	}
};

Edge edge[maxn],a[maxn];
ll dis[maxn], vis[maxn], n, m, cnt;
ll getdis(int s) {
	for(int i = 0; i <= n; ++i){
		vis[i] = 0;
		dis[i] = INF;
	}
	vis[s] = true;
	dis[s] = 0;
	Edge temp{0,0,0};
	sort(edge,edge+m*2);
	int _m = m*2;
	for(int i = 0; i < _m; ++i) {
		temp.c = edge[i].c;
		int pos = upper_bound(edge,edge+_m,temp)-edge;
		cnt = 0;
		for(int j = i; j < pos; ++j) {
			Edge& e = edge[j];
			ll u = e.u,v = e.v,d= e.c;
			if(vis[u]) {
				if(dis[v] > dis[u]+d){
					a[cnt].v = v;
					a[cnt++].c = dis[u]+d;
				}
			}
		}
		for(int j = 0; j < cnt; ++j) {
			Edge& e = a[j];
			dis[e.v] = min(dis[e.v],e.c);
			//pr(e.v);prln(e.c);
			vis[e.v] = true;
		}
		i = pos-1;
	}
	return dis[n];
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    ll t, u, v, c;
    cin >> t;
    while(t--) {
    	cin >> n >> m;
    	for(int i = 0 ; i < m; ++i) {
    		scanf("%lld%lld%lld",&u,&v,&c);
    		edge[i*2] = Edge{u,v,c};
    		edge[i*2+1] = Edge{v,u,c};
    	}
    	ll ans = getdis(1);
    	if(ans==INF) printf("No answer\n");
    	else printf("%lld\n", ans);
    }
    return 0;
}