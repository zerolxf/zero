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
int r[maxn], c[maxn], a[1234][1234];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, m, x, y, k;
    char op[10];
    while(cin >> n >> m >> k) {
    	for(int i = 1; i <= n; ++i) r[i] = i;
    	for(int j = 1; j <= m; ++j) c[j] = j;
    	for(int i = 1; i <= n; ++i) {
    		for(int j = 1; j <= m; ++j) {
    			scanf("%d", &a[i][j]);
    		}
    	}
    	for(int i = 0; i < k; ++i) {
    		scanf("%s%d%d",op,&x,&y);
    		if(op[0] == 'g') printf("%d\n", a[r[x]][c[y]]);
    		else if(op[0] == 'c') {
    			swap(c[x], c[y]);
    		} else swap(r[x],r[y]);
    	}
    }
    return 0;
}