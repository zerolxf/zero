/*************************************************************************
    > File Name: e.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月17日 星期日 19时39分41秒
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
struct Node{
	int b, p;
	bool operator < (const Node& rhs)const{
		return b < rhs.b || (b==rhs.b && p > rhs.p);
	}
}a[120][120];
int band[12000], mi[120], n;
int dp[2][12000];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	int t;
	map<int,int> rk;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		rk.clear();
		rep(i,n){
			scanf("%d",&mi[i]);
			rep(j,mi[i]){
				scanf("%d%d", &a[i][j].b, &a[i][j].p);
				rk[a[i][j].b] = 0;
			}
		}
		int rank = 0;
		for(map<int,int>::iterator itr = rk.begin(); itr != rk.end(); ++itr){
			(*itr).second = rank;
			band[rank++] = (*itr).first;
		}
		int now = 0, sz = rank;
		rep(i,sz) dp[now][i] = 0;
		for(int i = 0; i < n; ++i){
			now = now^1;
			rep(j,sz) dp[now][j] = INF;
			for(int j = 0; j < mi[i]; ++j){
				int kk = rk[a[i][j].b];
				for(int k = 0; k <= kk; ++k){
					dp[now][k] = min(dp[now][k], dp[1-now][k]+a[i][j].p);
				}
			}
		}
		double ans = 0;
		for(int i = 0; i < sz; ++i){
			ans = max(ans, (band[i]*1.0/dp[now][i]));
		//	pr(i);pr(band[i]);prln(ans);
		}
		printf("%.3f\n", ans);
	}
	return 0;
}
