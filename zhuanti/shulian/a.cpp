/*************************************************************************
	> File Name: a.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年07月02日 星期六 11时46分46秒
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
    Edge(){}
    Edge(int _v, int _nxt){
        v = _v;
        nxt = _nxt;
    }
}edge[maxn];
int edgenum, n, m, k;
int son[maxn], siz[maxn], head[maxn], top[maxn], fa[maxn], sum[maxn], add[maxn];
int w[maxn];
int depth[maxn];
void addedge(int u, int v){
    edge[edgenum] = Edge(v, head[u]);
    head[u] = edgenum++;
}
void pushdown(int rt, int l, int  r){
    if(add[rt]){
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        int m = (l + r) >> 1;
        sum[rt<<1|1] += (r-m)*add[rt];
        sum[rt<<1] += (m-l+1)*add[rt];
        add[rt] = 0;
    }
}
void update(int rt, int l, int r, int ql, int qr, int v){
    if(ql <= l && r <= qr){
        sum[rt] += (r-l+1)*v;
        add[rt] += v;
        return;
    }
    pushdown(rt, l, r);
    int m = (l + r) >> 1;
    if(m >= ql) update(rt<<1, l, m, ql, qr, v);
    if(m < qr) update(rt<<1|1, m+1, r, ql, qr, v);
}
int query(int rt, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return sum[rt];
    }
    pushdown(rt, l, r);
    int ans = 0;
    int m  = (l + r ) >> 1;
    if(m >= ql) ans += query(rt<<1, l, m, ql, qr);
    if(m < qr) ans += query(rt<<1|1, m+1, r, ql, qr);
    return ans;
}
int cnt;
void dfs(int u, int numfa){
    siz[u] = 1;
    son[u] = 0;
    fa[u] = numfa;
    for(int i = head[u]; ~i; i = edge[i].nxt){
        int v = edge[i].v;
        if(v == numfa) continue;
        depth[v] = depth[u] + 1;
        dfs(v,u);
        if(siz[v] > siz[son[u]]) son[u] = v;
        siz[u] += siz[v];
    }
}
int a[maxn];
void build(int u, int tp){
    top[u] = tp;
    w[u] = ++cnt;
    if(son[u]) build(son[u], tp);
    for(int i = head[u]; ~i; i = edge[i].nxt){
        int v = edge[i].v;
        if(v == fa[u] || v == son[u]) continue;
        build(v, v);
    }

}
int _n;
int query2(int u, int v){
    int tu = top[u], tv = top[v];
    int ans = 0;
    while(tu!=tv){
        if(depth[tu] < depth[tv]) swap(tu,tv), swap(u,v);
        ans += query(1, 1, _n, w[tu], w[u]);
        u = fa[tu];
        tu = top[u];
    }
    if(depth[u] > depth[v]) swap(u,v);
    ans += query(1, 1, _n, w[u], w[v]);
    return ans;
}
void update2(int u, int v, int x){
    int tu = top[u], tv = top[v];
    while(tu!=tv){
        if(depth[tu] < depth[tv]) swap(tu,tv), swap(u,v);
        update(1, 1, _n, w[tu], w[u], x);
        u = fa[tu];
        tu = top[u];
    }
    if(depth[u] > depth[v]) swap(u,v);
    update(1, 1, _n, w[u], w[v], x);
}

void init(){
    edgenum = 0;
    cnt = 0;
    depth[1] = 1;
    siz[0] = 0;
    for(int i = 0; i <= n; ++i){
        head[i] = -1;
        w[i] = 0;
    }
    _n = 1;
    while(_n < n) _n = _n << 1;
    for(int i = 0; i <= _n*2; ++i){
        sum[i] = add[i] = 0;
    }
    int x, u, v;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < m; ++i){
        scanf("%d%d", &u, &v);
        addedge(u, v);
        addedge(v, u);
    }
    dfs(1,0);
    build(1,1);
    char op[10];
    for(int i = 1; i <= n; ++i){
        update(1, 1, _n, w[i], w[i], a[i]);
    }
    for(int i = 0; i < k; ++i){
        scanf("%s", op);
        if(op[0] == 'Q'){
            scanf("%d", &x);
            int ans = query2(x, x);
            printf("%d\n",ans);
        }else if(op[0] == 'I'){
            scanf("%d%d%d", &u, &v, &x);
            update2(u, v, x);
        }else if(op[0] == 'D'){
            scanf("%d%d%d", &u, &v, &x);
            update2(u, v, -x);
        }
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(cin >> n >> m >> k){
        init();
    }
	return 0;
}
