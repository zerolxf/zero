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
int a[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int t, n, x;
    scanf("%d", &t);
    while(t--) {
        int ans = 0, pos;
        scanf("%d", &n);
        memset(a,0x3f,(n+10)*sizeof (int));
        for(int i = 0; i < n; ++i) {
            scanf("%d", &x);
            pos = lower_bound(a,a+n,x)-a;
            a[pos] = x;
            ans = max(ans,pos);
        }
        ++ans;
        printf("%d\n",ans);
    }
    return 0;
}
