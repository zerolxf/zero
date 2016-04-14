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
#define pr(x)      // cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
ll x[maxn], y[maxn], z[maxn];
ll c[1100][1100], d[maxn], n, cnt[maxn], vis[maxn], in[maxn], m;
int spfa(int s) {
	for(int i = 0; i < n; ++i) {
		d[i] = 1e18;
		//cnt[i] = 0;
		in[i] = 0;
	}
	rep(i,m) cnt[i] = 0;
	d[0] = 0;in[0] = 1;
	queue<int> q;
	q.push(s);
	while(q.size()) {
		int u = q.front(); q.pop();
		in[u] = 0;
		for(int i = 1; i < n; ++i) {
			if(i==u) continue;
			pr(u);
			if(d[u]+c[u][i] < d[i]) {
				d[i] = d[u] + c[u][i];
				pr(i);pr(c[u][i]);prln(d[i]);
				if(!in[i]) {
					q.push(i);
					in[i] = true;
				}
			}
		}

	}
	pr(n);prln(m);
	for(int i = 1; i < n; ++i) {
		pr(i);prln(d[i]);prln(d[i]%m);
		cnt[(d[i]%m)]++;
	}
	int ans = 0;
	for(int i = 0; i < m; ++i) {
		if(cnt[i]){
			pr(i);prln(cnt[i]);
			ans = cnt[i];
			return i;
		}
	}
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
   // int   x0,x1,y0,y1;
    while(cin >> n >> m >> x[0] >> x[1] >> y[0] >> y[1]) {
    	int _n = n*n;
    	z[1] = (x[1]*90123+y[1])%8475871+1;
    	for(int i = 2; i < _n; ++i) {
    		x[i] = (12345+x[i-1]*23456 + x[i-2]*34567+x[i-1]*x[i-2]*45678)%5837501;
    		y[i] = (56789 + y[i-1]*67890+y[i-2]*78901 + y[i-1]*y[i-2]*89012)%9860381;
    		z[i] = (x[i]*90123+y[i])%8475871+1;
    	}
    	for(int i = 0; i < n; ++i) {
    		for(int j = 0; j < n; ++j) {
    			if(i!=j) c[i][j] = z[i*n+j];
    			
    			else c[i][j] = 0;
    			pr(c[i][j]);
    		}
    		//printf("\n");
    	}
    	int ans = spfa(0);
    	printf("%d\n",ans );
    }
    return 0;
}