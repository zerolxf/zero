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
const int maxn = 4e5+1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int vis[410][410], cnt[410];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    int n, m;
    while(cin >> n >> m && (n+m) != 0){
        memset(vis, 0, sizeof vis);
        memset(cnt, 0, sizeof cnt);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                scanf("%d", &vis[i][j]);
                if(vis[i][j]) cnt[j]++;
            }
        }
        bool ok = false;
        for(int i = 0; i < n; ++i){
            if(cnt[i] == m) {
                ok = true;
            }
        }
        if(ok) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}

