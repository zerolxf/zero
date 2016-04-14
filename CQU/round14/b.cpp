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
const int maxn = 1e5+100;
const int INF = 0x3f3f3f3f;

vector<int>vt[maxn];
void init(int n)
{
    memset(leap,false,sizeof(leap));
    vt[1].push_back(1);
    for(ll i = 2;i <= n;i++)
    {
        if(leap[i])continue;
        vt[i].push_back(i);
        for(ll j = i*i;j <= n;j = j + i)
        {
            if(leap[j])continue;
            leap[j] = true;
            vt[j/i].push_back(j);
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    scanf("%d",&n);
    memset(num,0,sizeof(num));
    for(int i = 1;i <= n;i++)
    {
        int x;
        scanf("%d",&x);
        num[x]++;
    }
    init(n);
    int shen = n,del = 0;
    for(int i = 1;i < n;i++)
    {
        int temp = n - i + 1;
        for(int j = 0;j < vt[temp].size();i++)
        {
            del = del + num[vt[temp][j]];
            shen = shen - num[vt[temp][j]];
        }
        ans = (ans + fac[i]*pow_mod(fac[shen],mod - 2)*pow_mod(fac[shen - i],mod - 2))%mod;
        ans = (ans + del*)
    }
    return 0;
}
