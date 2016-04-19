/*************************************************************************
    > File Name: a.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月19日 星期二 12时40分33秒
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
const int hashsize = 1e6+107;
struct Hash{
	int head[hashsize];
	ll dp[hashsize];
	ll msk[hashsize];
	int nxt[hashsize];
	int sz;
	void clear() {
		sz = 0;
		memset(head, -1, sizeof head);
	}
	void push(ll _msk, ll t) {
		int x  = _msk%hashsize;
		for(int i = head[x]; ~i; i= nxt[i]) {
			if(msk[i] == _msk) {
				dp[i] += t;
				return;
			}
		}
		nxt[sz] = head[x];
		dp[sz] = t;
		msk[sz] = _msk;
		head[x] = sz++;
	}
	ll getans() {
		ll ans = 0;
		int x = 0;
		for(int i = head[x]; ~i; i = nxt[i]){
			ans += dp[i];
		}
		return ans;
	}
}hh[2];
char mp[16][16];
int maze[16][16];
int ex, ey;
void getmaze(int n, int m){
	memset(maze, 0, sizeof maze);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(mp[i][j] == '.') {
				maze[i][j] = 1;
				ex = i;ey = j;
			}
		}
	}
}
void decode(int code[],ll  x, int m){
	for(int i = 0; i <= m; ++i){
		code[i] = x&7;
		x >>=3;
	}
}
int ch[20];
ll encode(int code[], int m){
	ll ans = 0;
	memset(ch,-1, sizeof ch);
	ch[0] = 0;
	int cnt = 1;
	for(int i = 0; i <= m; ++i){
		if(ch[code[i]] == -1) ch[code[i]] = cnt++;
		code[i] = ch[code[i]];
	}
	for(int i = m; i >= 0; --i){
		ans <<=3;
		ans |= code[i];
	}
	return ans;
}
void shift(int code[], int m) {
	for(int i = m; i; --i){
		code[i] = code[i-1];
	}
	code[0] = 0;
}

void dpblank(int i, int j, int pre, int m) {
	int code[15];
	for(int p = 0; p < hh[pre].sz; ++p){
		ll s = hh[pre].msk[p];
		ll t = hh[pre].dp[p];
		decode(code, s, m);
//		pr(s);prln(t);
		int left = code[j];
		int up = code[j+1];
//		pr(left);prln(up);
		if(left && up){
			if(left == up && i == ex && j == ey){
				code[j] = 0; code[j+1] = 0;
			//	if(j==m) shift(code,m);
				hh[pre^1].push(encode(code,m), t);
			} else if(left != up){
				code[j] = 0; code[j+1] = 0;
				for(int c = 0; c  <= m; ++c){
					if(code[c] == up){
						code[c] = left;
					}
				}
			//	if(j==m) shift(code,m);
				hh[pre^1].push(encode(code,m), t);
			}
		} else if(left||up){
			int temp;
			if(left) temp = left;
			else temp = up;
			if(maze[i][j+1]){
				code[j+1] = temp;
				code[j] = 0;
				hh[pre^1].push(encode(code,m), t);
			}
			if(maze[i+1][j]){
				code[j+1] = 0;
				code[j] = temp;
			//	if(j==m) shift(code,m);
				hh[pre^1].push(encode(code,m), t);
			}
		} else if(left==0&&up==0){
			if(maze[i][j+1] && maze[i+1][j]){
				code[j] = 13;
				code[j+1] = 13;
				hh[pre^1].push(encode(code, m), t);
			}
		}
	}
}
void dpblock(int i, int j, int pre, int m){
	int code[15];
	memset(code, 0, sizeof code);
	for(int p = 0; p < hh[pre].sz; ++p){
		ll s = hh[pre].msk[p];
		ll t = hh[pre].dp[p];
		decode(code, s, m);
		int left = code[j], up = code[j+1];
		if(!left && !up) {
		code[j] = 0; code[j+1] = 0;
			if(j==m) shift(code, m);
			hh[pre^1].push(encode(code,m), t);
		}
	}
}
ll slove(int n, int m) {
	for(int i = 0; i < n; ++i){
		scanf("%s", mp[i]);
	}
	getmaze(n, m);
	if(ex == 0){
		printf("0\n");
		return 0;
	}
	int now = 0, pre = 1;	
	hh[now].clear();
	hh[now].push(0, 1);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j <=  m; ++j)
		{
			swap(now,pre);
			hh[now].clear();
			if(!maze[i][j]) dpblock(i,j,pre,m);
			else dpblank(i,j,pre,m);
		}
	}
	ll ans = hh[now].getans();
	printf("%lld\n",ans);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	
	int n, m;
	while(scanf("%d%d",&n,&m) != EOF) {
		slove(n, m);
	}
	return 0;
}
