/*************************************************************************
	> File Name: h.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月18日 星期一 17时27分31秒
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
const int maxn = 2e4+200;
const int INF = 0x3f3f3f3f;
const int M = 2e5+200;
int link[maxn][maxn/32+100];
int head[maxn], nxt[M], to[M];
int head2[maxn], nxt2[M], to2[M];
int edgenum2;
void addedge2(int u, int v){
    nxt2[edgenum2] = head2[u];
    to2[edgenum2] = v;
    head2[u] = edgenum2++;
}
int in[maxn];
int edgenum;
void addedge(int u, int v){
    nxt[edgenum] = head[u];
    to[edgenum] = v;
    head[u] = edgenum++;
}
int a[maxn], cnta;
int n;
bool vis[maxn];
int l, r;
void bfs(){
    l = r = 0;
    for(int i = 1; i <= n; ++i){
        if(in[i] == 0) {
            a[r++] = i;
            in[i]--;
        }
    }
    while(l < r){
        int u = a[l++];
        //prln(u);
        for(int i = head[u]; ~i; i = nxt[i]){
            int v = to[i];
            addedge2(v,u);
            if(--in[v] == 0) {
                a[r++] = v;
            }
        }
    }
}
int N;
void update(int u, int v){
    for(int i = 0; i <= N; ++i){
        link[u][i] |= link[v][i];
    }
}
bool getlink(int u, int v){
    return (link[u][v/32]&(1<<(v%32)));
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t,  m;
    scanf("%d", &t);
    while(t--){
        memset(head, -1, sizeof head);
        memset(in,0, sizeof in);
        memset(head2, -1, sizeof head2);
        edgenum = 0;
        edgenum2 = 0;
        scanf("%d%d", &n, &m);
        N = (n+31)/32+3;
        for(int i = 0; i <= n; ++i){
            memset(link[i], 0, sizeof link[i]);
            link[i][i/32] |= 1<<(i%32);
        }
        int u, v;
        for(int i = 0; i < m; ++i){
            scanf("%d%d", &u, &v);
            in[v]++;
            addedge(u, v);
        }
        bfs();
        int ans = 0;
        for(int i = 0; i < r; ++i){
            int u = a[i];
            for(int j = head2[u]; ~j; j= nxt2[j]){

                int v = to2[j];
                if(getlink(u,v)) ++ans;
                update(u,v);
            }
        }
        printf("%d\n", ans);
    }
	return 0;
}
