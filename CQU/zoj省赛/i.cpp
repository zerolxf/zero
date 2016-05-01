/*************************************************************************
    > File Name: i.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月23日 星期六 13时00分31秒
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
char mp[120][120];
int vis[120][120];
int dx[] = {
	0,-1, 0, 1, -1, 1
};
int dy[]={
	0,1, 1, 1, 2, 2
};
char body[] ="O/|\\()";
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	int t;
	cin >> t;
	int kase = 0;
	char str[120];
	while(t--){
		int n, m;
		cin >> n >> m;
		rep(i,n+2) rep(j,m+2) mp[i][j] = 'O';
		for(int i = 0; i < n; ++i){
			scanf("%s",str);
			for(int j = 1; j <= m; ++j){
				mp[i+2][j] = str[j-1];
			}
		}
		int ans = 0;
		for(int i = 0; i < n+2; ++i){
			for(int j = 0; j < m+2; ++j){
				bool ok = false;
				for(int k = 0; k < 6; ++k){
					int yy = i + dy[k];
					int xx = j + dx[k];
					if(xx > 0 && xx < m+1 && yy >= 2 && yy < n+2){
						if(mp[yy][xx] == body[k]) {
							ok = true;
							mp[yy][xx] = '.';
						}
					}
				}
				if(ok) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
