
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
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
ll a, b;
ll work(ll x, ll y)
{
	return max(a*x*x + b*y,a*y*y + b*x);

}
ll d[20];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    ll max1, max2, min1, min2;
	int t, kase = 1;
	scanf("%d", &t);
	while (t--)
	{
		ll n,ans = -INF;
		scanf("%lld%lld%lld", &n, &a, &b);
		if(n <= 10)
        {

            for(int i = 0; i < n; ++i) {
                scanf("%lld", d + i);
            }
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(j == i) continue;
                    ans = max(ans, work(a[i], a[j]));
                }
            }
        }
        else
        {
            for(int i = 0; i < 10; ++i) {
                scanf("%lld", d + i);
            }
            for(int i = 0; i < 10; ++i) {
                for(int j = 0; j < 10; ++j) {
                    if(j == i) continue;
                    ans = max(ans, work(a[i], a[j]));
                }
            }
            sort(d, d+10);
            max1 = d[9], max2 = d[8], min1 =
        }
		if(a >= 0)
        {
            max1 = max2 = 0; min1 = min2 = inf;
            for(int i = 1;i <= n;i++)
            {
                ll temp;
                scanf("%lld",&temp);
                if(temp > max1)
                {
                    max2 = max1;max1 = temp;
                }
                else if(temp > max2)
                {
                    max2 = temp;
                }
                if(temp < min1)
                {
                    min2 = min1;
                    min1 = temp;
                }
                else if(temp < min2)
                {
                    min2 = temp;
                }
            }
            ans = work(max1,max2);
            ans = max(ans,work(max1,min1));
            ans = max(ans,work(max1,min2));
            ans = max(ans,work(max2,min1));
            ans = max(ans,work(max2,min2));
            ans = max(ans,work(min1,min2));
            printf("Case #%d: %lld\n",kase++,ans);
        }
        else
        {
            max1 = 0; max2 = inf; min1 = min2 = inf;
            for(int i = 1;i <= n;i++)
            {
                ll temp;
                scanf("%lld",&temp);
                if(abs(temp) < abs(max2))
                {
                    max1 = max(max1,max2);
                    min1 = min(min1,max2);
                    max2 = temp;
                }
                else
                {
                    max1 = max(max1,temp);
                    min1 = min(min1,temp);
                }
            }
            ans = work(max2,max1);
            ans = max(ans,work(max2,min1));
            printf("Case #%d: %lld\n",kase++,ans);
        }
	}
}



