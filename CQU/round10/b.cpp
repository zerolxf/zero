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
double x[10];
double y[10];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    double x1, y1, x0, y0, a, b, p, xx, yy, pp;
    int t, n;
    cin >> t;
    while(t--) {
    	cin >> n;
    	x[0] = 0; y[0] = 0;
    	x[1] = 1; y[1] = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%lf%lf%lf",&xx,&yy,&pp);
			for(int j = 0; j < 2; ++j) {
				a = x[j];b = y[j];
				if(a==xx&&b==yy) continue;
				
			}
		}    	
    }
    return 0;
}