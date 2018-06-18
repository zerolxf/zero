
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
const int maxn = 3e5+100;
const int INF = 0x3f3f3f3f;
ll a[maxn], b[maxn], p[maxn], c[maxn], vis[maxn];
typedef pair<int,int> P;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    priority_queue<P> pq1, pq2, pq3;
    MEM(vis, 0);
    int n, m;
    cin >> n;
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    cin>> m;
    rep(i, m) cin>>c[i];
    rep(i, n){
    	if(a[i] == 1||b[i]==1){
    		pq1.push(P(-p[i], i));
    	}
    	if(a[i] == 2||b[i]==2){
    		pq2.push(P(-p[i], i));
    	}
    	if(a[i] == 3||b[i]==3){
    		pq3.push(P(-p[i], i));
    	}
    }
    rep(i,m){
    	if(c[i] == 1){
    		if(pq1.size() <= 0){
    			cout << "-1 ";
    		}else{
    			int ans = -1;
    			while(pq1.size() > 0){
    				P x = pq1.top(); pq1.pop();
    				if(vis[x.second]) continue;
    				else{
    					ans = -x.first;
    					vis[x.second] = true;
    					break;
    				}
    			}
    			cout << ans <<" ";
    		}
    	}else if(c[i] == 2){
    		if(pq2.size() <= 0){
    			cout << "-1 ";
    		}else{
    			int ans = -1;
    			while(pq2.size() > 0){
    				P x = pq2.top(); pq2.pop();
    				if(vis[x.second]) continue;
    				else{
    					ans = -x.first;
    					vis[x.second] = true;
    					break;
    				}
    			}
    			cout << ans <<" ";
    		}
    	}else if(c[i] == 3){
			if(pq3.size() <= 0){
    			cout << "-1 ";
    		}else{
    			int ans = -1;
    			while(pq3.size() > 0){
    				P x = pq3.top(); pq3.pop();
    				if(vis[x.second]) continue;
    				else{
    					ans = -x.first;
    					vis[x.second] = true;
    					break;
    				}
    			}
    			cout << ans <<" ";
    		}
    	}
    }
    return 0;
}
