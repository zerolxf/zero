
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
bool work[maxn];
int  p[maxn], h[maxn], xx[maxn], yy[maxn];
vector<int> G[maxn];
void print(int k) {
    for(int i = 0; i < k; ++i) {
        pr(i);prln(p[i]);
    }
}
void init(int k) {
   // prln(k);
    for(int i = 0; i <= k; ++i) {
        work[i] = false;
        G[i].clear();
       // p[i] = -9;
       p[i] = i;
      //  prln(p[i]);
        h[i] = 0;
       // pr(i);prln(p[i]);
    }
   // print(k);
}
int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}
bool same(int x, int y) {
  //  pr(x);prln(y);
    x = find(x); y = find(y);
 //  cout << "same "; pr(x);prln(y);
    return x == y;
}
void unite(int x, int y) {
    x = find(x); y = find(y);
    if(x == y) return;
    if(h[x] <= h[y]) {
        p[x] = y;
        if(h[x] == h[y])  ++h[y];
    } else p[y] = x;
}
void repair(int x) {
    work[x] = true;
  //  printf("repair%d\n", x);
    for(int i = 0; i < G[x].size(); ++i) {
       // pr(i);prln(G[x][i]);
       int v = G[x][i];
        if(work[v]){
            unite(x, v);
           // cout <<"unite ";pr(x);prln(v);
        }
    }
}

int dis(int i, int j) {
    return (xx[i] - xx[j])*(xx[i] - xx[j]) + (yy[i] - yy[j])*(yy[i] - yy[j]);
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int n, d, p, q;
    char op[10];
    scanf("%d%d", &n, &d);
    init(n);
    for(int i = 0; i < n; ++i) {
        scanf("%d%d", xx + i, yy + i);
      //  prln(i);
       // pr(xx[i]);prln(yy[i]);
    }
    d = d*d;
   // prln(d);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
          //  pr(i);pr(j);prln(dis(i,j));
            if(dis(i,j) <= d) {
                G[i].push_back(j);
                G[j].push_back(i);
                //pr(i);prln(j);
            }
        }
    }
    for(int i = 0; i < n; ++i) {
           // prln(i);
        for(int j = 0; j < G[i].size(); ++j) {
           // pr(G[i][j]);
        }
   // cout << endl;
    }
    while(scanf("%s", op) == 1){
       // prln(op);
        if(op[0] == 'O') {
            scanf("%d", &p);
            repair(p-1);
        } else {
            scanf("%d%d", &p, &q);
            //pr(x);prln(y);
          //  pr(p);prln(q);
            if(same(p - 1, q - 1)) printf("SUCCESS\n");
            else printf("FAIL\n");
        }
       // print(n);
    }
    return 0;
}
