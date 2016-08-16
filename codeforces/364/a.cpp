/*************************************************************************
	> File Name: a.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月23日 星期六 00时35分08秒
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
vector<int> G[maxn];
bool vis[maxn];
int getid(int x){
    int usize = G[x].size();
    for(int i = 0; i < usize; ++i){
        int v = G[x][i];
        if(vis[v]) continue;
        vis[v] = true;
        return v;
    }
}
int a[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    ll sum, x, n;
    while(cin >> n){
        for(int i = 0; i <= 100; ++i){
            G[i].clear();
            vis[i] = false;
        }
        sum =0;
        //prln(n);
        for(int i = 0; i < n; ++i){
            cin >> x;
            a[i+1] =x;
            //G[x].push_back(i+1);
            sum += x;
        }
        memset(vis, 0, sizeof vis);
        ll ans = sum*2/n;
        //prln(ans);
        for(int i = 1; i <= n; ++i){
            if(!vis[i]){
                for(int j = i+1; j <= n; ++j){
                    if(a[j]+a[i]==ans&&!vis[j]){
                        vis[i] = vis[j] = true;
                        printf("%d %d\n", i, j);
                    }
                }

            }
        }
    }
	return 0;
}
