/*************************************************************************
	> File Name: e.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月20日 星期三 14时49分55秒
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
const int INF = 0x3f3f3f3f;
int a[100], b[100], c[100];
bool vis[110][110];
struct Slove{
    int head[22], nxt[210], to[210], edgenum;
    int check[22];
    int match[22];
    int left_num, right_num;
    int n;
    void init(int _n){
        n =_n;
        left_num = right_num = n;
        memset(head, -1, sizeof head);
        edgenum = 0;
    }
    void addedge(int u, int v){
        nxt[edgenum] = head[u];
        to[edgenum] = v;
        head[u] = edgenum++;
    }
    bool dfs(int u){
        for(int i = head[u]; ~i; i = nxt[i]){
            int v = to[i];
            if(!check[v]){
                check[v] = true;
                if(match[v] == -1 || dfs(match[v])) {
                    match[u] = v;
                    match[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
    int hungry(){
        int ans = 0;
        memset(match, -1, sizeof match);
        for(int i = 1; i <= left_num; ++i){
            if(match[i] == -1){
                memset(check, 0, sizeof check);
                if(dfs(i)) ++ans;
            }
        }
        return ans;
    }
}solve;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, m;
    int u, v;
    while(cin >> n >> m){
        memset(vis, 0, sizeof vis);
        for(int i = 0; i < m; ++i){
            scanf("%d%d", &u, &v);
            vis[u][v] = true;
        }
        if(n == 0) printf("0\n");
        //else if(n == 1 && m) printf("1\n");
        //else if(n == 1 && !m) printf("0\n");
        if(n < 1) continue;
        int d[] = {1,2,3,4,5,6,7,8,9,10};
        int ans = 0;
        do{
            solve.init(n);
            int temp = d[n];
            d[n] = d[0];
            for(int i = 1; i <= n; ++i)      {
                for(int j = 1; j <= n; ++j){
                    int x = d[j-1];
                    if(!vis[i][x] && !vis[i][d[j]]){
                        //pr(i);prln(x);
                        solve.addedge(i, x+n);
                        solve.addedge(x+n, i);
                    }
                }
            }
            d[n] = temp;
            ans = max(ans, solve.hungry());
            //prln(ans);
        }while(next_permutation(d, d+n-1));
        printf("%d\n", n-ans);
    }
	return 0;
}
