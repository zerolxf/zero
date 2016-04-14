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
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
struct Node{
	ll l, r;
	bool operator < (const Node& rhs)const{
		return l < rhs.l || (l==rhs.l&&r < rhs.r);
	}
};
map<Node,bool> mp;
bool dfs(Node x) {
	ll l = x.l, r= x.r;
	if(x.l > x.r) swap(x.l,x.r);
	if(x.l==0) return true;
	if(mp.count(x)) return mp[x];
	if(x.r%x.l==0) {
		mp[x] = 1;
		return 1;
	} else {
		bool ans1, ans0;
		bool ok = dfs(Node{x.l,x.r%x.l});
		if(!ok) return mp[x] = 1;
		if(x.r>x.l*2) return mp[x] = 1;
		return mp[x] = 0;
	}
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    ll l, r;
    while(cin >> l >> r && l + r != 0) {
    	bool ok = dfs(Node{l,r});
    	if(ok) printf("Stan wins\n");
    	else printf("Ollie wins\n");
    }
    return 0;
}