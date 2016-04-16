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
int a[maxn], n, cnt[1000];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int w;
    while(cin >> n >> w && n+w!=0) {
    	for(int i = 0; i < n; ++i) cin >> a[i];
    	int ma = 0, aa = 0;
    	CLR(cnt);
    	for(int i = 0; i < n; ++i) {
    		aa = max(aa,a[i]);
    	}
    	int num = (aa+w)/w;
    	for(int i = 0; i < n; ++i) {
    		for(int j = num-1; j >= 0; --j) {
    			if(a[i] >= j*w) {
    				cnt[j]++;
    				break;
    			}
    		}
    	}
    	for(int i = 0; i < num; ++i) {
    		ma = max(ma,cnt[i]);
    	}
    	double ans = 0.01;
    	for(int i = 0; i < num; ++i) {
    		ans += (cnt[i]*1.0/ma)*(num-i-1)/(num-1);
    	}
    	printf("%.8f\n", ans);
    }
    return 0;
}