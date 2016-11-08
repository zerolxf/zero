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
int prime[maxn], N = 1e6, vis[maxn], cnt;
void getprime() {
	cnt = 0;
	for(ll i = 2; i <= N; ++i) {
		if(!vis[i]) {
			prime[cnt++] = i;
			for(ll j = i*i; j <= N; j+=i) {
				vis[j] = true;
			}
		}
	}
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n;
    getprime();
    while(cin >> n) {
    	int pos = upper_bound(prime,prime+cnt,n) - prime;
    	printf("%d\n", pos);
    }
    return 0;
}