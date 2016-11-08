/*************************************************************************
	> File Name: i.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月17日 星期日 09时05分03秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
ll ret(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y&1) ans = ans*x%MOD;
        x  = (x*x)%MOD;
        y >>= 1;
    }
    return ans;
}
int main(){
#ifdef LOCAL
	//freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

    ll n, k;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(k>n){
            cout << "0\n";
            continue;
        }
        ll y = n-k+1;
        ll ans = 1;
        if(y==1) ans = 1;
        else if(y == 2) ans = 2;
        else if(y>2) ans = (y+1)*ret(2,y-2)%MOD - (y)*ret(2,y-3)%MOD;
        ans = (ans%MOD+MOD)%MOD;
        cout << ans << "\n";
    }
	return 0;
}
