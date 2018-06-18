
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
const int INF = 0x3f3f3f3f;
const int N = 20;
int kill[N], xz[N], zd;
int n, m, a, b, c, S;
bool b_safe[maxn];
int dis[2][maxn], num[maxn];
void init_State(){
	for(int i = 0; i < S; ++i){
		b_safe[i] = true;
		for(int j = 0; j < n; ++j){
			if((i&(1<<j)) && (kill[j]&i) && !(xz[j]&i)) b_safe[i] = false;
			num[i] += (i>>j)&1;
		}
	}
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    int x, y;
    cin>>n>>m>>a>>b>>c;
    S = (1<<n)-1;
    rep(i,a) {
    	cin >> x >> y;
    	kill[x] |= 1<<y;
    }
    rep(i,b) {
    	cin>> x >> y;
    	xz[y] |= 1<<x;
    }
    rep(i,c){
    	cin>>x;
    	zd |= 1<<x;
    }
    init_State();
    memset(dis, 0x3f, sizeof dis);
    queue<int> q;
    dis[0][S] = 0;
    q.push(S<<1);
    while(q.size()){
    	int u = q.front()>>1, o = q.front()&1;q.pop();
    	// pr(o);prln(u);
    	for(int i = u; i; i = (i-1)&u){
    		int g = i;
    		if((g&zd) && b_safe[g] && b_safe[u^g] && num[g]<=m){
    			int uu = S^u^g, oo = o^1;
    			if(dis[oo][uu]<=dis[o][u]+1) continue;
    			dis[oo][uu]=dis[o][u]+1;
    			// pr(oo);prln(uu);
    			if(oo==1&&uu==S) break;
    			q.push((uu<<1)|oo);
    		}
    	}
    }
    int ans = dis[1][S];
    if(ans>=INF) ans = -1;
    cout<<ans<<"\n";
    return 0;
}
