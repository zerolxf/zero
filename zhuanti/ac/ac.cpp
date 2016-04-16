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
#define pr(x)      // cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
char ss[1234][55];
struct AC{
	int nxt[maxn][27], cnt[maxn], fail[maxn], root, sz;
	int newnode(){
		cnt[sz] = 0;
		MEM(nxt[sz],-1);
		return sz++;
	}
	void init(){
		sz = 0;
		root = newnode();
	}
	void insert(char *s, int id) {
		int n  = strlen(s);
		int u = root;
		for(int i = 0; i < n; ++i) {
			int& v = nxt[u][s[i]-'A'];
			if(v==-1) v = newnode();
			u = v;
		}
		cnt[u] = id;
	}
	void build() {
		queue<int> q;
		fail[root] = root;
		for(int i = 0; i < 26; ++i) {
			int& v = nxt[root][i];
			if(~v) {
				q.push(v);
				fail[v] = root;
			} else v = root;
		}
		while(q.size()) {
			int u = q.front(); q.pop();
			for(int i = 0; i < 26; ++i) {
				int& v= nxt[u][i];
				if(~v) {
					q.push(v);
					fail[v] = nxt[fail[u]][i];
				} else v = nxt[fail[u]][i];
			}
		}
	}
	int query(char *s,int ans[]) {
		int n = strlen(s);
		int u = root;
		for(int i = 0; i < n; ++i) {
			u = nxt[u][s[i]-'A'];
			for(int v = u; v != root; v = fail[v]) {
				ans[cnt[v]]++;
			}
		}
	}
}ac;
char s[2123456],word[2123456];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, sz = 0, ans[1024];
    //CLR(ans);
    while(scanf("%d", &n)!=EOF){
	    ac.init();
	    CLR(ans);
	    sz = 0;
	    for(int i = 1; i <= n; ++i) {
	    	scanf("%s", ss[i]);
	    	ac.insert(ss[i],i);
	    }
	    ac.build();
	    scanf("%s",s);
	    int len = strlen(s);
	    for(int i = 0; i < len; ++i) {
	    	if(s[i] >= 'A' && s[i] <= 'Z') {
	    		word[sz++] = s[i];
	    	} else if(sz) {
	    		word[sz] = 0;
	    		ac.query(word,ans);
	    		sz = 0;
	    	}
	    }
	    if(sz) {
	    	word[sz] = 0;
	    	ac.query(word,ans);
	    }
	    for(int i = 1; i <= n; ++i) {
	    	if(ans[i]) {
	    		printf("%s: %d\n",ss[i],ans[i]);
	    	}
	    }
	}
    return 0;
}










