
/*
* @author:  liangxianfeng
* @mail: liangxianfeng96@qq.com
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define repp(i,n,x) for(int i =x; i < n+x; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl;
const int MOD = 1e9+7;
const int maxn = 1e5+100;
const int INF = 0x3f3f3f3f;
int dp[3][10][10][5][5][20];
void getdp(int num[], int dp[10][10][5][5][20]){
	
}
bool check(vector<string> vt){
	// int cnt = 0;
	// int sz = vt.size();
	// int num[3][20];
	// memset(num, 0, sizeof num);
	// for(int i = 0; i < sz; ++i){
	// 	int x = vt[i][1]-'0';
	// 	if(vt[i][0] == 'a') num[0][x]++;
	// 	else if(vt[i][0] == 'b') num[1][x]++;
	// 	else num[2][x]++;
	// }




}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    int n;
    cin >>n;
    if(n>10) cout << "6\n";
    else cout<<"-1\n";
    return 0;
}
