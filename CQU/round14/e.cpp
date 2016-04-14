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
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
int num[1005],leap[1005];
int k,n;
void check(int dd,int l,int r,int kk)
{
    if(leap[dd] == 1 && leap[dd - 1] == 0)
    {
        num[dd] = k - kk;
        return;
    }
    if(kk == 1)
    {
        int ans = k - kk;
        for(int i = l;i <= dd;i++)
        {
            if(leap[i] != -1)continue;
            ans++;
        }
        num[dd] = ans;
        return;
    }
    int mid = (l + r)/2;
    if(mid >= dd)
    {
        leap[mid] = 1;
        check(dd,l,mid,kk - 1);
    }
    else
    {
        leap[mid] = 0;
        check(dd,mid,r,kk - 1);
    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    scanf("%d%d",&n,&k);
    memset(num,0,sizeof(num));
    for(int i = 1;i <= n;i++)
    {
        memset(leap,-1,sizeof(leap));
        leap[0] = 0;
        leap[n] = 1;
        check(i,0,n,k);
    }
    double ans = 0;
    for(int i = 1;i <= n;i++)
    {
        //cout<<i<<" "<<num[i]<<endl;
        ans = ans + num[i];
    }
    ans = ans/n;
    printf("%.5f\n",ans);
    return 0;
}
