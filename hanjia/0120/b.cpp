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
const int maxn = 2e6+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
int a[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int ans = 0;
    bool ok = true;
    int n, k;
    while(cin >> n >> k && n && k) {
    	for(int i = 1; i <= n; ++i) {
    		scanf("%d", &a[i]);
    	}
    	for(int i = k; i <= n-1; ++i) {
    		if(a[i]!=a[i+1]) ok = false;
    	}
    	if(ok) {
    		for(int i = k-1; i >= 1; --i) {
    			if(a[i] != a[k]) {
    				ans = i;
    				break;
    			}
    		}
    	}
    	if(ok) printf("%d\n", ans);
    	else printf("-1\n");
    }
    return 0;
}