/*************************************************************************
    > File Name: h.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月24日 星期日 15时40分52秒
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
int n, x;
int a[110][110], b[110], ans[100];
bool vis[110][110];

bool cmp(int x, int y) {
	return x > y;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	while(cin >> n >> x) {
		for(int i = 0; i < n; ++i){
			scanf("%d", &a[i][0]);
		}
		memset(vis, 0, sizeof vis);
		for(int i = 0; i < n; ++i){
			scanf("%d", &b[i]);
			a[i][b[i]+1] = x;
			ans[i] = 0;
			for(int j = 1; j <= b[i]; ++j){
				scanf("%d", &a[i][j]);
			}
			for(int j = 1; j <= b[i]; ++j){
				if(a[i][j] > x && a[i][j] < a[i][0] && !vis[i][a[i][j]]) {
					ans[i] += 15;
					vis[i][a[i][j]] = true;
				}
				if(a[i][j] < x && a[i][j] > a[i][0] && !vis[i][a[i][j]]) {
					ans[i] += 15;
					vis[i][a[i][j]] = true;
				}
			}
		}
		for(int i = 0; i < n; ++i){
			if(a[i][0] == x) {
				ans[i] = 0;
				continue;
			}
			ans[i] += abs(a[i][0] - x)*5;
		}
		for(int i = 0; i < n; ++i){
			printf("%d%c", ans[i],(i==n-1?'\n':' '));
		}
	}
	return 0;
}
