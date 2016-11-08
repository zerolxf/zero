/*************************************************************************
	> File Name: a.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月13日 星期五 18时57分55秒
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
struct Rec{
    ll num[3][3];
    Rec(){
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                if(i==j) num[i][j] = 1;
                else num[i][j] = 0;
            }
        }
    }
    Rec(int x){
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                num[i][j] = x;
            }
        }
    }
    Rec operator * (const Rec& rhs)const{
        Rec ans(0);
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                for(int k = 0; k < 3; ++k){
                    ans.num[i][j] += num[i][k]*rhs.num[k][j]; 
                }
                ans.num[i][j] %= MOD;
            }
        }
        return ans;
    }
}init;
Rec ret(const Rec &x, ll y){
    Rec ans, base = x;
    while(y){
        if(y&1) ans = ans*base;
        y>>=1;
        base = base*base;
    }
    return ans;
}
bool vis[10];
ll x[600];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--){
        int  m;
        ll n;
        scanf("%lld%d", &n, &m);
        memset(x, 0, sizeof x);
        memset(vis, 0, sizeof vis);
        for(int i = 1; i <= m; ++i) scanf("%lld", &x[i]);
        sort(x+1, x+m+1);
        if(x[1] < 3) vis[x[1]] = true;
        if(x[2] < 3) vis[x[2]] = true;
        ll ans1, ans2;
        if(vis[1]) ans1 = 0;
        else ans1 = 1;
        if(vis[2]) ans2 = 0;
        else ans2 = ans1 + 1;
        if(n <= 2) {
            if(n==1) printf("%lld\n", ans1);
            else printf("%lld\n", ans2);
            continue;
        }
        Rec a(1);
        Rec b(0);
        a.num[0][2] = 0;
        a.num[1][1] = 0;
        a.num[2][1] = 0;
        a.num[2][2] = 0;
        b.num[0][1] = 1;
        b.num[1][2] = 1;
        Rec ans;
        ll last = 2;
        for(int i = 1; i <= m; ++i){
            if(x[i] <= 2) continue;
            ans = ans*ret(a,x[i]-last-1);
            ans = ans*b;
            last = x[i];
        }
        ans = ans*ret(a,n-last);
        ll c = ans2*ans.num[0][0] + ans1*ans.num[1][0] + ans.num[2][0];
        c = c%MOD;
        printf("%lld\n", c);
    }
	return 0;
}
