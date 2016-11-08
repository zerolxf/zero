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
const int maxn = 2e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int p[maxn], ran[maxn],cnt[maxn], cntb[maxn], cntt[maxn], has[maxn], pos[maxn];
void init(int n) {
	for(int i = 0; i <= n; ++i) {
		p[i] = i;
		cnt[i] = 1;
		cntb[i] = 1;
		cntt[i] = 0;
		has[i] = i;
		pos[i] = i;
	}
}
int find(int x) {
	if(x==p[x]) {
		return x;
	}
	int px = p[x];
	p[x] = find(p[x]);
	cntt[x] += cntt[px];
	return p[x];
}
void unit(int cx, int cy) {
	int x = has[cx], y = has[cy];
	has[cx] = 0;
	if(x==0) return;
	has[cx] = 0;cntt[x]++;
	if(y==0) {
		has[cy] = x;
		return;
	}
	//pr(cx);pr(cy);pr(x);prln(y);
	p[x] = y;
	cnt[y] += cnt[x];
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    char op[10];
    int n, u, v, t, kase = 0, m;
    cin >> t;

    while(t--) {
    	cin >> n >> m;
    	init(n);
    	printf("Case %d:\n", ++kase);
    	for(int i = 0; i < m; ++i){
    		scanf("%s",op);
    		if(op[0]=='T') {
    			scanf("%d%d",&u,&v);
    			u = find(u);v = find(v);
    			unit(pos[u],pos[v]);
    		} else{
    			scanf("%d",&u);
    			int pu = find(u);
    			//prln(pu);
    			printf("%d %d %d\n",pos[pu],cnt[pu],cntt[u]);
    		}
    	}
    }
    return 0;
}