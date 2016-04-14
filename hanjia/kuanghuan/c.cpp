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
int a[maxn], b[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, m;
    while(cin >> n >> m) {
    	int la = 0, ans = 0, lb = 0;
    	for(int i = n; i >= 0; --i) {
    		cin >> a[i];
    		if(!ans) {
    			ans = a[i];
    			la = i;
    		}
    	}
    	ans = 0;
    	for(int i = m; i >= 0; --i) {
    		cin >> b[i];
    		if(!ans) {
    			ans = b[i];
    			lb = i;
    		}
    	}
    	if(la > lb) {
    		if(a[la]*b[lb] < 0) printf("-");
    		printf("Infinity\n");
    	} else if(la < lb) {
    		printf("0/1\n");
    	} else {
    		if(a[la]*b[lb] < 0) printf("-");
            int ansb = abs(b[lb]);
            int ansa = abs(a[la]);
            int tt = __gcd(ansb,ansa);
            ansb = ansb/tt;
            ansa = ansa/tt;
    		printf("%d/%d\n", ansa,ansb);
    	}
    }
    return 0;
}