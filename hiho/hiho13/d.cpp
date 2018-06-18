
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
#define pr(x)// cout << #x << " = " << x << " ";
#define prln(x)// cout << #x << " = " << x <<  endl;
const int MOD = 1000000007;
const int maxn = 1e5+100;
const int INF = 0x3f3f3f3f;
int num[10][10];
int cnt;
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
typedef pair<int,int> P;
vector<P> vt;
void dfs(int x, int y){
	num[x][y] = ++cnt;
	vt.push_back(P(x,y));
	for(int i = 0; i < 8; ++i){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx <= 0 || ny <= 0 || nx > 8 || ny > 8) continue;
		if(num[nx][ny] > 0) continue;
		dfs(nx, ny);

	}
}
struct Rec{
	ll a[110][110], n;
	Rec(){
		memset(a, 0, sizeof a);
	}
	void clear(){
		memset(a, 0, sizeof a);
	}
	void multiply(const Rec& rhs){
		Rec ans;
		ans.clear();
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				for(int k = 0; k < n; ++k){
					ans.a[i][j] += (rhs.a[k][j]*a[i][k])%MOD;
					ans.a[i][j] %= MOD;
				}
			}
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				a[i][j] = ans.a[i][j];
			}
		}
	}
	void print(){
	}
	void getp(){
	}
};
Rec getret(Rec x, ll y){
	Rec ans;
	ans.n = x.n;
	ans.clear();
	for(int i = 0; i < ans.n; ++i) ans.a[i][i] = 1;
	while(y){
		if(y&1) ans.multiply(x);
		y >>= 1;
		x.multiply(x);
	}
	return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    int r, c;
    ll n;
    cin >> n >> r >> c;
    dfs(r, c);
    int sz = vt.size();
    Rec ret;
    ret.n = sz;
    ret.clear();
    for(int i = 0; i < sz; ++i){
    	for(int j = i; j < sz; ++j){
    		int xx = vt[i].first-vt[j].first;
    		int yy = vt[i].second-vt[j].second;
    		if((abs(xx)==2&&abs(yy)==1)||(abs(xx)==1&&abs(yy)==2)){
    			ret.a[i][j] = 1;
    			ret.a[j][i] = 1;
    		}
    	}
    }
    Rec ret1 = getret(ret, n);
    ll ans = 0;
    for(int i = 0; i < sz; ++i){
    	ans += ret1.a[i][0];
    }
    ans %= MOD;
    cout << ans << endl;
    return 0;
}
