#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
#include<vector>


using namespace std;
const int maxn = 2e3+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
int n, m, dp[maxn][maxn], cost[200][2], v1, v2, v[200];
char ch[10], s[maxn];

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    while(cin >> n >> m) {
        scanf("%s", s);
        for(int i = 0; i < n; ++i) {
            scanf("%s%d%d", ch, &v1, &v2);
            //cost[ch][0] = v1;
            //cost[ch][1] = v2;
            v[ch[0]] = min(v1,v2);
        }
        char chl,chr;
        for(int i = 0; i < m; ++i) {
            dp[i][i] = 0;
        }
        for(int i = 1; i <= m; ++i) {
            for(int l = 0; l+i< m; ++l) {
                int r = l + i;
                chl = s[l];
                chr = s[r];
                dp[l][r] = INF;
              //  pr(dp[l][r]);
                if(s[l] == s[r]) {
                    dp[l][r] = min(dp[l+1][r-1],dp[l][r]);
                }
               // pr(dp[l][r]);
                dp[l][r] = min(dp[l][r], dp[l][r-1]+v[chr]);
                dp[l][r] = min(dp[l][r], dp[l+1][r]+v[chl]);
               // pr(l);pr(r);prln(dp[l][r]);
            }
        }
        printf("%d\n", dp[0][m-1]);
    }
    return 0;
}
