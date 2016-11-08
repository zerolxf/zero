/*************************************************************************
    > File Name: 1003.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月18日 星期日 12时06分52秒
 ************************************************************************/

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
        y>>=1;
        x=x*x%MOD;
    }
    return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    ll n, m, k;
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%lld%lld%lld", &n, &m, &k);
        if(n<m*k){
            cout<<"0\n";
            continue;
        }
        ll num = n-k*m;
        ll ans = 1;
        //prln(num);
        //for(int i = 1; i < m; ++i){
            //ans = ans*i%MOD;
        //}
        for(int i = 1; i <= num; ++i){
            ans = ans*i%MOD;
        }
        for(int i = 1; i <= m; ++i){
            ans = ans*ret(i, MOD-2)%MOD;
        }

        for(int i = 1; i <= num-m; ++i){
            ans = ans*ret(i, MOD-2)%MOD;
        }
        printf("%lld\n", ans);

    }

	return 0;
}
