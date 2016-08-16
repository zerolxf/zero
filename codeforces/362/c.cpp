/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月15日 星期五 01时32分32秒
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
#define pr(x) //cout << #x << " = " << x << " ";
#define prln(x)// cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
typedef pair<ll,ll> path;
map<path,ll> mp;
void getadd(path x, ll add){
    pr("add");pr(x.first);pr(x.second);pr(add);prln(mp[x]);
    if(mp.count(x)) mp[x] = mp[x] + add;
    else mp[x] = add;
}
ll get(path x){
    pr("get");pr(x.first);pr(x.second);prln(mp[x]);
    if(mp.count(x)) return mp[x];
    return 0;
}
int a[100], b[100];
int c[100];
int getc(ll x){
    int cnt = 0;
    for(int i = 0; i < 64;++i){
        if(x) cnt++;
        c[i] = x&1;
        x>>=1;
    }
    return cnt;
}
void geta(ll x, ll y, ll w){
    if(x<y) swap(x,y);
    prln("*****************");
    pr(x);prln(y);

    int lena = getc(x);
    for(int i = lena-1; i>=0 ; --i){
        a[lena-1-i] = c[i];
        b[lena-1-i] = a[lena-1-i];
    }
    prln(lena);
    for(int i = 0; i < lena; ++i){
        pr(i);prln(a[i]);
    }
    int lenb = getc(y);
    for(int i = lenb-1; i>=0; --i){
        b[lenb-1-i] = c[i];
    }
    ll aa = 0;
    int ma = 0;
    for(int i = 0; i < lena; ++i){
        if(b[i]==a[i]) ma++;
        else break;
    }
    prln(ma);
    ma = min(ma,lenb);
    for(int i = 0; i < lena; ++i){
        aa = aa*2+a[i];
        if(i>=ma) {
            getadd(path(aa/2,aa),w);
            pr("add");prln(aa);
        }
    }
    aa = 0;
    for(int i = 0; i < lenb; ++i){
        aa = aa*2+b[i];
        if(i>=ma) {
            getadd(path(aa/2,aa),w);
            pr("add");prln(aa);
        }
    }
}

ll getans(ll x, ll y){
    if(x<y) swap(x,y);

    prln("*****************");
    pr(x);prln(y);

    int lena = getc(x);
    for(int i = lena-1; i>=0 ; --i){
        a[lena-1-i] = c[i];
        b[lena-1-i] = a[lena-1-i];
    }
    int lenb = getc(y);
    for(int i = lenb-1; i>=0; --i){
        b[lenb-1-i] = c[i];
    }
    ll aa = 0;
    int ma = 0;
    for(int i = 0; i < lena; ++i){
        if(b[i]==a[i]) ma++;
        else break;
    }
    prln(lenb);
    ma = min(ma,lenb);
    ll ans = 0;
    for(int i = 0; i < lena; ++i){
        aa = aa*2+a[i];
        if(i>=ma){ 
            ans+=get(path(aa/2,aa));
            pr("get");prln(aa);
        }
    }
    aa = 0;
    for(int i = 0; i < lenb; ++i){
        aa = aa*2+b[i];
        if(i>=ma){ 
            ans+=get(path(aa/2,aa));
            pr("get");prln(aa);
        }
    }
    return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
        mp.clear();
    cin >> n;
    while(n--){
        ll u, v, w;
        int op;
        scanf("%d", &op);
        if(op == 1) {
            cin >> u >> v >> w;
            geta(u,v,w);
        }else{
            cin >> u >> v;
            ll ans  = getans(u,v);
            cout << ans << "\n";
        }
    }
	return 0;
}
