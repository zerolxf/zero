/*************************************************************************
	> File Name: k.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月05日 星期五 15时49分28秒
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
int ff[] = {-2, 0, 2};
const int INF = 0x3f3f3f3f;
ll dp[64][16][4][4];
ll p[5];
int fun(int a, int f){
    if(f >= 3) return 3;
    int rs = a+ff[f];
    if(rs<-1) return -1;
    if(rs>1) return 3;
    return rs+1;
}
const int MOD = 1e9+7;
// a+c-b-d >0
// a+d-b-c>0
//f1 ->  a+c-b-d 
//f2 ->  a+d-b-c
ll dfs(int pos, int mask, int f1, int f2){
    if(pos == -1){
        if(f1 >= 2 && f2 >= 1) return 1;
        return 0;
    }
    if(dp[pos][mask][f1][f2] != -1) return dp[pos][mask][f1][f2];
    ll ed[4], &ans = dp[pos][mask][f1][f2] = 0;
    for(int i = 0; i < 4; ++i){
        ed[i] = (mask>>i)&1 ? 1 : (p[i]>>pos)&1;
    }
    rep(i,ed[0]+1){
        rep(j, ed[1]+1){
            rep(k, ed[2]+1){
                rep(l, ed[3]+1){
                    int newmask = mask;
                    if(i^ed[0]) newmask |= 1;
                    if(j^ed[1]) newmask |= 2;
                    if(k^ed[2]) newmask |= 4;
                    if(l^ed[3]) newmask |= 8;
                    int ff1 = fun(i+k-j-l,f1), ff2 = fun(i+l-j-k,f2);
                    if(ff1 == -1 || ff2== -1) continue;
                    ans += dfs(pos-1, newmask, ff1, ff2);
                    if(ans > MOD) ans -= MOD;
                }
            }
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
    scanf("%d", &t);
    while(t--){
        memset(dp,-1,sizeof dp);
        scanf("%lld%lld%lld%lld", &p[0], &p[1], &p[2], &p[3]);
        ll ans = dfs(61, 0, 1, 1);
        ans = (ans%MOD+MOD)%MOD;
        printf("%lld\n",ans);  
    }
	return 0;
}
