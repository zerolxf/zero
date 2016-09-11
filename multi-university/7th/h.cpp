/*************************************************************************
    > File Name: h.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月10日 星期三 10时38分41秒
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
const int maxn = 1e6+1e5+100;
const int INF = 0x3f3f3f3f;
ll dp[1<<21];
int n, m;
int f[22][22];
int a[22], p;
int da[1<<21];
char cnt[1<<21];
ll fac[22];
ll base[22];
ll C[23][23];
void init(){
    memset(C, 0, sizeof C);
    C[0][0] = 1;
    for(int i = 1; i <= 20; ++i){
        C[i][0] = 1;
        for(int j = 1; j <= i; ++j){
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;scanf("%d", &t);
    int M = (1<<20);
    fac[0] = 1;
    base[0] = 1;
    for(int i = 1; i <= 20; ++i){
        fac[i] = fac[i-1]*i;
        base[i] = base[i-1]*2;
    }
    for(int i = 0; i < M; ++i){
        int ii = i, c = 0;
        while(ii){
            ii -= ii&(-ii);
            c++;
        }
        cnt[i] = c;
    }
    init();
    while(t--){
        scanf("%d%d%d", &p, &n, &m);
        for(int i = 0; i < m; ++i){
            scanf("%d", &a[i]);
        }
        int now = 0;
        da[0] = 0;
        int M = (1<<m);
        for(int i = 1; i < M; ++i){
            if(i>=base[now+1]) now++;
            da[i] = a[now] + da[i^(1<<now)];
        }
        memset(f,0,sizeof f);
        f[0][0] = 1;
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= m; ++j){
                if(j>=1&&(i>=j-1))f[i][j] += f[i][j-1];
                if(i>=1&&(i-1>=j))f[i][j] +=f[i-1][j];
                //pr(i);pr(j);prln(f[i][j]);
            }
        }
        ll a = 0, b = fac[n+m];
        for(int i = 0; i < M; ++i){
            if(da[i] < p) continue;
            int k = cnt[i];
            //pr(i);pr(da[i]);prln(f[k-1][k]);
            //prln(C[n][k-1]);prln(fac[k-1]);prln(fac[k]);prln(fac[n+m-2*k+1]);
            //pr(n);prln(k-1);
            a += f[k-1][k]*C[n][k-1]*fac[k]*fac[k-1]*fac[n+m-2*k+1];
        }
        if(da[M-1]>=p) a += f[n][m]*fac[n]*fac[m];
        ll c = __gcd(a,b);
        a/=c;
        b/=c;
        printf("%lld/%lld\n",a ,b);

    }
	return 0;
}
