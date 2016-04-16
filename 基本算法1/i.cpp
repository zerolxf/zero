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
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
char mp[200][200];
int step[200][200], n, m, cnt, ch[200];
int  rr[] = {-1,0,1,0};
int cc[] = {0,1,0,-1};
void dfs(int row, int col) {
    if(mp[row][col] == 0) {
        printf("%d step(s) to exit\n",cnt);
        return;
    } else if(step[row][col]) {
        printf("%d step(s) before a loop of %d step(s)\n",step[row][col]-1, cnt+1-step[row][col]);
        return;
    }
    step[row][col] = ++cnt;
    int dd = ch[mp[row][col]];
    dfs(row+rr[dd],col+cc[dd]);

}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int pos;
    ch['N'] = 0;ch['E'] = 1; ch['S'] = 2; ch['W'] = 3;
    while(scanf("%d%d%d", &n, &m, &pos) != EOF && (n||m||pos)) {
        cnt = 0;
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j <= m; ++j)
                step[i][j] = 0;
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%s", mp[i]+1);
            mp[i][0] = 0;
            mp[i][m+1] = 0;
        }
        for(int i = 0; i <= m+1; ++i) {
            mp[0][i] = 0;
            mp[n+1][i] = 0;
        }
        dfs(1,pos);
    }
    return 0;
}
