/*************************************************************************
    > File Name: e.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月27日 星期三 16时14分16秒
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
struct Hash{
	int sz;
	int dp[maxn];
	int msk[maxn];
	int nxt[maxn];
	int head[hashsize];
	void clear() {
		sz = 0;
		memset(head, -1, sizeof head);
	}
	void push(int _msk, int t) {
		int x  = _msk%hashsize;
		for(int i = head[x]; ~i; i = nxt[i]) {
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
	int getans() {
		int ans = 0;
		for(int i = 0; i < sz; ++i){
			if(!msk[i]){
				ans = dp[i];
				break;
			}
		}
		return ans;
	}
}
int n, m;
void shift(int *code) {
	for(int i = m; i > 0; --i){
		code[i] = code[i-1];
	}
	code[0] = 0;
}
int id[12345];
int idnum;
bool ok[1234][1234];
int ck[20], ckk[20];
void dfs(int pos, int k, int kk) {
	int left = k&7;
	if(pos == m) {
		if(left) return;
		decode(k, ck);
		k = encode(ck);
		decode(kk, ckk);
		kk = encode(ckk);
		if(id[k] < 0){
			id[k] = idnum++;
			k = id[k];
		}
		if(id[kk] < 0) {
			id[kk] = idnum++;
			k = id[kk];
		}
		vis[kk][k] = true;
		return;
	}
	decode(kk,ckk);
	decode(k, ck);
	for(int up = 1; up <= 7; ++up) {
		int cntup = 0;
		for(int j = 0; j <= pos; ++j){
			if(ckk[j] == up) cntup++;
		}
		if(cntup >= 2) continue;
		if(left == up) continue;
		if(left && up) {
			ck[pos] = 0; ck[pos+1] = 0;
			for(int c = 0; c <= m; ++c){
				if(ck[c] == up) ck[c] = left;
			}
			dfs(pos+1, (k<<3), (kk<<3)|up);
		} else {
			dfs(pos+1, (k<<3)|up, )
		}
	}
}

void decode(int x, int *code) {
	for(int i = 0; i <= m; ++i) code[i] = 0;
	for(int i = m; i >= 0; --i) {

	}
}



int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

	return 0;
}
