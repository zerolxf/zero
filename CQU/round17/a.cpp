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
double sum, a, b, c;
int n;
double getshun(double x, double y) {
	//if(x == y) return n*2;
	double ans = 0;
	if(x <= y) ans += y-x;
	else ans += n- (x-y);
	return ans;
}
double getni(double x, double y) {
	if(x >= y) return x - y;
	else return n - (y-x);
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    while(cin >> n >> a >> b >> c&&(a+b+c+n)!=0) {
    	sum = 0;
    	for(int i = 1; i <= n; ++i) {
    		sum += 2*n+getshun(i,a);
    		sum += n + getni(a,b);
    		sum += getshun(b,c);
    	}
    	sum = 0;
    	sum = (n-1)*1.0/2 + n*3 + getshun(a,b) + getni(b,c);
    	printf("%.3f\n",sum);
    }
    return 0;
}
