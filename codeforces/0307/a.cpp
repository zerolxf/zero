#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 2e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int ans[200][200];
void dfs(int a, int b) {
	if(a > 100 || b > 100) return;
	if(a > b) swap(a,b);
	if(a > 1) {
		if(ans[a-1][b+2] < ans[a][b]+1){
			ans[a-1][b+2] = ans[b+2][a-1] = ans[a][b]+1;
			dfs(a-1,b+2);
		}
	}
	if(b > 1) {
		if(ans[a+2][b-1] < ans[a][b]+1) {
			ans[a+2][b-1] = ans[b-1][a+2] = ans[a][b]+1;
			dfs(a+2,b-1);
		}
	}
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    ans[1][1] = 1;
    ans[1][2] = 1;
    ans[2][2] = 1;
    ans[2][1] = 1;
    dfs(1,2);
    dfs(2,2);
    dfs(2,1);
    int a, b;
    cin >> a >> b;
    cout << ans[a][b] << "\n";
    return 0;
}