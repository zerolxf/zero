/*************************************************************************
	> File Name: d.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月08日 星期日 00时06分18秒
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
int ans[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, k;
    cin >> n >> k;
    bool ok = true;
    if(n==4 || k < n+1) ok = false;
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    ans[1] = a; ans[2] = c;ans[4] = d;ans[n] = b;
    int p = 1;
    for(int i = 1; i <= n; ++i){
        if(i!=a&&i!=b&&i!=c&&i!=d){
            while(p <= n && ans[p]) p++;
            if(p<=n) ans[p] = i;
        }
    }
    if(ok) {
        for(int i = 1; i <= n; ++i){
            printf("%d ", ans[i]);
        }
        printf("\n");
        printf("%d %d %d ",ans[2], ans[1], ans[3]);
        for(int i = n; i >= 4; --i) {
            printf("%d ",ans[i]);
        }
        printf("\n");
    } else printf("-1\n");
	return 0;
}
