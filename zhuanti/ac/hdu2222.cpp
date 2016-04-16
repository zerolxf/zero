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
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
struct Automate{
	int nxt[maxn][27], fail[maxn], root, sz, cnt[maxn];
	int newnode()
	{
		cnt[sz] = 0;
		MEM(nxt[sz],-1);
		return sz++;
	}
	void init() {
		sz = 0;
		root = newnode();
	}
	void insert(char s[]) {
		int n = strlen(s);
		int u = root;
		for(int i = 0; i < n; ++i) {
			int &v = nxt[u][s[i]-'a'];
			if(v==-1) 	v = newnode();
			u = v;
		}
		cnt[u]++;
	}
	void build() {
		queue<int> q;
		fail[root] = root;
		for(int i = 0; i < 26; ++i) {
			int &v = nxt[root][i];
			if(~v) {
				fail[v] = root;
				q.push(v);
			} else v = root;
		}
		while(q.size()) {
			int u = q.front(); q.pop();
			for(int i = 0; i < 26; ++i) {
				int &v = nxt[u][i];
				if(~v) {
					fail[v] = nxt[fail[u]][i];
					q.push(v);
				} else v = nxt[fail[u]][i];
			}
		}
	}
	int query(char *s) {
		int n = strlen(s);
		int u = root, ret = 0;
		for(int i = 0; i < n; ++i) {
			u = nxt[u][s[i]-'a'];
			for(int v = u; v != root; v = fail[v]) {
				ret += cnt[v];
				cnt[v] = 0;
			}
		}
		return ret;
	}

}ac;
char s[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int t, n; cin >> t;
    while(t--) {
    	scanf("%d", &n);
    	ac.init();
    	for(int i = 0; i < n; ++i) {
    		scanf("%s", s);
    		ac.insert(s);
    	}
    	ac.build();
    	scanf("%s", s);
    	printf("%d\n", ac.query(s));
    }
    return 0;
}
























