/*************************************************************************
    > File Name: h.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年05月01日 星期日 21时24分37秒
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
const int hashsize = 6e4+7;
struct HASH{
	int sz;
	int nxt[maxn];
	int msk[maxn];
	int dp[maxn];
	int head[hashsize+1];
	void clear(){
		sz = 0;
		memset(head, -1, sizeof head);
	}
	void push(int _msk, int t){
		int x = _msk%hashsize;
		for(int i = head[x]; ~i; i = nxt[i]) {
			if(msk[i] == _msk){
				if(t >= dp[i]) continue;
				dp[i] = t;
				return;
			}
		}
		nxt[sz] = head[x];
		msk[sz] = _msk;
		dp[sz] = t;
		head[x] = sz++;
	}
}hh[2];
int m, n;
void shift(int *code){
	for(int i = m; i; --i){
		code[i] = code[i-1];
	}
	code[0] = 0;
}

void decode(int k, int *code){
	for(int i = m; i >= 0; --i){
		code[i] = k&3;
		k >>= 2;
	}
}
int encode(int *code){
	int ans = 0;
	for(int i = 0; i <= m; ++i){
		ans |=code[i];
		ans <<=2;
	}
	return ans;
}
int maze[30][30];
void dpblack(int i, int j, int now) {
	hh[now].clear();
	int pre = now^1;
	int code[15];
	for(int p = 0; p < hh[pre].sz; ++p){
		int k = hh[pre].msk[p];
		int t = hh[pre].dp[p];
		decode(k, code);
		if(maze[i][j] == 2 || maze[i][j] == 3) {
			int des = maze[i][j] -1;
			if(code[j] && code[j-1]) continue;
			int temp = code[j]?code[j]:code[j-1];
			if(temp == des) {
				code[j-1] = code[j] = 0;
				if(j==m) shift(code);
				hh[now].push(encode(code), t);
			} else if(temp == 0){
				if(maze[i][j+1] == 0) {
					code[j] = des;
					hh[now].push(encode(code), t+1);
				}
			}
		}else if(maze[i][j] == 0){
			if(code[j] == 0 && code[j-1] == 0){
				int temp = 1;
				if((maze[i+1][j] == 0 || maze[i+1][j] == temp+1)&& (maze[i][j+1] == 0 || maze[i][j+1] == temp+1)){
					code[j] = code[j-1] = temp;
					hh[now].push(encode(code), t+2);
				}
				temp++;
				if((maze[i+1][j] == 0 || maze[i+1][j] == temp+1)&& (maze[i][j+1] == 0 || maze[i][j+1] == temp+1)){
					code[j] = code[j-1] = temp;
					hh[now].push(encode(code), t+2);
				}
			} else if(!(code[j]&&code[j-1])) {
				int temp = code[j]?code[j]:code[j-1];
				if(maze[i][j+1] == 0 || maze[i][j+1] == temp+1){
					code[j-1] = 0;
					code[j] = temp;
					hh[now].push(encode(code), t+1);
				}
				if(maze[i+1][j] == 0 || maze[i+1][j] == temp+1){
					code[j-1] = temp;
					code[j] = 0;
					if(j==m) shift(code);
					hh[now].push(encode(code), t+1);
				}
			} else if(code[j]&&code[j-1]){
				if(code[j] != code[j-1]) continue;
				code[j] = code[j-1] = 0;
				if(j==m) shift(code);
				hh[now].push(encode(code), t);
			}
		}
	}
}


int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

	return 0;
}
