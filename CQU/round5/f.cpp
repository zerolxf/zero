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
const int N = 1e6;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int num, ans[maxn];
char ss[maxn*10];
char str[2200][55];
struct Automata{
	int nxt[N][30], fail[N], cnt[N], sz, root;
	int newnode() {
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
			int& v = nxt[u][s[i]-'A'];
			if(v==-1) v = newnode();
			u = v;
		}
		cnt[u] = ++num;
	}
	void build() {
		queue<int> q;
		int u = root;
		fail[u] = u;
		for(int i = 0; i < 27; ++i) {
			int& v = nxt[u][i];
			if(~v) {
				q.push(v);
				fail[v] = root;
			} else v = root;
		}
		while(q.size()) {
			int u = q.front(); q.pop();
			for(int i = 0; i < 27; ++i) {
				int& v = nxt[u][i];
				if(~v) {
					q.push(v);
					fail[v] = nxt[fail[u]][i];
				} else v = nxt[fail[u]][i];
			}
		}
	}
	void query(char s[]) {
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
char word[maxn*10];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n;
    num  = 0;
    scanf("%d",&n);
    ac.init();
    for(int i = 0; i <= n; ++i) ans[i] = 0;
    for(int i = 1; i <= n ;++i){
    	scanf("%s",str[i]);
    	ac.insert(str[i]);
    }
    ac.build();
    scanf("%s",ss);
    int len = strlen(ss);
    int sz = 0;
    for(int i = 0; i < len; ++i){
    	if(ss[i] >= 'A' && ss[i] <= 'Z') word[sz++] = ss[i];
    	else {
    		if(sz) {
    			word[sz] = 0;
    			ac.query(word);
    		}
    		sz = 0;
    	}
    }
    if(sz) {
  		word[sz] = 0;
  		ac.query(word);
    }
  //  ac.query(ss);

    for(int i = 1; i <= n; ++i){
    	if(ans[i]) printf("%s: %d\n",str[i], ans[i]);
    }
    return 0;
}