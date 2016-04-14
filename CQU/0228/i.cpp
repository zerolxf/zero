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
int a[]={1,2,10,1},b[]={14,36,30,8};
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int x,sum2=0;
    for(int i = 0; i <4;++i) sum2 +=a[i];
    for(int i = 0; i < 4; ++i){
    	prln(b[i]);
    	int sum = 0, sum1 = 0;
    	x = 0;
    	for(int j = 0; j < 4; ++j){
    		x = x^a[j];
    		sum += a[j]^b[i];
    		sum1 += a[j]^(sum2-a[j]);
    		pr((a[j]^b[i]));
    	}
    	prln(sum1);prln(sum);prln(x);
    	prln("***************");
    }
    return 0;
}