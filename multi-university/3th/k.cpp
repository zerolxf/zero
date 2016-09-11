/*************************************************************************
	> File Name: k.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月26日 星期二 19时27分14秒
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
int x[maxn], y[maxn], vis[maxn];
int get(int i, int j){
    return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

    int t;
    cin >> t;
    while(t--){
        int n, m;
        scanf("%d%d",&n, &m);
        bool ok =false;
        for(int i = 0; i < n; ++i){
            scanf("%d%d", &x[i], &y[i]);
            //pr(x[i]);prln(y[i]);
        }
        memset(vis, 0, sizeof vis);
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                int k = get(i,j);
                //pr(i);pr(j);prln(k);
                if(vis[k]) {
                    ok = true;
                    break;
                }
                vis[k] = true;
            }
            if(ok) break;
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}
