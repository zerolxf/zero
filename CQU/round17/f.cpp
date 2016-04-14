#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
#include<vector>

using namespace std;
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)     //  cout << #x << " = " << x << " ";
#define prln(x)   //  cout << #x << " = " << x <<endl;
#define ll long long
ll gcd(ll x, ll y) {
    if(y == 0){
        return x;
    }
    return gcd(y,x%y);
}
bool isok(ll cc, ll c, ll dd, ll d, ll a, ll b) {
    pr(cc);pr(c);pr(dd);pr(d);pr(a);prln(b);
    if(cc == 0 && dd == 0) return true;
    if(cc%a == 0 && d%b == 0 && dd%b == 0 && (c-cc)%a == 0) return true;
    if(cc%a == 0 && (d-dd)%b == 0 && dd%b == 0 && c %a == 0) return true;
    if(cc == 0 && dd%b == 0 && c%a == 0) return true;
    if(dd == 0 && cc%a == 0 && d%b == 0) return true;
    swap(a,b);
    if(cc%a == 0 && d%b == 0 && dd%b == 0 && (c-cc)%a == 0) return true;
    if(cc%a == 0 && (d-dd)%b == 0 && dd%b == 0 && c %a == 0) return true;
    if(cc == 0 && dd%b == 0 && c%a == 0) return true;
    if(dd == 0 && cc%a == 0 && d%b == 0) return true;
    return false;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
 int t;
 cin >> t;
 ll a, b, c, d;
    while(t--) {
        cin >> a >> b >> c >> d;
        bool ok = false;
        ll g = gcd(a,b);
        g = gcd(g,c);
        g = gcd(g,d);
        a/=g;b/=g;c/=g;d/=g;
        ll l = a*b/gcd(a,b);
        ll aa = a+b, bb = l;
        pr(a);pr(b);pr(aa);pr(bb);pr(c);pr(d);
        if((c%a==0&&d%b==0)||(c%b==0&&d%a==0)) ok = true;
        if(isok(c%aa,c,d%bb,d,a,b)) ok = true;
        if(isok(c%bb,c,d%aa,d,a,b)) ok = true;
        if(isok(c%a,c,d%b,d,a,b)) ok = true;
        if(isok(c%b,c,d%a,d,a,b)) ok = true;
        if(c*d%(a*b) != 0) ok = false;
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
