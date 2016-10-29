/*************************************************************************
    > File Name: hdu4734.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月06日 星期四 01时01分55秒
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

int dp[11][20];
int num[11];
int numa[11];

int initnum(int x){
    int cnt = 0;
    while(x > 0){
        num[++cnt] = x%10;
        x /= 10;
    }
    return cnt;
}
int initnuma(int x){
    int cnt = 0;
    while(x > 0){
        numa[++cnt] = x%10;
        x/=10;
    }
    return cnt;
}
int dfs(int pos, int status,  int limit){
    if(pos < 1) return status <= 0;
    if(!limit  && dp[pos][status+9] != -1) return dp[pos][status+9];
    int ans = 0;
    int ed = limit?num[pos]:9;
    for(int i = 0; i <= ed; ++i){
        int newstatus = status*2+i-numa[pos];
        newstatus = min(newstatus, 9);
        newstatus = max(newstatus, -9);
        ans += dfs(pos-1, newstatus,   limit&&i==num[pos]);
    }
    if(!limit) dp[pos][status+9] = ans;
    return ans;
}
int work(int a, int b){
    memset(num, 0, sizeof num);
    memset(numa, 0, sizeof numa);
    memset(dp, -1, sizeof dp);
    int cnta = initnuma(a);
    int cntb = initnum(b);
    int ans = dfs(max(cnta,cntb), 0,  1);
    return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t, a, b;
    int kase = 0;
    scanf("%d", &t);
    while(t--){
       scanf("%d%d", &a, &b);
        int ans = work(a, b);
        printf("Case #%d: %d\n", ++kase, ans);
    }
	return 0;
}
