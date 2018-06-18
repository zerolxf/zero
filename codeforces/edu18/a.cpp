
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
ll a[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    int n;
    cin >> n;
    rep(i,n) cin >> a[i];
    sort(a,a+n);
   	ll ans = 1e10, cnt = 1;
   	for(int i = 1; i < n; ++i){
   		if(a[i]-a[i-1]<ans){
   			ans = a[i]-a[i-1];
   			cnt=1;
   		}else if(a[i]-a[i-1]==ans){
   			cnt++;
   		}
   	}
   	cout<<ans << " " << cnt<<endl;
    return 0;
}
