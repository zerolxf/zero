
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
bool isok(int x, int y){
	int b = (x/50)%475;
	bool ans = false;
	for(int i = 0; i < 25; ++i){
		b = (b*96+42)%475;
		if(b+26==y) ans = true;
	}
	return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    vector<int> num;
    int x, y, z;
    cin>>x>>y>>z;
    int ans = INF;
    for(int i = z; i <= 2000000; ++i){
    	bool flag= isok(i,x);
    	if(flag){
    		if((i-y)>=0){
    			if((i-y)%100==0){
    				int res = (i-y)/100;
    				ans = min(ans, res);
    			}
    			if((i-y)%50==0){
    				int res = (i-y+50)/100;
    				ans = min(ans, res);
    			}
    		}else{
    			if((y-i)%50==0) {
    				int res = (y-i)/50;
    				ans = 0;
    			}
    		}
    	}
    }	
    cout<<ans<<"\n";
    return 0;
}
