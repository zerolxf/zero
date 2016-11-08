/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月26日 星期二 08时55分34秒
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
int head[maxn], nxt[maxn], to[maxn];
ll c[maxn];
int edgenum;
const int N = (1<<8)+100;
ll dxy[(1<<8)+100][(1<<8)+100];
int op;
void addedge(int u, int v){
    nxt[edgenum] = head[u];
    //pr(u);pr(v);pr(head[u]);pr(edgenum);prln(nxt[edgenum]);
    to[edgenum] = v;
    head[u] = edgenum++;
}
ll dp[maxn];
ll xy[(1<<16)+100][N];
inline ll get(int x, int y){
    if(op == 0) return x&y;
    if(op == 1) return x|y;
    if(op == 2) return x^y;
}
void dfs(int u){
    ll ma = -INF;
    int a = c[u]>>8, b =  c[u]&((1<<8)-1);
    //pr(u);pr(a);prln(b);
    for(int i = 0; i < N; ++i){
        if(dxy[i][b] != -INF && (dxy[i][b] + (get(i,a)<<8))> ma){
            ma = dxy[i][b] + (get(i,a)<<8);
        }
    }
    dp[u] = max(dp[u], ma);
    //prln(dp[u]);
    //prln(ma);
    for(int i = 0; i < N; ++i){
        xy[u][i] = dxy[a][i];
        dxy[a][i] = max(dxy[a][i], dp[u] + get(b,i));
        //pr(i);prln(dxy[a][i]);
    }
    for(int i = head[u]; ~i; i = nxt[i]){
        int v = to[i];
        //pr(i);pr(nxt[i]);prln(v);
        dfs(v);
    }
    for(int i = 0; i < N; ++i){
        dxy[a][i] = xy[u][i];
    }
}
const int MOD = 1e9+7;
int f[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t, n;
    char s[10];
    scanf("%d", &t);
    while(t--){
        scanf("%d%s", &n, s);
        if(s[0] == 'A') op = 0;
        else if(s[0] == 'O') op = 1;
        else op = 2;
        //pr(n);prln(s);
        for(int i = 1; i <= n; ++i){
            scanf("%lld", &c[i]);
            //pr(i);prln(c[i]);
        }
        for(int i = 0; i <= n; ++i){
            dp[i] = 0;
            f[i] = -1;
            head[i] = -1;
        }
        edgenum = 0;
        for(int i = 0; i <N; ++i){
            for(int j = 0; j < N; ++j){
                dxy[i][j] = -INF;
            }
        }
        int v;
        //memset(head, -1, sizeof head);
        for(int i = 2; i <= n; ++i){
            scanf("%d", &v);
            f[i] = v;
            //pr(v);pr(head[v]);prln(i);
            addedge(v, i);
        }
        ll ans = 0;
        int root = -1;
        for(int i = 1; i <= n; ++i){
            if(f[i] == -1) root = i;
        }
        //prln(root);
        //for(int i = 1; i <= n; ++i){
            //for(int j = head[i]; ~j; j = nxt[j]){
                //int v = to[j];
                //pr(i);prln(v);
            //}
        //}
        dfs(root);
        for(ll i = 1; i <= n; ++i){
            ans = (ans + c[i]*i + dp[i]*i)%MOD;
        }
        printf("%lld\n",ans);
    }
	return 0;
}
