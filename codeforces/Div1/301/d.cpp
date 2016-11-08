/*************************************************************************
    > File Name: d.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月29日 星期六 16时42分33秒
 ************************************************************************/

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
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
ll sum[maxn];
int n, m;
void add(int x){
    for(int i = x; i <= n; i += i&(-i)) sum[i] += 1;
}
ll getsum(int x){
    ll ans = 0;
    for(int i = x; i > 0; i -= i&(-i)) ans += sum[i];
    return ans;
}
inline ll query(ll x, ll y){
    return getsum(x) - getsum(y);
}
vector<int> lpos[maxn], rpos[maxn];
int l[maxn], r[maxn], a[maxn], pos[maxn];
ll ans[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }
    for(int i = 0; i < m; ++i){
        scanf("%d%d", &l[i], &r[i]);
        lpos[l[i]-1].push_back(i);
        rpos[r[i]].push_back(i);
    }
    for(int i = 1; i <= n; ++i){
        int siz = lpos[i].size();
        for(int j = a[i]; j <= n; j += a[i]) add(pos[j]);
        for(int j = 0; j < siz; ++j){
            int v = lpos[i][j];
            ans[v] -= query(r[v], l[v]-1);
        }
        siz = rpos[i].size();
        for(int j = 0; j < siz; ++j){
            int v = rpos[i][j];
            ans[v] += query(r[v], l[v]-1);
        }
    }
    rep(i,m) cout << ans[i] << "\n";

	return 0;
}
