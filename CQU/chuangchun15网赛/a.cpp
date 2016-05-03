/*************************************************************************
    > File Name: a.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年05月01日 星期日 17时11分12秒
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
char name[maxn][220];
int val[maxn];
int n, k, m, q;
struct Node{
	int t, v;
	bool operator < (const Node& rhs)const{
		return v < rhs.v || (v==rhs.v && t > rhs.t);
	}
	Node(){

	}
	Node(int _t, int _v){
		t = _t; v = _v;
	}
};
struct P{
	int t, p;
	bool operator < (const P& rhs)const{
		return t < rhs.t;
	}
}p[maxn];
int ans[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	int kase, t;
	scanf("%d", &kase);
	while(kase--){
		scanf("%d%d%d", &k, &m, &q);
		for(int i = 1; i <= k; ++i){
			scanf("%s%d", name[i], &val[i]);
		}	
		priority_queue<Node> pq;
		for(int i = 0; i < m; ++i){
			scanf("%d%d", &p[i].t, &p[i].p);
		}
		sort(p,p+m);
		int tail = 1, anscnt = 0, cnt;
		for(int i = 0; i < m; ++i){
			while(tail <= p[i].t && tail <= k){
				pq.push(Node(tail,val[tail]));
				tail++;
			}
			cnt = 0;
			while(pq.size() > 0 && cnt < p[i].p){
				ans[++anscnt] = pq.top().t;
				pq.pop();
				cnt++;
			}
		}
		while(tail <= k){
			pq.push(Node(tail, val[tail]));
			tail++;
		}
		while(pq.size() > 0){
			ans[++anscnt] = pq.top().t;
			pq.pop();
		}
		int x;
		for(int i = 0; i < q; ++i){
			scanf("%d", &x);
			printf("%s", name[ans[x]]);
			if(i==q-1) printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
