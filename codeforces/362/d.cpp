/*************************************************************************
	> File Name: d.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月15日 星期五 03时15分18秒
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
int head[maxn], nxt[maxn], to[maxn];
int  siz[maxn];
int p[maxn];
double ans[maxn];
void dfs(int u){
    siz[u] = 1;
    for(int i = head[u]; ~i; i = nxt[i]){
        int v = to[i];
        dfs(v);
        siz[u] += siz[v];
    }
}
void slove(int u){
    ans[u] = ans[p[u]] +1 + (siz[p[u]]-1-siz[u])/2.0;
    for(int i = head[u]; ~i; i = nxt[i]){
        int v = to[i];
        slove(v);
    }

}
int edgenum;
void addedge(int u, int v){
    nxt[edgenum] = head[u];
    to[edgenum] = v;
    head[u] = edgenum++;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    while(cin >> n){
        edgenum = 0;
        memset(head,-1,sizeof head);
        p[0] = 0;
        addedge(0,1);
        for(int i = 2; i <= n; ++i){
            scanf("%d",&p[i]);
            addedge(p[i],i);
        }
        dfs(0);
        slove(1);
        for(int i = 1; i <= n; ++i){
            printf("%.2f ",ans[i]);
        }
        printf("\n");
    }
	return 0;
}
