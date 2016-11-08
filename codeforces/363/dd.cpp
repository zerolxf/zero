/*************************************************************************
	> File Name: dd.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月19日 星期二 22时03分25秒
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
int head[maxn], nxt[maxn], to[maxn], vis[maxn], be[maxn];
int edgenum;
void addedge(int u, int v){
    nxt[edgenum] = head[u];
    to[edgenum] = v;
    head[u] = v;
}
int a[maxn], p[maxn], fa[maxn], siz[maxn];
void dfs(int u, int now){
    vis[u] = now;
    for(int i = head[u]; ~i; i = nxt[i]){
        int v = to[i];
        if(vis[i] == now){

        }
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    while(cin >> n){
        for(int i = 1; i <= n; ++i){
            scanf("%d", &fa[i]);
            addedge(i, fa[i]);
        }

    }
	return 0;
}
