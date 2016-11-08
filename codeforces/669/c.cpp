/*************************************************************************
    > File Name: c.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月25日 星期一 00时53分38秒
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
int a[150][150];
int op[15000], r[15000], c[15000], x[15000];
int n, m;
void shiftr(int x) {
	for(int i = m+1; i; --i){
		a[x][i] = a[x][i-1];
	}
	a[x][1] = a[x][m+1];
}
void shiftc(int x){
	for(int i = n+1; i; --i){
		a[i][x] = a[i-1][x];
	}
	a[1][x] = a[n+1][x];
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	for(int i = 0; i < 150; ++i){
		for(int j = 0; j < 150; ++j){
			a[i][j] = INF;
		}
	}
	int  q;
	cin >> n >> m >> q;
	for(int i = 0; i < q; ++i){
		cin >> op[i];
		if(op[i] == 3){
			cin >> r[i] >> c[i] >> x[i];
		} else if(op[i] == 2){
			cin >> c[i];
		} else cin >> r[i];
	}
	int rr = 1, cc = 1, nr, nc;
	for(int i = q-1; i >= 0; --i){
		if(op[i] == 3){
			a[r[i]][c[i]] = x[i];
		} else if(op[i] == 2) {
			shiftc(c[i]);
		} else if(op[i] == 1){
			shiftr(r[i]);
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			nr = i;nc = j;
			if(a[nr][nc] >= INF) printf("0 ");
			else printf("%d ", a[nr][nc]);
		}
		printf("\n");
	}
	return 0;
}
