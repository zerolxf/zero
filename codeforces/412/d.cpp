
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
#define pr(x) //cout << #x << " = " << x << " ";
#define prln(x) //cout << #x << " = " << x <<  endl;
const int MOD = 1e9+7;
const int maxn = 1e5+100;
const int INF = 0x3f3f3f3f;
int a[] = {2, 4, 8, 16, 32};
int b[] = {1, 1, 1, 1, 1};
int getnum(int solve, int all){
	if(a[0]*solve > b[0]*all) return 500;
	else if(a[1]*solve > b[1]*all) return 1000;
	else if(a[2]*solve > b[2]*all) return 1500;
	else if(a[3]*solve > b[3]*all) return 2000;
	else if(a[4]*solve > b[4]*all) return 2500;
	else return 3000;
}
int t[2][10], score[10];
int n;
int kk = 0;
bool check(){
	int numa = 0, numb = 0;
	rep(i, 5){
		if(t[0][i]!=-1)numa += score[i] - score[i]*t[0][i]/250;
		if(t[1][i]!=-1)numb += score[i] - score[i]*t[1][i]/250;
	}

	return numa > numb;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    int cnta[10], cntb[10], num[10], n, c[10];
    cin >> n;
    rep(i, 5) cnta[i] = n, cntb[i] = 0;
    rep(i,2){
    	rep(j, 5) {
    		cin >> t[i][j]; 
    		if(t[i][j]>=0) cntb[j]++;
    	}
    }
    rep(i,5){
    	if(t[0][i] != -1){
    		if(t[1][i] != -1) {
    			if(t[1][i] <= t[0][i]) c[i] = 1;
    			else c[i] = 0;
    		}else c[i] = 0;
    	}else c[i] = 0;
    }
    rep(i,5){
    	prln(c[i]);
    }
    rep(i,n-2){
    	rep(j, 5) {
    		cin >> num[j]; if(num[j]>=0) cntb[j]++;
    	}
    }
    int N = 120*400;
    int ans = -1;
    rep(j, 5){
		score[j] = getnum(cntb[j], cnta[j]);
	}
    if(check()) ans = 0;
    prln(ans);
    if(ans==-1)
    rep(i,N){
    	rep(j, 5){
    		cnta[j]++;
    		cntb[j]+=c[j];
    		score[j] = getnum(cntb[j], cnta[j]);
    		if(i==26){
    			prln(score[j]);
    		}
    	}
    	if(check()) {
    		ans = i+1;
    		break;
    	}
    }
    cout<<ans<<"\n";
    return 0;
}
