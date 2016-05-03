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
bool dp[512][512];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, kase;
    scanf("%d", &kase);
    while(kase--){
        scanf("%d", &n);
        get(n);
        memset(dp, -1 , sizeof dp);
        dp[0][0] = 0;
        for(int i = 0; i <= 100; ++i){
            for(int j = 0; j< n; ++j){
               int a 
            }
        }
    }
	return 0;
}
