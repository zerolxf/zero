
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
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
vector<int> edge[maxn];
ll in[maxn];
bool huan[maxn];
int p[maxn];
int used[maxn];
void dfs(int x){
    used[x] = true;
    for(int i = 0; i < edge[x].size(); ++i){
        int v = edge[x][i];
        if(used[v]) continue;
        dfs(v);
    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    int n, m, u, v;
    ll cnt = 0;
    cin >> n >> m;
    rep(i, m){
    	scanf("%d%d", &u, &v);
    	if(u^v) in[u]++,in[v]++,edge[u].push_back(v), edge[v].push_back(u);
    	else cnt++,huan[u] = true;
    }
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        if(huan[i] || edge[i].size() > 0){
            dfs(i);
            break;
        }
    }
    for(int i = 1; i <= n; ++i){
        if(!used[i] && (huan[i] || edge[i].size() > 0)){
            prln(i);
            cout<<"0\n";
            return 0;
        }
    }
    for(int i = 1; i <= n; ++i){
        ans += in[i]*(in[i]-1)/2;
    }
    ans += cnt*(cnt-1)/2+cnt*(m-cnt);
    cout<<ans<<"\n";
    return 0;
}
