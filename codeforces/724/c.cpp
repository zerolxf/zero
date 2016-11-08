/*************************************************************************
    > File Name: c.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月08日 星期六 21时33分05秒
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
#define pr(x) //cout << #x << " = " << x << " ";
#define prln(x) //cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const ll INF = 1e18;
long long extend_gcd(long long a,long long b,long long &x,long long &y)
{
    if(a==0&&b==0) return -1;//无最大公约数
    if(b==0){x=1;y=0;return a;}
    long long d=extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
ll xmod;
ll n, m;
ll gcdnm;
inline ll getans(ll d){
    ll ansx = 0, ansy = 0;
    if(d%gcdnm==0){
        ll t = d/gcdnm;
        extend_gcd(2*n,2*m,ansx,ansy);
        ansx*=abs(t);
        ansx = (ansx%xmod+xmod)%xmod;
        if(d>=0&&ansx>0) ansx -= xmod;
        return 2*n*abs(ansx);
    }
    return INF;
}
ll fun(ll posx, ll posy){
    ll ans = INF;
    ans = min(ans, getans(posx-posy)+posx);
    ans = min(ans, getans(posx-2*m+posy)+posx);
    ans = min(ans, getans(2*n-posx-posy)+2*n-posx);
    ans = min(ans, getans(2*n-posx-2*m+posy)+2*n-posx);
    return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

    ll k;
    while(cin>>n>>m>>k){
        gcdnm = __gcd(2*n,2*m);
        xmod = 2*m/gcdnm;
        ll ans = INF;
        ll xx, yy;
        rep(i,k){
            cin>>xx>>yy;
            ans = fun(xx,yy);
            if(ans==INF) printf("-1\n");
            else cout<<ans<<"\n";
        }


    }

	return 0;
}
