
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
const int maxn = 5e4+100;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
int p[maxn], n, ans, m;
void init(int k) {
    ans = k;
    for(int i = 0; i <= k; ++i) {
        p[i] = i;
       // h[i] = 1;
    }
}
int find(int x) {
    return x == p[x]? x : p[x] = find(p[x]);
}
void unite(int x, int y) {
    x = find(x); y = find(y);
    if(x == y) return ;
    --ans;
    p[y] = x;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int kase = 0, a, b,f;
    while(scanf("%d%d", &n, &m) == 2 && n + m !=0) {
        init(n);
        ++kase;
        for(int i = 0; i < m; ++i) {
            scanf("%d%d", &a, &b);
            unite(a, b);
        }
        printf("Case %d: %d\n", kase, ans);
    }
    return 0;
}
