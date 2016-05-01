/*************************************************************************
    > File Name: c.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月23日 星期六 23时48分31秒
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
const int HASH = 1e5+7;
struct Hash{
	int sz;
	int head[HASH];
	ll dp[maxn];
	ll msk[maxn];
	int nxt[maxn];
	void clear() {
		sz = 0;
		memset(head, -1, sizeof head);
	}
	void push(ll _msk, ll t) {
		int x = _msk%HASH;
		for(int i= head[x]; ~i; i = nxt[i]) {
			if(msk[i] == _msk){
				dp[i] += t;
				return;
			}
		}
		nxt[sz] = head[x];
		msk[sz] = _msk;
		dp[sz] = t;
		head[x] = sz++;
	}
}hh[2];
int n, m;
ll encode(int *code){
	ll ans = 0;
	int ch[15];
	memset(ch, -1, sizeof ch);
	ch[0] = 0;
	int cnt = 1;
	for(int i = 0; i <= m; ++i){
		if(ch[code[i]] == -1) ch[code[i]] = cnt++;
		code[i] = ch[code[i]];
		ans <<= 3;
		ans |= code[i];
	}
	return ans;
}
void decode(ll x, int *code){
	for(int i = m; i >= 0; --i){
		code[i] = x&7;
		x >>= 3;
	}
}
void shift(int *code){
	for(int i = m; i >= 0; --i){
		code[i] = code[i-1];
	}
	code[0] = 0;
}
int maze[15][15];
void dpblank(int i, int j, int now) {
	int code[15];
	int pre = now^1;
	//pr(i);prln(j);
	for(int p = 0; p < hh[pre].sz; ++p){
		ll t = hh[pre].dp[p];
		ll k = hh[pre].msk[p];
		//pr(k);
		//prln(t);
		decode(k, code);
		int left = code[j-1];
		int up = code[j];
		if(i == n && j == 1) {
			if(left) continue;
			if(up) {
				code[j] = 0;code[j-1] = 0;
				if(j == m) shift(code);
				hh[now].push(encode(code), t);
				continue;
			}
			code[j-1] = 0; code[j] = 13;
			if(maze[i][j+1]) hh[now].push(encode(code), t);
			continue;
		}
		if(i == n && j == m) {
			if(left && up) continue;
			if(left || up) {
				code[j] = code[j-1] = 0;
				if(j == m) shift(code);
				hh[now].push(encode(code), t);
				continue;
			}
			continue;
		}
		if(left && up) {
			if(left == up) continue;
			for(int c = 0; c <= m; ++c) if(code[c] == up) code[c] = left;
			code[j] = code[j-1] = 0;
			if(j == m) shift(code);
			hh[now].push(encode(code), t);
		} else if (left || up) {
			int temp = left?left:up;
			if(maze[i][j+1]) {
				code[j] = temp; code[j-1] = 0;
				hh[now].push(encode(code), t);
			}
			if(maze[i+1][j]){
				code[j-1] = temp; code[j] = 0;
				if(j == m) shift(code);
				hh[now].push(encode(code), t);
			}
		} else{
			if(maze[i][j+1] && maze[i+1][j]) {
				code[j] = code[j-1] = 13;
				hh[now].push(encode(code), t);
			}
		}
	}
}

void dpblock(int i, int j, int now){
	int code[15];
	int pre = now^1;
	for(int p = 0; p < hh[pre].sz; ++p){
		ll t = hh[pre].dp[p];
		ll k = hh[pre].msk[p];
		decode(k, code);
		code[j] = code[j-1] = 0;
		if(j == m) shift(code);
		hh[now].push(encode(code), t);
	}
}

void slove(){
	char s[16];
	memset(maze, 0, sizeof maze);
	for(int i = 1; i <= n; ++i){
		scanf("%s", s);
		for(int j = 1; j <= m; ++j){
			if(s[j-1] == '.') maze[i][j] = 1;
		}
	}
	int now = 0, pre;
	hh[now].clear();
	hh[now].push(0,1);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			now = now^1;
			hh[now].clear();
			if(maze[i][j]) dpblank(i,j,now);
			else dpblock(i,j,now);
		}
	}
	ll ans = 0;
	for(int i = 0; i < hh[now].sz; ++i){
		ans += hh[now].dp[i];
	}
	printf("%lld\n", ans);
}

int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	while(cin >> n >> m && (n+m) != 0){
		slove();
	}
	return 0;
}
