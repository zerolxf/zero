/*************************************************************************
	> File Name: f.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月05日 星期四 17时16分25秒
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
int a[20];
int des, depth;
int dis[maxn];
bool vis[maxn];
bool dfs(int pos) {
    if(pos > depth) {
        return false;
    }
    bool ok = false;
    if(a[pos] == des) return true;
    if(pos == depth) {
        return a[pos] == des;
    }
    int ma = 1;
    //for(int i = 0; i <= pos; ++i) if(a[i] > ma) ma = a[i];
    if(((a[pos] )<< (depth-pos)) < des)   return false;
    for(int i = 0; i <= pos; ++i){
        a[pos+1] = a[pos] - a[i];
        if(a[pos+1] > 0) {
            ok = dfs(pos+1);
        }
        if(ok) return ok;
        a[pos+1] = a[i] + a[pos];
        if(a[pos+1] > 2*des+1) continue;
        ok = dfs(pos+1);
        if(ok) return ok;
    }
    return false;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);

//	freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, t;
    scanf("%d", &t);
    for(int i = 0; i < 2000; ++i){
        dis[i] = INF;
    }
   dis[0] = 1;
    while(t--) {
        scanf("%d", &n);
        if(dis[n] < INF) {
            printf("%d\n", dis[n]);
            continue;
        }
        a[0] = 1;
        int pos = 0;
        int nn = n;
        while(nn) {
            pos++;
            nn>>=1;
        } 
        pos = max(pos-1,1);
        for(int i = pos;; ++i) {
            des = n;
            depth = i;
            if(dfs(0)){
                printf("%d\n",i);
                dis[n] = i;
                break;
            }
        }
    }
	return 0;
}
