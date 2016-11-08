/*************************************************************************
	> File Name: g.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月30日 星期六 23时54分21秒
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
const int maxn = 5e4+100;
const int INF = 0x3f3f3f3f;
struct Node{
    ll mi, ma, num1, num2, p;
    Node(){
        mi = INF;
        ma = -INF;
        num1 = 0;
        num2 = 0;
        p = -1;
    }
     void update(const Node& a, const Node& b){
        //Node ans;
        this->num1 = max(a.num1, b.num1);
        this->num1 = max(this->num1, b.ma-a.mi);

        this->num2 = max(a.num2, b.num2);
        this->num2 = max(this->num2, a.ma-b.mi);

        this->mi = min(a.mi, b.mi);
        this->ma = max(a.ma, b.ma);
        this->p = b.p;
        //pr("***ANS****");
        //prdp(ans);
        //return ans;
    }

    Node(ll _mi, ll _ma, ll _num1, ll _num2, ll _p){
        mi = _mi;
        ma = _ma;
        num1 = _num1;
        num2 = _num2;
        p = _p;
    }
    Node operator = (const Node& rhs){
        return Node(rhs.mi, rhs.ma, rhs.num1, rhs.num2, rhs.p);
    }
}dp[maxn][20], init, node[maxn];

void prdp(const Node& x){
    pr(x.p);pr(x.mi);pr(x.ma);pr(x.num1);prln(x.num2);
}
int head[maxn], nxt[maxn*2], to[maxn*2], n, edgenum, dep[maxn], c[maxn];
Node update(const Node& a, const Node& b){
    Node ans;
    ans.num1 = max(a.num1, b.num1);
    ans.num1 = max(ans.num1, b.ma-a.mi);

    ans.num2 = max(a.num2, b.num2);
    ans.num2 = max(ans.num2, a.ma-b.mi);

    ans.mi = min(a.mi, b.mi);
    ans.ma = max(a.ma, b.ma);
    ans.p = b.p;
    //pr("***ANS****");
    //prdp(ans);
    return ans;
}
void addedge(int u, int v){
    nxt[edgenum] = head[u];
    to[edgenum] = v;
    head[u] = edgenum++;
}
void dfs(int u){
    for(int i = head[u]; ~i; i = nxt[i]){
        int v = to[i];
        if(dep[v]==-1){
            dep[v] = dep[u] + 1;
            //pr(v);prln(u);
            //dp[v][0] = init;
            //dp[v][0].p = u;
            dp[v][0].update(node[v], node[u]);
            dfs(v);
        }
    }
}

void ST(){
    //prln("ST START***************");
    for(int j = 1; (1<<j) <= n; ++j){
        for(int i = 1; i <= n; ++i){
            if(dp[i][j-1].p != -1){
                //pr(i);prln(j);
                //prdp(dp[i][j-1]);
                dp[i][j].update(dp[i][j-1], dp[dp[i][j-1].p][j-1]);
                //prdp(dp[i][j]);
            }
        }
    }
    //prln("ST END***************");
}
void clear(){
    memset(head, -1, sizeof head);
    memset(dep, -1, sizeof dep);
    edgenum = 0;
    //for(int i = 0; i <= n; ++i){
        //for(int j = 0; j < 20; ++j){
            //dp[i][j] = init;
        //}
    //}
}
ll lca(int u, int v){
    int du = 0, dv = 0;
    for(dv = 0; (1<<(dv+1)) <= dep[v]; dv++);
    for(du = 0; (1<<(du+1)) <= dep[u]; du++);
    Node ansu, ansv;
    if(dep[u] > dep[v]){
        for(int i = du; i >= 0; --i){
            if(dep[u]-dep[v]>=(1<<i)){
                ansu.update(ansu, dp[u][i]);
                u = dp[u][i].p;
            }
        }
        if(u == v) return ansu.num1;
    }else if(dep[u] < dep[v]){
        for(int i = dv; i >= 0; --i){
            if(dep[v]-dep[u]>=(1<<i)){
                ansv.update(ansv, dp[v][i]);
                v = dp[v][i].p;
            }
        }
        if(u == v) return ansv.num2;
    }
    for(int i = du; i >= 0; --i){
        if(dp[u][i].p != -1 && dp[u][i].p != dp[v][i].p){
            ansu.update(ansu, dp[u][i]);
            ansv.update(ansv, dp[v][i]);
            u = dp[u][i].p;
            v = dp[v][i].p;
        }
    }
    ansu.update(ansu, dp[u][0]);
    ansv.update(ansv, dp[v][0]);
    ll ans = 0;
    ans = max(ansu.num1, ansv.num2);
    ans = max(ans, ansv.ma-ansu.mi);
    return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    scanf("%d", &n);
    clear();
    //prln(n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &c[i]);
        node[i].mi = node[i].ma = c[i];
        node[i].num1 = node[i].num2 = 0;
        node[i].p = i;
        //dp[i][0].mi = dp[i][0].ma = c[i];
        //dp[i][0].num1 = dp[i][0].num2 = 0;
    }
    int u, v;
    for(int i = 0; i < n-1; ++i){
        scanf("%d%d", &u, &v);
        //pr(u);prln(v);
        addedge(u, v);
        addedge(v, u);
    }
    dep[1] = 0;
    dfs(1);
    for(int i = 1; i <= n; ++i){
        //pr(i);pr(dep[i]);pr(dp[i][0].p);prln(dp[i][0].mi);
    }
    ST();
    //for(int i = 1; i <= n; ++i){
        //for(int j = 0; j < 2; ++j){
            //pr(i);prln(j);prdp(dp[i][j]);
        //}
    //}
    
    int q = 0;
    scanf("%d", &q);
    while(q--){
        scanf("%d%d", &u, &v);
        ll ans = lca(u,v);
        printf("%lld\n", ans);
    }
	return 0;
}
