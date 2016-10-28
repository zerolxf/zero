/*************************************************************************
	> File Name: 3585.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月31日 星期日 19时30分27秒
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
int x[maxn], y[maxn];
struct Edge{
    int u, v, dis;
    Edge(){}
    Edge(int _u, int _v, int _dis){
        dis = _dis;
        u = _u;
        v = _v;
    }
    bool operator < (const Edge& rhs)const{
        return dis < rhs.dis;
    }
}edge[maxn];
int getdis(int a, int b){
    return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
}
void init(){

}
int cnt[maxn];
const int N = 5000;
int head[5000], nxt[5000], to[5000];
int edgenum;
void addedge(int u, int v){
    nxt[edgenum] = head[u];
    to[edgenum] = v;
    head[u] = edgenum++;
}
int edgenum1;
int n, k;

struct MAX_CLIQUE {
    static const int N=55;

    bool G[N][N];
    int n, Max[N], Alt[N][N], ans;

    bool DFS(int cur, int tot) {
        if(cur==0) {
            ans = max(ans,tot);
            if(tot>=k) {
                return 1;
            }
            return 0;
        }
        for(int i=0; i<cur; i++) {
            //if(cnt[i] < k-1) continue;
            if(cur-i+tot<k) return 0;
            int u=Alt[tot][i];
            if(Max[u]+tot<k) return 0;
            int nxt=0;
            for(int j=i+1; j<cur; j++)
                if(G[u][Alt[tot][j]]) Alt[tot+1][nxt++]=Alt[tot][j];
            if(DFS(nxt, tot+1)) return 1;
        }
        return 0;
    }

    int MaxClique() {
        ans=0, memset(Max, 0, sizeof Max);
        for(int i=n-1; i>=0; i--) {
            if(cnt[i]<k-1) continue;
            int cur=0;
            for(int j=i+1; j<n; j++) if(G[i][j]) Alt[1][cur++]=j;
            DFS(cur, 1);
            Max[i]=ans;
        }
        return ans;
    }
};

MAX_CLIQUE fuck;
bool ok(int dis){
    Edge  temp(0,0,dis);
    int mi = k-1;
    int pos = lower_bound(edge, edge+edgenum1, temp) - edge;
    rep(i,N){
        head[i] = -1;
        cnt[i] = 0;
    }
    edgenum = 0;
    for(int i = pos; i < edgenum1; ++i){
        int u = edge[i].u;
        int v = edge[i].v;
        addedge(u,v);
        addedge(v,u);
        cnt[u]++; cnt[v]++;
    }
    for(int c = 1; c <= n; ++c)
    for(int i = 1; i <= n; ++i){
        if(cnt[i] < mi && cnt[i] != 0) {
            cnt[i] = 0;
            for(int j = head[i]; ~j; j = nxt[j]){
                int v = to[j];
                if(cnt[v] > 0) --cnt[v];
            }
        }
    }
    fuck.n = n+1;
    for(int i = 1; i <= n; ++i){
        if(cnt[i]<mi) continue;
        for(int j = head[i]; ~j; j = nxt[j]){
            int v = to[j];
            if(cnt[v] < mi) continue;
            fuck.G[i][v] = 1;
            fuck.G[v][j] = 1;
        }
    }
    int ma = fuck.MaxClique();
    if(ma >= k) return true;
    return false;

}
int dis[maxn];
int dcnt;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(cin >> n >> k){
        for(int i = 1; i <= n; ++i){
            scanf("%d%d", &x[i], &y[i]);
        }
        edgenum1 = 0;
        dcnt = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = i+1; j <= n; ++j){
                edge[edgenum1++] = Edge(i,j,getdis(i,j));
                dis[dcnt++] = getdis(i,j);
            }
        }
        sort(dis, dis+dcnt);
        dcnt = unique(dis, dis+dcnt)-dis;
        sort(edge, edge+edgenum1);
        int l = 0, r = dcnt-1; 
        int num = 0;
        while(l < r){
            //if(++num>100) break;
            int mid = (l+r+1) >> 1;
            if(ok(dis[mid])) l = mid;
            else r = mid-1;
        }
        printf("%.2f\n", sqrt(dis[l]));

    }
	return 0;
}
