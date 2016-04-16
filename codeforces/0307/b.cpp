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
int cnt[maxn], ans;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int x, n;
    cin >> n;
    rep(i,n) {
    	cin >> x;
    	cnt[x]++;
    }
    int num = 0;
    ans = 0;
    while(num < n) {
    	ans--;
    	for(int i = 1; i <= 1000; ++i) {
    		if(num != n) {
    			if(cnt[i]) {
    				ans++;
    				num++;
    				cnt[i]--;
    			}
    		}
    	}
    }
    cout << ans << "\n";
    return 0;
}