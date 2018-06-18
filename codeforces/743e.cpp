
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
const int N = 1e3+100;
int getnum(int x){
	int ans = 0;
	while(x){
		x -= x&(-x);
		ans++;
	}
	return ans;
}
int nxt1[N][10], nxt[10];
int dp[N][N][10];
int a[maxn], n;
const int m = 8;
const int S = (1<<8)-1;
bool check2(int order[], int num[]){
	int pre = 1;
	for(int i = 0; i < 8; ++i){
		int x = order[i], y = num[i];
		if(!y) continue;
		int nxt_pos = dp[pre][y][x];
		if(nxt_pos>n) return false;
		pre = nxt_pos+1;
	}
	return true;
}
int check(int len){
	int num[10] = {0};
	int ans = 0;
    for(int i = 0; i < S; ++i){
    	int order[]={1, 2, 3, 4, 5, 6, 7, 8, 9};
    	for(int j = 0; j < m; ++j)	num[j] = len + (S>>j)&1;
		do{
			if(check2(order, num)) {
                ans = max(len*8+getnum(i), ans);
                prln(len);prln(getnum(i));
			}
	    }while(next_permutation(num, num+m));
	}
	return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    cin >> n;
    rep(i,n) cin >> a[i+1];
    rep(i, 9) nxt[i] = n+1;
    for(int i = n; i > 0;  --i){
    	for(int j = 1; j <= 8; ++j){
    		nxt1[i][j] = nxt[j];
    	}
    	nxt[a[i]] = i;
    }
    MEM(dp, 0x3f);
    for(int i = 1; i <= n; ++i){
    	for(int j = 1; j <= 8; ++j){
    		dp[i][1][j] == a[i]==j? i:nxt1[i][j];
    	}
    }
    for(int i = 2; i <= n; ++i){
    	for(int j = n-i+1; j >= 1; --j){
    		for(int k = 1; k <= 8; ++k){
    			dp[j][i][k] = a[j]==k?dp[j+1][i-1][k]:dp[j+1][i][k];
    		}
    	}
    }
    int l = 0, r = n/8;
    while(l < r){
    	int mid = (l+r+1) >> 1;
    	pr(l);pr(r);prln(mid);
    	if(check(mid)) l = mid;
    	else r = mid-1;
    }
    prln(l);
    int ans = check(l);
    cout << ans <<"\n";
    return 0;
}
