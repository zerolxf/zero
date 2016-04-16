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
ll num[]={0,0,1,3,6,10,15,21};
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    ll a, b, c, sum, ans, x;
    while(cin >> a >> b >> c) {
    	if(a > b) swap(a,b);
    	if(a > c) swap(a,c);
    	if(b > c) swap(b,c);
    	x = 0;
    	if(a >= 2) x += 2;
    	else x += a;
    	if(b >= 2) x += 2;
    	else x += b;
    	if(c >= 2) x += 2;
    	else x += c;
    	ans = (a+b+c-x)*x + num[x];
    	printf("%lld\n", ans);
    	
    }
    return 0;
}