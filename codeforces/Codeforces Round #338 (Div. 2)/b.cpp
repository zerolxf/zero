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
const long long INF = 0x3f3f3f3f;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
ll num[maxn], ans, u, v;
vector<int> G[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, m;
    while(cin >> n >> m) {
        for(int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        ans = 0;
        for(int i = 1; i <= n; ++i) {
            num[i] = 1;
            for(int j = 0; j < G[i].size(); ++j) {
                v = G[i][j];
                if(v < i) {
                    num[i] = max(num[i], num[v]+1);
                }
            }
            ans = max(ans,num[i]*G[i].size());
        }
        printf("%lld\n", ans);
    }
    return 0;
}
