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
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    ll a, b, ans1, ans2, last;
    ans1 = 0; ans2 = 0;
    while(cin >> a >> b) {
    	if(a == b) {
    		ans1 = a-1;
    		ans2 = a;
    	} else {
    		if(a < b) swap(a,b);
    		ans2 = b;
    		if(b%1) {
    			ans1 = b-1;
    			last = a - ans1;
    			ans1 += last-1;
    		} else {
    			ans1 = b - 1;
    			last = a - ans1;
    			ans1 += last -1;
    		}
    	}
    	cout << ans1 << " " << ans2 << "\n";
    }
    return 0;
}