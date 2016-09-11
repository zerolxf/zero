/*************************************************************************
    > File Name: d.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月09日 星期二 20时06分07秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,j) memset(a,j,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 1e6+10;
const int INF = 0x3f3f3f3f;
bool vis[maxn];
int pp[maxn][22];
int pcnt;
int prime[maxn];
int a[maxn];
int cnta;
void getprime(){
    pcnt = 0;
    prime[1] = 0;
    a[cnta++] = 1;
    for(int i = 2; i < maxn; ++i){
        if(vis[i]) continue;
        a[cnta++] = i;
        for(int j = i; j < maxn; j += i){
            vis[j] = true;
            int jj = j;
            while(jj%i == 0){
                prime[j]++;
                jj /= i;
            }
        }
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    int kase = 0;
    char op[10];
    int x;
    cnta = 0;
    pcnt = 0;
    getprime();
    while(scanf("%d", &n) != EOF){
        if(n==0) break;
        memset(pp,0,sizeof pp);
        memset(vis,0,sizeof vis);
        printf("Case #%d:\n",++kase);
        for(int i = 0; i < n; ++i){
            scanf("%s%d",  op, &x);
            if(op[0] == 'I'){
                if(vis[x]) continue;
                vis[x] = true;
                int ma = sqrt(x+0.5);
                for(int j = 1; j <= ma; ++j){
                    if(x%j) continue;
                    pp[j][prime[x/j]]++;
                    pp[x/j][prime[j]]++;
                }
            }else if(op[0] == 'D'){
                if(!vis[x]) continue;
                vis[x] = false;
                int ma = sqrt(x+0.5);
                for(int j = 1; j <= ma; ++j){
                    if(x%j) continue;
                    pp[j][prime[x/j]]--;
                    pp[x/j][prime[j]]--;
                }
            }else{
                int ans = INF;
                int ma = sqrt(x+0.5);
                for(int j = 1; j <= ma; ++j){
                    if(x%j) continue;
                    for(int k = 0; k <= 20; ++k){
                        if(pp[j][k])ans = min(prime[x/j]+k, ans);
                        if(pp[x/j][k])ans = min(prime[j]+k, ans);
                    }
                }
                if(ans == INF){
                    printf("-1\n");
                }else printf("%d\n",ans);
            }
        }

    }

	return 0;
}
