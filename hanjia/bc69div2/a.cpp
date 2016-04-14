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
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
ll a, b, t, c;
bool judge(int x1, int x2){
	if(c%2) return false;
	int cc = c/2;
	if(x1%2==0&&x2%2==0) return true;
	return false;
	for(int i = 0; i <= x1; ++i){
		if((cc-i*a)%b==0&&(cc-i*a)/b <= x2) return true;
	}
	return false;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    cin >> t;
    int ans = 0,x1,x2 ,num1, num2, ma, mb;
    while(t--) {
    	cin >> a >> b >> c;
 		ans = INF;
    	ma = c/a; mb = c/b;
    	for(int i = ma; i >= 0; --i) {
    		if((c-i*a)%b==0) {
    			x1 = i;x2=(c-i*a)/b;
    			//pr(x1);prln(x2);
    			if(x1+x2< ans&&judge(x1,x2)){
    				num1 =x1;num2 = x2;
    				ans = num1+num2;
    			}
    		}
    	}
    	if(ans!=INF) {
    		cout << num1 << " " << num2 << "\n";
    	} else cout << "Impossible\n";
    }
    return 0;
}