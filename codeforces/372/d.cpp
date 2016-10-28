/*************************************************************************
    > File Name: d.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月17日 星期六 22时48分15秒
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
#define rep(i,n) for(ll i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x)// cout << #x << " = " << x << " ";
#define prln(x) //cout << #x << " = " << x <<  endl; 
const ll maxn = 4e5+100;
const ll INF = 1e13;
const ll IINF = 1e17;ll dis[maxn];
ll u[maxn], v[maxn], eto[maxn];
ll cc[maxn];
ll head[maxn], nxt[maxn], to[maxn];
ll cost[maxn];
ll edgenum;
void addedge(ll uu, ll vv, ll c){
    nxt[edgenum] = head[uu];
    to[edgenum] = vv;
    cost[edgenum] = c;
    head[uu] = edgenum++;
}
struct Node{
    ll dis, u;
    bool operator < (const Node& rhs)const{
        return dis > rhs.dis;
    }
};
bool vis[maxn];
ll src, ed;
ll bfs(ll n){
    for(ll i = 0; i <= n; ++i) dis[i] = IINF, vis[i] = false;
    dis[src] = 0;
    priority_queue<Node> pq;
    pq.push(Node{0,src});
    while(pq.size()){
        Node node = pq.top();pq.pop();
        if(vis[node.u]) continue;
        vis[node.u] = true;
        ll u = node.u;
        for(ll i = head[u]; ~i; i = nxt[i]){
            //prln(i);
            ll v = to[i];
            if(dis[v] > dis[u]+cost[i]){
                dis[v] = dis[u] + cost[i];
                pq.push(Node{dis[v], v});
            }
        }
    }
    return dis[ed];
}
bool flag[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

    ll n, m;
    ll L;
    while(cin>>n>>m>>L>>src>>ed){
        memset(flag, 0, sizeof flag);
        memset(head,-1,sizeof head);
        edgenum = 0;
        rep(i,m){
            cin>>u[i]>>v[i]>>cc[i];
            if(cc[i]==0)cc[i] = INF,flag[i] = true;
            eto[i] = edgenum;
            addedge(u[i], v[i], cc[i]);
            addedge(v[i], u[i], cc[i]);
        }

        ll mi = bfs(n);
        if(mi>=IINF||mi<L){
            printf("NO\n");
            return 0;
            break;
        }else{
            rep(i,m){
                if(cc[i]==INF){
                    cost[eto[i]] = 1;
                    cost[eto[i]^1] = 1;
                    cc[i] = 1;
                }
            }


          mi = bfs(n);
            ll need = L-mi;
            if(need<0){
                printf("NO\n");
            }else{
                printf("YES\n");
                    rep(i,m){
                        if(!flag[i]) continue;
                        cc[i] += need;
                        cost[eto[i]] += need;
                        cost[eto[i]^1] += need;
                        ll left = L-bfs(n);
                        if(left==0) break;
                        cc[i] -= need;
                        cost[eto[i]] -= need;
                        cost[eto[i]^1] -= need;
                    }
                    //need = L - bfs(n);
                    rep(i,m){
                        cout<<u[i] << " " << v[i] << " " << cc[i] << "\n";
                    }
            }
        }

    }
	return 0;
}
