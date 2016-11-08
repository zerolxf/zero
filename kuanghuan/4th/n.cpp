/*************************************************************************
    > File Name: n.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月07日 星期日 14时41分07秒
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
int head[maxn], nxt[maxn], to[maxn], vis[maxn], dp[maxn], cnt;
int edgenum;
void addedge(int u, int v){
    nxt[edgenum] = head[u];
    to[edgenum] = v;
    head[u] = edgenum++;
}
void dfs(int u,  int fa, int x){
    dp[u] = x;
    for(int i = head[u]; ~i; i = nxt[i]){
        int v = to[i];
        if(v == fa) continue;
        int xx = x;
        if(i&1) xx--;
        else xx++;
        if(i&1){
            //pr(i);pr(u);pr(v);
            //prln(cnt);
            cnt++;
        }
        dfs(v, u, xx);
    }
}
void init(){
    memset(head, -1, sizeof head);
    edgenum = 0;
    cnt =0;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, u, v;
    while(scanf("%d", &n) != EOF){
        init();
        for(int i = 0; i < n-1; ++i){
            scanf("%d%d", &u, &v);
            //pr(u);prln(v);
            addedge(u,v);
            addedge(v,u);
        }
        dfs(1, 1, 0);
        vector<int> ans;
        int mi = INF;
        for(int i = 1; i <= n; ++i){
            mi = min(mi, dp[i]);
        }
        for(int i = 1; i <= n; ++i){
            if(dp[i] == mi){
                ans.push_back(i);
            }
        }
        //prln(ans[0]);
        //prln(dp[ans[0]]);prln(cnt);
        printf("%d\n",mi+cnt);
        int usiz = ans.size();
        for(int i = 0; i < usiz; ++i){
            printf("%d ", ans[i]);
        }
        printf("\n");

    }
	return 0;
}
