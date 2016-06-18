/*************************************************************************
	> File Name: c.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年06月17日 星期五 14时26分56秒
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
#define pr(x) //cout << #x << " = " << x << " ";
#define prln(x)// cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
int head[maxn], top[maxn], fa[maxn], son[maxn], siz[maxn], depth[maxn];
int mi[maxn], ma[maxn], flag[maxn];
int w[maxn];
int edgenum, z;
struct Edge{
    int v, nxt, c;
    Edge(){}
    Edge(int _v, int _nxt, int _c){
        v = _v, nxt = _nxt; c = _c;
    }
}edge[maxn];
int n, m, root;
void pushdown(int rt){
    if(flag[rt]){
        flag[rt<<1] += flag[rt];
        flag[rt<<1] = flag[rt<<1]&1;
        ma[rt<<1] = -ma[rt<<1];  
        mi[rt<<1] = -mi[rt<<1];
        swap(ma[rt<<1], mi[rt<<1]);
        flag[rt<<1|1] += flag[rt];
        flag[rt<<1|1] = flag[rt<<1|1]&1;
        ma[rt<<1|1] = -ma[rt<<1|1];  
        mi[rt<<1|1] = -mi[rt<<1|1];
        swap(ma[rt<<1|1], mi[rt<<1|1]);
        flag[rt] = 0;
    }
}
void pushup(int rt){
    ma[rt] = max(ma[rt<<1], ma[rt<<1|1]);
    mi[rt] = min(mi[rt<<1], mi[rt<<1|1]);
}
void update1(int rt, int l, int r, int ql, int qr){
    //pr(rt);pr(l);pr(r);pr(ql);prln(qr);
    if(ql <= l && r <= qr){
        swap(ma[rt], mi[rt]);
        ma[rt] = -ma[rt];
        mi[rt] = -mi[rt];
        flag[rt] = flag[rt]^1;
        return;
    }
    //pr(rt);pr(l);pr(r);pr(ql);prln(qr);
    pushdown(rt);
    int m = l + r >> 1;
    if(m >= ql) update1(rt<<1, l, m, ql, qr);
    if(m < qr) update1(rt<<1|1, m+1, r, ql, qr);
    pushup(rt);
}
void update(int rt, int l, int r, int o, int v){
    if(l == r){
        mi[rt] = ma[rt] = v;
        flag[rt] = 0;
        return;
    }
//    pr(rt);pr(l);pr(r);pr(o);prln(v);
    pushdown(rt);
    int m = l + r >> 1;
    if(m >= o) update(rt<<1, l, m, o, v);
    else update(rt<<1|1, m+1, r, o, v);
    pushup(rt);
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
void addedge(int u, int v, int c){
    edge[edgenum] = Edge(v, head[u], c);
    head[u] = edgenum++;
}
void dfs(int u){
    son[u] = 0, siz[u] = 1;
    for(int i = head[u]; ~i; i = edge[i].nxt){
        int v = edge[i].v;
        if(v == fa[u]) continue;
        fa[v] = u;
        depth[v] = depth[u] + 1;
        dfs(v);
        if(siz[v] > siz[son[u]])  son[u] = v;
        siz[u] += siz[v];
    }
}

void build(int u, int tp){
    w[u] = ++z; top[u] = tp;
    //pr(u);prln(w[u]);
    if(son[u]) build(son[u], tp);
    for(int i = head[u]; ~i; i = edge[i].nxt){
        int v = edge[i].v;
        if(v == fa[u] || v == son[u]) continue;
        build(v, v);
    }
}
int find(int u, int v){
    int tu = top[u], tv = top[v];
    int ans = -INF;
    //pr(u);prln(v);
    while(tu != tv){
        if(depth[tu] < depth[tv]) swap(tu,tv), swap(u,v);
        //pr(tu);prln(u);
       // pr(w[tu]);prln(w[u]);
        ans = max(ans, query(1, 1, z, w[tu], w[u]));
        u = fa[tu]; tu = top[u];
    }
    if(u == v) return ans;
    if(depth[u] > depth[v]) swap(u, v);
    //pr(v);prln(u);
    //pr(w[v]);prln(w[u]);
    return max(ans, query(1, 1, z, w[son[u]], w[v]));
}

void update2(int u, int v){
    int tu = top[u], tv = top[v];
    //pr(u);prln(v);
    while(tu != tv){
        if(depth[tu] < depth[tv]) swap(tu, tv), swap(u, v);
   //     pr(tu);prln(u);
 //       pr(w[tu]);prln(w[u]);
        update1(1, 1, z, w[tu], w[u]);
        u = fa[tu]; tu = top[u];
    }
    if(u == v) return ;
    if(depth[u] > depth[v]) swap(u, v);
//    pr(w[v]);prln(w[u]);
    update1(1, 1, z, w[son[u]], w[v]);
}
int d[maxn][3];
void init(){
    memset(siz, 0, sizeof siz);
    memset(ma, 0x3f, sizeof ma);
    memset(flag, 0, sizeof flag);
    memset(mi, 0x80, sizeof mi);
    for(int i = 0; i < maxn; ++i){
        mi[i] = -INF;
    }
    memset(head, -1, sizeof head);
    root = n;
    z = edgenum = depth[root] = fa[root] = 0;
    for(int i = 1; i < n; ++i){
        scanf("%d%d%d", &d[i][0], &d[i][1], &d[i][2]);
        addedge(d[i][0], d[i][1], d[i][2]);
        addedge(d[i][1], d[i][0], d[i][2]);
    }
    dfs(root);
    build(root, root);
    for(int i = 1; i < n; ++i){
        if(depth[d[i][0]] > depth[d[i][1]]) swap(d[i][0], d[i][1]);
        update(1, 1, z, w[d[i][1]], d[i][2]);
    }
    
}
void work(){
    int a, b;
    char op[10];
    while(scanf("%s",op) != EOF){
        if(op[0] == 'D') break;
        scanf("%d%d", &a, &b);
        if(op[0] == 'C'){
            update(1, 1, z, w[d[a][1]], b);
        }else if(op[0] == 'N') update2(a, b);
        else printf("%d\n", find(a, b));

    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        init();
        work();
    }
	return 0;
}
