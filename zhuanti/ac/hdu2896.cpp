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
const int maxn = 1e5+1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
struct Automata{
	int nxt[maxn][130], cnt[maxn],  fail[maxn], root, sz, vis[maxn];
	int newnode(){
		cnt[sz] = 0;
		vis[sz] = 0;
		MEM(nxt[sz],-1);
		return sz++;
	}
	void init() {
		sz = 0;
		root = newnode();
	}
	void insert(char *s, int id) {
		int n = strlen(s);
		int u = root;
		for(int i = 0; i < n; ++i) {
			int& v = nxt[u][s[i]];
			if(v==-1) v = newnode();
			u = v; 
		}
		cnt[u] = id;
		//st[u][cnt[u]++] = id;
	}
	void build() {
		queue<int> q;
		fail[root] = root;
		for(int i = 0; i < 128; ++i ) {
			int& u = nxt[root][i];
			if(~u) {
				q.push(u);
				fail[u] = root;
			} else u = root;
		}
		while(q.size() ) {
			int u = q.front(); q.pop();
			for(int i = 0; i < 128;  ++i) {
				int& v= nxt[u][i];
				if(~v) {
					q.push(v);
					fail[v] = nxt[fail[u]][i];
				} else v = nxt[fail[u]][i];
			}
		}
	}
	int query(char *s, int num[], int id) {
		int n = strlen(s);
		int u = root, ret = 0;
		for(int i = 0; i < n; ++i) {
			u = nxt[u][s[i]];
			for(int v = u; v != root; v =fail[v]) {
				if(vis[v]==id) continue;
				//for(int j = 0; j < cnt[v]; ++j) {
				if(cnt[v])	num[ret++] = cnt[v];
				//}
				vis[v] = id;
			}
		}
	}
}ac;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    char s[maxn];
    int num[maxn], n, m;
    scanf("%d", &n);
    ac.init();
    for(int i = 0; i < n; ++i) {
    	scanf("%s", s);
    	ac.insert(s,i+1);
    }
    ac.build();
    scanf("%d", &m);
    int tot = 0;
    for(int i = 1; i <= m; ++i) {
    	scanf("%s", s);
    	int ans = ac.query(s,num,i);
    	if(ans) tot++;
    	else continue;
    	sort(num,num+ans);
    	printf("web %d:",i);
    	for(int j = 0; j < ans; ++j) {
    		printf(" %d", num[j]);
    	}
    	printf("\n");
    }
    printf("total: %d\n",tot);
    return 0;
}
