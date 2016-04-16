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
#define ll long long
int a[maxn], b[maxn], ans, n, xy;
bool cmp(int x, int y) {
	return x > y?x:y;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    while(cin >> n >> xy) {
    	for(int i = 0; i < n; ++i) {
    		scanf("%d", &a[i]);
    	}
    	for(int i = 0; i < n; ++i) {
    		scanf("%d", &b[i]);
    	}
    	sort(b,b+n,cmp);
    	sort(a,a+n);
    	ans = 1;
    	int _n = (n+1)/2;
    	int pos;
    	/*for(int i = 0; i < n; ++i) {
    		pos = lower_bound(b,b+n,xy-a[i])-b;
    		ans = max(ans, min(n-i,n-pos));
    		//pr(i);prln(ans);
    	}
    	for(int i = 0; i < n; ++i) {
    		pos = lower_bound(a,a+n,xy-b[i])-a;
    		ans = max(ans, min(n-i,n-pos));
    		//pr(i);prln(ans);
    	}*/

    	pos = n-1;
    	int l = 0, r = 0, cnt = 0;
    	while(l<n&&r<n) {
    		if(a[l]+b[r]>=xy) {
    			cnt++;l++;r++;
    		} else l++;
    	}

    	ans = max(ans,cnt);
    	printf("1 %d\n",ans);
    }
    return 0;
}