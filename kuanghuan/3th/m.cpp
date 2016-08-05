/*************************************************************************
	> File Name: m.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月30日 星期六 10时59分06秒
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
int dep[maxn];
typedef pair<int,int> P;
vector<P> G[maxn];
void dfs(int u, int fa){
    int usiz = G[u].size();
    for(int i = 0; i < usiz; ++i){
        int v= G[u][i].first;
        if(v==fa) continue;
        dep[v] = dep[u]+1;
        dfs(v,u);
    }
}
int ans[maxn];
P q[maxn];
int ct;
priority_queue<P> pq[maxn];
void dfs2(int u){
    int usiz = G[u].size();
    for(int i = 0; i < usiz; ++i){
        int v = G[u][i].first;
        int c = G[u][i].second;
        if(dep[v]<dep[u]) continue;
        int qcnt = 0;
        while(pq[v].size()){
            P temp = pq[v].top();pq[v].pop();
            ans[temp.second]++;
            if(c<=0){
                q[qcnt++] = temp;
            }else{
                c--;
                ct++;
                pq[u].push(temp);
            }
        }
        for(int i = 0; i < qcnt; ++i){
            pq[v].push(q[i]);
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
    int u, v, c;
    memset(ans, 0, sizeof ans);
    scanf("%d", &n);
    for(int i = 0; i <= n; ++i){
        G[i].clear();
    }
    for(int i = 1; i <= n; ++i){
        scanf("%d" , &p);
        pq[i].push(P(-p,i));
    }
    for(int i = 0; i < n-1; ++i){
        scanf("%d%d%d", &u, &v, &c);
        G[u].push_back(P(v,c));
        G[v].push_back(P(u,c));
    }
    dep[1] = 0;
    dfs(1, 1);
    ct=0;
    for(int i = 0; i <= n+2; ++i){
        dfs2(1);
        if(ct==0) break;
    }
    cout << ans[1];
    for(int i = 2; i <= n; ++i){
        cout<<" "<<ans[i];
    }
    cout<<"\n";
	return 0;
}
