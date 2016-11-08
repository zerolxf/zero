/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年07月03日 星期日 13时34分33秒
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
#define pr(x) //cout << #x << " = " << x << " ";
#define prln(x)// cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;

int num[][3] = {{2,1,0},{1,2,0},{1,1,1}};
int cost[10][5]; 
int tempsum[10];
inline void add(int asum[], int bsum[], int d, int e){
    for(int i = 0; i < 3; ++i) asum[i] = bsum[i] + cost[d][i]*e;
}
inline void del(int asum[], int bsum[], int d, int e){
    for(int i = 0; i < 3; ++i) asum[i] = bsum[i] - cost[d][i]*e;
}
inline bool check(int nowsum[], int d, int e){
    add(tempsum, nowsum, d, e);
    for(int i = 0; i < 3; ++i){
        if(tempsum[i]>tempsum[(i+1)%3]+tempsum[(i+2)%3]+1) return false;
    }
    return true;
}
int initnum[10];
int dfs(int has[]){
    int ans = 0;
    for(int i = 0; i < 8; ++i){
        int ma = 12345678;
        if(cost[i][3] < 1) continue;
        for(int j = 0; j < 3; ++j){
            if(cost[i][j]) {
                ma = min(ma, initnum[j]/cost[i][j]);
            }
        }
        if(ma==0||ma==12345678) continue;
        if(!check(has, i, ma)) continue;
        del(initnum, initnum, i, ma);
        /*if(initnum[0]<0||initnum[1]<0||initnum[2]<0) {
            add(initnum, initnum, i, ma);
            continue;
        }*/
        for(int j = 0; j < 3; ++j){
            if(i&(1<<j)) has[j] += ma;
        }
        ans = max(ans, dfs(has)+ma*cost[i][3]);
        add(initnum, initnum, i, ma);
        for(int j = 0; j < 3; ++j){
            if(i&(1<<j)) has[j] -= ma;
        }
    }
    return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    int s = 8;
    int ans = 0;
    memset(cost,0,sizeof cost);
    for(int i = 0; i < s; ++i){
        for(int j = 0; j < 3; ++j){
            if(i&(1<<j)){
                cost[i][3]++;
                for(int k = 0; k < 3; ++k){
                   cost[i][k] += num[j][k]; 
                }
            }
        } 
    }
    scanf("%d", &t);
    while(t--){
        ans = 0;
        int has[5];
        for(int i = 0; i < 5; ++i) has[i] = 0;
        for(int i = 0; i < 3; ++i){
            scanf("%d", &initnum[i]);
        }
        ans = dfs(has);
        if(initnum[0]>=2&&initnum[1]>=1){
            del(initnum, initnum, 1, 1);
            ans = max(ans,dfs(has)+1);
            add(initnum, initnum, 1, 1);
        }

        if(initnum[0]>=1&&initnum[1]>=2){
            del(initnum, initnum, 2, 1);
            ans = max(ans,dfs(has)+1);
            add(initnum, initnum, 2, 1);
        }
        if(initnum[0]>=1&&initnum[1]>=1&&initnum[2]>=1){
            del(initnum, initnum, 4, 1);
            ans = max(ans,dfs(has)+1);
            add(initnum, initnum, 4, 1);
        }
        printf("%d\n",ans);
    }
	return 0;
}
