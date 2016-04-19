/*************************************************************************
    > File Name: b.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月16日 星期六 19时02分01秒
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
int num[maxn], n, m, a[20], b[20];
struct Node{
	int need, num;
}dp[2][maxn];
int getbit(int x) {
	int ans = 0;
	while(x){
		x -= x&(-x);
		ans++;
	}
	return ans;
}
int cnt[maxn], idnum;
map<int,int> id;
int getid(int x) {
	if(id.count(x)) return id[x];
	return id[x]=idnum++;
}
bool ok(int x) {
	if(!id.count(x)) return false;
	return true;
}
void getnum(){
	idnum = 0;
	id.clear();
	memset(cnt,0x3f,sizeof cnt);
	for(int i = 0;i < a[n]; ++i){
		int y = 0, x = 0;
		for(int j = 0; j < n; ++j){
			x = 0;
			x += (i>>j)&1;
			if(j > 0) x += (i>>(j-1))&1;
			if(j < n-1) x += (i>>(j+1))&1;
			y = y*7 + x;
		}
		int idy = getid(y);
		cnt[idy] = min(cnt[idy], getbit(i));
		num[idy] = y;
	}
}
int mp[15][15], c[15];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	while(scanf("%d%d", &n, &m) != EOF){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				scanf("%d",&mp[i][j]);
			}
		}
		getnum();
		for(int i = 0; i < m; ++i){
			c[i] = 0;
			for(int j = 0; j < n; ++j){
				c[i] = c[i]*7 + mp[j][i];
			}
		}
		int now = 0;
		for(int i = 0; i < idnum; ++i){
			if(cnt[i] >= INF) continue;
			dp[now][i].need = c[0] - num[i];
			dp[now][i].num = cnt[i];
		}
		for(int i = 1; i < m; ++i){
			now = now^1;
			rep(j,idnum) dp[now][j].num = INF;
			for(int j = 0; j < idnum; ++j){
				int nj = dp[1-now][j].need;
				if(!ok(nj)) continue;
				int idn = id[nj];
				if(cnt[idn] >= INF || dp[1-now][j].num >= INF) continue;
				if(dp[1-now][j].num + cnt[idn] > dp[now][idn].num) continue;
				dp[now][idn].num = dp[1-now][j].num + cnt[idn];
				dp[now][idn].need = c[i] - nj;
			}
		}
		int ans = INF;
		for(int i = 0; i < idnum; ++i){
			int x = dp[now][i].need;
			if(!ok(x)) continue;
			int xid = id[x];
			ans = min(ans, dp[now][i].num + cnt[xid]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
