/*************************************************************************
	> File Name: k.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月18日 星期一 09时10分14秒
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
const int maxn = 2e5+100;
const int INF = 0x3f3f3f3f;
int edgenum, to[maxn], c[maxn], head[maxn], nxt[maxn], v[maxn], vv[maxn];
int cnt[maxn];
void addedge(int u, int y, int cost){
    nxt[edgenum] = head[u];
    c[edgenum] = cost;
    to[edgenum] = y;
    head[u] = edgenum++;
}
int q[20];
ll an[20];
int n, m, k;
const int Hashsize = 1e5+7;
struct Hash{
    int state[Hashsize], ct[Hashsize], h[Hashsize], nxt[Hashsize], sz;
    void clear(){
        memset(h, -1, sizeof h);
        sz = 0;
    }
    void push(int st, int cnt){
        int msk = st%Hashsize;
        for(int i = h[msk]; ~i; i = nxt[i]){
            int v = state[i];
            if(v==st){
                ct[i]+=cnt;
                return;
            }
        }
        nxt[sz] = head[msk];
        state[sz] = st;
        ct[sz] = cnt;
        h[msk] = sz++;

    }
    int get(int st){
        int msk = st%Hashsize;
        for(int i = h[msk]; ~i; i = nxt[i]){
            int v = state[i];
            if(v==st){
                return ct[i];
            }
        }
        return 0;
    }
}hh;
void dfs(int u, int fa){
    for(int i = head[u]; ~i; i = nxt[i]){
        int x = to[i];
        if(x==fa) continue;
        v[x] = v[u]^c[i];
        cnt[v[x]]++;
        //prln(v[x]);
        //hh.push(v[x], 1);
        dfs(x, u);
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

    int t;
    scanf("%d", &t);
    while(t--){
        edgenum = 0;
        //hh.clear();
        scanf("%d", &n);
        memset(cnt,0,sizeof cnt);
        int x, y, cost;
        memset(head, -1, sizeof head);
        for(int i = 1; i < n; ++i){
            scanf("%d%d%d", &x, &y, &cost);
            addedge(x, y, cost);
            addedge(y, x, cost);
        }
        vv[1] = v[1] = 0;
        cnt[v[1]]++;
        //hh.push(v[1], 1);
        dfs(1, 0);
        scanf("%d", &m);
        for(int i = 0; i < m; ++i){
            scanf("%d", &k);
            ll ans = 0;
            for(int i = 1; i <= n; ++i){
                int x = v[i]^k;
                //prln(x);
                ans += cnt[x];
            }
            if(!k) ans += n;
            ans /= 2;
            cout << ans << "\n";
        }

    }
	return 0;
}
