/*************************************************************************
	> File Name: a.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月20日 星期三 10时07分21秒
 ************************************************************************/
#pragma comment(linker, "/STACK:102400000,102400000")

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
const int maxn = 2e5+100;
const int INF = 0x3f3f3f3f;
int head[maxn], nxt[maxn], to[maxn];
ll cost[maxn];
struct Edge{
    ll u, v, c;
    bool operator <(const Edge& rhs)const{
        return c < rhs.c;
    }
    Edge(){}
    Edge(int _u, int _v, ll _c){
        u = _u;
        v = _v;
        c =_c;
    }
}edge[1223456];
int pa[maxn];
ll n, m;
int edgenum ;
bool vis[maxn];
void init(){
     memset(head, -1, sizeof head);
     for(int i = 0; i <= n; ++i){
        pa[i]=i;
        vis[i] = 0;
     }
    edgenum = 0;
}
int find(int x){
    return pa[x] = (pa[x]==x?x:find(pa[x]));
}
ll siz[maxn];
void addedge(int u, int v, int c){
    nxt[edgenum] = head[u];
    to[edgenum] = v;
    cost[edgenum] = c;
    head[u] = edgenum++;
}
ll ans;
int dfs(int u){
    int cntu = 1;
    vis[u] = true;
    for(int i = head[u]; ~i; i = nxt[i]){
        int v = to[i];
        if(vis[v]) continue;
        int tmp = dfs(v);
        cntu+=tmp;
        //pr(v);prln(tmp);
        ans += (ll)tmp*(n-tmp)*cost[i];
        //prln(ans);
    }
    //prln(cntu);
    return cntu;

}
struct Node{
    int now, pre;
    Node(){}
    Node(int _now, int _pre){
        now = _now;
        pre = _pre;
    }
};
void slove(){
    sort(edge, edge+m);
    ll cnt = 0;
    for(int i = 0; i < m; ++i){
        int u = edge[i].u, v = edge[i].v;
        u = find(u), v = find(v);
        if(u==v) continue;
        pa[u] = v;
        cnt += edge[i].c;
        addedge(u, v, edge[i].c);
        addedge(v, u, edge[i].c);
    }
    ans = 0;
    queue<Node> q;
    q.push(Node(1,0));
    while(q.size()){
        int u = q.front().now;
        int pre = q.front().pre;
        q.pop();
        pr(u);prln(pre);
        vis[u] = true;
        siz[u] = 1;
        for(int i = head[u]; ~i; i = nxt[i]){
             int v = to[i];
            if(v == pre) continue;
            q.push(Node(v, u));
            //int tmp = dfs(v);
            //cntu+=tmp;
            //pr(v);prln(tmp);
            //ans += (ll)tmp*(n-tmp)*cost[i];


        }
        siz[pre] += siz[u];
    }
    for(int i = 1; i <= n; ++i){
        for(int j = head[i]; ~j; j = nxt[j]){
            int v = to[j];
            int mi = min(siz[v], siz[i]);
            pr(v);pr(i);prln(mi);
            prln(cost[j]);
            ans += (ll)mi*(n-mi)*cost[j];
        }
    }
    //dfs(1);
    double xx ;
    prln(ans);
    if(n>1) xx = ans*1.0/(ll)n/(n-1);
    else xx = 0;
    printf("%lld %.2f\n", cnt, xx);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%lld%lld", &n, &m);
        init();
        int u, v, c;
        memset(head, -1, sizeof head);
        for(int i = 0; i < m; ++i){
            scanf("%d%d%d", &u, &v, &c);
            edge[i].u = u;
            edge[i].v = v;
            edge[i].c = c;
        }
        slove();
    }
	return 0;
}
