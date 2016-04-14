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
const int maxn = 6e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long

int p[maxn], ran[maxn];
int find(int x) {
    return x == p[x]?x:find(p[x]);
}
bool same(int x, int y) {
    x = find(x);y = find(y);
    return x==y;
}
void unite(int x, int y) {
    x = find(x);y = find(y);
    if(x == y) return ;
    if(ran[x] > ran[y]) {
        p[y] = x;
    } else {
        p[x] = y;
        if(ran[x] == ran[y]) ++ran[y];
    };
} 
void init(int n) {
    n = n*3;
    for(int i = 0; i <= n; ++i) {
        p[i] = i;
        ran[i] = 1;
    }
}

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, k, d, x, y;
    cin >> n >> k ;
        int ans = 0;
        init(n);
        for(int i = 0; i < k; ++i) {
            scanf("%d%d%d", &d, &x, &y);

            x--;y--;
            if(x >= n || y >= n || x < 0 || y < 0) {
                ++ans;
                //pr(x);prln(y);
                continue;
            }
            if(d == 1) {
                if(same(x,y+n)||same(x,y+2*n)) {
                    ++ans;
                    //pr(x);prln(y);
                    continue;
                }
                unite(x,y);unite(x+n,y+n);unite(x+2*n,y+2*n);
            } else {
                if(same(x,y)||same(x,y+2*n)) {
                    ++ans;
                    //pr(x);prln(y);
                    continue;
                }
                unite(x,y+n);unite(x+n,y+2*n);unite(x+2*n,y);
            }
        }
        printf("%d\n",ans);
    
    return 0;
} 