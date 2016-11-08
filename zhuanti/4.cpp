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
const int maxn = 1e7+1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int vis[maxn];
int a[maxn];
bool viss[maxn];
int N ;
int sum[maxn];
int cnt;
bool dfs(int pos){
    if(cnt>1) return false;
  //  prln(pos);
  //  prln(cnt);
    if(pos == N+1){
        for(int i = 1; i <= N; ++i){
            cout << a[i] << " ";
        }
        prln("xx");
        cnt++;
        return true;
    }

    for(int i = 1; i <= 3*N+17; ++i){
        bool ok = true;
        sum[pos] = sum[pos-1] + i;
       // if(vis[i]) continue;

      //  prln(i);
        for(int j = 0; j < pos; ++j){
            int ss = sum[pos] - sum[j];
        //    prln(ss);
        //    prln(viss[ss]);
            if(viss[ss]) ok = false;
        }
        //prln(ok);
        if(!ok){

            continue;
        }else{
            for(int j = 0; j < pos; ++j){
            int ss = sum[pos] - sum[j];
            viss[ss] = true;
            }

          //  prln(pos);
            a[pos] = i;
            vis[i] = true;
            viss[sum[pos]] = true;
            if(dfs(pos+1)) {

            }
            for(int j = 0; j < pos; ++j){
                int ss = sum[pos] - sum[j];
                viss[ss] = false;
            }
            a[pos] = i;
            viss[sum[pos]] = false;
        }
    }
    return false;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    N = 40;
    sum[0] = 0;
    memset(vis, 0, sizeof vis);
    memset(viss, 0, sizeof viss);
    dfs(1);
    return 0;
}
