
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
int p[maxn*2], h[maxn*2], n;
void init(int k) {
    for(int i = 0; i <= k; ++i) {
        p[i] = i;
        h[i] = 1;
    }
}
int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}
bool unite(int x, int y ) {
    int px = find(x), py = find(y);
    if(px == py) return false;
    p[px] = find(y + n);
    p[py] = find(x + n);
    return true;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int t, k, a, b, kase = 0; cin >> t;
    while(t--) {
        if(kase) cout << "\n";
        printf("Scenario #%d:\n", ++kase);
        scanf("%d%d", &n, &k);
        init(n*2);
        bool ok = true;
        for(int i = 0; i < k; ++i) {
            scanf("%d%d", &a, &b);
            if(!unite(a,b)) ok = false;
        }
        if(ok) printf("No suspicious bugs found!\n");
        else printf("Suspicious bugs found!\n");
    }
    return 0;
}
