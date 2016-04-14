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
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
ll p[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    ll n,m,t;
    scanf("%lld%lld%lld",&n,&m,&t);
    for(int i = 1;i <= m;i++)
        scanf("%lld",&p[i]);
    ll ans = 1e18;
    ans = min(ans,(n - m)*t);

    ll temp = 0,v = t,pos = 0;
    for(int i = 1;i <= m;i++)
    {
        temp = temp + (p[i] - pos)*v;
        if(v > 0)
            v--;
        pos = p[i];
    }
    temp = temp + v*(n - pos);
    ans = min(ans,temp);
    temp = 0,pos = 0;v = t;
    for(int i = 1;i <= m;i++)
    {
        temp = temp + (p[i] - pos)*v;
        //cout<<temp<<endl;
        //cout<<"v"<< " "<<v<<endl;
        ll ans1 = n - p[i] - (m - i);
        ll ans2 = v;
        //cout<<ans1<<" "<<ans2<<endl;
        pos = p[i];
        if(ans1 >= ans2 && v > 0)
        {
            v--;
        }
        else
            pos++;
    }
    temp = temp + (n - pos)*v;
    ans = min(ans,temp);
    printf("%lld\n",ans);
    return 0;
}
