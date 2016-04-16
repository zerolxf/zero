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
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)     // cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define ll long long
int vis[1100][110], last[1100], tail[1100], ed, cnt;
bool ok[1100][110];
int q[1100][110], temp[1100];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, m, k, t;
    ll a, x, y, b, c;
    scanf("%d",&t);
    while(t--){
    	scanf("%d%d%d", &n, &m, &k);
    	for(int i = 1; i <= n; ++i) {
    		tail[i]=0;
    		for(int j = 1; j <= k; ++j) {
    			vis[i][j] = 0;
    			last[i] = 0;
    			q[i][tail[i]++] = j;
    		}
    	}
    	//pr(n);pr(m);prln(k);
    	bool ans = true;
    	//prln(ans);
    	for(int i = 1; i <= m; ++i) {
    		scanf("%lld%lld%lld%lld%lld", &a, &x, &b, &y, &c);
    		if(b==0) {
    			swap(x,y);
    			swap(a,b);
    		}
    		if(x==y) {
    			b += a;
    			a = 0;
    			if(b==0&&c!=0) ans = false;
    			if(b!=0&&c==0) ans = false;
    		}
    		if(a==0&&b==0&&c==0) continue;
    		if(a==0&&b==0&&c!=0) {
    			ans = false;
    		}
    		if(!ans) continue;
    		if(a==0) {
	    		tail[y] = 0;
	    		if(c/b > 0 && c%b==0 && c/b <= k) {
	    			if(vis[y][c/b]>=last[y]) {
	    				q[y][tail[y]++] = c/b;
	    				vis[y][c/b] = i;
	    			}
	    		}
	    		last[y] = i;
	    	}
    		if(a&&b){
    			if(x==y) {
    				b = a+b;

    			}
    			tail[y] = 0;
    			cnt = 0;
	    		while(tail[x]) {
	    			ll u = q[x][--tail[x]];
	    			ll v= c-a*u;
	    			if((v/b > 0) && (v%b==0) && (v/b <= k)) {
	    				if(vis[y][v/b]>=last[y]) {
	    					temp[cnt++] = u;
	    					q[y][tail[y]++] = v/b;
	    					vis[y][v/b] = i;
	    					vis[x][u] = i;
	    				}
	    			}

	    		}
	    		//prln(cnt);
	    		tail[x] = 0;
	    		while(cnt) q[x][tail[x]++] = temp[--cnt];
	    		last[x] = last[y] = i;
	    	}
	    	if(tail[x] == 0 || tail[y] == 0) ans = false;
    	}
    	for(int i = 1; i <= n; ++i) if(tail[i] == 0) ans = false;
    	if(ans) printf("yes\n");
    	else printf("no\n");
    }
    return 0;
}