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
const int maxn = 1 << 16 + 10;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x << "\n";
#define ll long long


int num[20], r[maxn], c[maxn], q[maxn<<2], d[maxn];
bool in[maxn], done[maxn];
int getnum(int x, int y) {
    int ans = 0;
    for(int i = y-1; i < 16; i += 4) ans = ans | (1<<i);
    for(int i = (x-1)*4; i < x*4; i++) ans = ans | (1<<i);
    return ans;
}
void init() {
    for(int i = 1; i <= 4; ++i) {
        for(int j = 1; j <= 4; ++j) {
            num[(i-1)*4+j] = getnum(i,j);
        }
    }
}
void getdis() {
    init();
    for(int i = 0; i < maxn; ++i) {
        in[i] = 0;
        d[i] = INF;
    }
    d[0] = 0; in[0] = 1;
    int s = 0, e = 0;
    q[++e] = 0;
    int u, v;
    while(s < e) {
        u = q[++s]; in[u] = 0;
        if(done[u]) continue;
        done[u] = 1;
        for(int i = 1; i <= 4; ++i) {
            for(int j = 1; j <= 4; ++j) {
                v = u^num[(i-1)*4+j];
                if(!done[v])
                if(d[v] > d[u] + 1) {
                    d[v] = d[u] + 1;
                    r[v] = i; c[v] = j;
                    if(!in[v]) {
                        q[++e] = v; in[v] = 1;
                    }
                }
            }
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    char mp[10];
    int ans, x, y, pos = 0;
    getdis();
    ans = 0;
    for(int i = 0; i < 4; ++i) {
        scanf("%s", mp);
        for(int j = 0; j < 4; ++j){
            if(mp[j] == '+') pos = pos + (1 << ((i*4)+j));
        }
    }
    ans = d[pos];
    printf("%d\n", ans);
    while(ans--) {
        x = r[pos];
        y = c[pos];
        printf("%d %d\n", x, y);
        pos = pos ^ num[(x-1)*4+y];
    }
    return 0;
}
