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
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
#ifdef LOCAL
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#endif
#define ll long long
int x[maxn], y[maxn], p[maxn], ran[maxn];
vector<int> G[maxn];
void init(int n) {
    for(int i = 0; i <= n; ++i) {
        p[i] = -1;
        ran[i] = 1;
    }
}
int find(int x) {
    return p[x]=(x == p[x]?x:find(p[x]));
}
void unite(int x, int y) {
    x = find(x); y = find(y);
    if(x == y) return;
    if(ran[x] > ran[y]) {
        p[y] = x;
    } else {
        p[x] = y;
        if(ran[x] == ran[y]) ran[y]++;
    }
    return;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, d, a, b;
    char op[10];
    cin >> n >> d;
        init(n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", x+i, y+i);
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = i+1; j <= n; ++j) {
                if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) <= d*d){
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            } 
        }
        while(scanf("%s", op) !=EOF) {
           // prln(op);
            if(op[0] == 'S') {
                scanf("%d%d", &a, &b);
                if(p[a]==-1||(p[b]==-1)) {
                    printf("FAIL\n");
                    continue;
                }
                a = find(a); b = find(b);
                if(a == b && a != -1) printf("SUCCESS\n");
                else printf("FAIL\n");
            } else {
                scanf("%d", &a);
                p[a] = a;
                for(int i = 0; i < G[a].size(); ++i) {
                    if(~p[G[a][i]]) unite(a, G[a][i]);
                }
            }
        }
    return 0;
}