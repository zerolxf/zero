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
double p[maxn];
double a[maxn];
bool cmp(double x,double y){
	return x > y;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int t;
    cin >> t;
    p[1] = 1;
    for(int i = 2; i <= 55; ++i){
    	p[i] = p[i-1]*0.95;
    }
    while(t--){
    	int n;
    	double ans = 0;
    	cin >> n;
    	for(int i = 1; i <= n; ++i){
    		cin >> a[i];
    	}
    	sort(a+1,a+n+1,cmp);
    	double sum =  0;

    	for(int i = 1; i <= n; ++i){
    		sum += a[i]*p[i];
    	}
    	printf("%.10f\n",sum );
    }
    return 0;
}