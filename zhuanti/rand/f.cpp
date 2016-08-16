/*************************************************************************
	> File Name: f.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年07月13日 星期三 01时46分26秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const double INF = 1e18;

int n;
double dis[55][55], dp[55][1000];
int x[maxn], y[maxn];
void getdis(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            dis[i][j] = sqrt((double)(1.0*x[i]-x[j])*(1.0*x[i]-x[j]) + (double)(1.0*y[i]-y[j])*(1.0*y[i]-y[j]));
        }
    }
}
struct Ac{
    int next[1000][55], fail[1000], end[1000];
    int L, root;
    int newnode(){
        for(int i = 1; i <= n; ++i){
            next[L][i] = -1;
        }
        end[L++] = 0;
        return L-1;
    }
    void init(){
        L = 0;
        root = newnode();
    }

    void insert(int a[], int cnt){
        int now = root;
        for(int i = 0; i < cnt; ++i){
            if(next[now][a[i]] == -1) next[now][a[i]] = newnode();
            now = next[now][a[i]];
        }
        end[now] = 1;
    }
    void build(){
        queue<int> q;
        fail[root] = root;
        for(int i = 1; i <= n; ++i){
            if(next[root][i] == -1){
                next[root][i] = root;
            }else{
                fail[next[root][i]] = root;
                q.push(next[root][i]);
            }
        }
        while(q.size()){
            int now = q.front(); q.pop();
            end[now] |= end[fail[now]];
            for(int i = 1; i <= n; ++i){
                if(next[now][i] == -1) next[now][i] = next[fail[now]][i];
                else{
                    fail[next[now][i]] = next[fail[now]][i];
                    q.push(next[now][i]);
                }
            }
        }
    
    }
    void slove(){
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < L; ++j){
                dp[i][j] = INF;
            }
        }
        dp[1][next[root][1]] = 0;
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < L; ++j){
                if(dp[i][j] < INF){
                    for(int k = i+1; k <= n; ++k){
                        int ss = next[j][k];
                        if(end[ss]) continue;
                        dp[k][ss] = min(dp[k][ss], dp[i][j] + dis[i][k]);
                    }
                }
            }
        }
        double ans = INF;
        for(int i = 0; i < L; ++i){
            ans = min(ans, dp[n][i]);
        }
        if(ans == INF) printf("Can not be reached!\n");
        else printf("%.2f\n",ans);
    }
}ac;
int a[10];

int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int m;
    while(scanf("%d%d", &n, &m) == 2){
        if(n==0 && m == 0) break;
        for(int i = 1; i <= n; ++i){
            scanf("%d%d", &x[i],&y[i]);
        }
        getdis();
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
//                pr(i);pr(j);prln(dis[i][j]);
            }
        }
        ac.init();
        int k;
        while(m--){
            scanf("%d", &k);
            for(int i = 0; i < k; ++i){
                scanf("%d", &a[i]);
            }
            ac.insert(a, k);
        }
        ac.build();
        ac.slove();
    }
	return 0;
}
