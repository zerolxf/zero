
/*************************************************************************
    > File Name: 1012.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月17日 星期六 14时59分18秒
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
#include<bitset>
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
const int N = 51;
bitset<90> dp[2][11][N][N][N], ans;
void clr(int now, int n){
    for(int i = 0; i <= 10; ++i){
        for(int j = 0; j <= n; ++j){
            for(int k = 0; k <= n; ++k){
                for(int l = 0; l <= n; ++l){
                    dp[now][i][j][k][l].reset();
                }
            }
        }
    }

}
int a[maxn];
struct Q{
    int x, y, z;
}q[maxn];
inline void getxor(ll now[], ll pre[]){
    now[0] = now[0] | pre[0];
    now[1] = now[1] | pre[1];
}
inline void move(ll now[], ll x){
    now[1] <<= x;
    now[1] = now[0],ci

}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif


    int t;
    scanf("%d", &t);
    while(t--){
        int n, m, x, y, z;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            if(a[i]>87) a[i] = 0;
        }
        scanf("%d", &m);
        for(int i = 0; i < m; ++i){
            scanf("%d%d%d", &x, &y, &z);
            q[i] = Q{x,y,z};
        }

        int now = 0, pre = 1;
        clr(now, n);clr(pre, n);
        dp[now][0][0][0][0][0] = true;
        for(int s = 1; s <= n; ++s){
            //要
            swap(now,pre);
            //clr(now, n);
            for(int i = 0; i <= 10; ++i){
                for(int j = 0; j <= s; ++j){
                    for(int k = 0; k <= j; ++k){
                        for(int l = 0; l <= k; ++l){
                            //不要的不作为禁止的
                            //dp[now][i][j][k][l] = (dp[pre][i][j][k][l]) | dp[now][i][j][k][l];
                            //if(i>=1) dp[now][i][j][k][l] = (dp[pre][i-1][j][k][l]<<a[s])|dp[now][i][j][k][l];
                        }
                        //dp[now][i][0][j][k] = (dp[pre][i][0][j][k]) | dp[now][i][0][j][k];
                        //if(i>=1) dp[now][i][0][j][k] = (dp[pre][i-1][0][j][k]<<a[s])|dp[now][i][0][j][k];
                    }
                    //dp[now][i][0][0][j] = (dp[pre][i][0][0][j]) | dp[now][i][0][0][j];
                    //if(i>=1) dp[now][i][0][0][j] = (dp[pre][i-1][0][0][j]<<a[s])|dp[now][i][0][0][j];
                }

                //不要的作为1禁止的
                //dp[now][i][0][0][s] = (dp[pre][i][0][0][0]) | dp[now][i][0][0][s];
                //不要的作为2
                for(int j = 1; j <= s; ++j){
                    //dp[now][i][0][s][j] = (dp[pre][i][0][0][j]) | dp[now][i][0][s][j];
                }
                //不要的作为3
                for(int j = 1; j <= s; ++j){
                    for(int k = 1; k <= j; ++k){
                        //dp[now][i][s][j][k] = (dp[pre][i][0][j][k]) | dp[now][i][s][j][k];
                    }
                }
            }
        }
        int num[4];
        for(int i = 0; i < m; ++i){
            num[0] = q[i].x;
            num[1] = q[i].y;
            num[2] = q[i].z;
            sort(num, num+3);
            int cnt = unique(num, num+3)-num;
            for(int j = cnt; j < 3; ++j){
                num[j] = 0;
            }
            ans = dp[now][10][num[2]][num[1]][num[0]];
            ans = ans>>87;
            if(ans[0]) printf("Yes\n");
            else printf("No\n");

        }

    }

	return 0;
}
