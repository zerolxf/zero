
/*
* @author:  liangxianfeng
* @mail: liangxianfeng96@qq.com
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define repp(i,n,x) for(int i =x; i < n+x; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl;
const int MOD = 1e9+7;
const int maxn = 2e5+100;
int a[maxn], b[maxn];
int N, now;
int getk(int x){
	x %= N;
	now = (now+x)%N;
	int ans = a[now];
	for(int i = now; i < N; ++i){
		a[i] = a[i+1];
	}
	N--;
	now = (now)%N;
	return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i) a[i] = i;
    N = n;now = 0;
    rep(i,k) cin >> b[i];
    rep(i,k){
    	int ans = getk(b[i]);
    	cout<<ans+1<<" ";
    }
    return 0;
}
