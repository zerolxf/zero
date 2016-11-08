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
struct Edge{
    int v, c, nxt;
}edge[maxn];
int head[maxn], edgenum;
void addedge(int u, int v, int c) {
    edge[edgenum].v = v;
    edge[edgenum].nxt = head[u];
    edge[edgenum].c = c;
    head[u] = edgenum++;
}
int dis[110][12345];
bool in[maxn];
void spfa(int s, int n, int d[]){
    for(int i = 0; i <= 10200; ++i){
        in[i] = false;
        d[i] = INF;
    }
    d[s] = 0;in[s] = true;
    queue<int> q;
    q.push(s);

    while(q.size()) {
        int u = q.front(); q.pop();
        in[u] = false;
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v;
            if(d[v] > d[u] + edge[i].c){
                d[v] = d[u] + edge[i].c;
                if(!in[v]) {
                    q.push(v);
                    in[v] = true;
                }
            }
        }
    }
}
int city[200];
void init(int n, int m, int h){
    edgenum = 0;
    for(int i = 0; i <= n+h+2; ++i){
        head[i] = -1;
    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, m, h, u, v, c;
    while(scanf("%d",&n) != EOF && n) {
        scanf("%d",&h);
        city[0] = 1;
        for(int i = 1; i <= h; ++i){
            scanf("%d",&city[i]);
        }
        city[h+1] = n;
        scanf("%d",&m);
        init(n,m,h);
        for(int i = 0; i < m; ++i){
            scanf("%d%d%d",&u,&v,&c);
            addedge(u,v,c);
            addedge(v,u,c);
        }
        //pr(n);pr(m);prln(h);
        for(int i = 0; i <= h+1; ++i){
            spfa(city[i],n,dis[i]);
        }
        for(int i = 1; i <= h+2; ++i) {
            for(int j = 1; j <= h+2; ++j){
                if(dis[i-1][city[j-1]] <= 600) {
                    addedge(n+i,n+j,1);
                    //pr(i);pr(j);prln(dis[i][city[j]]);
                }
            }
        }
        spfa(n+1,h,dis[0]);
        int ans = dis[0][h+2+n];
        if(ans != INF) {
            printf("%d\n",ans-1);
        } else printf("-1\n");
    }
    return 0;
}
