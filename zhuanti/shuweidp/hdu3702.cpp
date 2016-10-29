/*************************************************************************
    > File Name: hdu3702.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月06日 星期四 02时27分53秒
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
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
const int N = 2200;
ll dp[22][22][N*2+100];
int num[22];
void initnum(ll x){
    for(int i = 1; i <= 19; ++i){
        num[i] = x % 10;
        x /= 10;
    }
}
ll dfs(int pos, int pivt, int status, int limit){
    if(pos<1) return status==0;
    if(!limit && dp[pivt][pos][status+N] != -1) return dp[pivt][pos][status+N];
    ll ans = 0;
    int ed = limit?num[pos]:9;
    for(int i = 0; i <= ed; ++i){
        ans += dfs(pos-1, pivt, status+i*(pos-pivt), limit&&i==num[pos]);
    }
    if(!limit) dp[pivt][pos][status+N] = ans;
    return ans;
}
ll work(ll x){
    if(x<0) return 0;
    initnum(x);
    ll ans = 0;
    for(int i = 1; i <= 19; ++i){
        ans += dfs(19, i, 0, 1);
    }
    ans -= 18;
    return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

    int t;
    memset(dp, -1, sizeof dp);
    scanf("%d", &t);
    while(t--){
        ll l, r;
        scanf("%lld%lld", &l, &r);
        ll ans = work(r)- work(l-1);
        printf("%lld\n", ans);
    }
	return 0;
}
