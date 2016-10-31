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
ll a[maxn], b[maxn];
ll num[1100][1100];
ll r[maxn], c[maxn], sumr[maxn], sumc[maxn], sumrr, sumcc;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    rep(i,1100){
        r[i] = c[i] = sumr[i] = sumc[i] = 0;
    }
    sumrr = sumcc = 0;
    int n;
    scanf("%d",&n);
    bool ok = true;
    ll sum = 1;
    ll rr = 0, cc = 0;
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= n; ++j){
            scanf("%I64d",&num[i][j]);
            if(num[i][j]==0) rr=i,cc=j;
            sumr[i] = sumr[i] + num[i][j];
            sumc[j] = sumc[j] + num[i][j];
            if(i==j) sumrr += num[i][j];
            if(i+j==n+1) sumcc += num[i][j];
        }
    }
    for(int i = 1; i <=n;++i)if(i!=rr) sum=sumr[i];
    ll ans = sum - sumr[rr];
    if(ans<=0) ok = false;
    if(rr==cc) sumrr += ans;
    if(rr+cc==n+1) sumcc += ans;
    sumr[rr] += ans;
    sumc[cc] += ans;
    for(int i = 1; i <= n; ++i){
        if(sum!=sumr[i]) ok = false;
        if(sum!=sumc[i]) ok = false;
    }
    if(sumcc!=sum||sumrr!=sum) ok = false;
    if(ok) printf("%I64d\n",ans);
    else printf("-1\n");

    return 0;
}
