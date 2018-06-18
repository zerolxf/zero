
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
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
vector<ll> vt;
bool vis[maxn];
void getprime(){
	for(ll i = 2; i < 1e6; ++i){
		if(vis[i]) continue;
		vt.push_back(i);
		for(ll j = i*i; j < 1e6; j += i){
			vis[j] = true;
		}
	}
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif	
    getprime();
    ll n;
    cin >> n;
    ll ans1, ans2;
    for(int i = 2; i <= n; ++i){
    	if(vis[i]) continue;
    	if(vis[n-i]) continue;
    	ans1 = i, ans2 = n-i;
    	break;
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
