
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
#include<vector>

using namespace std;
const int maxn = 1e5+100;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
int sccno[maxn], sccnt, ins[maxn], in[maxn], dfn[maxn], low[maxn], dfnnum, cnt, stk[maxn], top, n, m, head[maxn];
struct Edge{
    int v, nxt;
    bool bridge;
}edge[maxn];
void addedge(int u, int v) {
    edge[cnt] = (Edge){v, head[u]};
    head[u] = cnt++;
    edge[cnt] = (Edge){u, head[v]};
    head[v] = cnt++;
}
void tarjan(int fa, int u) {
    dfn[u] = low[u] = ++dfnnum;
    stk[top++] = u;
    ins[u] = true;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int &v = edge[i].v;
        if(v == fa) continue;
        if(!dfn[v]) {
            tarjan(u, v);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]) {
                edge[i].bridge = edge[i^1].bridge = true;
            }
        } else if(ins[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(low[u] == dfn[u]) {
        int v; ++sccnt;
        do{
            v = stk[--top];
            ins[v] = false;
            sccno[v] = sccnt;
        }while(u != v);
    }
}
int slove() {
    for(int i = 1; i <= n; ++i) {
        if(!dfn[i]) tarjan(-1, i);
    }
    int v, ans = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = head[i]; ~j; j = edge[j].nxt) {
            if(edge[j].bridge) {
                v = edge[j].v;
                ++in[sccno[v]];
                ++in[sccno[i]];
            }
        }
    }
    for(int i = 1; i <= sccnt; ++i) {
        if(in[i] == 2) ans ++;
    }
    return (ans+1)/2;
}
void init() {
    memset(head, -1, (n+2)*sizeof(int));
    memset(dfn, 0, (n+2)*sizeof(int));
    memset(ins, 0, (n+2)*sizeof(int));
    memset(in, 0, (n+2)*sizeof(int));
    cnt = sccnt = top = dfnnum = 0;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int u, v, m;
    while(cin >> n >> m) {
        init();
        for(int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            addedge(u, v);
        }
        printf("%d\n", slove());
    }
    return 0;
}
