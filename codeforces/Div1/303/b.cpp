/*************************************************************************
    > File Name: b.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月31日 星期一 19时22分02秒
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
#include <ctime>


using namespace std;
#define ll  long long
#define ld  long double
#define rep(i,n) for(int i =0; i < n; ++i)
#define repp(i,n,x) for(int i =x; i < n+x; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;

ll n, m, x, y, a, b;
typedef pair<ll,ll> P;
typedef pair<P,P> pii;
vector<pii> ans;
bool checkok(ll x1, ll y1){
    return 0<=x1&&x1<=n&&0<=y1&&y1<=m;
}
bool checkin(ll x1, ll y1, ll x2, ll y2){
    //pr(x1);pr(y1);pr(x2);prln(y2);
    return x1<=x&&x<=x2&&y1<=y&&y<=y2&&checkok(x1,y1)&&checkok(x2,y2);
}
bool add(ll aa, ll bb){
    //pr(aa);prln(bb);
    bool ok = false;
    if(aa<=n&&bb<=m&&aa>0&&bb>0){
        if(checkin(0,0,aa,bb)){
            ok = true;
            ans.push_back(pii(P(0,0), P(aa,bb)));
        }
        if(checkin(0,m-bb,aa,m)){
            ok = true;
            ans.push_back(pii(P(0,m-bb),P(aa,m)));
        }
        if(checkin(n-aa,m-bb,n,m)){
            ok = true;
            ans.push_back(pii(P(n-aa,m-bb),P(n,m)));
        }
        if(checkin(n-aa,0,n,bb)){
            ok = true;
            ans.push_back(pii(P(n-aa,0),P(n,bb)));
        }
        ll minaa = (aa)/2;
        ll minbb = bb/2;
        ll maxaa = aa-minaa;
        ll maxbb = bb-minbb;

        if(checkin(x-minaa,0,x+maxaa,bb)){
            ok = true;
            ans.push_back(pii(P(x-minaa,0),P(x+maxaa,bb)));
        }

        swap(minaa,maxaa);
        if(checkin(x-minaa,0,x+maxaa,bb)){
            ok = true;
            ans.push_back(pii(P(x-minaa,0),P(x+maxaa,bb)));
        }
        swap(minaa,maxaa);

        if(checkin(0,y-minbb,aa,y+maxbb)){
            ok = true;
            ans.push_back(pii(P(0,y-minbb),P(aa,y+maxbb)));
        }

        swap(minbb,maxbb);
        if(checkin(0,y-minbb,aa,y+maxbb)){
            ok = true;
            ans.push_back(pii(P(0,y-minbb),P(aa,y+maxbb)));
        }
        swap(minbb,maxbb);

        //3
         if(checkin(x-minaa,m-bb,x+maxaa,m)){
            ok = true;
            ans.push_back(pii(P(x-minaa,m-bb),P(x+maxaa,m)));
        }

        swap(minaa,maxaa);

         if(checkin(x-minaa,m-bb,x+maxaa,m)){
            ok = true;
            ans.push_back(pii(P(x-minaa,m-bb),P(x+maxaa,m)));
        }
        swap(minaa,maxaa);

        //4
        //
        
        if(checkin(n-aa,y-minbb,n,y+maxbb)){
            ok = true;
            ans.push_back(pii(P(n-aa,y-minbb),P(n,y+maxbb)));
        }


        swap(minbb,maxbb);
        if(checkin(n-aa,y-minbb,n,y+maxbb)){
            ok = true;
            ans.push_back(pii(P(n-aa,y-minbb),P(n,y+maxbb)));
        }

        swap(minbb,maxbb);

        

        //pr(minaa);pr(minbb);pr(maxaa);prln(maxbb);
        if(checkin(x-minaa,y-minbb,x+maxaa,y+maxbb)){
            ok = true;
            ans.push_back(pii(P(x-minaa,y-minbb),P(x+maxaa,y+maxbb)));
        }
        if(checkin(x-minaa,y-maxbb,x+maxaa,y+minbb)){
            ok = true;
            ans.push_back(pii(P(x-minaa,y-maxbb),P(x+maxaa,y+minbb)));
        }
        if(checkin(x-maxaa,y-minbb,x+minaa,y+maxbb)){
            ok = true;
            ans.push_back(pii(P(x-maxaa,y-minbb),P(x+minaa,y+maxbb)));
        }
        if(checkin(x-maxaa,y-maxbb,x+minaa,y+minbb)){
            ok = true;
            ans.push_back(pii(P(x-maxaa,y-maxbb),P(x+minaa,y+minbb)));
        }

    }
    return ok;
}
long double qr(long double xx,long double yy){
    return xx*xx+yy*yy;
}
bool cmp(const pii& s, const pii& t){

    ll dsx = s.second.first - s.first.first;
    ll dtx = t.second.first - t.first.first;
    if(dsx > dtx) return true;
    else if(dsx < dtx) return false;

    long double ds = qr((ld)(s.first.first+ s.second.first)-x*2, (ld)(s.first.second+s.second.second)-y*2);
    long double dt = qr((ld)(t.first.first+ t.second.first)-x*2, (ld)(t.first.second+t.second.second)-y*2);
    if(ds < dt) return true;
    else if(ds>dt) return false;

    return s < t;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(cin >> n >> m >> x >> y >> a >> b){
        ll g = __gcd(a,b);
        a /= g, b /= g;
        //for(ll i = 1; i*a<=n&&i*b<=m; ++i){
            //add(a*i,b*i);
        //}
        //add(a, b);
        //add(a*2,b*2);
        ll l = 1, r = min(n/a,m/b);
        add(a*l,b*l);
        add(a*r,b*r);
        while(l < r){
            ll mid = (l+r+1) >> 1;
            add(a*l,b*l);
            add(a*r,b*r);
            //prln(mid);
            if(add(a*mid,b*mid)) l = mid;
            else r = mid-1;
        }
        add(a*(l-1),b*(l-1));
        add(a*(l+1),b*(l+1));
        int siz = ans.size();

        sort(ans.begin(), ans.end(), cmp);
        //prln("ans");
        //for(int i = 0; i < siz; ++i){
            pii d = ans[0];
            cout << d.first.first << " ";
            cout << d.first.second << " ";
            cout << d.second.first << " ";
            cout << d.second.second << "\n";
        //}

    }

	return 0;
}
