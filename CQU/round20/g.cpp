#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
#include<vector>

using namespace std;
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
#define rep(i,n) for(int i = 0; i < n; ++i)
int dis[120][120], dp[320][120], cost[120], v[120], head[120], sa[120];

int n, m, t, s, e, edgenum;
void init(){
    for(int i = 0; i < n; ++i){
        head[i] = -1;
        for(int j = 0; j < n; ++j){
            if(i==j) dis[i][i] = 0;
            else dis[i][j] = INF;
        }
    }
    memset(dp, -1, sizeof dp);
    edgenum = 0;
}
struct Node{
    int v, id;
    bool operator < (const Node& rhs)const{
        return v < rhs.v || (v == rhs.v && id < rhs.id);
    }
}a[120];
void getdis(){
    rep(k,n) rep(i,n) rep(j,n){
        if(dis[i][k] != INF && dis[k][j] != INF)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int tt;
    int kase = 0;
    scanf("%d",&tt);
    while(tt--){
        scanf("%d%d%d%d%d",&n,&m,&t,&s,&e);
        init();
        rep(i,n) scanf("%d",&cost[i]);
        rep(i,n) scanf("%d",&v[i]);
        rep(i,n) a[i] = Node{v[i],i};
        sort(a,a+n);
        rep(i,n){
            sa[i] = a[i].id;//pr(i);;prln(sa[i]);
        }
        int u, vv, c;
        rep(i,m){
            scanf("%d%d%d",&u,&vv,&c);
            dis[u][vv] = min(dis[u][vv],c);
            dis[vv][u] = dis[u][vv];
        }
        getdis();
        rep(i, n){
            if(dis[s][i]+cost[i]> t) continue;
            dp[dis[s][i]+cost[i]][i] = v[i];
        }
        for(int i = 0; i <= t; ++i){
            for(int j = 0; j < n; ++j){
                int jj = sa[j];
                for(int k = j+1; k < n; ++k){
                    int kk = sa[k];
                    int temp =  i + dis[jj][kk] + cost[kk];
                    if(dis[jj][kk] == INF || (dp[i][jj] < 0) || temp > t || v[kk] <= v[jj]) continue;
                    dp[temp][kk] = max(dp[temp][kk], dp[i][jj] + v[kk]);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i <= t; ++i){
            ans = max(dp[i][e], ans);
            for(int j = 0; j < n; ++j){
                if(dis[j][e] + i <= t) ans = max(ans, dp[i][j]);
            }
        }
        printf("Case #%d:\n",++kase);
        printf("%d\n",ans);
    }

    return 0;
}
