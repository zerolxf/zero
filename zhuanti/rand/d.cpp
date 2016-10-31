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
const int maxn = 4e6;
const int INF = 0x3f3f3f3f;
#define pr(x)     //  cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int mp[maxn];
int unit;
struct Node{
    int l, r, id;
    bool operator < (const Node& rhs)const{
        if(l/unit==rhs.l/unit) return r < rhs.r;
        return l/unit < rhs.l/unit;
    }
}q[maxn];
ll num[maxn], qq[maxn], sum[maxn];
int n, m, k;
void modui() {
    sort(q, q+m);
    int L = 0, R = 0;
    ll ans = 0, cnt;
    memset(mp,0,sizeof mp);
    sum[0] = 0;
    for(int i = 1; i <= n; ++i){
        sum[i] = sum[i-1]^num[i];
    }
    mp[0]=1;
    for(int i = 0; i < m; ++i){
        while(R < q[i].r) {
            cnt = mp[sum[++R]^k];
            mp[sum[R]]++;
            ans += cnt;
          //  mp[sum[R]]++;
            pr(L);pr(R);pr(cnt);prln(ans);
        }
        while(R > q[i].r) {
            mp[sum[R]]--;
            cnt = mp[sum[R--]^k];
            ans -= cnt;
            pr(L);pr(R);pr(cnt);prln(ans);
        }
        while(L < q[i].l){
            mp[sum[L]]--;
            cnt = mp[sum[L++]^k];
            ans -= cnt;
            pr(L);pr(R);pr(cnt);prln(ans);
        }
        while(L > q[i].l){
            cnt = mp[sum[--L]^k];
            mp[sum[L]]++;
            ans += cnt;
           pr(L);pr(R);pr(cnt);prln(ans);
        }
        qq[q[i].id] = ans;
        pr(q[i].id);pr(L);pr(R);pr(cnt);prln(ans);
    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    while(scanf("%d%d%d", &n, &m, &k) != EOF){
        for(int i = 1; i <= n; ++i){
            scanf("%I64d", &num[i]);
        }
        unit = sqrt(n);
        for(int i = 0; i < m; ++i){
            scanf("%d%d", &q[i].l, &q[i].r);
            q[i].l--;
            q[i].id = i;
        }
        modui();
        for(int i = 0; i < m; ++i){
            printf("%I64d\n", qq[i]);
        }
    }
    return 0;
}
