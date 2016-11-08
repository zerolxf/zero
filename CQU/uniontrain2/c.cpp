/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月13日 星期五 23时22分57秒
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
int n, dp[41][41][41][41], cnt[41][41][41][41];
int num[400];
int kase;
int dfs(int a, int b, int c, int d){
    int &ans = dp[a][b][c][d];
    if(ans >= 0 && cnt[a][b][c][d] == kase) return ans;
    ans = 0;
    if(a+b+c+d==0) return ans=num[n];
    int temp;
    if(a >= 1){
        temp = dfs(a-1, b, c, d);
        if(temp > ans) ans = temp;
    };
    if(b >= 1) {
        temp = dfs(a, b-1, c, d);
        if(temp > ans) ans = temp;
    }
    if(c >= 1){
        temp = dfs(a, b, c-1, d);
        if(temp > ans) ans = temp;
    }
    if(d >= 1) {
        temp =  dfs(a, b, c, d-1);
        if(temp > ans) ans = temp;
    }
    ans += num[n-a-b*2-c*3-d*4];
    //pr(a);pr(b);pr(c);prln(d);
  //  prln(ans);
    cnt[a][b][c][d] = kase;
    return ans;
}
int e[5];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
//	freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t, x, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        kase++;
        memset(e,0,sizeof e);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &num[i]);
        }
        for(int i = 0; i < m; ++i){
            scanf("%d", &x);
            e[x]++;
        }
        int ans = dfs(e[1],e[2],e[3],e[4]);
        printf("%d\n",ans);
    }
	return 0;
}
