/*************************************************************************
    > File Name: e.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月30日 星期六 14时37分04秒
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
ll p[maxn], num[maxn], dp[maxn], ans[maxn];
struct Node{
	int id, t;
	Node(){

	}
	Node(int _id, int _t){
		t = _t;
		id = _id;
	}
	bool operator <(const Node& rhs)const{
		return t < rhs.t;
	}
}q[maxn];
struct Edge{
	int u, v, c;
	Edge(){

	}
	Edge(int _u, int _v, int _c){
		u = _u; v = _v; c = _c;
	}
	bool operator < (const Edge& rhs)const{
		return c < rhs.c;
	}
}edge[maxn];
int find(int x){
	return p[x] = (x==p[x]?x:find(p[x]));
}
ll unite(int x, int y){
	ll ret = 0;
	x = find(x); y = find(y);
	if(x==y) return 0;
	p[x] = y;
	ret = num[x]*num[y];
	num[y] += num[x];
	return ret;
}
void init(int n){
	for(int i = 0; i <= n; ++i){
		p[i] =i;
		num[i] = 1;
	}
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	int n, m, qnum;
	int kase = 0;
	scanf("%d", &kase);
	while(kase--){
		scanf("%d%d%d", &n, &m, &qnum);
		init(n);
		int u, v, c, x;
		for(int i = 0; i < m; ++i){
			scanf("%d%d%d", &u, &v, &c);
			edge[i] = Edge(u,v,c);
		}
		for(int i = 0; i < qnum; ++i){
			scanf("%d", &x);
			q[i] = Node(i,x);
		}
		sort(edge, edge+m);
		for(int i = 0; i <= m; ++i) dp[i] = 0;
		ll ret = 0;
		for(int i = 0; i < m; ++i){
			ret += unite(edge[i].u, edge[i].v);
			dp[i] = ret;
		}
		for(int i = 0; i < qnum; ++i){
			Edge temp = Edge(0,0,q[i].t);
			int pos = upper_bound(edge, edge+m, temp) - edge;
			printf("%lld\n", dp[pos-1]*2);
		}
	}
	return 0;
}
