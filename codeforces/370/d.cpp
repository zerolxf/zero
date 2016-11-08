/*************************************************************************
    > File Name: d.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月11日 星期日 01时38分48秒
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
bool ok = false;
ll tans = 0;
ll ret(ll x, ll y){
    ll ans = 1;
    ll temp = 1;
    ll tempx = x;
    while(y){
        if(y&1){
            ans = ans*x%MOD;
            temp = temp*tempx;
            if(temp<0||tempx>=tans||temp>=ans) ok = true;
        }
        y>>=1;
        x=x*x%MOD;
        //if(tempx>(ll)sqrt(tans+0.5)) ok = true;
        tempx = tempx*tempx;
    }
    //prln(ans);
    //prln(temp);
    return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    ll a, b, n, k, t;
    cin>>a>>b>>k>>t;
    ll l = -k*t;
    ll r = k*t;
    //pr(l);prln(r);
    for(int i = l; i <= r; ++i){
        ll mi = l, ma = r;
        mi = max(mi, i-(a-b)+1);
        //ma = min(ma, r-(a-b)+1);
        ll num = 0;
        if(ma>=mi) num = ma-mi+1;
        else num = 0;
        //pr(mi);pr(ma);pr(i);prln(num);
        tans += num;
    }
    //prln(tans);
    if(tans<=0){
        printf("0\n");
        return 0;
    }
    ll mi = ret(2*k+1,t);
    if(!ok) tans = mi;
    cout<<tans<<"\n";
	return 0;
}
