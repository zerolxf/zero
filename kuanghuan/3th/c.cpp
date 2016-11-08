/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月30日 星期六 13时45分22秒
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
int c[130][130];
int dp[110][110][130];
char s[maxn];
int ss[maxn];
int n, k;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(scanf("%s%d", s+1, &k) != EOF){
        scanf("%d", &n);
        int len = strlen(s+1);
        ss[0] = 100;
        for(int i = 1; i <= len; ++i){
            ss[i] = s[i]-'a';
        }
        char u[10], v[10];
        int cc;
        for(int i = 0; i < n; ++i){
            scanf("%s%s%d", u,v,&cc);
            c[u[0]-'a'][v[0]-'a'] = cc;
        }
        rep(i,len+1) rep(j,k+1) rep(a,26) dp[i][j][a] = -INF;
        for(int i = 0; i < 26; ++i){
            if(i==ss[1]) dp[1][0][i] = 0;
            else dp[1][1][i] = 0;
        }
        for(int i = 2; i <= len; ++i){
            for(int j = 0; j <= k; ++j){
                for(int l = 0; l < 26; ++l){
                    for(int x = 0; x < 26; ++x){
                        if(l==ss[i])
                            dp[i][j][l] = max(dp[i][j][l], dp[i-1][j][x]+c[x][l]);
                        else if(j>=1){
                            dp[i][j][l] = max(dp[i][j][l], dp[i-1][j-1][x]+c[x][l]);
                        }
                    }
                }
            }
        }
        int ans = -INF;
        for(int i = 0; i <= k; ++i){
            for(int j = 0; j < 26; ++j){
                ans = max(ans, dp[len][i][j]);
            }
        }
        cout << ans << "\n";

    
    }
	return 0;
}
