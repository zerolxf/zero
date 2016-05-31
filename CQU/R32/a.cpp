/*************************************************************************
	> File Name: a.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月28日 星期六 12时54分45秒
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
#define rep(i,n) for(ll i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const ll maxn = 4e5+100;
const ll INF = 0x3f3f3f3f;
char s[maxn];
const ll base = 1e10;
struct Bignum{
    ll a[40] ;
    Bignum(){}
    Bignum(ll len) {
        memset(a, 0, sizeof a);
        ll ans = 0;
        ll b = (len+9)/10;
        for(ll i = 0; i < b; ++i) {
            ll c = min((i+1)*10,len);
            ans = 0;
            for(ll j = c-1; j >= i*10; --j){
                ans = ans*10 + s[j] - '0';
            }
            a[i] = ans;
        }
    }
    void div(ll x) {
        ll c = 0, d = 0;
        for(ll i = 39; i >= 0; --i) {
            d = c*base + a[i];
            c = d%x;
            a[i] = d/x;
        }
    }
    void add(ll x) {
        ll c = x, d = 0;
        for(ll i = 0; i < 40; ++i){
            d = a[i] + c;
            a[i] = d%base;
            c = d/base;
        }
    }
    ll mod(ll x) {
        ll c = 0,d = 0;
        for(ll i = 39; i >= 0; --i){
            d = c*base + a[i];
            c = d%x;
        }
        return c;
    }
    void print(){
        for(int i = 20; i>=0; --i){
            printf("%lld",a[i]);
        }
        printf("\n");
    }
};
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

    while(scanf("%s", s) != EOF) {
        ll len = strlen(s);
        ll llen = len/2;
        for(ll i = 0; i < llen; ++i) {
            swap(s[i], s[len-i-1]);
        }
        Bignum a, b, c;
        a = Bignum(len);
        b = a;
        //a.print(); b.print();
        a.add(1);
        //a.print(); b.print();
        ll d = a.mod(9999);
        ll e = b.mod(9999);
        ll i = d*e%9999;
        if(a.mod(2) == 0) a.div(2);
        else b.div(2);
        ll f = a.mod(9999);
        ll g = b.mod(9999);
        ll h = f*g%9999;
        ll ans = 0;
        ans = (h*h%9999) + (h*(e*2+1)%9999) + i;
        ans = ans%9999;
        printf("%lld\n", ans);
    }
	return 0;
}
