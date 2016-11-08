/*************************************************************************
    > File Name: 1451.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年05月01日 星期日 16时04分54秒
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
struct Node{
	int cost, h, id;
	bool operator < (const Node& rhs)const{
		return cost > rhs.cost;
	}
	Node(){

	}
	Node(int _cost, int _h, int _id){
		cost = _cost;
		h = _h;
		id = _id;
	}
};
int pre[maxn], ma[maxn], h[maxn], last[maxn], type[maxn], dp[maxn];
int n;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	int kase, t;
	scanf("%d", &t);
	kase = 0;
	while(t--){
		scanf("%d", &n);
		memset(type, -1, sizeof type);
		memset(last, -1, sizeof last);
		priority_queue<Node> pq;
		for(int i = 1; i <= n; ++i){
			scanf("%d%d", &type[i], &h[i]);
		}
		pre[1] = 1;
		last[type[1]] = 1;
		for(int i = 2; i <= n; ++i){
			if(type[i] == type[i-1]){
				pre[i] = i;
			}else{
				pre[i] = max(pre[i-1], last[type[i]]+1);
			}
			last[type[i]] = i;
		}
		dp[0] = 0;
		for(int i = 1; i <= n; ++i){
			pq.push(Node(dp[i-1]+h[i], h[i], i));
			dp[i] = dp[i-1] + h[i];
			while(pq.size()){
				Node x = pq.top();
				if(x.id < pre[i]) {
					pq.pop();
					continue;
				}
				if(x.h < h[i]){
					pq.pop();
					x.cost += h[i] - x.h;
					dp[i] = min(dp[i], x.cost);
					x.h  = h[i];
					pq.push(x);
					continue;
				} else {
					dp[i] = min(dp[i], x.cost);
					break;
				}
			}
		}
		printf("Case %d: %d\n",++kase, dp[n]);
	}
	return 0;
}
