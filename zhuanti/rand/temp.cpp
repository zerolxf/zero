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
<<<<<<< HEAD
const int maxn = 1e4+100;
=======
const int maxn = 1e3+100;
>>>>>>> d7101ef5dea836d78175db40a41e2c508c4f943b
const double INF = 1e20;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
<<<<<<< HEAD
int s[maxn],  n, m, k;
int x[maxn], y[maxn];
=======
int s[maxn],  n, m;
double x[maxn], y[maxn];
>>>>>>> d7101ef5dea836d78175db40a41e2c508c4f943b
double dis[55][55];
double dp[55][maxn];
struct Automate{
    int fail[maxn], ch[maxn][55],  siz, cnt[maxn], root;
    int newnode(){
        cnt[siz] = 0;
        memset(ch[siz], -1, sizeof ch[siz]);
<<<<<<< HEAD
        return siz++;
=======
        for(int i = 1; i <= n;++i){
            ch[siz][i] = -1;
        }
        siz++;
        return siz-1;
>>>>>>> d7101ef5dea836d78175db40a41e2c508c4f943b
    }
    void init(){
        siz = 0;
        root = newnode();
    }
    void insert(int s[], int num) {
        int u = root;
        for(int i = 0; i < num; ++i){
<<<<<<< HEAD
            int &v = ch[u][s[i]];
            if(v == -1) v = newnode();
            u = v;
        }
        cnt[u]++;
=======
            int v = ch[u][s[i]];
            if(v == -1) ch[u][s[i]] = newnode();
            u = ch[u][s[i]];
        }
        cnt[u] = 1;
>>>>>>> d7101ef5dea836d78175db40a41e2c508c4f943b
    }
    void build() {
        queue<int> q;
        int u = root;
        fail[root] = root;
<<<<<<< HEAD
        for(int i = 0; i <= 50; ++i){
            int &v = ch[u][i];
            if(~v) {
                q.push(v);
                fail[v] = root;
            }else v = root;
=======
        for(int i = 1; i <= n; ++i){
            int &v = ch[u][i];
            if(v!=-1) {
                q.push(v);
                fail[ch[u][i]] = root;
            }else ch[u][i] = root;
>>>>>>> d7101ef5dea836d78175db40a41e2c508c4f943b
        }
        while(q.size()){
            u =  q.front();q.pop();
            cnt[u] |= cnt[fail[u]];
<<<<<<< HEAD
            for(int i = 1; i <= 50; ++i){
                int &v = ch[u][i];
                if(~v) {
                    q.push(v);
                    fail[v] = ch[fail[u]][i];
                }else v = ch[fail[u]][i];
=======
            for(int i = 1; i <= n; ++i){
                int &v = ch[u][i];
                if(v!=-1) {
                    q.push(v);
                    fail[ch[u][i]] = ch[fail[u]][i];
                }else ch[u][i] = ch[fail[u]][i];
>>>>>>> d7101ef5dea836d78175db40a41e2c508c4f943b
            }
        }
    }
    void slove(){
        for(int i = 0; i <= n; ++i){
<<<<<<< HEAD
            for(int j = 0; j < siz; ++j){
=======
            for(int j = 0; j <= siz; ++j){
>>>>>>> d7101ef5dea836d78175db40a41e2c508c4f943b
                dp[i][j] = INF;
            }
        }
        dp[1][ch[root][1]] = 0;
<<<<<<< HEAD
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < siz; ++j){
                if(dp[i][j] < INF){
                    for(int k = i+1; k <= n; ++k){
                        int nxt = ch[j][k];
                        if(cnt[nxt]) continue;
                        dp[k][nxt] = min(dp[k][nxt], dp[i][j]+dis[i][k]);
=======
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < siz; ++j){
                if(dp[i][j] < INF){
                    for(int k = i+1; k <= n; ++k){
                        int ss = ch[j][k];
                        if(cnt[ss]) continue;
                        dp[k][ss] = min(dp[k][ss], dp[i][j]+dis[i][k]);
>>>>>>> d7101ef5dea836d78175db40a41e2c508c4f943b
                    }

                }
            }
        }
        double ans = INF;
        for(int i = 0; i < siz; ++i){
<<<<<<< HEAD
            ans = min(ans, dp[n][i]);
        }
        if(ans>=INF) printf("Can not be reached!\n");
=======
            if(dp[n][i] < INF)
            ans = min(ans, dp[n][i]);
        }
        if(ans==INF) printf("Can not be reached!\n");
>>>>>>> d7101ef5dea836d78175db40a41e2c508c4f943b
        else printf("%.2f\n",ans);
    }
}ac;

int main(){
<<<<<<< HEAD
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
=======
    while(cin >> n >> m ){
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
>>>>>>> d7101ef5dea836d78175db40a41e2c508c4f943b
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
