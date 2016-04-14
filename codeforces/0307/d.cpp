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
const int maxn = 6e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
ll suml[maxn], sumr[maxn];
ll a[maxn], b[maxn], aa, bb;
char s[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    ll T, n;
    cin >> n >> aa >> bb >> T;
    scanf("%s",s+1);
    sumr[0] = 0;
    if(s[1]=='h') sumr[1] = 1;
    else sumr[1] = 1+bb;
    for(int i = 2; i <= n; ++i) {
    	if(s[i] == 'h') {
    		sumr[i]  = sumr[i-1] + aa + 1;
    	} else sumr[i] = sumr[i-1] + aa + bb + 1;
    }
    suml[n+1] = 0;
    for(int i = n; i > 0; --i) {
    	if(s[i] == 'h') {
    		suml[i] = suml[i+1] + aa + 1;
    	} else suml[i] = suml[i+1] + bb +1 + aa;
    }
    ll ans = 0;
    if(s[1]=='w'&&T<bb+1) {
    	cout << "0\n";
    	return 0; 
    }
    for(int i = 1; i <= n; ++i) {
    	a[i] = sumr[i] + aa*(i-1);
    }
    if(sumr[n] <= T) ans = n;
    if(ans != n)
    for(int i = n; i > 0;--i) {
    	if(suml[i] <= T) {
    		ll left = T-suml[i];
    		int pos = upper_bound(a+1,a+1+n,left) - a - 1;
    		ans = max(ans,pos+n-i+1);
    	}
    }
    ll pos = upper_bound(sumr+1,sumr+1+n,T) - sumr - 1;
    ans = max(ans,pos);
    for(int i = 1; i <= n; ++i) {
    	a[i] = suml[n-i+1];
    }
    pos = upper_bound(a+1,a+1+n,T) - a - 1;
    ans = max(pos,ans);
    for(int i = 1; i <= n; ++i) {
    	a[i] = sumr[n-i+1] + aa*(i);
    }
    for(int i = 1; i <= n;++i) {
    	if(sumr[i] <= T) {
    		ll left = T-sumr[i];
    		ll pos = upper_bound(a+1,a+1+n,left) - a - 1;
    		//ll pos = 0;
    		ans = max(ans,i+pos-1);
    	}
    }
    if(ans > n) ans = n;
    cout << ans << "\n";
    return 0;
}