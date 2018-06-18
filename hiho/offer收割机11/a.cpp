
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
#define ll unsigned long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define repp(i,n,x) for(int i =x; i < n+x; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl;
const int MOD = 1e9+7;
const int maxn = 1e5+100;
const int INF = 1e9+7;
char s[maxn];
ll cnt[3][maxn];
ll sum[maxn];
const ll addnum = 2e12+1e6+1;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
  //  int ans = INF;
    int l = 0, r = -1;
    scanf("%s", s+1);
    int len = strlen(s+1);
    cnt[0][0] = cnt[1][0] = cnt[2][0] = 0;
    int a[4];
    map<ll,int> mp;
    for(int i = 1; i <= len; ++i){
    	for(int j = 0; j < 4; ++j){
    		a[j] = 0;
    	}
    	if(s[i] == 'h') a[0] = 1;
    	if(s[i] == 'i') a[1] = 1;
    	if(s[i] == 'o') a[2] = 1;
    	for(int j = 0; j < 3; ++j){
    		cnt[j][i] = cnt[j][i-1] + a[j];
    	}
    	sum[i] = cnt[0][i]*1000000000000 + cnt[1][i]*1000000 + cnt[2][i];
    	
    	if(mp.count(sum[i]) == 0) mp[sum[i]] = i;
    }
    int ans = INF;
    if(mp.count(addnum)){
    	ans = mp[addnum];
    }
    for(int i = 1; i <= len; ++i){
    	if(mp.count(sum[i]+addnum)){
    		int index = mp[sum[i]+addnum];
    		ans = min(ans, index-i);
    		//pr(i);prln(index);
    	}
    }
    if(ans==INF){
    	cout << "-1\n";
    }else{
    	cout << ans << endl;
    }
    return 0;
}
