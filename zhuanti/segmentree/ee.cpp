/*************************************************************************
    > File Name: ee.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年05月01日 星期日 19时01分50秒
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
	int t, task, fa;
	Node(){
	}
	Node(int _time, int _task, int _fa){
		t = _time;
		fa = _fa;
		task = _task;
	}
}node[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	int t, kase = 0, n, m, x, y, mit, mid;
	char op[10];
	scanf("%d", &t);
	Node init(0,-1,-1);
	while(t--){
		printf("Case #%d:\n",++kase);
		scanf("%d", &n);
		for(int i = 0; i <= n; ++i){
			node[i] = init;
		}
		for(int i = 1; i < n; ++i){
			scanf("%d%d", &x, &y);
			node[x].fa = y;
		}
        
        scanf("%d", &m);
		for(int i = 1; i <= m; ++i){
			scanf("%s", op);
			if(op[0] == 'C'){
				scanf("%d", &x);
				int tt = node[x].t, id = x;
				while(node[x].fa != -1){
					x = node[x].fa;
					if(node[x].t > tt){
						tt = node[x].t;
						id = x;
					}
				}
				printf("%d\n",node[id].task);
			} else {
				scanf("%d%d", &x, &y);
				node[x].task = y;
				node[x].t = i;
			}
		}
	}
	return 0;
}
