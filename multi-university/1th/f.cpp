/*************************************************************************
	> File Name: f.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月22日 星期五 15时04分33秒
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
const int maxn = 1e7+5;
const int INF = 0x3f3f3f3f;
int phi[maxn], prime[maxn];
const int MOD = 1e9+7;
bool vis[maxn];
int pt;
ll sum[maxn];
void init(){
    int k = 0;
    pt = 0;

    phi[1] = 1;
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]){
            phi[i] = i-1;
            prime[pt++] = i;
            //prln(i);
            //if(i>100) break;
        }
        for(int j = 0; j < pt ; ++j){
            k = prime[j]*i;
            if(k>=maxn) break;
            vis[k] = true;
            if(i%prime[j] == 0){
                phi[k] = phi[i] * prime[j];
                break;
            }
            else{
                phi[k] = phi[i] * (prime[j]-1);
            }
        }
    }
    sum[0] = 0;
    for(int i = 1; i < maxn; ++i){
        sum[i] = (sum[i-1] + phi[i])%MOD;
    }
}
ll getans(int n, int m){
    if(n == 1) return sum[m];
    if(m == 1) return phi[n];
    if(m < 1) return 0;
    for(int i = 0; i < pt; ++i){
        if(n%prime[i] == 0){
            return ((ll)(prime[i]-1)*getans(n/prime[i], m)%MOD + getans(n, m/prime[i]))%MOD;
        }
    }
}
ll ret(ll x, ll y, int p){
    ll ans = 1;
    x%=p;
    //prln(p);
    while(y){
        if(y&1)ans = ans*x%p;
        //pr(x);pr(y);pr(ans);prln(MOD);
        x = x*x%p;
        y >>= 1;
    }
    return ans;
}
ll getpow(ll k, int p){
    if(p == 1) return 0;
    ll tmp = getpow(k, phi[p]);
    return ret(k, tmp+phi[p], p);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    init();
    //cout << "0";
    //return 0;
    int n, m, p;
    while(scanf("%d%d%d", &n, &m, &p) != EOF){
        ll k = getans(n,m);
        //prln(k);
        //for(int i = 1; i <= 20; ++i){
            //pr(i);prln(phi[i]);
        //}
        //cout << getpow(k, p) << "\n";
        printf("%lld\n",getpow(k,p));
        //prln(ret(2,9,MOD));
    }
	return 0;
}
