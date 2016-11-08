/*************************************************************************
	> File Name: r.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月30日 星期六 09时47分25秒
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
const int maxn = 1e5+100;
const int INF = 0x3f3f3f3f;
vector<int> G[maxn];
ll dp[maxn], llson[maxn], rrson[maxn], v[maxn];
int fa[maxn];
int num[maxn];
void dfs(int u){
    llson[u] = v[u];
    rrson[u] = v[u];
    //prln(u);
    //prln("1");
    int usiz = G[u].size();
    for(int i = 0; i < usiz; ++i){
        dfs(G[u][i]);
        llson[u] = min(llson[u], llson[G[u][i]]);
        rrson[u] = max(rrson[u], rrson[G[u][i]]);
    }
}
void dfs2(int u){
    int usiz = G[u].size();
    //prln(u);
    for(int i = 0; i < usiz; ++i){
        int vv = G[u][i];
        dp[vv] = dp[u];
        num[vv] = num[u]+1;
        //pr(vv);pr(num[vv]);
        //prln(v[vv]);
        if(v[vv] < v[u]){
            dp[vv] += llson[G[u][i^1]];
        }else{
            dp[vv] += rrson[G[u][i^1]];
        }
        dfs2(vv);
    }
}
struct Node{
    int id, v;
    Node(){}
    Node(int _id, int _v){
        id = _id;
        v = _v;
    }
    bool operator < (const Node& rhs)const{
        return v < rhs.v;
    }
}node[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    while(cin >> n){
        int root = 1;
        for(int i = 1; i <= n; ++i){
            cin >> fa[i] >> v[i];
            //scanf("%d%I64d", &fa[i], &v[i]);
            node[i-1] = Node(i, v[i]);
            if(fa[i] == -1) root = i;
            if(fa[i] == -1) continue;
            G[fa[i]].push_back(i);
        }
        sort(node, node+n);
        dp[0] = num[0] = 0;
        dfs(root);
        dfs2(root);
        int q;
        scanf("%d", &q);
        int x;
        for(int i = 0; i < q; ++i){
            scanf("%d", &x);
            Node temp = Node(0,x);
            int pos = upper_bound(node, node+n, temp)-node;
            int id = 0;
            if(pos == n){
                pos--;
                id = node[pos].id;
            }else{
                    id = node[pos].id;
                    if(G[id].size() > 0){
                        pos--;
                        id = node[pos].id;
                        //prln(pos);
                        //pr(id);prln(num[id]);
                        //if(v[G[id][0]]>v[G[id][1]]) id = G[id][0];
                        //else id = G[id][1];
                    }else id = node[pos].id;
            }
            //pr(pos);
            //id = node[pos].id;
            //double ans = 0;
            double ans = (double)dp[id]*1.0/num[id];
            //cout<<ans<<"\n";
            //pr(x);pr(v[id]);
            //pr(id);pr(num[id]);prln(dp[id]);
            printf("%.10f\n", ans);
            //prln("**********");
        }
    }
	return 0;
}
