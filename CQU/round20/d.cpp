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
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
#define rep(i,n) for(int i = 0; i < n; ++i)
int dp[15][1<<14];
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
int ds[15][210][210], d[20][20], mp[200][200];
int x[30], y[30], mindis[30];
bool in[210][210];
int n, m, k;
void spfa(int s, int (*dis)[210]){
    mindis[s] = INF;
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= m; ++j){
            dis[i][j] = INF;
            in[i][j] = false;
        }
    }
     if(mp[y[s]][x[s]] < 0) return;
    queue<int> q;
    mindis[s] = INF;
    q.push(y[s]*1000+x[s]);
    in[y[s]][x[s]] = true;
    dis[y[s]][x[s]] = 0;
    while(q.size()) {
        int qx = q.front(); q.pop();
        int r = qx/1000, c = qx%1000;
        in[r][c] = false;
        if(r == 1 || r == n || c == 1 || c == m){
            mindis[s] = min(mindis[s], dis[r][c] + mp[y[s]][x[s]]);
        }
        for(int i = 0; i < 4; ++i){
            int rr = r + dy[i];
            int cc = c + dx[i];
            if(rr < 1 || rr > n || cc < 1 || cc > m) continue;
            if(mp[rr][cc] < 0) continue;
            if(dis[rr][cc] > dis[r][c] + mp[rr][cc]){
                dis[rr][cc] = dis[r][c] + mp[rr][cc];
                if(!in[rr][cc]) {
                    q.push(rr*1000+cc);
                    in[rr][cc] = true;
                }
            }
        }
    }
}
int dfs(int pos, int s) {
    int& ans = dp[pos][s];
    if(ans != INF) return ans;
    s = s^(1<<pos);
    for(int i = 0; i < k; ++i){
        if((1<<i)&s){
            if(d[pos][i] == INF) continue;
            ans = min(ans, dfs(i, s) + d[i][pos]);
        }
    }
    return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int t, kase = 0;
    scanf("%d",&t);
    while(t--){
        memset(dp,0x3f,sizeof dp);
        memset(d,0x3f,sizeof d);
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                scanf("%d",&mp[i][j]);
            }
        }
        scanf("%d",&k);
        for(int i = 0; i < k; ++i){
            scanf("%d%d",&y[i], &x[i]);
            x[i]++;y[i]++;
        }
        for(int i = 0; i < k; ++i){
            spfa(i, ds[i]);
        }
        for(int i = 0; i < k; ++i){
            for(int j = 0; j < k; ++j){
                if(i == j) d[i][j] = 0;
                else d[i][j] = ds[i][y[j]][x[j]];
            }
        }
        for(int i = 0; i < k; ++i) {
            dp[i][1<<i] = mindis[i];
        }
        int ans = INF;
        for(int i = 0; i< k; ++i){
            int temp = dfs(i,(1<<k)-1) + mindis[i] - mp[y[i]][x[i]];
            ans = min(ans, temp);
        }
        if(ans == INF) printf("0\n");
        else printf("%d\n",ans);
    }
    return 0;
}
