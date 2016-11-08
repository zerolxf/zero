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
map<int,int> mp;
int num[20],a[20];
int dir[]={1,2,4,5,-1,-2,-4,-5};
int get(int op) {
	ll temp;
	for(int i = 1; i <= 9; ++i) {
		a[i] = num[i];
	}
	if(op > 0) {
		temp = a[op];
		a[op] = a[op+1];
		a[op+1] =a[op+4];
		a[op+4] = a[op+3];
		a[op+3] = temp;
	} else {
		op = -op;
		temp = a[op];
		a[op] = a[op+3];
		a[op+3] = a[op+4];
		a[op+4] = a[op+1];
		a[op+1] = temp;
	}
	temp = 0;
	for(int i = 9; i; --i) {
		temp = temp*10+a[i];
	}
	return temp;
}
int q[7654321];
ll y;
void bfs(int x) {
	//queue<int> q;
	int tail = 0;
	mp[x] = 0;
	q[++tail] = x;
	while(tail) {
		ll u = q[tail--];
		ll uu = u;
		int du = mp[u];
		for(int i = 1; i <= 9; ++i) {
			num[i] = uu%10;
			uu/=10;
		}
		for(int i = 0; i < 8; ++i) {
			ll v = get(dir[i]);
			if(mp.count(v)) {

			} else {
				mp[v] = du+1;
				if(du+1<=9) q[++tail]=v;
			}
		}
	}
}

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
 // freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    ll x = 0; y = 0;
    int kase = 0;
    for(int i = 9; i ; --i) {
    	x = x*10+i;
    }
    mp[x] = 0;
    bfs(x);
    while(cin >> x && x) {
    	y = x/(1000000000);
    	x = x%(1000000000);
    	for(int i = 1; i<=9; ++i){
    		a[i] = x%10;
    		x/=10;
    	}
    	x = 0;
    	for(int i = 1; i <= 9; ++i) {
    		x = x*10+a[i];
    	}
    	int ans = 0;
    	if(mp.count(x)) {
    		ans = mp[x];
    	} else ans = -1;
    	if(ans > y) ans = -1;
    	printf("%d. %d\n",++kase,ans);
    }
    return 0;
}