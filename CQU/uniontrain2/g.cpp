/*************************************************************************
	> File Name: g.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月14日 星期六 20时22分02秒
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
ll ti = 0;
bool vis[50][50];
bool dfs(int a[], int aa, int b[], int bb) {
    if(aa==0){
        for(int i = 0; i < bb; ++i){
            if(b[i] != 0) return false;
        }
        return true;
    }
    bool ok = false;
    int num = a[aa-1];
    for(int i = 0; i < bb; ++i){
        if(num <= b[i] && !vis[b[i]][num]) {
            b[i]-=num;
            b[bb] = num-1;
            if(dfs(a,aa-1,b,bb+1)) return true;
            b[i] += num;
            vis[b[i]][num] = true;
        }
    }
    return false;
}
int num[50];
int c[50];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t, n;
//    scanf("%d", &t);
  //  while(t--){
        scanf("%d",&n);
        memset(vis,0,sizeof vis);
        for(int i = 0; i < n; ++i){
            scanf("%d", &num[i]);
        }
        sort(num, num+n);
        c[0] = num[n-1] - 1;
        if(c[0]>24){
            printf("NO\n");
    //        continue;
        }
        bool ok = dfs(num, n-1, c, 1);
        if(ok) printf("YES\n");
        else printf("NO\n");
   // }
	return 0;
}
