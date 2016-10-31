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
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int a[maxn], p[maxn];
int find(int x){
    return p[x] = (p[x]==x?x:find(p[x]));
}
void unite(int x, int y){
    x = find(x); y = find(y);
    p[x] = y;
}
int head[maxn], to[maxn], nxt[maxn], edgenum;
void addedge(int u, int v){
    to[edgenum] = v;
    nxt[edgenum] = head[u];
    head[u] = edgenum++;
}

int b[maxn], c[maxn];
int n, m;
bool vis[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    while(cin >> n >> m){
        edgenum = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            head[i] = -1;
            p[i] = i;
            vis[i] = false;
        }
        int u, v;
        for(int i = 1; i <= m; ++i){
            scanf("%d%d", &u, &v);
            unite(u,v);
        }
        int x;
        vector<int> pp;
        for(int i = 1; i <= n; ++i){
            x = find(i);
            if(!vis[x]){
                pp.push_back(x);
                vis[x] = true;
            }
            addedge(x,i);
        }
        int cnt = 0;
        for(int i = 0; i < pp.size(); ++i){
                int u = pp[i];
                cnt = 0;
            for(int j = head[u]; ~j; j = nxt[j]){
                b[cnt++] = a[to[j]];
            }
            sort(b,b+cnt);
            cnt = 0;
            for(int j = head[u]; ~j; j = nxt[j]){
                c[to[j]] = b[cnt++];
            }
        }
        for(int i = 1; i <= n; ++i){
            printf("%d ",c[i]);
        }
        printf("\n");
    }
    return 0;
}
