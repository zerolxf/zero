
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
#define pr(x) //cout << #x << " = " << x << " ";
#define prln(x) //cout << #x << " = " << x <<  endl;
const int MOD = 1e9+7;
const int maxn = 6e5+100;
const int INF = 0x3f3f3f3f;
vector<ll> vt;
ll x[maxn];
ll n, a, b, h, w;
int (ll y){
    ll ans = 0, res = 1, sz = vt.size();
    ll p = sz-1;
    while(res < y && p >= 0){
        res *= vt[p--];
        ans++;
    }
    return ans;
}
ll solve(ll aa, ll bb){
    aa = (aa+a-1)/a, bb = (bb+b-1)/b;

    int len1 = min(getmaxlen(aa), n), len2 = min(getmaxlen(bb), n);
    ll ans = INF;
    for(int i = 0; i <= len1; ++i){
        for(int j = 0; j <= len2 && (i+j) <= n; ++j){
            if(dfs(i, j, 0)) ans = min(ans, i+j);
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    cin >> a >> b >> h >> w >> n;
    rep(i,n){
        cin>>x[i];
    }
    sort(x,x+n);
    int len = min(n, 36);
    for(int i = n-1; i >n-1-len; --i){
        vt.push_back(x[i]);
    }
    ll aa =
    int l = 1, r = len;

    return 0;
}

