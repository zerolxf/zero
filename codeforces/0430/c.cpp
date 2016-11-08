/*************************************************************************
    > File Name: c.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月30日 星期六 01时03分26秒
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

char s[maxn];

bool vis[130][130][130];
bool ge[130][130][130];
string vec[62000];
int tot;
string ss;
bool aa[2][maxn];
void dfs(int pos){
	if(pos<5) return;
	if(pos-1>=5&&!vis[s[pos-1]][s[pos]][0]) {
		vis[s[pos-1]][s[pos]][0] = true;
		if(!aa[0][pos-1]||!aa[1][pos-1]||!aa[0][pos-3]||!aa[1][pos-5]) {
			aa[0][pos-1] = true;
			dfs(pos-2);
		}
		vis[s[pos-1]][s[pos]][0] = false;
	}
	if(pos-2>=5&&!vis[s[pos-2]][s[pos-1]][s[pos]]){
		vis[s[pos-2]][s[pos-1]][s[pos]] = true;
		if(!aa[1][pos-2]||!aa[1][pos-2]||!aa[0][pos-4]||!aa[1][pos-5]) {
			aa[1][pos-2] = true;
			dfs(pos-3);
		}
		vis[s[pos-2]][s[pos-1]][s[pos]] = false;

	}
}
string temp;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	while(scanf("%s", s) != EOF){
		int len = strlen(s);
		dfs(len-1);
		for(int i = 5; i < len; ++i){
			if(i+2<=len&&aa[0][i]){
				temp.clear();
				temp+=s[i];temp+=s[i+1];
				vec[tot++] = temp;
			}
			if(i+3<=len&&aa[1][i]){
				temp.clear();
				temp+=s[i];temp+=s[i+1];
				temp+=s[i+2];
				vec[tot++] = temp;
			}
		}
		sort(vec, vec+tot);
		tot = unique(vec, vec+tot) - vec;
		printf("%d\n",tot);
		for(int i = 0; i < tot; ++i){
			cout << vec[i] << "\n";
		}
	}
	return 0;
}
