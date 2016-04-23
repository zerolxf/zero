/*************************************************************************
    > File Name: b.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月23日 星期六 01时48分37秒
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
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
const int hashsize = 100007;
struct Hash{
	int head[hashsize];
	int nxt[maxn];
	ll dp[maxn];
	int msk[maxn];
	int sz;
	void clear(){
		sz = 0;
		memset(head, -1, sizeof head);
	}
	void push(int _msk, ll t){
		int x = _msk%hashsize;
		for(int i= head[x]; i != -1; i = nxt[i]){
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
}hh[2];


int n, m;
void decode(int x, int code[]){
	for(int i = 0; i <= m; ++i) code[i] = 0;
	for(int i = m; i >= 0; --i){
		code[i] = x&1;
		x = x / 2;
	}
}

int encode(int code[]){
	int ans = 0;
	for(int i = 0; i <= m; ++i){
		ans = ans*2;
		ans = ans + code[i];
	}
	return ans;
}

void shift(int code[]){
	for(int i = m; i > 0; --i){
		code[i] = code[i-1];
	}
	code[0] = 0;
}
int maze[15][15];
void dpblank(int i, int j, int now){
	int pre = now^1;
	int code[15];
	memset(code, 0, sizeof code);
	for(int p = 0; p < hh[pre].sz; ++p){
		int k = hh[pre].msk[p];
		ll t = hh[pre].dp[p];
		decode(k, code);
		int left = code[j-1];
		int up = code[j];
		if(left && up){
				code[j-1] = code[j] = 0;
//				if(j == m) shift(code);
				hh[now].push(encode(code), t);
		} else if (left || up) {
			if(maze[i][j+1]) {
				code[j-1] = 0;
				code[j] = 1;
				hh[now].push(encode(code), t);
			}
			if(maze[i+1][j]){
				code[j-1] = 1;
				code[j] = 0;	 
//				if(j==m) shift(code);
				hh[now].push(encode(code), t);
			}
		} else if(maze[i+1][j] && maze[i][j+1]){
			code[j-1] = code[j] = 1;
			hh[now].push(encode(code), t);
		}
	}
}

void dpblock(int i, int j, int now) {
	int pre = now^1;
	int code[15];
	memset(code, 0, sizeof code);
	for(int p = 0; p < hh[pre].sz; ++p){
		ll t = hh[pre].dp[p];
		int k = hh[pre].msk[p];
		decode(k, code);
//		code[j] = 0;code[j-1] = 0;
		if(j == m+1) shift(code);
		hh[now].push(encode(code),t);
	}
}

ll slove(){
	memset(maze, 0, sizeof maze);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			scanf("%d", &maze[i][j]);
		}
	}
	int now = 0;
	hh[now].clear();
	hh[now].push(0,1);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m+1; ++j){
			now ^= 1;
			hh[now].clear();
			if(maze[i][j]) dpblank(i,j, now);
			else dpblock(i, j, now);
		}
	}
	ll ans = 0;
	for(int i = 0; i < hh[now].sz; ++i){
		if(!hh[now].msk[i])
		ans += hh[now].dp[i];
	}
	return ans;
}



int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	 int t, kase = 0;
	 cin >> t;
	 while(t--){
		 scanf("%d%d",&n,&m);
		 ll ans = slove();
		printf("Case %d: There are %lld ways to eat the trees.\n", ++kase, ans);
	 }
	return 0;
}
