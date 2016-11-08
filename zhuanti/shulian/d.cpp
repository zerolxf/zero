/*************************************************************************
	> File Name: d.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年06月17日 星期五 10时44分09秒
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
struct Edge{
    int v, nxt;
    ll c;
    Edge(){}
    Edge(int _v, int _nxt, ll _c){
        v = _v;
        nxt = _nxt;
        c = _c;
    }
}edge[maxn];
int edgenum;
int head[maxn], w[maxn], fa[maxn], son[maxn], siz[maxn], depth[maxn], top[maxn];
int n, z, root, m;
ll sum[maxn];
ll d[maxn][3];
void addedge(int u, int v, ll c){
    edge[edgenum] = Edge(v, head[u], c);
    head[u] = edgenum++;
}

void dfs(int u){
    siz[u] = 1, son[u] = 0;
    for(int i = head[u]; ~i; i = edge[i].nxt){
        int v = edge[i].v;
        if(v == fa[u]) continue;
        fa[v] = u;
        depth[v] = depth[u] + 1;
        dfs(v);
        if(siz[v] > siz[son[u]]) son[u] = v;
        siz[u] += siz[v];
    }
}

void build(int u, int tp){
    w[u] =  ++z; top[u] = tp;
    if(son[u] != 0) build(son[u], tp);
    for(int i = head[u]; ~i; i = edge[i].nxt){
        int v = edge[i].v;
        if(v == son[u] || v == fa[u]) continue;
        build(v, v);
    }
}

void update(int rt, int l, int r, int o, ll v){
    if(l == r){
        sum[rt] = v;
        return;
    }
    int m = l + r >> 1;
    if(m >= o) update(rt<<1, l, m, o, v);
    else update(rt<<1|1, m+1, r, o, v);
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

ll query(int rt, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr){
        return sum[rt];
    }
    int m = l + r >> 1;
    ll ans = 0;
    if(m >= ql) ans += query(rt<<1, l, m, ql, qr);
    if(m < qr) ans += query(rt<<1|1, m+1, r, ql, qr);
    return ans;
}

inline ll find(int u, int v){
    int fu = top[u], fv = top[v];
    ll ans = 0;
    while(fu != fv){
        if(depth[fu] < depth[fv]) {
            swap(fu,fv);
            swap(u,v);
        }
        ans += query(1, 1, z, w[fu], w[u]);
        u = fa[fu]; fu = top[u];
    }
    if(u == v) return ans;
    if(depth[u] > depth[v]) swap(u,v);
    return ans += query(1, 1, z, w[son[u]], w[v]);
}
int a, b;
ll c;
void init(){
    root = 1;
    fa[root] = z = depth[root] = edgenum = 0;
    memset(siz, 0, sizeof siz);
    memset(head, -1, sizeof head);
    memset(sum, 0, sizeof sum);
    for(int i = 1; i < n; ++i){
        scanf("%d%d%lld", &a, &b, &c);
        d[i][0] = a, d[i][1] = b, d[i][2] = c;
        addedge(a, b, c);
        addedge(b, a, c);
    }
    dfs(root);
    build(root, root);
    for(int i = 1; i < n; ++i){
        if(depth[d[i][0]] > depth[d[i][1]]) swap(d[i][0], d[i][1]);
        update(1, 1, z, w[d[i][1]], d[i][2]);
    }
}

void work(){
    for(int i = 0; i < m; ++i){
        scanf("%d%d%lld", &a, &b, &c);
        if(a == 0) update(1, 1, z, w[d[b][1]], c);
        else printf("%lld\n", find(b, c));
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(cin >> n >> m){
        init();
        work();
    } 
	return 0;
}
