/*************************************************************************
    > File Name: d.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月15日 星期一 14时30分23秒
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
const int INF = 0x3f3f3f3f;
long double x[maxn], y[maxn];
long double dis[1100][1100];
inline long double getdis(int i, int j){
    long double dis = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
    return sqrt(dis);
}
struct Node{
    long double x, y, c;
}dp[2][maxn];
inline void get(long double& a, long double b, const long double c){
    if(c >= a){
        b = a;
        a = c;
    }else if(c > b){
        b = c;
    }
}
int main(){
	freopen("froggy.in","r",stdin);
	freopen("froggy.out","w",stdout);
    int n;
    long double w;
    cin >> w >> n;
        for(int i = 1; i <= n; ++i){
            cin >> x[i] >> y[i];
        }
        for(int i = 1; i <= n; ++i){
            for(int j = i; j <= n; ++j){
                dis[i][j] = dis[j][i] = getdis(i,j);
            }
        }
        for(int i = 1; i <= n; ++i){
            dp[0][i] = Node{1, 1,x[i]};
            dp[1][i] = Node{x[i]/2, y[i], x[i]/2};
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(i==j) continue;
                long double a = dp[0][j].c, b = dis[i][j];
                long double c = max(a,b/2);
                if(c<dp[1][i].c){
                    dp[1][i] = Node{(x[i]+x[j])/2, (y[i]+y[j])/2, c};
                }
                c = max(a, b);
                if(c<dp[0][i].c){
                    dp[0][i] = Node{-1, -1, c};
                }
                c = max(dp[1][j].c, b);
                if(c<dp[1][i].c){
                    dp[1][i] = Node{dp[1][j].x, dp[1][j].y, c};
                }
            }
        }
        Node ans = Node{w/2, 0, w/2};
        for(int i = 1; i <= n; ++i){
            long double c = max(dp[1][i].c, w-x[i]);
            if(c < ans.c){
                ans = dp[1][i];
                ans.c = c;
            }
            c = max(dp[0][i].c, (w-x[i])/2);
            if(c < ans.c){
                ans.c = c;
                ans.x = (w+x[i])/2;
                ans.y = y[i]/2;
            }
        }
        ans.x *=1000;
        ans.y*=1000;
        ceil(ans.x);
        ceil(ans.y);
        ans.x/=1000;
        ans.y/=1000;
        printf("%.3f %.3f\n", (double)ans.x, (double)ans.y);


	return 0;
}
