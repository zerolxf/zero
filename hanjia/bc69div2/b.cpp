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
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       //cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int a[100];
int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
bool judge(ll x) {
	ll last = x%100000;
	for(int i = 0; i <= 4; ++i) {
		a[i] = last%10;
		pr(i);prln(a[i]);
		last = last/10;
	}
	bool ok = true;
	for(int i = 0; i <= 3; ++i) {
		if(a[i]!=a[i+1]){
			ok = false;
		}
	}
	if(ok) return true;
	ok = true;
	for(int i = 0; i <= 3; ++i) {
		if(a[i]!=a[i+1]+1){
			ok = false;
		}
	}
	if(ok) return true;
	ok = true;
	for(int i = 0; i < 4; ++i){
		if(a[i]!=a[i+1]-1){
			ok = false;
		}
	}
	if(ok)  return true;
	prln("7");
	int year = x/10000%10000;
	prln(year);
	int mon = x/100%100;
	int day = x%100;
	if(mon > 12 || mon < 1) return false;
	prln("0");
	if(year > 2016 || year < 1980){
		prln(year);
		prln("4");
		return false;
	} 
	prln("1");
	if(mon==2&&year%4==0) {
		if(day<=29&&day>0) return true;
	}
	prln("2");
	if(year%4!=0) {
		if(day<=month[mon-1]&&day>0) return true;
	}
	return false;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    ll t, n, x, a, b, ans;
   
    cin >> t;
    while(t--) {
    	cin >> n >> a >> b;
    	ans = 0;
    	for(int i = 0; i < n; ++i) {
    		scanf("%I64d",&x);
    		if(judge(x)) {
    			ans += a;
    			prln(x);
    			prln("****************");
    		}
    		else ans +=b;
    	}
    	cout << ans << "\n";
    }
    return 0;
}