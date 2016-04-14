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
	int p[maxn], cnt[2000];
	vector<int> G[2000];
	bool link[1100][1100];
	int find(int x) {
		return p[x] = (x==p[x]?x:find(p[x]));
	}
	void unite(int x, int y){
		x = find(x); y = find(y);
		if(x == y) return;
		p[x] = y;
	}
	void init(int n){
		for(int i = 0; i <= n; ++i){
			p[i] = i;
			cnt[i] = 0;
			G[i].clear();
		}
	}
	bool same(int x, int y){
		return find(x)==find(y);
	}
	int main(){
	#ifdef LOCAL
	    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
	  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
	 #endif
	    int n, m, x, y;
	    while(cin >> n &&n) {
	    	cin >> m;
	    	init(n);

	    	for(int i = 0; i < m; ++i) {
	    		scanf("%d%d",&x,&y);
	    		unite(x,y);
	    		//link[x][y] = link[y][x] = true;
	    		cnt[x]++;
	    		cnt[y]++;
	    	}

	    	int ok = 1;
	    	for(int i = 1; i <= n; ++i) {
	    		if(cnt[i] < 2 || cnt[i]%2) ok = 0;
	    		if(!same(i,1)) ok = 0;
	    	}
	    	printf("%d\n", ok);
	    }
	    return 0;
	}