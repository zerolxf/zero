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
int N, prime[maxn], dep[maxn], num[10], vis[maxn];
bool isprime[maxn];
void getprime() {
	int cnt = 0;
	N = 10000;
	CLR(vis);
	for(ll i = 2; i <= N; ++i){
		//prln(i);
		if(!vis[i]) {
			//prln(i);
			isprime[i] = true;
			prime[cnt++] = i;
			for(int j = i; j <= N; j+=i) {
				vis[j] = true;
				//prln(j);
			}
		}
	}
}
int getnum(int x,int i,int k) {
	//pr(x);
	int y = x/num[i-1];
	y = y%10;
	//pr(y);pr(k);
	x = x - y*num[i-1] + k*num[i-1];
	//prln(x);
	return x;
}
int getans(int x, int y) {
	queue<int> q;
	q.push(x);
	dep[x] = 0;
	while(q.size()) {
		int u = q.front();q.pop();
		//pr(u);
		if(u == y) return dep[u];
		if(vis[u]) continue;
		vis[u] = true;
		//prln(u);
		for(int i = 1; i <= 4; ++i) {
			for(int j = 0; j < 10; ++j) {
				if(i==4&&j==0) continue;
				int v = getnum(u,i,j);
				if(isprime[v]&&!vis[v]) {
					//pr(v);
					dep[v] = min(dep[v], dep[u]+1);
					if(v==y) return dep[v];
					q.push(v);
				}
			}
		}
	}
	return dep[y];
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    num[0] = 1;num[1] = 10;num[2]=100;num[3]=1000;
    int t, x, y;
    getprime();
    cin >> t;
    while(t--) {
    	cin >> x >> y;
    	//MEM(dep,0x3f);
    	for(int i = 0; i <= N; ++i) dep[i] = INF;
    	CLR(vis) ;
    	int ans =  getans(x,y);
    	if(ans == INF) {
    		printf("Impossible\n");
    		continue;
    	}
    	printf("%d\n", ans);
    }
    return 0;
}