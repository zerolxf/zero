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
const int maxn = (1 << 16) + 10;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
int d[maxn], q[maxn<<1], num[20];
bool in[maxn];
int getnum(int x, int y) {
    int ans = 0;
    for(int i = max(1,y-1); i <= min(4,y+1); ++i) ans = ans | (1<<((x-1)*4+i-1));
    for(int i = max(1,x-1); i <= min(4,x+1); ++i) ans = ans | (1<<((i-1)*4+y-1));
    return ans;
}
void initnum() {
    for(int i = 1; i <= 4; ++i) {
        for(int j = 1; j <= 4; ++j) {
            num[(i-1)*4+j] = getnum(i,j);
        }
    }
}
void spfa() {
    initnum();
    for(int i = 0; i < maxn; ++i) {
        d[i] = INF;
        in[i] = 0;
    }
    d[0] = 0; in[0] = true;
    int s, e, u, v;
    s = e = 0;
    q[++e] = 0;
    while(s < e) {
        u = q[++s]; in[u] = 0;
        for(int i = 1; i <= 4; ++i) {
            for(int j = 1; j <= 4; ++j) {
                v = u ^ num[(i-1)*4+j];
                if(d[v] > d[u] + 1) {
                    d[v] = d[u] + 1;
                    if(!in[v]) {
                        q[++e] = v;
                        in[v] = true;
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
    int ans, pos1, pos2;
    pos1 = pos2 = 0; ans = INF;
    spfa();
    for(int i = 0; i < 4; ++i) {
        scanf("%s", mp);
        for(int j = 0; j < 4; ++j) {
            if(mp[j] == 'w') pos1 += (1 << (i*4+j));
        }
    }
    pos2 = (1 << 16) - 1 - pos1;
    ans = min(d[pos1], d[pos2]);
    if(ans != INF)  printf("%d\n", ans);
    else printf("Impossible\n");
    return 0;
}
