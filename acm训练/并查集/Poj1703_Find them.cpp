
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
int p[maxn], h[maxn];
void init(int k) {
    for(int i = 0; i <= k; ++i) {
        p[i] = i;
        h[i] = 1;
    }
}
int find(int x) {
    return x == p[x]? x : p[x] = find(p[x]);
}
void unite(int x ,int y) {
    x = find(x); y = find(y);
    if(x == y) return ;
    if(h[x] <= h[y]) {
        p[x] = y;
        if(h[x] == h[y]) ++h[y];
    } else p[y] = x;
}
bool same(int x, int y) {
    return find(x) == find(y);
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int n, m, t, x, y, kase = 0;
    char op[10];
    cin >> t;
    while(t--) {
        cin >> n >> m;
        init(n*2);
        for(int i = 0; i < m; ++i) {
            scanf("%s%d%d", op, &x, &y);
            if(op[0] == 'D') {
                unite(x, y + n);
                unite(y, x + n);
            } else {
                if(same(x, y)) cout << "In the same gang.\n";
                else if(same(x, y + n)) cout << "In different gangs.\n";
                else cout << "Not sure yet.\n";
            }
        }
    }
    return 0;
}
