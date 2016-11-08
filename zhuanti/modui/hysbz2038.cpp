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
const int maxn = 5e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       //cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
ll gcd(ll a, ll b) {
	return b?gcd(b,a%b):a;
}
int num[maxn], n, m, unit;
ll cnt[maxn];
struct Ans{
	ll  a, b;
	void reduce() {
		ll k = gcd(a,b);
		a /= k; b /= k;
	}
}q[maxn];
struct Node{
	int l, r, id;
	bool operator < (const Node& rhs)const{
		return l/unit < rhs.l/unit || (l/unit==rhs.l/unit&& r < rhs.r);
	}
}node[maxn];
void mo(){
	//sort(node,node+m);
	ll L = 1, R = 0;
	ll ans = 0;
	for(int i = 0; i < m; ++i) {
		pr(i);pr(L);prln(R);
		while(R < node[i].r) {
			++R;
			ans += 2*cnt[num[R]] + 1;
			++cnt[num[R]];
		}
		while(R > node[i].r) {
			ans -= 2*cnt[num[R]] - 1;
			cnt[num[R--]]--;
		}
		while(L < node[i].l) {
			ans -= 2*cnt[num[L]] -1;
			cnt[num[L++]]--;
		}
		while(L > node[i].l) {
			L--;
			ans += 2*cnt[num[L]]+1;
			++cnt[num[L]];
		}
		q[node[i].id].a = ans - (R-L+1);
		q[node[i].id].b = (R-L)*(R-L+1);
		q[node[i].id].reduce();
	}
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
    	scanf("%d", &num[i]);
    }
    for(int i = 0; i < m; ++i) {
    	scanf("%d%d", &node[i].l, &node[i].r);
    	node[i].id = i;
    }
    prln("1");
    unit = sqrt(n);
    sort(node,node+m);
    prln("2");
    mo();
    prln("3");
    for(int i = 0; i < m; ++i) {
    	printf("%lld/%lld\n",q[i].a,q[i].b);
    }
    prln("4");
    return 0;
}












