/*************************************************************************
    > File Name: b.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月25日 星期一 00时41分51秒
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
int a[maxn];
char s[maxn];
bool vis[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	int n;
	while(scanf("%d",&n) != EOF) {
		scanf("%s", s);
		memset(vis, 0, sizeof vis);
		rep(i,n) scanf("%d",&a[i]);
		int m = 0;
		while(m < n && m >= 0 && !vis[m]){
			vis[m] = true;
			if(s[m] == '>') m += a[m];
			else m-=a[m];
		}
		if(m >= 0 && m < n){
			printf("INFINITE\n");
		} else printf("FINITE\n");
	}
	return 0;
}
