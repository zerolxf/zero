/*************************************************************************
	> File Name: e.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年07月01日 星期五 17时01分54秒
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
int c[maxn], n, k;
int dp[550][550];
bool in[550][550];
typedef pair<int,int> pii;
void dijstra() {
    for(int i = 0; i <= 540; ++i){
        for(int j = 0; j <= 540; ++j){
            dp[i][j] = INF;
            in[i][j] = false;
        }
    }
    dp[0][0] = 0;
    in[0][0] = true;
    queue<pii> q;
    q.push(pii(0,0));
    while(q.size()){
        pii u = q.front(); q.pop();
        in[u.first][u.second] = false;
        int num = dp[u.first][u.second];
        if(u.first>k||u.second>k) continue;
        if(num == n) continue;
        int v1, v2;
        for(int i = num; i < n; ++i){
            v1 = u.first + c[i];
            v2 = u.second + c[i];
            if(v1<=k)
            if(dp[v1][u.second] > i+1){
                dp[v1][u.second] = i+1;
                if(!in[v1][u.second]){
                    in[v1][u.second] = true;
                    q.push(pii(v1, u.second));
                }
            }
            if(v2<=k)
            if(dp[u.first][v2] > i+1){
                dp[u.first][v2] = i+1;
                if(!in[u.first][v2]){
                    in[u.first][v2] = true;
                    q.push(pii(u.first, v2));
                }
            }
        }
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i){
        scanf("%d", &c[i]);
    }
    dijstra();
    int ans = 0;
    for(int i = 0; i <= k; ++i){
        if(dp[i][k-i] < INF && dp[k-i][i] < INF) ans++;
    }
    printf("%d\n",ans);
    for(int i = 0; i <= k; ++i){
         if(dp[i][k-i] < INF && dp[k-i][i] < INF)printf("%d ",i);
    }
    printf("\n");
	return 0;
}
