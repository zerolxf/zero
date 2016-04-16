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
const int MOD = 9973;
int n;
struct Rec{
	ll num[15][15];

	Rec operator*(const Rec& rhs){
		Rec ans;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				ans.num[i][j] = 0;
				for(int l = 1; l <= n; ++l) {
						ans.num[i][j] = (ans.num[i][j]+(num[i][l]*rhs.num[l][j]))%MOD;
				}
			}
		}
		return ans;
	}
	 Rec operator =(const Rec& rhs){
	 	for(int i = 1; i <= n; ++i){
	 		for(int j = 1; j <= n; j++)
	 			num[i][j] = rhs.num[i][j];
	 	}
	 }
}unit;

Rec ret(Rec a, ll k) {
	Rec ans, temp;
	//if(k==0) return unit;
	if(k==1) return a;
	//Rec ans, temp;
	temp = a*a;
	temp = ret(temp,k/2);
	if(k%2==1) ans = a*temp*temp;
	else ans = temp*temp;
	//prln(k);print(ans);
	return ans;
}
Rec pow(Rec A, ll k) {
	Rec ans = unit;
	while(k > 0) {
		if(k%2) ans = ans*A;
		A = A*A;
		k = k/2; 
	}
	return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    ll  k, t;
    Rec a;
    for(int i = 0; i < 11; ++i) {
    	for(int j = 0; j < 11; ++j){
    		if(i==j) unit.num[i][j] = 1;
    		else unit.num[i][j] = 0;
    	}
    }
  	cin >> t;
  	while(t--) {

  		cin >> n >> k;
  		for(int i = 1; i <= n; ++i) {
  			for(int j = 1; j <= n; ++j) {
  				cin >> a.num[i][j];
  			}
  		}
  		Rec ans = pow(a,k);
  		ll b = 0;
  		for(int i = 1; i <= n; ++i) {
  			b += ans.num[i][i];
  		}
  		b%=MOD;
  		printf("%lld\n",b);
  	}
    return 0;
}