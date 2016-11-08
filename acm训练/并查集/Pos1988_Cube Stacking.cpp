
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
int p[maxn], h[maxn], cnt[maxn];
void init(int k) {
    for(int i = 0; i < k; ++i) {
        p[i] = i;
        h[i] = 1;
        cnt[i] = 1;
    }
}
int find(int x) {
    int px = p[x];
    if(x == px) return x;
    int root = find(px);
    h[x] += h[px] - 1;
    p[x] = root;
    return root;
}
void unite(int x, int y) {
    int px = find(x), py = find(y);
    if(px == py) return;
    h[px] = cnt[py] + 1;
    cnt[py] += cnt[px];
    p[px] = py;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int n, p, x, y;
    cin >> p;
    init(maxn);
    char op[10];
    for(int i = 0; i < p; ++i) {
        scanf("%s", op);
        if(op[0]=='M') {
            scanf("%d%d", &x, &y);
            unite(x, y);
        }
        else {
            scanf("%d", &x);
            find(x);
        cout << h[x] - 1 << "\n";
        }
    }
    return 0;
}
