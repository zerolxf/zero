
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
const int maxn = 1e5+100;
const int N = (1<<20)+100;
int pa[N], area[N], len[N];
bool vis[1100][1100];
int find(int x){
	return pa[x] == x?x:find(pa[x]);
}
void init(){
	memset(vis, 0, sizeof vis);
	for(int i = 0; i < N; ++i){
		pa[i] = -1;
		area[i] = 0;
		len[i] = 0;
	}
}
void se(int x, int l, int a){
	pa[x] = x;
	len[x] = l;
	area[x] = a;
}
int unite(int x, int y){
	x = find(x), y = find(y);
	if(x==y) return 0;
	pa[x] = y;
	len[y] += len[x];
	area[y] += area[x];
	return 1;
}
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    int n, x, y;
    cin >> n;
    init();
    for(int i = 0; i <= 1000+1; ++i){
    	int j = 0;
    	pa[(i<<10)|j] = 0, len[(i<<10)|j] = 0, area[(i<<10)|j] = 0;
    	pa[(j<<10)|i] = 0, len[(j<<10)|i] = 0, area[(j<<10)|i] = 0; 
    	//vis[]
    	j = 1000+1;
    	pa[(i<<10)|j] = 0, len[(i<<10)|j] = 0, area[(i<<10)|j] = 0;
    	pa[(j<<10)|i] = 0, len[(j<<10)|i] = 0, area[(j<<10)|i] = 0;
    }
    int ans = 0, ans2 = 0;;
    for(int i = 0; i < n; ++i){
    	cin >> x >> y;
    	ans++;
    	x++,y++;
    	int l = 0;
    	for(int d = 0; d < 4; ++d){
    		int nx = x + dx[d];
    		int ny = y + dy[d];
    		if(nx==0||nx==1001||ny==0||ny==1001||!vis[nx][ny]) l++;
    	}
    	ans2 += l;
    	vis[x][y] = true;
    	int id = (x<<10)|y;
    	se(id, l, 1);
    	for(int d = 0; d < 4; ++d){
    		int nx = x + dx[d];
    		int ny = y + dy[d];
    		if(nx==0||nx==1001||ny==0||ny==1001) continue;
    		if(vis[nx][ny]){
    			int id = (x<<10)|y;
    			id = find(id);
    			len[id] -= 1;
    			ans2--;
    			ans-=unite((nx<<10)|ny, (x<<10)|y);
    		}
    		//cout<<ans<< " " << i+1 << " " << 
    	}
    	cout<<ans<< " " << i+1 << " " << ans2<<endl;
    }
    return 0;
}
