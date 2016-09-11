/*************************************************************************
    > File Name: a.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月15日 星期一 12时11分53秒
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
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
ll sumr[maxn], sumc[maxn];
ll sum1, sum2;
bool visr[maxn], visc[maxn];
int main(){
	freopen("adjustment.in","r",stdin);
	freopen("adjustment.out","w",stdout);
    int n, m;
    ll r, c;
    while(scanf("%d%d", &n, &m) != EOF){
        rep(i,n+2) visc[i] = visr[i] = 0;
        r = c = n;
        for(int i = 1; i <= n; ++i){
            sum1 += i;
            sum2 += i;
        }
        char op[10];
        int x;
        for(int i = 0; i < m; ++i){
            scanf("%s%d",op,&x);
            if(op[0] == 'R'){
                if(visr[x]){
                    printf("0\n"); continue;
                }
                r--;
                visr[x] = true;
                sum1 -= x;
                ll ans = sum2+(ll)(x)*c;
                printf("%lld\n", ans);
            }else {
                if(visc[x]){
                    printf("0\n"); continue;
                }
                c--;visc[x] = true;
                sum2 -= x;
                ll ans = sum1 + (ll)(x)*r;
                printf("%lld\n",ans);
            }

        }

    }


	return 0;
}
