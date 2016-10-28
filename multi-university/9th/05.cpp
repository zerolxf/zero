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
const int maxn = 4e5+1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int f[maxn];
int a, p, x, l, r;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d%d%d", &a, &p, &x, &l, &r);
        f[0] = 0;
        f[1] = 1;
        int ma = max(3,r);
        for(int i = 2; i <= ma; ++i){
            f[i] = (a*f[i-1] + f[i-2])%p;
        }
        int ans = 0;
        for(int i = l; i <= r; ++i){
            if(f[i] == x) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
