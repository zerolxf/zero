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
#define pr(x)     //  cout << #x << " = " << x << " ";
#define prln(x)   //  cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int d[maxn][3];
struct Edge{
    int v, c, nxt;
    Edge(){}
    Edge(int _v, int _c, int _nxt){
        v = _v; c = _c;
        nxt = _nxt;
    }
}edge[maxn];
int head[maxn], edgenum, top[maxn], p[maxn], siz[maxn], son[maxn], w[maxn], depth[maxn];
int cnt, n;
void addedge(int u, int v, int c){
    edge[edgenum] = Edge(v, c, head[u]);
    head[u] = edgenum++;
}
/*  void dfs(int u) {
    siz[u] = 1;
    son[u] = 0;
    prln(u);
    for(int i = head[u]; ~i; i = edge[i].nxt){
        int v = edge[i].v;
        if(v == p[u]) continue;
        depth[v] = depth[u] + 1;
        p[v] = u;
        dfs(v);
        siz[u] += siz[v];

        if(siz[v] > siz[son[u]]) son[u] = v;
    }

}*/
void dfs(int u){
son[u] = 0, siz[u] = 1;
for(int i = head[u]; ~i; i = edge[i].nxt){
    int v = edge[i].v;
    if(v == p[u]) continue;
    p[v] = u;
    depth[v] = depth[u] + 1;
    dfs(v);
    if(siz[v] > siz[son[u]])  son[u] = v;
    siz[u] += siz[v];
}
}

void build(int u, int tp){
    w[u] = ++cnt; top[u] = tp;
    //pr(u);prln(w[u]);
    if(son[u]) build(son[u], tp);
    for(int i = head[u]; ~i; i = edge[i].nxt){
        int v = edge[i].v;
        if(v == p[u] || v == son[u]) continue;
        build(v, v);
    }
}
int ma[maxn], add[maxn], mi[maxn];
void pushdown(int rt){
    if(add[rt]){
        add[rt<<1] += add[rt];
        add[rt<<1] = add[rt<<1]&1;
        ma[rt<<1] = -ma[rt<<1];
        mi[rt<<1] = -mi[rt<<1];
        swap(ma[rt<<1], mi[rt<<1]);
        add[rt<<1|1] += add[rt];
        add[rt<<1|1] = add[rt<<1|1]&1;
        ma[rt<<1|1] = -ma[rt<<1|1];
        mi[rt<<1|1] = -mi[rt<<1|1];
        swap(ma[rt<<1|1], mi[rt<<1|1]);
        add[rt] = 0;
    }
}
void pushup(int rt){
    ma[rt] = max(ma[rt<<1], ma[rt<<1|1]);
    mi[rt] = min(mi[rt<<1], mi[rt<<1|1]);
}
void update1(int rt, int l, int r, int ql, int qr){
    if(ql <= l &&  r <= qr){
        add[rt] ^= 1;
        ma[rt] = -ma[rt];
        mi[rt] = -mi[rt];
        swap(ma[rt], mi[rt]);
        pr(l);pr(r);prln(ma[rt]);
        return;
    }
    pushdown(rt);
    int m = l + r >> 1;
    if(m >= ql) update1(rt<<1, l, m, ql, qr);
    if(m < qr) update1(rt<<1|1, m+1, r, ql, qr);
    pushup(rt);
}
void update2(int u, int v){
    int tu = top[u], tv = top[v];
    //pr(u);prln(v);
    while(tu != tv){
    if(depth[tu] < depth[tv]) swap(tu, tv), swap(u, v);
    //     pr(tu);prln(u);
    //       pr(w[tu]);prln(w[u]);
    update1(1, 1, cnt, w[tu], w[u]);
    u = p[tu]; tu = top[u];
    }
    if(u == v) return ;
    if(depth[u] > depth[v]) swap(u, v);
    //    pr(w[v]);prln(w[u]);
    update1(1, 1, cnt, w[son[u]], w[v]);
}
int query(int rt, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return ma[rt];
    }
    pushdown(rt);
  //  pr(rt);pr(l);pr(r);pr(ql);prln(qr);
    int m = l + r >> 1;
    int ans = -INF;
    if(m >= ql) ans = max(ans, query(rt<<1, l, m, ql, qr));
    if(m < qr) ans = max(ans, query(rt<<1|1, m+1, r, ql, qr));
    return ans;
}
int find(int u, int v){
    int tu = top[u], tv = top[v];
    int ans = -INF;
    //pr(u);prln(v);
    while(tu != tv){
        if(depth[tu] < depth[tv]) swap(tu,tv), swap(u,v);
        //pr(tu);prln(u);
       // pr(w[tu]);prln(w[u]);
        ans = max(ans, query(1, 1, cnt, w[tu], w[u]));
        u = p[tu]; tu = top[u];
    }
    if(u == v) return ans;
    if(depth[u] > depth[v]) swap(u, v);
    //pr(v);prln(u);
    //pr(w[v]);prln(w[u]);
    return max(ans, query(1, 1, cnt, w[son[u]], w[v]));
}
/*
void change(int rt, int l, int r, int o, int v){
    prln("change");
    pr(rt);pr(l);pr(r);pr(o);prln(v);
    if(l == r ){
        ma[rt] = mi[rt] = v;
        add[rt] = 0;
        return;
    }
    pr(rt);pr(l);pr(r);prln(v);
    pushdown(rt);
    int m = l + r >> 1;
    if(m >= o) change(rt<<1, l, m, o, v);
    else change(rt<<1|1, m+1, r, o, v);
    pushup(rt);
}*/
void update(int rt, int l, int r, int o, int v){
    if(l == r){
        mi[rt] = ma[rt] = v;
        add[rt] = 0;
        return;
    }
//    pr(rt);pr(l);pr(r);pr(o);prln(v);
    pushdown(rt);
    int m = l + r >> 1;
    if(m >= o) update(rt<<1, l, m, o, v);
    else update(rt<<1|1, m+1, r, o, v);
    pushup(rt);
}


