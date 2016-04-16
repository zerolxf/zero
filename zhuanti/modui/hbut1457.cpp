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
const int maxn = 123456;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,(n)*sizeof(int))
map<int, int> mp;
int num[maxn], n, m, unit;
ll cnt[maxn];
ll gcd(ll a, ll b){
	return b?gcd(b,a%b):a;
}
struct Query{
	int l, r, id;
	bool operator < (const Query& rhs)const{
		return l/unit < rhs.l/unit || (l/unit==rhs.l/unit&&r < rhs.r);
	}
}q[maxn];
ll ans[maxn];

void mo() {
	MN(cnt,0,n+10);
	sort(q,q+m);
	int L = 1, R = 0;
	ll sum = 0;
	for(int i = 0; i < m; ++i) {
		while(R < q[i].r) {
			ll x = cnt[num[++R]]++;
			sum += x*x*3 + 3*x + 1;
		}
		while(R > q[i].r) {
			ll x = cnt[num[R--]]--;
			sum -= x*x*3 - 3*x + 1;
		}
		while(L > q[i].l) {
			ll x = cnt[num[--L]]++;
			sum += x*x*3 + x*3 +1;
		}
		while(L < q[i].l) {
			ll x = cnt[num[L++]]--;
			sum -= x*x*3-x*3+1;
		}
		ans[q[i].id] = sum;
	}
}

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int x, id;
    while(scanf("%d", &n) != EOF) {
    	mp.clear();
    	id = 1;
    	for(int  i = 1; i <= n; ++i) {
    		scanf("%d", &x);
			if(mp.count(x)) num[i] = mp[x];
			else{
				cnt[i] = 0;
				mp[x] = id;
				num[i] = id++;
			}
    	}
    	scanf("%d", &m);
    	for(int i = 0; i < m; ++i ) {
    		scanf("%d%d", &q[i].l, &q[i].r);
    		q[i].id = i;
    	}
    	unit = sqrt(n+0.5);
    	mo();
    	for(int i =0; i < m; ++i) {
    		printf("%I64d\n", ans[i]);
    	}
    }
    return 0;
}


















