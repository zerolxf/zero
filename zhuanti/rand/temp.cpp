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
const double INF = 1e20;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int s[maxn],  n, m, k;
int x[maxn], y[maxn];
double dis[55][55];
double dp[55][maxn];
struct Automate{
    int fail[maxn], ch[maxn][55],  siz, cnt[maxn], root;
    int newnode(){
        cnt[siz] = 0;
        memset(ch[siz], -1, sizeof ch[siz]);
        return siz++;
    }
    void init(){
        siz = 0;
        root = newnode();
    }
    void insert(int s[], int num) {
        int u = root;
        for(int i = 0; i < num; ++i){
            int &v = ch[u][s[i]];
            if(v == -1) v = newnode();
            u = v;
        }
        cnt[u]++;
    }
    void build() {
        queue<int> q;
        int u = root;
        fail[root] = root;
        for(int i = 0; i <= 50; ++i){
            int &v = ch[u][i];
            if(~v) {
                q.push(v);
                fail[v] = root;
            }else v = root;
        }
        while(q.size()){
            u =  q.front();q.pop();
            cnt[u] |= cnt[fail[u]];
            for(int i = 1; i <= 50; ++i){
                int &v = ch[u][i];
                if(~v) {
                    q.push(v);
                    fail[v] = ch[fail[u]][i];
                }else v = ch[fail[u]][i];
            }
        }
    }
    void slove(){
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j < siz; ++j){
                dp[i][j] = INF;
            }
        }
        dp[1][ch[root][1]] = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < siz; ++j){
                if(dp[i][j] < INF){
                    for(int k = i+1; k <= n; ++k){
                        int nxt = ch[j][k];
                        if(cnt[nxt]) continue;
                        dp[k][nxt] = min(dp[k][nxt], dp[i][j]+dis[i][k]);
                    }

                }
            }
        }
        double ans = INF;
        for(int i = 0; i < siz; ++i){
            ans = min(ans, dp[n][i]);
        }
        if(ans>=INF) printf("Can not be reached!\n");
        else printf("%.2f\n",ans);
    }
}ac;

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    while(cin >> n >> m && (n+m) != 0){
        ac.init();
        for(int i = 1; i <= n; ++i){
            scanf("%d%d", &x[i], &y[i]);
        }
        memset(dis,0,sizeof dis);
        for(int i = 1; i <= n; ++i){
            for(int j = i; j <= n; ++j){
                dis[i][j] = dis[j][i] = sqrt((double)(x[i]*1.0-x[j])*(x[i]*1.0-x[j]) +(double)(y[i]*1.0-y[j])*(y[i]*1.0-y[j]));
            }
        }
        for(int i = 0; i < m; ++i){
            scanf("%d", &k);
            for(int j = 0; j < k; ++j){
                scanf("%d", &s[j]);
                ac.insert(s, k);
            }
        }
        ac.build();
        ac.slove();
    }
    return 0;
}
