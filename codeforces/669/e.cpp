/*************************************************************************
    > File Name: e.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月26日 星期二 23时12分10秒
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
int op[maxn], x[maxn], id[maxn], t[maxn], head[maxn], nxt[maxn],num;
void addedge(int x, int oop, int iid, int tt) {
	op[num] = oop;
	id[num] = iid;
	t[num] = tt;
	nxt[num] = head[x];
	head[x] = num++;
}
map<int,int> mp;
int mpnum = 0;
int getid(int x) {
	if(mp.count(x)) return mp[x];
	mp[x] = mpnum++;
	return mpnum-1;
}
int bit[maxn];
int rk;
void getadd(int x, int v) {
	while(x <= rk){
		bit[x] += v;
		x += x&(-x);
	}
}
int getsum(int x) {
	int ans = 0;
	while(x > 0){
		ans += bit[x];
		x -= x&(-x);
	}
	return ans;
}
vector<int> qid;
map<int,int> tt;
vector<int> temp;
int ans[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	int n, a, b, c, d;
	memset(head, -1, sizeof head);
	scanf("%d",&n);
	for(int i = 0; i < n; ++i){
		scanf("%d%d%d",&a, &b, &c);
		d = getid(c);
		addedge(d, a, i, b);
		if(a == 3)qid.push_back(i);
	}
	for(int i = 0; i < mpnum; ++i){
		rk = 0;
		tt.clear();
		temp.clear();
		for(int u = head[i]; ~u; u = nxt[u]) {
			tt[t[u]] = 0;	
			temp.push_back(u);
		}
		for(map<int,int>::iterator itr = tt.begin(); itr != tt.end(); ++itr){
			itr->second = ++rk;
		}
		memset(bit, 0, (rk+5)*sizeof(int));
		for(int u = temp.size()-1; u >= 0; --u) {
			int j = temp[u];
			a = op[j]; b = tt[t[j]]; d = id[j];
			if(a == 1) {
				getadd(b, 1);
			} else if(a == 2) {
				if(getsum(b) > 0) getadd(b, -1);
			} else {
				ans[d] = getsum(b);
			}
		}
	}
	for(int i = 0; i < qid.size(); ++i){
		d = qid[i];
		printf("%d\n", ans[d]);
	}
	return 0;
}
