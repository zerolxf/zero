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
const int maxn = 1e4+100;
const long long INF = 0x3f3f3f3f;
#define pr(x) //cout << #x << " = " << x << " ";
#define prln(x) //cout << #x << " = " << x <<endl;
#define ll long long
int vis[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, m, v, num;
    bool ok = true;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num);
        for(int j = 0; j < num; ++j) {
            scanf("%d", &v);
            vis[v] = 1;
        }
    }
    for(int i = 1; i <= m; ++i) {
        if(!vis[i]) ok = false;
    }
    if(ok) printf("YES\n");
    else printf("NO\n");
    return 0;
}
