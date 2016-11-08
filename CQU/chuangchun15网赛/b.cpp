/*************************************************************************
    > File Name: b.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月30日 星期六 14时01分50秒
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
int val[maxn], cnt[maxn];
int head[maxn], nxt[maxn], vv[maxn], edgenum;
void addedge(int u, int v){
	nxt[edgenum] = head[u];
	vv[edgenum] = v;
	head[u] = edgenum++; 
}
int n, m;
int vis[maxn];
int q[maxn], bfsnum;
int flag[maxn];
ll bfs(int s){
	int tail = 0;
	bfsnum++;
	ll ans = 0;
	q[tail++] = s;
	flag[s] = bfsnum;
	for(int i = 0; i < tail; ++i){
		int u = q[i];
		ans += val[u];
		for(int j = head[u]; ~j;j = nxt[j]){
			int v = vv[j];
			if(vis[v]) continue;
			if(bfsnum == flag[v]) continue;
			q[tail++] = v;
			flag[v] = bfsnum;
		}
	}
	if(tail%2==1) return ans;
	return 0;
}
ll getans() {
	queue<int> q;
	for(int i = 1; i <= n; ++i){
		if(cnt[i] <= 1){
			q.push(i);
			vis[i] = true;
		}
	}
	ll ans = 0;
	while(q.size()){
		int u = q.front(); q.pop();
		for(int i = head[u]; ~i; i= nxt[i]){
			int v = vv[i];
			if(cnt[v] > 1) --cnt[v];
			if(cnt[v] <= 1 && !vis[v]){
				q.push(v);
				vis[v] = true;
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		if(!vis[i] && flag[i] == 0){
			ans += bfs(i);
		}
	}
	return ans;
}

int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		edgenum = 0;
		rep(i,n+10) head[i] = -1, cnt[i] = 0, vis[i] = false, flag[i] = 0;;
		for(int i = 1; i <= n; ++i){
			scanf("%d", &val[i]);
		}
		int u, v;
		for(int i = 0; i < m; ++i){
			scanf("%d%d", &u, &v);
			cnt[u]++;cnt[v]++;
			addedge(u,v);
			addedge(v,u);
		}
		ll ans = getans();
		printf("%lld\n", ans);
	}
	return 0;
}
