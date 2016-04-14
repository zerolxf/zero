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
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int a[maxn], sum, ans;
bool cmp(int a, int b) {
	return a > b;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, m, k;
    while(cin >> n >> m >> k) {
    	sum = 0;
    	for(int i = 1; i <= n; ++i) {
    		cin >> a[i];
    		sum += a[i];
    	}
    	if(sum+k-n<m) {
    		printf("-1\n");
    		continue;
    	}
    	if(k >= m) {
    		printf("0\n");
    		continue;
    	}
    	sum = 0;
    	sort(a+1,a+1+n,cmp);
    	for(int i = 1; i <= n; ++i) {
    		sum += a[i];
    		if(sum + k -i >= m) {
    			printf("%d\n",i);
    			break;
    		}
    	}
    }
    return 0;
}