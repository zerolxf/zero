/*************************************************************************
    > File Name: c.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月30日 星期五 22时44分21秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
struct Node{
    int num, t;
    int pre;
    Node(){}
    Node(ll _num, ll _t, int _pre){
        num = _num;
        t = _t;
        pre = _pre;
    }
}dp[5100];
struct Nnode{
    ll t;
    int u, num;
    int pre;
    Nnode(){}
    Nnode(ll _t, int _u, int _num, int _pre){
        t = _t;
        u = _u;
        num = _num;
        pre = _pre;
    }
    bool operator < (const Nnode& rhs)const{
        return t > rhs.t;
    }
};
int cnt[5100];
int head[maxn], nxt[maxn], to[maxn];
ll cost[maxn];
int edgenum = 0;
int last[5100][5100];
void addedge(int u, int v, int c){
    nxt[edgenum] = head[u];
    to[edgenum] = v;
    cost[edgenum] = c;
    head[u] = edgenum++;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

    memset(cnt, 0, sizeof cnt);
    int n, m, u, v, c, T;
    scanf("%d%d%d", &n, &m, &T);
    memset(head, -1, sizeof head);
    rep(i,m){
        scanf("%d%d%d", &u, &v, &c);
        addedge(u, v, c);
    }
    for(int i = 1; i <= n; ++i){
        dp[i] = Node(0,0,0);
    }
    //dp[1][cnt[1]] = Node(1, 0);
    priority_queue<Nnode> pq;
    pq.push(Nnode(0, 1, 1,0));
    while(pq.size()){
        Nnode x = pq.top(); pq.pop();
        int u = x.u;
        int num = x.num;
        int pre = x.pre;
        ll t = x.t;
        //pr(u);pr(num);prln(t);
        if(num<=dp[u].num) continue;
        dp[u] = Node(num,t,pre);
        last[u][num] = pre;
        for(int i = head[u]; ~i; i = nxt[i]){
            int v = to[i];
            if(num+1>dp[v].num&&t+cost[i]<=T){
                pq.push(Nnode(t+cost[i], v, num+1,u));
            }
        }
    }
    vector<int> path;
    int now = n;
    int ans = dp[n].num;
    int num = ans;
    while(num != 0){
        path.push_back(now);
        now = last[now][num--];
    }
    printf("%d\n",ans);
    num = ans;
    for(int i = num-1; i>= 0; --i){
        printf("%d ", path[i]);
    }
    printf("\n");
	return 0;
}
