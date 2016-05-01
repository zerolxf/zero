/*************************************************************************
    > File Name: d.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月30日 星期六 00时23分48秒
 ************************************************************************/
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
const int maxn = 121000+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0; i < n; ++i)
struct Node{
    int l, r;
    int ll, rr;
    int c;
}node[maxn*4];
struct Line{
    int x1, x2, y;
    int id;
    Line(){};
    Line(int _x1, int _x2, int _y, int _id){
        x1 = _x1; x2 = _x2; y = _y;
        id = _id;
    }
}line[maxn];
int x[maxn];/*
void build(int rt, int l, int r) {
    node[rt].l = l;node[rt].r = r;
    node[rt].ll = x[l]; node[rt].rr = x[r];
    node[rt].c = 0;
    if(l+1==r) return;
    int m = (l+r)/2;
    build(rt<<1, l, m);
    build(rt<<1|1, m, r);
}*/
void build(int i,int l,int r)
{
    node[i].l = l;
    node[i].r = r;
    node[i].ll = x[l];
    node[i].rr = x[r];
    node[i].c = 0;
    if(l+1 == r)return;
    int mid = (l+r)/2;
    build(i<<1,l,mid);
    build((i<<1)|1,mid,r);
}/*
void pushdown(int rt) {
    if(node[rt].l  + 1== node[rt].r) return;
    if(node[rt].c != -1) {
        node[rt<<1].c = node[rt<<1|1].c = node[rt].c;
        node[rt].c = -1;
    }
}*/
void pushdown(int r)
{
    if(node[r].l + 1 == node[r].r)return;
    if(node[r].c != -1)
    {
        node[r<<1].c = node[(r<<1)|1].c = node[r].c;
        node[r].c = -1;
    }
}
int pre[maxn];
/*
void update(int rt, Line e){
    if(node[rt].ll == e.x1 && node[rt].rr == e.x2) {
        if(e.id > 0) node[rt].c = e.id;
        else e.id = pre[-e.id];
        return;
    }
    pushdown(rt);
    if(e.x2 <= node[rt<<1].rr) update(rt<<1, e);
    else if(e.x1 >= node[rt<<1|1].ll) update(rt<<1|1, e);
    else {
        Line tmp = e;
        tmp.x2 = node[rt<<1].rr;
        update(rt<<1, tmp);
        tmp = e;
        tmp.x1 = node[rt<<1|1].ll;
        update(rt<<1|1, e);
    }
}*/
void update(int i,Line e)
{
    if(node[i].ll == e.x1 && node[i].rr == e.x2)
    {
        if(e.id > 0)
            node[i].c = e.id;
        else node[i].c = pre[-e.id];
        return;
    }
    pushdown(i);
    if(e.x2 <= node[i<<1].rr)update(i<<1,e);
    else if(e.x1 >= node[(i<<1)|1].ll)update((i<<1)|1,e);
    else
    {
        Line tmp = e;
        tmp.x2 = node[i<<1].rr;
        update(i<<1,tmp);
        tmp = e;
        tmp.x1 = node[(i<<1)|1].ll;
        update((i<<1)|1,tmp);
    }
}
int query(int i,Line e)
{
    if(node[i].c != -1)
        return node[i].c;
    if(e.x2 <= node[i<<1].rr)return query(i<<1,e);
    else if(e.x1 >= node[(i<<1)|1].ll)return query((i<<1)|1,e);
    else
    {
        e.x2 = node[i<<1].rr;
        return query(i<<1,e);
    }
}
/*
int query(int rt, Line e) {
    if(node[rt].c != -1) {
        return node[rt].c;
    }
   // pushdown(rt);
    if(e.x2 <= node[rt<<1].rr) return query(rt<<1, e);
    else if(e.x1 >= node[rt<<1|1].ll) return query(rt<<1|1, e);
    else {
        e.x2 = node[rt<<1].rr;
        return query(rt<<1, e);
    }
}
*/
long long ans[maxn];
vector<int> vec[maxn];
void dfs(int u)
{
    int sz = vec[u].size();
    for(int i = 0;i < sz;i++)
    {
        int v = vec[u][i];
        ans[u] -= ans[v];
        dfs(v);
    }
}

bool cmp(Line a, Line b){
    return a.y < b.y;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, w, h, tot = 0, x1, x2, y1, y2;
    while(scanf("%d",&n)==1){
    scanf("%d%d",&w, &h);
    tot = 0;
    ans[0] = (long long)w*h;
    for(int i = 1; i <= n; ++i){
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if(x1 > x2) swap(x1,x2);
        if(y1 > y2) swap(y1,y2);
        ans[i] = (long long)(x2-x1)*(y2-y1);
        line[tot] = Line(x1, x2, y1,i);
        x[tot++] = x1;
        line[tot] = Line(x1,x2,y2,-i);
        x[tot++] = x2;
    }
    sort(x,x+tot);
        tot = unique(x,x+tot) - x;
        build(1,0,tot-1);
        sort(line,line+2*n,cmp);
        for(int i = 0;i <= n;i++)
            vec[i].clear();
        for(int i = 0;i < 2*n;i++)
        {
            if(line[i].id > 0)
            {
                pre[line[i].id] = query(1,line[i]);
                vec[pre[line[i].id]].push_back(line[i].id);
            }
            update(1,line[i]);
        }
    dfs(0);
    sort(ans, ans+n+1);
         for(int i = 0;i <= n;i++)
        {
            printf("%lld",ans[i]);
            if(i < n)printf(" ");
            else printf("\n");
        }   }
    return 0;
}
