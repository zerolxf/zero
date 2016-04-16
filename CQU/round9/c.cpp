
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
	int a, b;
	bool operator < (const Node& rhs)const{
		return b < rhs.b;
	}
	/* data */
}a[maxn];
bool cmp(const Node& a, const Node& b){
	return a.a > b.a;
}
bool vis[1100];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, t;
    cin >> t;
    while(t--){
    	scanf("%d",&n);
    	//prln(n);
    	for(int i = 0; i < n; ++i){
    		vis[i] = 0;
    		scanf("%d%d",&a[i].a,&a[i].b);
    	}
    	sort(a,a+n,cmp);
    	bool ok = true;
    	ll ans = 0;
    	for(int i = 0; i < n; ++i){
    		ok = false;
    		if(vis[i]) continue;
    		vis[i] = true;
    		for(int j = n-1; j >= 0; --j){
    			if(!vis[j] && a[i] < a[j]){
    				ok = true;
    				ans += a[i].a;
    				vis[j] = true;
    				break;
    			}
    		}
    		if(!ok) {
    			vis[i] = false;
    		}
    	}
    	cout << ans << "\n";
    }
    return 0;
}