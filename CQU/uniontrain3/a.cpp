/*************************************************************************
	> File Name: a.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月28日 星期六 17时29分10秒
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
int  l[maxn], r[maxn];
int edgenum, head[maxn], to[maxn], nxt[maxn];
void addedge(int u, int v) {
    nxt[edgenum] = head[u];
    to[edgenum] = v;
    head[u] = edgenum++;
}
bool vis[maxn];
void bfs(int s) {
    queue<int> q;
    q.push(s);
    while(q.size()){
        int u = q.front();
        q.pop();
        vis[u] = true;
        for(int i = head[u]; ~i; i = nxt[i]) {
            int v = to[i];
            if(vis[v]) continue;
            q.push(v);
        }
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t, n, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        MEM(l,0);MEM(r,0);
        MEM(vis,0);
        MEM(head,-1);
        edgenum = 0;
        int a, b;
        for(int i = 0; i < m; ++i){
            scanf("%d%d", &a, &b);
            l[a]++;r[b]++;
            addedge(a,b);
            addedge(b,a);
        }
        bfs(1);
        bool ok = true, ok2 = true;
        for(int i = 1; i <= n; ++i){
            if(!vis[i]) ok = false;
        }
        a = 0, b = 0;
        for(int i = 1; i <= n; ++i){
            if((l[i]+r[i])%2) b++;
            if(l[i] == r[i]) continue;
            if(abs(l[i]-r[i]) == 1) a++;
            else ok2 = false;
        }
        if(ok&&b<3) printf("Yes ");
        else printf("No ");
        if(ok&&ok2&&a<3) printf("Yes\n");
        else printf("No\n");
    }
	return 0;
}
