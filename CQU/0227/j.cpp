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
const int maxn = 2e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int x[maxn], y[maxn], cntx[maxn], cnty[maxn];
struct Node
{
	int x, y;
	bool operator < (const Node& rhs)const{
		return y*rhs.x < x*rhs.y;
	}
	void reduce(){
		int gg = __gcd(x,y);
		x/=gg;y/=gg;
	}
	/* data */
};

map<Node,int> count1[800];
int n;
inline int ma(int x, int y){
	if(x > y) return x;
	return y;
}
int getans() {
	for(int i = 0; i < n; ++i) count1[i].clear();
	for(int i = 0; i < n; ++i){
    		for(int j = i+1; j < n; ++j){
    			if((x[i]-x[j])*(y[i]-y[j]) > 0) {
    				Node temp{abs(y[i]-y[j]),abs(x[i]-x[j])};
    				temp.reduce();
    				//double temp = (y[i]-y[j])/(x[i]-x[j]);
    				//temp = (ll)(temp*1e6);
    				count1[i][temp]++;
    				//count1[j][temp]++;
    			} else if(((x[i]-x[j])*(y[i]-y[j]) < 0)){
    				Node temp{abs(y[i]-y[j]),abs(x[i]-x[j])};
    				temp.reduce();
    				//double temp = (y[i]-y[j])/(x[i]-x[j]);
    				//temp = (ll)(temp*1e6);
    				count1[i][temp]++;
    				//temp.y = -temp.y;
    				//count1[i][temp]++;
    				//count1[j][temp]++;
    			}
    		}
    	}
    	int ans = 0;
    for(int i = 0; i < n; ++i){
    	for(map<Node,int>::iterator  itr = count1[i].begin(); itr!=count1[i].end(); ++itr){
    		ans = ma(ans, itr->second);
    	}
    }
    return ans+1;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int t, kase = 0,  m, ans = 0;
    cin >> t;
    while(t--){
    	printf("Case %d: ", ++kase);
    	cin >> n;
    	CLR(cntx);
    	CLR(cnty);
    	ans = 0;
    	for(int i = 0; i < n; ++i){
    		scanf("%d%d",&x[i],&y[i]);
    		cntx[x[i]+10000]++;
    		cnty[y[i]+10000]++;
    	}
    	for(int i = 0; i < n; ++i){
    		ans = ma(ans,cntx[x[i]+10000]);
    		ans = ma(ans,cnty[y[i]+10000]);
    	}
    	ans = ma(getans(),ans);

    	printf("%d\n", ans);
    }
    return 0;
}