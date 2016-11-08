/*************************************************************************
	> File Name: g.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月04日 星期三 17时29分57秒
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
int dp[550][5500];
int num[550][20];
int a[20];
char s[30];
int t, n, m, c;
void getnum(int m, int n) {
    for(int i = 0; i < m; ++i){
        num[1][i] = a[i]%n;
    }
    for(int i = 2; i <= 500; ++i){
        for(int j = 0; j < m; ++j){
            num[i][j] = num[i-1][j]*c%n;
        }
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    for(int i = 0; i <= 15; ++i){
        s[i] = i+'0';
        if(i >= 10) s[i] = 'A' + i-10;
    }
    scanf("%d", &t);
    while(t--){
        char ss[20];
        scanf("%d%d%d", &n, &c, &m);
        for(int i = 0; i < m; ++i){
            scanf("%s", ss);
            if(ss[0] <= '9' && ss[0] >= '0') a[i] = ss[0] -'0';
            else a[i] = ss[0] - 'A' + 10;
        }
        sort(a,a+m);
        a[m] = a[0];
        getnum(m,n);
        int len = 500;
        for(int i = 0; i <= len; ++i){
            for(int j = 0; j <= n; ++j){
                dp[i][j] = -1;
            }
        }
        dp[0][0] = 0;
        bool ok = false;
        for(int i = 1; i <= len; ++i){
            for(int j = 0; j < n; ++j){
                for(int k = 0; k < m; ++k){
                    if(a[k] == 0 && j == 0) continue;
                    if(dp[i-1][(j+n-num[i][k])%n] != -1 && dp[i][j] == -1){
                        dp[i][j] = k;
                        if(j==0) ok = true;
                        break;
                    }
                }
                if(j==0&&a[0]==0)
                if(dp[i-1][(j+n-num[i][0])%n] != -1 && dp[i][j] == -1){
                    dp[i][j] = 0;
                }
                if(ok) break;
            }
            if(ok) break;
        }
        int ans = -1, pos;
        for(int i = 1; i <= len; ++i){
            if(dp[i][0] != -1 && a[dp[i][0]] != 0){
                ans = dp[i][0];
                pos = i;
                break;
            }
        }
        if(ans == -1) {
            printf("BOMB!!!\n");
            continue;
        }
        int l = 0;
        while(pos > 0 && ans != -1){
            ans = dp[pos][l];
            printf("%c", s[a[ans]]);
            l = (l-num[pos][ans]+n)%n;
            pos--;
        }
        printf("\n");
    }
	return 0;
}
