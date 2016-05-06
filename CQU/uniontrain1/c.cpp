/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月02日 星期一 22时07分26秒
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
int num[maxn];
void get(int x) {
    num[0] = 1%x;
    for(int i = 1; i <= 250; ++i){
        num[i] = num[i-1]*10%x;
    }
}
int ans[maxn];

bool dfs(int pos, int x, int mod, bool ok) {
    if(mod == 0 && ok) {
        for(int i = pos-1; i >= 0; --i){
            printf("%d", ans[i]);
            return true;
        } 
    }

}
struct Node{
    int flag, last;
};
Node dp[512][10512][2];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
    freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, kase;
    scanf("%d", &kase);
    while(kase--){
        scanf("%d", &n);
        get(n);
        
        memset(dp, -1 , sizeof dp);
        for(int i = 0; i <= 110; ++i){
            for(int j = 0; j <= n; ++j){
                dp[i][j][0].last = dp[i][j][1].last = -1;
                dp[i][j][1].flag = dp[i][j][0].flag = 0;
            }
        }
        dp[0][0][0].last = 0;
        dp[0][0][0].flag = false;
        for(int i = 0; i <= 100; ++i){
            for(int j = 0; j< n; ++j){
                if(dp[i][j][0].last != -1){
                    //pr(i);pr(j);pr(i+1);prln((j+num[i])%n);
                    //prln(dp[i][j][0].last);
                    if(dp[i][j][0].flag){
                        if(!dp[i+1][(j+num[i])%n][1].flag){
                            dp[i+1][(j+num[i])%n][1].flag = true;
                            dp[i+1][(j+num[i])%n][1].last = j*2;
                        }
                        if(!dp[i+1][(j)%n][0].flag){
                            dp[i+1][(j)%n][0].flag = true;
                            dp[i+1][(j)%n][0].last = j*2;
                        }
                    } else {
                        if(!dp[i+1][(j+num[i])%n][1].flag){
                            dp[i+1][(j+num[i])%n][1].flag = true;
                            dp[i+1][(j+num[i])%n][1].last = j*2;
                        }
                        if(!dp[i+1][(j)%n][0].flag){
                            dp[i+1][(j)%n][0].flag = false;
                            dp[i+1][(j)%n][0].last = j*2;
                        }
                        
                    }
                } 
                if(dp[i][j][1].last != -1){
                        //pr(i);pr(j);pr(i+1);prln((j+num[i])%n);
                       // prln(dp[i][j][1].last);
                        if(!dp[i+1][(j+num[i])%n][1].flag){
                            dp[i+1][(j+num[i])%n][1].flag = true;
                            dp[i+1][(j+num[i])%n][1].last = j*2+1;
                        }
                        if(!dp[i+1][(j)%n][0].flag){
                            dp[i+1][(j)%n][0].flag = true;
                            dp[i+1][(j)%n][0].last = j*2+1;
                        }
                } 
            }
        }
        int ans = -1, pos = 0;
        for(int i = 1; i <= 100; ++i){
            if(dp[i][0][1].flag){
                ans = 1;
                pos = i;
                break;
            }
        }
        while(pos != 0){
            if(ans%2) {
                printf("1");
            } else printf("0");
            ans = dp[pos][ans/2][ans%2].last;
            pos--;
        }
        printf("\n");
    }
	return 0;
}
