/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月29日 星期日 13时16分44秒
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
int edgenum, head[maxn];
struct Edge{
    int v, nxt;
}edge[maxn];
void addedge(int u, int v){
    edge[edgenum].nxt = head[u];
    edge[edgenum].v = v;
    head[u] = edgenum++;
}
bool vis[510][510];
int cnt[510], in[510];
int flag[510];
void init(){
    memset(head, -1, sizeof head);
    MEM(flag,-1);
    memset(vis,0,sizeof vis);
    MEM(cnt,0);
    edgenum = 0;
}
bool dfs(int s) {
    queue<int> q;
    q.push(s);
    flag[s] = 0;
    while(q.size()){
        int u = q.front(); q.pop();
        for(int i = head[u]; ~i; i = edge[i].nxt){
            int v = edge[i].v;
            if(flag[v] == -1){
                flag[v] = flag[u]^1;
                q.push(v);
            }else if(flag[v] == flag[u]) return false;
        }
    }
    return true;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d%d", &n, &m);
        int u, v;
        init();
        for(int i = 0; i < m; ++i){
            scanf("%d%d", &u, &v);
            vis[u][v] = true;
            vis[v][u] = true;
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(i==j||vis[i][j]) continue;
                addedge(i,j);
                cnt[i]++;
            }
        }
        bool ok = true;
        for(int i = 1; i <= n; ++i){
            if(flag[i] != -1 || cnt[i] == 0) continue;
            ok = ok && dfs(i);
        }
        for(int i = 1; i <= n; ++i){
            if(cnt[i] == 0) continue;
            for(int j = i+1; j <= n; ++j){
                if(cnt[j] == 0) continue;
                if(vis[i][j] && flag[i] != flag[j]){
                    ok = false;
                }
            }
        }
        if(ok) printf("Yes\n");
        else printf("No\n");
    }
	return 0;
}
