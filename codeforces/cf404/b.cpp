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
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
struct Node{
    ll l, r, k;
    Node(){}
    Node(ll _l , ll _r, ll _k){
        l = _l, r = _r;k = _k;
    }
    bool operator < (const Node& rhs)const{
        return l < rhs.l || (l == rhs.l && r < rhs.r);
    }
}node1[maxn], node2[maxn], a[maxn], b[maxn], c[maxn];

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
 #endif
    int n, m, l, r;
    ll rmin = 1e10, lmax = -1e10;
    cin >> n;
    for(int i = 0; i < n; ++i){
        scanf("%d%d", &l, &r);

        rmin = min(rmin, (ll)r);
        lmax = max(lmax, (ll)l);
    }
    cin>>m;
    ll ans = 0;
    for(int i = 0; i < m; ++i){
        scanf("%d%d", &l, &r);
        ans = max(ans, (ll)l-rmin);
        ans = max(ans, lmax-(ll)r);
    }

    cout << ans << endl;
    return 0;
}

