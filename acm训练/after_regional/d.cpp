
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
#include<vector>

using namespace std;
const int maxn = 1e5+100;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
ll dp[maxn], p[maxn], ran[maxn], num[maxn], cost[maxn];
struct node{
    int u,v,cost;
    bool operator < (const node& rhs) const{
        return cost < rhs.cost;
    }
}a[maxn];
int find(int x) {
    return p[x] = (p[x] == x? x:find(p[x]));
}
ll unit(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return 0;
    else {
        if(ran[x] > ran[y]){
            p[y] = x;
        }
        else p[x] = y;
        if(ran[y] == ran[x]) ran[y]++;
        ll ans = num[x]*num[y];
        num[x] = num[y] = num[x] + num[y];
        return ans;
    }
}
void init(int n) {
    for(int i = 0; i <= n; ++i) {
        p[i] = i;
        num[i] = 1;
        ran[i] = 1;
    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int n, m, q, u, v, t, x;
    cin >> t;
    while(t--) {
        cin >> n >> m >> q;
        init(n);
        for(int i = 1; i <= m; ++i) {
            scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].cost);
            cost[i] = a[i].cost;
        }
        sort(a+1, a + m + 1);
        sort(cost+1, cost+m+1);
        for(int i = 1; i <= m; ++i) {
            dp[i] = dp[i-1] + unit(a[i].v, a[i].u);
        }
        int ans;
        for(int i = 0; i < q; ++i) {
            scanf("%d", &x);
            ans = upper_bound(cost+1, cost + 1 + m, x) - cost - 1;
            cout << dp[ans]*2 << "\n";
        }
    }
    return 0;
}
