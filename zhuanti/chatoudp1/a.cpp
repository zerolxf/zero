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
const int maxn = 210;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
#define rep(i,n) for(int i = 0; i < n; ++i)
int cnt, state[maxn], num[maxn];
bool link[maxn][maxn];
const int N = 1<<11;
int getnum(int x) {
    int ans = 0;
    while(x) {
        ans++;
        x -= x&(-x);
    }
    return ans;
}
void getstate() {
    cnt = 0;
    for(int i = 0; i < N; ++i) {
        int last = -3;
        bool ok = true;
        for(int j = 0; j < 10; ++j) {
            if(i&(1<<j)) {
                if(j-last > 2) last = j;
                else ok = false;
            }
        }
        if(ok) {
            state[cnt] = i;
            num[cnt++] = getnum(i);
        }
    }
    for(int i = 0; i < cnt; ++i) {
        for(int j = 0; j < cnt; ++j) {
            link[i][j] = false;
            if(state[i]&state[j]) continue;
            link[i][j] = true;
        }
    }
}
int mp[maxn];
int dp[2][maxn][maxn];

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    getstate();
    int n, m;
    char s[15];
    while(scanf("%d%d",&n, &m) != EOF){
        for(int i = 0; i< n; ++i){
            scanf("%s",s);
            mp[i] = 0;
            for(int j = 0; j < m; ++j){
                if(s[j] == 'H') mp[i] = mp[i]*2 +1;
                else mp[i] = mp[i] * 2;
            }
        }
        int now = 0;
        int sz = lower_bound(state,state+cnt,1<<m) - state;
        memset(dp,0,sizeof dp);
        for(int i = 0; i < sz; ++i) {
            if(state[i] & mp[0]) continue;
            dp[now][0][i] = num[i];
        }
        for(int k = 1; k < n; ++k) {
            now = now^1;
            //rep(i,sz) rep(j,sz) dp[now][i][j] = -INF;
            for(int l = 0; l < sz; ++l){
                if(state[l] & mp[k]) continue;
                for(int i = 0; i < sz; ++i) {
                    for(int j = 0; j < sz; ++j) {
                        if(!link[i][j] || !link[i][l] || !link[j][l]) continue;
                        dp[now][j][l] = max(dp[now][j][l], dp[1-now][i][j] + num[l]);
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < sz; ++i){
            for(int j = 0; j < sz; ++j){
                ans = max(ans, dp[now][i][j]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
