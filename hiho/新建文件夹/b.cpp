
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
const int maxn = 1e8+100;
const int INF = 0x3f3f3f3f;
map<ll,ll> mp;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    int n, c, m;
    cin >> n;
    for(int i = 0; i < n; ++i){
    	ll sum = 0;
    	cin >> m;
    	for(int j = 0; j < m; ++j){
    		scanf("%d", &c);
    		sum += c;
    		if(j == m-1) continue;
    		if(mp.count(sum) == 0) mp[sum] = 1;
    		else mp[sum]++;
    	}
    }
    map<ll,ll>::iterator itr = mp.begin();
    ll ans = 0;
    for(; itr != mp.end(); ++itr){
    	ans = max(ans, itr->second);
    	int k = itr->second;
    	int kk = itr->first;

    	//pr(kk);prln(k);
    }
    ans = n-ans;
    cout<<ans<<endl;
    return 0;
}
