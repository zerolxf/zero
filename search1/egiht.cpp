/*************************************************************************
    > File Name: egiht.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月06日 星期三 20时39分03秒
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
const int maxn = 6e6+100;
const int INF = 0x3f3f3f3f;
int fac[20];
int getnum(int a[]) {
	int sum = 0;
	for(int i = 0; i < 9; ++i){
		int num = 0;
		for(int j = i+1; j < 9; ++j){
			if(a[j] < a[i]) num++;
		}
		sum += num*fac[9-i-1];
	}
	return sum+1;
}

int dx[] ={0, 1, 0, -1};
int dy[] ={-1, 0, 1, 0};
char str[] = "dlur";
void getli(int x, int a[]){
	bool vis[11];
	--x;
	for(int i = 0; i < 9; ++i) vis[i] = 0;
	for(int i = 0; i < 9; ++i){
		int num = 0;
		num = x/fac[9-i-1];
		x = x%fac[9-i-1];
		for(int j = 0; j < 9; ++j){
			if(vis[j]) continue;
			if(num==0){
				a[i] = j+1; 
				vis[j] = true;
				break;
			}
			--num;
		}
	}
}
int dis[maxn], pre[maxn], path[maxn];
void bfs(int s) {
	for(int i = 0; i <= fac[9]; ++i){
		dis[i] = INF;
	}
	dis[s] = 0;
	queue<int> q;
	q.push(s);
	int b[10];
	while(q.size()){
		int u = q.front();q.pop();
		getli(u, b);
		int x,y,pos;
		for(int i = 0; i < 9; ++i) if(b[i] == 9) pos = i;
		y = pos/3,x = pos%3;
		for(int i = 0; i < 4; ++i){
			int xx = x + dx[i];
			int yy = y + dy[i];
			int pp = yy*3+xx;
//			pr(xx);pr(yy);prln(u);
			if(xx < 0 || xx > 3 || yy < 0 || yy > 3) continue;
			swap(b[pos], b[pp]);
			int v = getnum(b);
//			pr(i);pr(v);pr(dis[v]);prln(u);
			if(dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				pre[v] = pre[u];
				path[v] = i;
				q.push(v);
			}
			swap(b[pos],b[pp]);
		}
	}
}
int ans[maxn];
void printpath(int t) {
	int cnt = 0;
	while(t != fac[9]) {
		ans[cnt++] = path[t];
		t = pre[t];
	}
	for(int i = cnt-1; i >= 0; ++i){
		printf("%c", str[ans[i]]);
	}
	printf("\n");
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	int a[10];
	char s[10];
	fac[0] = 1;
	for(int i = 1; i <= 9; ++i){
		fac[i] = fac[i-1]*i;
	}
	for(int i = 0; i < 9; ++i){
		scanf("%s", s);
		a[i] = s[0] - '0';
		if(s[0] == 'x') a[i] = 9;
	}
	int t = getnum(a);
	bfs(1);
	for(int i = 0; i < 9; ++i) pr(a[i]);
	getli(t,a);
	for(int i = 0; i < 9; ++i) pr(a[i]);
	if(dis[t] == INF) printf("unsolvable\n");
	else printpath(t);
	return 0;
}
