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
const double eps = 1e-9;
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       //cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)	
#define MN(a,b,n) memset(a,b,n*sizeof(int))
char mp[200][200];
int vis[200][200];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int n, m;
double sum;
bool dfs(double u, int x, int y) {
	prln(u);
	if(abs(u-sum)<eps) return true;
	pr(x);prln(y);
	for(int i = 0; i < 4; ++i) {
		int nx = x+2*dx[i],xx = x+dx[i];
		int ny = y+2*dy[i],yy = y+dy[i];
		if(nx<n&&ny<m&&nx>=0&&ny>=0){
			if(!vis[nx][ny]) {
				double k=0;
				pr(xx);pr(yy);prln(mp[xx][yy]);
				if(mp[xx][yy]=='*') k = u*(mp[nx][ny]-'0');
				if(mp[xx][yy]=='-') k = u-mp[nx][ny]+'0';
				if(mp[xx][yy]=='+') k = u+mp[nx][ny]-'0';
				if(mp[xx][yy]=='/'&&(mp[nx][ny]-'0')!=0) k = u/(mp[nx][ny]-'0');
				if(mp[xx][yy]=='/'&&(mp[nx][ny]=='0')) return false;
				if(abs(k-sum)<eps) return true;
				prln(k);
				vis[nx][ny] = true;
				if(dfs(k,nx,ny)) return true;
				vis[nx][ny] = false;
			}
		}
	}
	return false;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int t;
    scanf("%d", &t);
    while(t--) {
    	cin >> n >> m >> sum;
    	for(int i = 0; i < n; ++i) {
    		scanf("%s",mp[i]);
    		for(int j = 0; j < m; ++j) {
    			vis[i][j] = false;
    		}
    	}
    	bool ok = false;
    	for(int i = 0; i <=n/2; ++i) {
    		if(ok) break;
    		for(int j = 0; j <= m/2; ++j) {
    			vis[i*2][j*2] = true;
    			pr(i);prln(j);
    			if(dfs(mp[i*2][j*2]-'0',i*2,j*2))
    			{
    				ok = true;
    				break;
    			}
    			//prln(ans);
    			vis[i*2][j*2] = false;
    		}
    	}
    	if(ok) printf("Possible\n");
    	else printf("Impossible\n");
    }
    return 0;
}