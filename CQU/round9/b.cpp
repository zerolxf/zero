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
const double pi = acos(-1);
const double eps = 1e-9;
int L,R;
struct  Node
{
	double x, y, p;
	void scan(){
		scanf("%lf%lf%lf",&x,&y,&p);
		p = p/180*pi;
		x -= L;
		y = fabs(y);
	}

}p[maxn];
double dp[(1<<21)];
double get(int id, double x){
	double len = sqrt((p[id].x-x)*(p[id].x-x)+p[id].y*p[id].y);
	double cosx = acos((x-p[id].x)/len);
	if(cosx - p[id].p < eps) return R;
	double ans = len*sin(p[id].p)/sin(cosx-p[id].p);
	return min(ans+x,R*1.0);
}

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n;
    while(cin >> n >> L >> R){
    	R-=L;
    	for(int i = 0; i < n; ++i){
    		p[i].scan();
    	}
    	dp[0] = 0;
    	for(int i = 0; i < (1<<n); ++i){
    		for(int j = 0; j < n; ++j){
    			if(i&(1<<j)) continue;
    			dp[i|(1<<j)] = max(dp[i|(1<<j)],get(j,dp[i]));
    		}
    	}
    	double ans = dp[(1<<n)-1];
    	printf("%.10f\n",(ans));
    }
    return 0;
}