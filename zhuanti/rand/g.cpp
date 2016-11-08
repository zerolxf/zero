
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
const int maxn = 1e3+100;
const double INF = 1e20;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int s[maxn],  n, m;
double x[maxn], y[maxn];
double dis[55][55];
double dp[55][maxn];
struct Automate{
    int fail[maxn], ch[maxn][55],  siz, cnt[maxn], root;
    int newnode(){
        cnt[siz] = 0;
        memset(ch[siz], -1, sizeof ch[siz]);
        for(int i = 1; i <= n;++i){
            ch[siz][i] = -1;
        }
        siz++;
        return siz-1;
    }
    void init(){
        siz = 0;
        root = newnode();
    }
    void insert(int s[], int num) {
        int u = root;
        for(int i = 0; i < num; ++i){
            int v = ch[u][s[i]];
            if(v == -1) ch[u][s[i]] = newnode();
            u = ch[u][s[i]];
        }
        cnt[u] = 1;
    }
    void build() {
        queue<int> q;
        int u = root;
        fail[root] = root;
        for(int i = 1; i <= n; ++i){
            int &v = ch[u][i];
            if(v!=-1) {
                q.push(v);
                fail[ch[u][i]] = root;
            }else ch[u][i] = root;
        }
        while(q.size()){
            u =  q.front();q.pop();
            cnt[u] |= cnt[fail[u]];
            for(int i = 1; i <= n; ++i){
                int &v = ch[u][i];
                if(v!=-1) {
                    q.push(v);
                    fail[ch[u][i]] = ch[fail[u]][i];
                }else ch[u][i] = ch[fail[u]][i];
            }
        }
    }
    void slove(){
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= siz; ++j){
                dp[i][j] = INF;
            }
        }
        dp[1][ch[root][1]] = 0;
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < siz; ++j){
                if(dp[i][j] < INF){
                    for(int k = i+1; k <= n; ++k){
                        int ss = ch[j][k];
                        if(cnt[ss]) continue;
                        dp[k][ss] = min(dp[k][ss], dp[i][j]+dis[i][k]);
                    }

                }
            }
        }
        double ans = INF;
        for(int i = 0; i < siz; ++i){
            if(dp[n][i] < INF)
            ans = min(ans, dp[n][i]);
        }
        if(ans==INF) printf("Can not be reached!\n");
        else printf("%.2f\n",ans);
    }
}ac;

int main(){
    while(scanf("%d%d", &n, &m) == 2 ){
        if(n==0&&m==0) break;
        ac.init();
        for(int i = 1; i <= n; ++i){
//            scanf("%lf%lf", &x[i], &y[i]);
            cin >> x[i] >> y[i];
        }
        int k;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                dis[i][j] =  sqrt((double)(1.0*x[i]*1.0-x[j])*(1.0*x[i]*1.0-x[j]) +(double)(1.0*y[i]*1.0-y[j])*(1.0*y[i]*1.0-y[j]));
            }
        }
        for(int i = 0; i < m; ++i){
            scanf("%d", &k);
            for(int j = 0; j < k; ++j){
                scanf("%d", &s[j]);
                
            }
ac.insert(s, k);
        }
        ac.build();
        ac.slove();
    }
    return 0;
}
