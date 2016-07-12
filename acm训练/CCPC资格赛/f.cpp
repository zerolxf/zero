#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<stack>
#include<queue>
#define pr(x) cout << #x << " = " << (x) << '\n';
#define ll long long
using namespace std;

const int MAXN = 211;
const int INF = 0x7f7f7f7f;

ll x[MAXN], y[MAXN], z[MAXN], f[MAXN], l[MAXN], dis[MAXN][MAXN];

ll getdis(int a, int b)
{
    ll dis = (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]) + (z[a] - z[b]) * (z[a] - z[b]);
    return dis;
}

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lld%lld%lld%lld%lld", &x[i], &y[i], &z[i], &f[i], &l[i]);
        }

      //  l[1] = 10;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (l[j] == 0 || l[i] == 0) dis[i][j] = dis[j][i] = 1e18;
                else dis[i][j] = dis[j][i] = getdis(i, j);
            }
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                for (int k = 1; k <= n; ++k)
                {
                    dis[j][k] = min(dis[j][k], max(dis[j][i], dis[i][k]));
                }

        ll ans = 0;
        for (int i = 2; i <= n; ++i)
        {
            if (f[i] != 0)
            {
                ans = max(ans, dis[1][i]);
            }
        }
        if (ans == 1e18) puts("-1");
        else printf("%.16lf\n", sqrt(ans));
    }
    return 0;
}
