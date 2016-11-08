/*************************************************************************
    > File Name: c.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月07日 星期日 22时34分19秒
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
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
int n, q;
int tyep[maxn], a[maxn];
int head[maxn], nxt[maxn], vis[maxn];
int edgenum;
int cnt[maxn];
int ans;
void addedge(int u){
    nxt[++edgenum] = head[u];
    head[u] = edgenum;
    ans++;
}
void init(){
    memset(head, -1, sizeof head);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(cin >> n >> q){
        init();
        int x, y;
        int first = 1;
        memset(vis,0,sizeof vis);
        memset(cnt,0,sizeof cnt);
        ans = 0;
        for(int i = 0; i<q; ++i){
            scanf("%d%d",&x, &y);
            if(x == 1) {
                addedge(y);
                printf("%d\n",ans);
            }
            else if(x == 2){
                for(int j = head[y]; ~j; j = nxt[j]){
                    if(!vis[j]){
                        ans--;
                    }
                    vis[j] = true;
                }
                head[y] = -1;
                printf("%d\n",ans);
            }else{
                if(first <= y){
                    for(int j = first; j <= y; ++j){
                        if(!vis[j]) {
                            ans--;
                            vis[j] = true;
                        }
                    }
                }
                first = max(y+1,first);
                printf("%d\n",ans);
            }
        }
    }
	return 0;
}
