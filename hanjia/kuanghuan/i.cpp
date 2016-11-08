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
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)     //  cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int ans;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n , k;
    while(cin >> n >> k){
	    int ans = INF;
	    for(int i = 0; i <= 50; ++i) {
	    	if(i > n) continue;
	    	if(ans!=INF) break;
	    	//pr(i);prln(ans);
	    	for(int j = 0; j <= 50; ++j) {
	    		//pr(j);pr(1);
	    		if(i+j>n||i*2+j*3>k) break;
	    		//prln(2);
	    		for(int l = 0; l <= 50; ++l) {
	    			//pr(3);
	    			if(i+j+l>n||i*2+j*3+l*4>k) break;
	    			//prln(4);
	    			for(int e = 0; e <= 50; ++e) {
	    				if(ans==INF&&i+j+l+e==n&&i*2+j*3+l*4+e*5==k) {
	    					//prln("*****");pr(i);
	    					if(i < ans) ans = i;
	    					//prln(ans);
	    				}
	    			}
	    		}
	    	}
	    }
	    cout << ans << "\n";
	}
    return 0;
}