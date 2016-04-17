/*************************************************************************
    > File Name: g.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月17日 星期日 22时46分39秒
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
const int maxn = 4e6+100;
const int INF = 0x3f3f3f3f;
const int hashsize = 60007;
int Pow[24];
struct Node{
	int head[hashsize];
	int dp[hashsize];
	int msk[hashsize];
	int next[hashsize];
	int sz;
	void clear(){
		memset(head, -1 ,sizeof head);
		sz = 0;
	}
	inline void push(int _msk, int t){
		int x = _msk%hashsize;
		for(int i = head[x]; ~i; i = next[i]){
			if(msk[i] == _msk){
				if(dp[i] > t) dp[i] = t;
				return;
			}
		}
		next[sz] = head[x];
		msk[sz] = _msk;
		dp[sz] = t;
		head[x] = sz++;
	}
	inline int ans(){
		int x = 0;
		for(int i = head[x]; i != -1; i = next[i]){
			if(!msk[i]) return dp[i]-2;
		}
		return 0;
	}
}hh[2];
int mp[30][30], n, m;
void solve(){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d",&mp[i][j]);
		}
	}
	int now, pre;
	now = 0, pre = 1;
	hh[pre].clear();
	hh[pre].push(0,0);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j <= m; ++j){
			hh[now].clear();
			int ch = mp[i][j] - 1;
			for(int p = 0; p < hh[pre].sz; ++p){
				int k = hh[pre].msk[p];
				int t = hh[pre].dp[p];
				int left = (k/Pow[j])%3;
					if(j == m){
						if(k/Pow[m]) continue;
						hh[now].push(k*3, t);
						continue;
					}
				int up = (k/Pow[j+1])%3;
				if(ch == -1){
					if(left && up && (left == up)){
						int kk = k - left*Pow[j] - up*Pow[j+1];
						hh[now].push(kk, t+1);
						continue;
					}
					if((left || up) && (up == 0 || left == 0)) {
						int kk = k - left*Pow[j] - up*Pow[j+1];
						int temps = left?left:up;
						int tempk = kk + temps*Pow[j];
						hh[now].push(tempk, t+1);
						tempk = kk + temps*Pow[j+1];
						hh[now].push(tempk, t+1);
						continue;
					}
					if(!left && (!up)) {
						hh[now].push(k, t);
						int kk = k + Pow[j] + Pow[j+1];
						hh[now].push(kk, t+1);
						kk += Pow[j] + Pow[j+1];
						hh[now].push(kk, t+1);
						continue;
					}
				}

				else if(ch == 0){
					if(!left && !up){
						hh[now].push(k,t);
					}
				}
				else if (ch) {
					if(left&&up) continue;
					if(left == ch || up == ch){
						int kk = k - up*Pow[j+1] - left*Pow[j];
						hh[now].push(kk , t+1);
					}
					else if (!left && !up) {
						int kk = k +ch*Pow[j];
						hh[now].push(kk, t+1);
						kk = k  + ch*Pow[j+1];
						hh[now].push(kk, t + 1);
					}
				}
			}
			swap(now,pre);
		}
	}
	printf("%d\n", hh[pre].ans());
}

int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	Pow[0] = 1;
	for(int i = 1; i < 20; ++i) Pow[i] = Pow[i-1]*3;
	while(scanf("%d%d",&n,&m) != EOF && (n+m)!=0) {
		solve();
	}
	return 0;
}
