/*************************************************************************
    > File Name: k.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月08日 星期六 01时08分48秒
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
const int N = 5100;
unsigned long long dp[5500];
unsigned long long g[5500];
void init(){
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 3;
    g[3] = 1;
    g[4] = 2;
    for(int i = 5; i <= N; ++i){
        g[i] = dp[i-1];
        for(int j = 3; j < i; ++j){
            g[i] += dp[j-1]*dp[i-j+1];
        }
        dp[i] = g[i];
        for(int j = 3; j < i; ++j){
                dp[i] += (g[j])*(dp[i-j+2]);
        }
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

    init();
    int n;
    while(cin>>n){
        cout<<dp[n]<<"\n";
    }
	return 0;
}

