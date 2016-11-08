
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
int p[maxn*3], h[maxn*3];
int N, k;
int findset(int x) {
    return p[x] == x? x: p[x] = findset(p[x]);
}
void unit(int x, int y) {
    x = findset(x); y = findset(y);
    if(x == y) return;
    if(h[x] > h[y]) p[y] = x;
    else {
        p[x] = y;
        if(h[x] == h[y]) h[y]++;
    }
}
bool same(int x, int y) {
    return findset(x) == findset(y);
}
void init(int n) {
    for(int i = 0; i <= n; ++i) {
        p[i] = i;
        h[i] = 0;
    }
}
int add(int op, int x, int y) {

    if(x < 1 || y < 1 || x > N || y > N) return true;
    if(op == 1) {
        if(same(x, y + N) || same(y, x + N)) {
            return true;
        } else {
            unit(x, y);unit(x + N, y + N);unit(x + N*2, y + N*2);
            return false;
        }
    } else {
        if(same(x, y) || same(y, x + N)) {
            return true;
        } else {
            unit(x, y + N);
            unit(x + N, y + 2*N);
            unit(x + 2*N,y);
            return false;
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
        while(scanf("%d%d", &N, &k) == 2){
            init(N*3);
            int op, ans = 0, a, b;
            for(int i = 0; i < k; ++i) {
                scanf("%d%d%d", &op, &a, &b);
                ans += add(op, a, b);
            }
            printf("%d\n", ans);
        }
    return 0;
}
