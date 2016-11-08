
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
const int INF = 0x7f7f7f7f;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
int cost[maxn], space[maxn], v[300], u[300], t[300], x[300], y[300], z[300];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int T, m, n, p, mcost, mspace, maxv;
    cin >> T;
    while(T--) {
        cin >> n >> m >> p;
        maxv = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d%d%d", t+i, u+i, v+i);
            maxv = maxv + t[i] * v[i];
        }
        memset(space, 0x3f, sizeof(int)*maxv);
        space[0] = 0;
        mspace = mcost = INF;
        prln(maxv);
        for(int i = 0; i < n; ++i) {
            int k = 1;
            while(k < v[i]) {
                for(int j = maxv; j >= k*t[i]; --j) {
                    space[j] = min(space[j], space[j - k*t[i]]+ k*u[i]);
                    if(j >= p) mspace = min(mspace, space[j]);
                }
                v[i] -= k;
                k = k << 1;
            }
            k = v[i];
            for(int j = maxv; j >= k*t[i]; --j) {
                space[j] = min(space[j], space[j - k*t[i]]+ k*u[i]);
                if(j >= p) mspace = min(mspace, space[j]);
            }
            pr(i);prln(mspace);
        }
        if(mspace > maxv) {
            cout << "TAT\n";
            continue;
        }
        int maxs = 0;
        for(int i = 0; i < m; ++i) {
            scanf("%d%d%d", x+i, y+i, z+i);
            maxs += x[i]*z[i];
        }
        pr(1);
        memset(cost, 0x7f, sizeof(int)*maxs);
        cost[0] = 0;
        for(int i = 0; i < m; ++i) {
            int k = 1;
            while(k < z[i]) {
                for(int j = maxs; j >= k*y[i]; --j) {
                    cost[j] = min(cost[j], cost[j-k*y[i]] + k*x[i]);
                    if(j >= mspace) mcost = min(mcost, cost[j]);
                    z[i] -= k;
                    k = k << 1;
                }
                k = z[i];
                for(int j = maxs; j >= k*y[i]; --j) {
                    cost[j] = min(cost[j], cost[j- k*y[i]] + k*x[i]);
                    if(j >= mspace) mcost = min(mcost, cost[j]);
                }
            }
        }
        pr(2);
        if(mcost > 5e4) {
            cout << "TAT\n";
            continue;
        } else cout << mcost << "\n";
    }
    return 0;
}