char op[10];
void init(){
     memset(siz, 0, sizeof siz);
    memset(ma, 0x3f, sizeof ma);
    memset(add, 0, sizeof add);
    memset(mi, 0x80, sizeof mi);
    for(int i = 0; i < maxn; ++i){
        mi[i] = -INF;
    }
    for(int i = 0; i < maxn; ++i){
        head[i] = -1;
    }
    int root = n;
    cnt = edgenum = depth[root] = p[root] = 0;
    memset(head, -1, sizeof head);
    for(int i = 0; i < n-1; ++i){
        scanf("%d%d%d", &d[i][0], &d[i][1], &d[i][2]);
        addedge(d[i][0], d[i][1], d[i][2]);
        addedge(d[i][1], d[i][0], d[i][2]);
    }
    dfs(root);
    build(root, root);
    for(int i = 0; i < n-1; ++i){
        if(depth[d[i][0]] > depth[d[i][1]]) swap(d[i][1], d[i][0]);
        update(1, 1, cnt, w[d[i][1]], d[i][2]);
    }
    int a, b;
   /* while(scanf("%s", op) != EOF){
        if(op[0] == 'D') return;
        else if(op[0] == 'Q') {
            scanf("%d%d", &u, &v);
            int ans = find(u, v);
            printf("%d\n", ans);
        }else if(op[0] == 'C'){
            scanf("%d%d", &u, &v);
            change(1, 1, cnt, w[d[u-1][1]], v);
        }else if(op[0] == 'N'){
            scanf("%d%d", &u, &v);
            update2(u,v);
        }
    }*/

    while(scanf("%s",op) != EOF){
        if(op[0] == 'D') break;
        scanf("%d%d", &a, &b);
        if(op[0] == 'C'){
            update(1, 1, cnt, w[d[a-1][1]], b);
        }else if(op[0] == 'N') update2(a, b);
        else printf("%d\n", find(a, b));

    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        init();
    }
    return 0;
}
