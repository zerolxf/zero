/*************************************************************************
	> File Name: d.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月19日 星期二 21时43分40秒
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
#define prln(x) //cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
int a[maxn], p[maxn], fa[maxn], siz[maxn];
int nnow;
int vvis[maxn];
int find(int x){
    //pr(x);prln(p[x]);
    if(vvis[x] == nnow) return x;
    vvis[x] = nnow;
    if(x == p[x]) return x;
    if(nnow == x || p[x] == nnow) return nnow;
    return p[x] = (p[x]==x?x:find(p[x]));
}
bool unit(int u, int v){
    u = find(u); v = find(v);
    if(u==v) return true;
    return false;
}
int sccno[maxn], dfn[maxn], low[maxn], head[maxn], nxt[maxn], to[maxn], v[maxn], edgenum, dfnnum;
int q[maxn], vis[maxn];
int scc;
int edge[maxn][2];
int m, n;
void addedge(int u, int v){
    nxt[edgenum] = head[u];
    to[edgenum] = v;
    head[u] = edgenum++;
}
void init(){
    memset(head, -1, sizeof head);
    edgenum = 0;
    scc = 0;
    dfnnum = 0;
}
int qcnt;
int cnt[maxn];
        int in[maxn];
void tarjan(int u, int f){
    int v;
    dfn[u] = ++dfnnum;
    low[u] = dfnnum;
    vis[u] = true;
    q[qcnt++] = u;
    for(int i = head[u]; ~i; i = nxt[i]){
        v = to[i];
        if(v == f) continue;
        if(!vis[v]){
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }else if(vis[v]){
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(low[u] == dfn[u]) {
        scc++;
        do{
            v = q[--qcnt];
            sccno[v] = scc;
            vis[v] = false;
            cnt[v]++;
        }while(u != v);
    }
}
void sccno_slove(){
    memset(dfn, 0, sizeof dfn);
    memset(vis, 0, sizeof vis);
    memset(cnt, 0, sizeof cnt);
    qcnt = 0; 
    dfnnum = 0;
    scc = 0;
    for(int i = 1; i <= n; ++i){
        if(!dfn[i]) tarjan(i, i);
    }
}
int dfs(int  u){
    if(vis[u]) return u;
    if(p[u] == u) return u;
    vis[u] = true;
    return dfs(p[u]);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    while(cin >> n){
        memset(siz, 0, sizeof siz);
        int root = 0;
        init();
        for(int i = 1; i <= n; ++i){
            scanf("%d", &fa[i]);
            //addedge(i,fa[i]);
            if(fa[i] == i) root = i;
            siz[i] += 1;
            p[i] = fa[i];
        }
        //sccno_slove();
        memset(vis, 0, sizeof vis);
        memset(vvis, 0, sizeof vvis);
        memset(in, 0, sizeof in);

        int ans = 0;
        if(root) ans--;
        queue<int> q;
        in[0] = true;
        vis[0] = true;
        prln("********");
        for(int i = 1; i <= n; ++i){
            if(vis[i]) continue;
            prln(i);
            int ff = p[i];
            q.push(i);
            in[i] = true;
            bool ins = false;
            pr(!vis[ff]);pr(!in[ff]);prln(ff);
            while((!in[ff])  && !vis[ff]){
                q.push(ff);
                prln(ff);
                in[ff] = true;
                ff = p[ff];
            }
            pr(!vis[ff]);pr(!in[ff]);prln(ff);
            if(!root) root = ff;
            if(in[ff]) ans++;
            prln(i);
            p[ff] = 0;
            while(q.size()){
                int u = q.front();
                q.pop();
                in[u] = false;
                vis[u] = true;
            }
        }
        
        //for(int i = 1; i <= n; ++i){
            //nnow = i;
            //int u = find(fa[i]);
            //if(u == i && !root){
                //ans++;
                //root = fa[i];
                //fa[fa[i]] = fa[i];
            //}else if(u==i && i != root){
                //ans++;
                //fa[fa[i]] = root;
            //}
        //}
        //for(int i = 1; i <= n; ++i){
            //pr(i);prln(sccno[i]);
            //if(cnt[sccno[i]] > 1 && !root){
                //if(vis[sccno[i]]) continue;
                //root = i;
                //fa[root] = i;
                //ans++;
                //vis[sccno[i]] = true;
            //}
            //if(cnt[sccno[i]] > 1 ){
                //if(vis[sccno[i]]) continue;
                //fa[i] = root;
                //ans++;
                //vis[sccno[i]] = true;
            //}
        //}
        printf("%d\n",ans);
        for(int i = 1; i <= n; ++i){
            if(p[i]) printf("%d ",fa[i]);
            else printf("%d ",root);
        }
        printf("\n");

    }
	return 0;
}
