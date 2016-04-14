#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<utility>
#include<sstream>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1005;
const int mod = 10000007;
struct mat
{
    int n,m;
    int a[20][20];
    void clr()
    {
        memset(a,0,sizeof(a));
    }
    void prin()
    {
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
}I;
mat mul(mat& a,mat& b)
{
    mat c;
    c.clr();
    c.n = a.n;c.m = b.m;
    for(int i = 0;i < a.n;i++)
    {
        for(int k = 0;k < b.n;k++)
        {
            for(int j = 0;j < b.m;j++)
                c.a[i][j] = (c.a[i][j] + a.a[i][k]*b.a[k][j])%mod;
        }
    }
    return c;
}
mat pow_mod(mat& a,int n)
{
    if(n == 0)return I;
    if(n == 1)return a;
    mat ans = pow_mod(a,n/2);
    ans = mul(ans,ans);
    if(n%2)
        ans = mul(ans,a);
    return ans;
}
int main()
{
	#ifdef LOCAL
	freopen("C:\\Users\\巍巍\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\巍巍\\Desktop\\out.txt","w",stdout);
	#endif // LOCAL
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF)
    {
        mat I;
        I.n = I.m = n + 2;
        I.clr();
        for(int i = 0;i < I.n;i++)
            I.a[i][i] = 1;
        mat pp;
        pp.n = pp.m = n + 2;
        pp.clr();
        for(int i = 0;i < pp.n;i++)
        {
            if(i == pp.n - 1)
            {
                pp.a[i][pp.m - 1] = 1;
                continue;
            }
            for(int j = 0;j < pp.m;j++)
            {
                if(j == pp.m - 1)
                    pp.a[i][j] = 3;
                else if(j == 0)
                    pp.a[i][j] = 10;
                else if(j <= i)
                    pp.a[i][j] = 1;
                else
                    pp.a[i][j] = 0;
            }
        }
        mat ans = pow_mod(pp,m);
        mat rans;
        rans.n = n + 2;rans.m = 1;
        rans.a[0][0] = 23;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&rans.a[i][0]);
            rans.a[i][0] = rans.a[i][0]%mod;
        }
        rans.a[n + 1][0] = 1;
        ans = mul(ans,rans);
        printf("%d\n",ans.a[n][0]);
    }
	return 0;
}