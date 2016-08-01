/*************************************************************************
	> File Name: e.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月01日 星期一 20时02分24秒
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
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
int cost[110][110], val[110][110];
int num[110];
int a[110];
ll dp[110][110][110];
int m;
void get(int cnt){
    scanf("%d", &num[cnt]);
    int n = num[cnt];
    //prln(num[cnt]);
    //prln(cnt);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        //pr(i);prln(a[i]);
    }
    memset(dp, 0, sizeof dp);
    for(int k = 1; k <= 100; ++k){
        for(int i = 1; i <= n; ++i){
            dp[k][1][i] = max(dp[k][1][i], (ll)1);
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j+i-1 <= n; ++j){
                dp[k][i][j] = max(dp[k-1][i-1][j]+a[i+j-1], dp[k-1][i-1][j+1]+a[j]); 
            }
        }
    }
    for(int i = 1; i <= 100; ++i){
        //cost[cnt][i] = i;
        val[cnt][i] = dp[i][n][1];
        //pr(i);prln(val[cnt][i]);
    }

}
ll d[2][maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    while(cin >> n >> m){
        for(int i = 1; i <= n; ++i){
            get(i);
        }
        int now = 1, pre = 0;
        memset(dp, 0, sizeof d);
        memset(dp[now], 0, sizeof dp[now]);
        for(int i = 1; i <= n; ++i){
            swap(now,pre);
            memset(dp[now], 0, sizeof dp[now]);
            for(int j = 0; j <= m; ++j){
                for(int k = 0; k <= num[i]; ++k){
                    if(k<=j)
                    d[now][j] = max(d[now][j], d[pre][j-k]+val[i][k]);
                }
            }
        }
        ll ans = 0;
        for(int i = 0; i <= m; ++i){
            ans = max(ans, d[now][i]);
        }
        cout << d[now][m] << "\n";
    }
	return 0;
}
