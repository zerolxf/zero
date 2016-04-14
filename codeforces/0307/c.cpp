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
struct Node
{
	int x,y;
	bool operator < (const Node& rhs)const{
		return x < rhs.x || (x==rhs.x&&y < rhs.y);
	}
	/* data */
};
map<int,int> hashx,hashy;
map<Node,int> ha;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, x, y;
    ll ans = 0;
    cin >> n;
    rep(i,n) {
    	cin >> x >> y;
    	Node temp;
    	temp.x = x;temp.y = y;
    	if(hashx.count(x)) {
    		ans += hashx[x];
    		hashx[x]++;
    	} else hashx[x] = 1;
    	if(hashy.count(y)) {
    		ans += hashy[y];
    		hashy[y]++;
    	} else hashy[y] = 1;
    	if(ha.count(temp)) {
    		ans -= ha[temp];
    		ha[temp]++;
    	} else ha[temp] = 1;
    }
    cout << ans << "\n";
    return 0;
}