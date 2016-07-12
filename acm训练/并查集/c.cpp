
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
const int maxn = 100;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
int p[maxn];
bool vis[maxn];
void init() {
    for(int i = 0; i < maxn; ++i) {
        p[i] = i;
        vis[i] = 0;
    }
}
int find(int x) {
    return x == p[x]? x : p[x] = find(p[x]);
}
void unite(int x, int y) {
    x = find(x); y = find(y);
    if(x == y) return;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int u, v, kase = 0;
    while(scanf("%d%d", &u, &v) == 2 && u + v != -2) {
        init();
        bool ok = true;
        p[v] = u;
        if(u == v)  ok = false;
        vis[u] = vis[v] = true;
        while(scanf("%d%d", &u, &v) == 2 && u + v != 0) {
            if(p[v] != v && p[v] != u) {
                ok = false;
            } else {
                p[v] = u;
                vis[u] = vis[v] = true;
            }
        }
        printf("Case %d is ", ++kase);
        int root, first = 1;
        for(int i = 0; i < maxn; ++i) {
            if(first && vis[i]){
                root = find(i);
                first = 0;
            }
            else if(vis[i] && root != find(i)) {
                ok = false;
                break;
            }
        }

        if(ok) printf("a tree.\n");
        else printf("not a tree.\n");
    }
    return 0;
}
