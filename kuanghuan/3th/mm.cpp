/*************************************************************************
	> File Name: mm.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月30日 星期六 14时58分58秒
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
typedef pair<int,int> P;
vector<P> G[maxn];
set<P> st[maxn];
P q[maxn];
int dep[maxn];
void dfs1(int u, int fa){
    int usiz = G[u].size();
    for(int i = 0; i < usiz; ++i){
        int v = G[u][i].first;
        if(v == fa) continue;
        dep[v] = dep[u] + 1;
        dfs1(v, u);
    }
}
int ans[maxn];
void dfs2(int u){
    int usiz = G[u].size();
    for(int i = 0; i < usiz; ++i){
        int v = G[u][i].first;
        if(dep[v]<=dep[u]) continue;
        int c = G[u][i].second;
        int qcnt = 0;
        for(auto itr:st[v]){
            ans[itr.second]++;
            if(c<=0) continue; 
            c--;
            //prln(v);
            q[qcnt++] = itr;
            st[u].insert(itr);
        }
        for(int i = 0; i < qcnt; ++i){
            st[v].erase(q[i]);
        }
        dfs2(v);
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, p;
    scanf("%d", &n);
    for(int i =1; i <= n; ++i){
        scanf("%d", &p);
        st[i].insert(P(p,i));
    }
    int u, v, c;
    for(int i = 0; i < n; ++i){
        scanf("%d%d%d", &u, &v, &c);
        G[u].push_back(P(v,c));
        G[v].push_back(P(u,c));
    }
    memset(ans, 0, sizeof ans);
    memset(dep, 0,sizeof dep);
    dfs1(1, 1);
    for(int i = 0; i <= n+1;++i){
        dfs2(1);
    }
    cout<<ans[1];
    for(int i = 2; i <= n; ++i){
        printf(" %d", ans[i]);
    }
    cout<<"\n";

	return 0;
}
