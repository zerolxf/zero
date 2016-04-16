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
int dp[maxn];
int mod[] = {1,10,100,1000,10000,100000};
int MOD;
int ret[10][10];
struct Ret
{
	int a, b, c, d;
	Ret operator*(const Ret& rhs)const{
		return Ret{a*rhs.a+b*rhs.c,a*rhs.b+b*rhs.d,c*rhs.a+d*rhs.c,c*rhs.b+d*rhs.d}; 
	}
	void getmod(){
		a = a%MOD;b = b%MOD;
		c = c%MOD;d = d%MOD;
	}
};
Ret getret(int x, Ret ret) {
	//Ret ans{1,1,1,0},base{1,1,1,0};
	if(x == 0) return Ret{1,0,0,1};
	if(x == 1) return ret;
	Ret ans{1,0,0,1},temp;
	if(x%2) ans = ans*ret;
	ret = ret*ret;
	ret.getmod();
	temp = getret(x/2,ret);
	ans = ans*temp;
	ans.getmod();
	return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, m, a, b, t, kase = 0;
    cin >> t;

    while(t--) {
    	printf("Case %d: \n", ++kase);
    	cin >> a >> b >> n >> m;
    	MOD = mod[m];
    	if(n < 2) printf("%d\n",n==0?a:b);
    	else {
    		Ret ans = getret(n,Ret{1,1,1,0});
    		//pr(ans.a);pr(ans.b);pr(ans.c);prln(ans.d);
    		ll num = ans.c*b+ans.d*a;
    		num = num%MOD;
    		printf("%d\n", num);
    	}
    }
    return 0;
}