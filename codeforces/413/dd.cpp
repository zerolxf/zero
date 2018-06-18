#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <utility>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f;
const int maxn = 400010;
#define pr(x) cout << #x <<" = " << x << " ";
#define prln(x) cout << #x <<" = " << x << " " << endl;

int size, tot;
int num[maxn], id[maxn], a[maxn], mp[maxn];

int dfs(int pos, ll h, ll w, ll a, ll b) {
	if(h >= a && w >= b) return 0;
	if(pos >= tot) {
		if(h >= a && w >= b) return 0;
		return inf;
	}
	int ans = inf;
	ll temph = h;
	for(int i = 0; i <= num[pos]; i++) {
		ll tempw = w;
		for(int j = 0; j <= num[pos] && i + j <= num[pos]; j++) {
			ans = min(ans, i + j + dfs(pos + 1, temph, tempw, a, b));
			if(tempw >= b) break;
			tempw = tempw * id[pos];
		}
		if(temph >= a) break;
		temph = temph * id[pos];
	}
	return ans;
}

int main()
{
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    #endif
    int A, b, h, w, n; scanf("%d%d%d%d%d", &A, &b, &h, &w, &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    size = min(40, n);
    tot = 1;
	for(int i = 1; i <= size; i++) a[i] = a[n - size + i];
	memset(num, 0, sizeof(num));
	for(int i = size; i >= 1; i--) {
		if(mp[a[i]]) {
			num[mp[a[i]]]++;
		}
		else {
			id[tot] = a[i];
			mp[a[i]] = tot++;
			num[mp[a[i]]]++;
		}
	}
    int ans = inf;
	ans = dfs(1, h, w, A, b);
	ans = min(ans, dfs(1, h, w, b, A));
	if(ans == inf) {
		printf("-1\n");
	}
	else {
		printf("%d\n", ans);
	}
    return 0;
}
