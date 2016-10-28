/*************************************************************************
    > File Name: c.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月12日 星期五 00时50分29秒
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
const ll INF = 1e18;
ll dp[maxn][2];
ll a[maxn], n;
string str[maxn][2];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    cin >> n;
    rep(i,n){
        scanf("%I64d",&a[i+1]);
    }
    for(int i = 0; i <= n; ++i){
        dp[i][0] = dp[i][1] = 1e18;
    }
    string temp;
    rep(i,n){
        cin>>temp;
        str[i+1][0] = temp;
        str[i+1][1] = temp;
        reverse(str[i+1][1].begin(), str[i+1][1].end());
        //scanf("%s", str[i][0])
    }
    ll ans = 1e18;
    dp[1][0] = 0, dp[1][1] = a[1];
    str[0][0] = "";
    str[0][1] = "";
    for(int i = 1;i<n;++i){
        for(int j = 0; j < 2; ++j){
            if(str[i+1][0]>=str[i][j]){
                dp[i+1][0] = min(dp[i+1][0],dp[i][j]);
            }
            if(str[i+1][1]>=str[i][j]){

                dp[i+1][1] = min(dp[i+1][1],dp[i][j]+a[i+1]);
            }
        }
    }
    ans = min(dp[n][0], dp[n][1]);
    if(ans>=INF){
        printf("-1\n");
    }else{
        cout<<ans<<"\n";
    }

	return 0;
}
