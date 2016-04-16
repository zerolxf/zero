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
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int num, sum, x, t,n, kase = 0;
    cin >> t;
    while(t--) {
    	cin >> n;
    	num = sum = 0;
    	for(int i = 0; i < n; ++i) {
    		scanf("%d",&x);
    		if(x >= 1) num++;
    		sum += abs(x);
    	}
    	printf("Case %d: ", ++kase);
    	//int gg = __gcd(sum,num);
    	if(num==0) printf("inf\n");
    	else {
    		//prln(num);
    		int gg = __gcd(sum,num);
    		printf("%d/%d\n",sum/gg,num/gg);
    	}
    }

    return 0;
}