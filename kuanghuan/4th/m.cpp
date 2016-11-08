/*************************************************************************
    > File Name: m.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月07日 星期日 14时03分21秒
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
const int maxn = 5e5+100;
const int INF = 0x3f3f3f3f;
int dp[maxn][30], n, k;
int last[maxn][30];
int cost[30];
int pre[30];
char s[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(scanf("%d%d", &n, &k) != EOF){
        scanf("%s", s+1);
        memset(dp, 0x3f, sizeof dp);
        memset(last, -1, sizeof last);
        //pr(n);pr(k);prln(s+1);
        for(int i = 1; i <= n; ++i){
            s[i] -= 'A';
            for(int j = 0; j < k; ++j){
                if(j == s[i]){
                    dp[i][j] = cost[j];
                    last[i][j] = pre[j];
                }else{
                    dp[i][j] = cost[j] + 1;
                    last[i][j] = pre[j];
                }
            }
            memset(cost, 0x3f, sizeof cost);
            memset(pre, -1, sizeof pre);
            for(int j = 0; j < k; ++j){
                for(int l = 0; l < k; ++l){
                    if(j==l) continue;
                    if(dp[i][j] < cost[l]){
                        pre[l] = j;
                        cost[l] = dp[i][j];
                    }
                }
            }
        }
        int ans = INF, pos = -1;
        for(int i = 0; i < k; ++i){
            if(dp[n][i] < ans){
                ans = dp[n][i];
                pos = i;
            }
        }
        printf("%d\n",ans);
        int cnt = n;
        //prln(ans);
        stack<char> st;
        while(pos != -1 && cnt > 0){
            //printf("%c",pos+'A');
            st.push(pos+'A');
            //prln(pos);
            pos = last[cnt--][pos];
        }
        while(st.size()){
            char ch =  st.top();
            st.pop();
            printf("%c",ch);
        }
        printf("\n");
    }
	return 0;
}
