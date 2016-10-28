/*************************************************************************
    > File Name: 9.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月18日 星期日 13时41分21秒
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
const int maxn = 400;
const int INF = 0x3f3f3f3f;
const int N = 400;
ll dp[N][N][2];
ll gcd(ll x, ll y){
    if(y==0) return x;
    return gcd(y, x%y);
}
ll v[maxn], key[maxn];
ll dfs(int i, int j, int fg){
    if(fg==0){
        ll &ans = dp[i][j][fg];
        if(ans!=-2) return ans;
        ans = -1;
        if(i == j-1){
            if(gcd(key[i], key[j]) == 1) return -1;
            ans = max(ans, v[i]+v[j]);
            return ans;
        }
        if((j-i+1)%2!=0) return -1;
        for(int k = i+1; k < j; k+=2){
            ll l = dfs(i,k,0);
            ll r = dfs(k+1, j, 0);
            if(l<0||r<0) continue;
            ans = max(ans, l+r);
        }
        for()
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                dp[i][j][0] = -1;
                dp[i][j][1] = 0;
            }
        }
        for(int i = 1; i <= n; ++i) dp[i+1][i][0] = 0;

    }
	return 0;
}
