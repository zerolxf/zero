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
ll hasht[10100][1100];
ll hashs[maxn];
const ll MOD = 1e15-1;
int n, m, len;
int last[maxn], vis[maxn], path[maxn];
char T[maxn], str[111111][1010];
map<ll,int> id;
void dfs(int pos) {
	if(pos==0) return;
	dfs(last[pos]);
	printf("%s ", str[path[pos]]);
}
void gethash(int maxlen) {
	rep(i,len+1) hasht[i][1] = T[i]-'a';
	for(int i = 2; i <= maxlen; ++i) {
		for(int j = i-1; j <len; ++j) {
			hasht[j+1-i][i] = (hasht[j+1-i][i-1]*28+T[j]-'a')%MOD;
		}
	}
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    scanf("%d",&len);
    scanf("%s",T);
    scanf("%d",&m);
    int maxlen = 0;
    rep(i,len+2) last[i] = -1;
    last[0] = 0;
   // rep(i,len+2) hasht[i] = 0;
    for(int i = 0; i < m; ++i) {
    	scanf("%s", str[i]);
    	int len1 = strlen(str[i]);
    	maxlen = max(maxlen,len1);
    	ll x = 0;
    	for(int j = len1-1; j>=0; --j) {
    		if(str[i][j] >= 'A' && str[i][j] <= 'Z') {
    			x = (x*28+str[i][j]-'A')%MOD;
    		} else x = (x*28+str[i][j]-'a')%MOD;
    	}
    	hashs[i] = x;
    	id[x] = i;
    }
    gethash(maxlen);
    int num=0;
    for(int j = 0; j < len; ++j) {
    	num = min(j+1,maxlen);
	    for(int i = 1; i <= num; ++i) {
    		if(last[j-i+1]!=-1 &&  last[j+1]==-1 && id.count(hasht[j+1-i][i])) {
    			last[j+1] = j-i+1;
    			path[j+1] = id[hasht[j-i+1][i]];
    		}
    	}
    }
    dfs(len);
    printf("\n");
    return 0;
}