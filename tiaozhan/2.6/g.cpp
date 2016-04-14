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
const int maxn = 1e7+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
ll a[maxn], b[maxn];
bool vis[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, N = 1e5+1, cnt = 0;
    for(ll i = 5; i <= N; i+=4){
    	if(!vis[i]) {
    		a[cnt++] = i;
    		//pr(i);
    		for(ll j = i; j <= N; j+=i) {
    			vis[j] = true;
    		}
    	}
    }
    CLR(vis);
    int num = 0;
    for(ll i = 0; i < cnt; ++i) {
        if(a[i]*a[i] > N) continue;
    	for(ll j = i; j < cnt; ++j) {
            if(a[i]*a[j] > N) break;
            int x = a[i]*a[j];
            if(vis[x]) continue;
            b[num++] = x;
            vis[x] = true;
        }
    }
    sort(b,b+num);

    while(cin >> n && n) {
    	int pos = upper_bound(b,b+num,n) -b;
    	printf("%d %d\n",n,pos);
    }
    return 0;
}