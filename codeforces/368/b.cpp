#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 4e5+1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int vis[maxn];
int dis[maxn];
typedef pair<int,int> P;
vector<P> G[maxn];
vector<int> p;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    int n, m, k;
    while(cin>>n>>m>>k){
        int u, v, c, x, y;
        int ans = INF;
        for(int i = 0; i < m; ++i){
            scanf("%d%d%d",&u,&v,&c);
            G[u].push_back(P(v,c));
            G[v].push_back(P(u,c));
        }
      //    prln(n);
        for(int i = 0; i < k; ++i){
            scanf("%d",&x);
            p.push_back(x);
            vis[x] = true;
        }
    //    prln(n);
        for(int i = 0; i < p.size(); ++i){
                u = p[i];
            for(int j = 0; j < G[u].size();++j){
                int v = G[u][j].first;
                if(vis[v]) continue;
                if(G[u][j].second < ans){
                    ans = G[u][j].second;
                }
            }
        }
       //   prln(n);
        if(ans==INF) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}
