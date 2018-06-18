
/*
* @author:  liangxianfeng
* @mail: liangxianfeng96@qq.com
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define repp(i,n,x) for(int i =x; i < n+x; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl;
const int MOD = 1e9+7;
const int maxn = 210*210+100;
const int INF = 0x3f3f3f3f;
string str[210];
int n, m;
const int N = 210;
vector<int> edge[maxn];
struct Node{
	int l, r, u, d;
	Node(){}
	Node(int _l, int _r, int _u, int _d){
		l = _l;
		r = _r;
		u = _u;
		d = _d;
	}
}node[N][N];
void addedge(int u, int v){
	edge[u].push_back(v);
	edge[v].push_back(u);
}
int vis[maxn];
int ans = 0;
void dfs(int u){
	vis[u] = ans;
	for(int i = 0; i < edge[u].size(); ++i){
		int v = edge[u][i];
		if(vis[v]) continue;
		dfs(v);
	}
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    int cnt = 0;
    string temp;
    scanf("%d%d", &n, &m);
    getline(cin, temp);
    for(int i = 0; i < n; ++i){
    	getline(cin, str[i]);
    }
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j){
    		if(str[i][j] == ' '){
    			node[i][j] = Node(cnt,cnt+1,cnt,cnt+1);
    		}else if(str[i][j] == '\\'){
    			node[i][j] = Node(cnt,cnt+1,cnt+1,cnt);
    		}else {
    			node[i][j] = Node(cnt,cnt+1,cnt,cnt+1);
    		}
    		if(j > 0){
    			addedge(node[i][j].l, node[i][j-1].r);
    		}
    		if(i > 0){
    			addedge(node[i][j].u, node[i-1][j].d);
    		}
    		if(str[i][j] == ' '){
    			addedge(node[i][j].l, node[i][j].r);
    		}
    		cnt+=2;
    	}
    }
    ans=0;
    memset(vis, 0, sizeof vis);
    rep(i,n){
    	rep(j,m){
    		int l = node[i][j].l, r = node[i][j].r;
    		if(!vis[l]) {
    			ans++;
    			dfs(l);
    		}
    		if(!vis[r]){
    			ans++;
    			dfs(r);
    		}
    	}
    }
    cout<<ans<<endl;
    return 0;
}
