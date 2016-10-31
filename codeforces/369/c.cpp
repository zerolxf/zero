#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 4e5+1e4+100;
const long long INF = 1e18;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
ll dp[110][110][110];
ll a[110][110];
int n, m, k;
int b[110], bb[110];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    while(cin>>n>>m>>k){
        rep(i,n) {
            cin>>b[i+1];
            bb[i+1] = b[i+1];
        }
        rep(i,n){
            rep(j,m){
                cin>>a[i+1][j+1];
            }
        }
        rep(i,110){
            rep(j,110){
                rep(kk,110){
                    dp[i][j][kk] = INF;
                }
            }
        }
        b[0] = 0;
        if(b[1]!=0){
            dp[1][b[1]][1] = 0;
        }else{
            for(int i = 1; i <= m; ++i){
                dp[1][i][1] = a[1][i];
            }
        }
        for(int i = 2; i <= n; ++i){
            for(int kk = 1; kk <= k; ++kk){
                rep(lll,n){
                    b[lll+1] = bb[lll+1];
                }
                if(b[i]!=0){
                    if(b[i-1]!=0){
                        if(b[i-1]==b[i]){
                            if(dp[i-1][b[i]][kk]>=INF) continue;
                            dp[i][b[i]][kk] = min(dp[i][b[i]][kk], dp[i-1][b[i]][kk]);
                        }
                        else{
                            if(dp[i-1][b[i-1]][kk-1]>=INF) continue;
                            dp[i][b[i]][kk] = min(dp[i][b[i]][kk], dp[i-1][b[i-1]][kk-1]);

                        }
                        continue;
                    }
                    for(int jj = 1; jj <= m; ++jj){
                        b[i-1] = jj;
                        if(b[i-1]==b[i]){
                            if(dp[i-1][b[i]][kk]>=INF) continue;
                            dp[i][b[i]][kk] = min(dp[i][b[i]][kk], dp[i-1][b[i]][kk]);
                        }
                        else{
                            if(dp[i-1][b[i-1]][kk-1]>=INF) continue;
                            dp[i][b[i]][kk] = min(dp[i][b[i]][kk], dp[i-1][b[i-1]][kk-1]);

                        }
                    }
                    b[i-1] = 0;
                    continue;
                }
                for(int j = 1; j <= m; ++j){
                    b[i] = j;
                    if(b[i-1]!=0){
                        if(b[i-1]==b[i]){
                            if(dp[i-1][b[i]][kk]>=INF) continue;
                            dp[i][b[i]][kk] = min(dp[i][b[i]][kk], dp[i-1][b[i]][kk]+a[i][b[i]]);
                        }
                        else{
                            if(dp[i-1][b[i-1]][kk-1]>=INF) continue;
                            dp[i][b[i]][kk] = min(dp[i][b[i]][kk], dp[i-1][b[i-1]][kk-1]+a[i][b[i]]);

                        }
                        continue;
                    }
                    for(int jj = 1; jj <= m; ++jj){
                        b[i-1] = jj;
                        if(b[i-1]==b[i]){
                            dp[i][b[i]][kk] = min(dp[i][b[i]][kk], dp[i-1][b[i]][kk]+a[i][b[i]]);
                        }
                        else{
                            dp[i][b[i]][kk] = min(dp[i][b[i]][kk], dp[i-1][b[i-1]][kk-1]+a[i][b[i]]);

                        }
                    }
                    b[i-1] = 0;
                }
                b[i] = 0;
            }
            //}
        }
        ll ans = INF;
        if(b[n]!=0) ans = min(ans, dp[n][b[n]][k]);
        else{
            for(int i = 1; i <= m; ++i){
                ans = min(ans, dp[n][i][k]);
            }
        }
        if(ans>=INF){
            printf("-1\n");
        }else printf("%I64d\n",ans);

    }


    return 0;
}
