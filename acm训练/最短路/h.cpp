
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
const int maxn = 1e5+100;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
int ma[maxn], mi[maxn], u[maxn], v[maxn], n, m;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= n; ++i) {
        mi[i] = 1;
        ma[i] = n;
    }
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", u+i, v+i);
        ma[v[i]]--;
        mi[u[i]]++;
    }
    for(int i = 0; i <= 2*n; ++i) {
        for(int j = 0; j < m; ++j) {
            int a = u[j], b = v[j];
            ma[b] = min(ma[a]-1, ma[b]);
            mi[a] = max(mi[a], mi[b]+1);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(mi[i] == ma[i]) ans++;
       // pr(mi[i]);pr(ma[i]);prln(i);
    }
    cout << ans << "\n";
    return 0;
}
