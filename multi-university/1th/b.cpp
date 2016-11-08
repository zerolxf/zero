/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月20日 星期三 10时44分43秒
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
const int maxn = 2e6+1e5;
const int INF = 0x3f3f3f3f;
int sg[maxn];
int getnum(int dig[]){
    int ans = 0;
    for(int i = 19; i >= 0; --i){
        ans = (ans<<1) + dig[i];
    }
    return ans;
}
int n;
const int N = 1<<20;
int dfs(int x){
    int& ans = sg[x];
    if(ans != -1) return ans;
    bool vis[60];
    memset(vis, 0, sizeof vis);
    int last = 20;
    for(int i = 19; i>=0; --i){
        if(!((x>>i)&1)) {
            last = i;
            continue;
        }
        if(last == 20) continue;
        int nx = x^(1<<i)^(1<<last);
        int xx = dfs(nx);
        vis[xx] = true;
    }
    for(int i = 0; i < N; ++i){
        if(!vis[i]) return sg[x] = i;
    }
    return sg[x] = 22;
}
int a[maxn], b[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    memset(sg, -1, sizeof sg);
    while(t--){
        int dig[30];
        scanf("%d", &n);
        int m = 0, x = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &m);
            memset(dig, 0, sizeof dig);
            for(int j = 0; j < m; ++j){
                scanf("%d", &x);
                dig[x-1] = 1;
            }
            a[i] = getnum(dig);
        }
        x = 0;
        for(int i = 1;i <= n; ++i){
             x = x^dfs(a[i]);
        }
        if(x == 0) printf("NO\n");
        else printf("YES\n");
    }
	return 0;
}
