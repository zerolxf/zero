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
const int maxn = 1e3+110;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
int p[maxn];
bool vis[maxn];
int root, first = 1;
    int u, v, kase = 0;
void init() {
    for(int i = 0; i < maxn; ++i) {
        p[i] = i;
        vis[i] = 0;
    }
}
int find(int x) {
    return x == p[x]? x : p[x] = find(p[x]);
}

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    while(scanf("%d%d", &u, &v) == 2 && u + v != -2) {
       // if(u+v==0) continue;
        init();
        bool ok = true;
        printf("Case %d is ", ++kase);
        if(u+v != 0){
            p[v] = u;
            if(u == v)  ok = false;
            vis[u] = vis[v] = true;
            root = v;
            while(scanf("%d%d", &u, &v) == 2 && u + v != 0) {
             //   if(!ok) continue;
                    v = find(v);
                    u = find(u);
                    if(v == u) ok = false;
                    p[v] = u;
                    vis[u] = vis[v] = true;
            }
            root = find(root);
            for(int i = 0; i < maxn; ++i) {
                if(vis[i] && root != find(i)) {
                    ok = false;
                    break;
                }
            }
        }
        if(ok) printf("a tree.\n");
        else printf("not a tree.\n");
    }
    return 0;
}
