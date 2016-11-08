/*************************************************************************
	> File Name: i.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月21日 星期四 22时59分49秒
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
bool vis[maxn];
int a[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t, n, m;
    scanf("%d", &t);
    while(t--){
        memset(vis, 0, sizeof vis);
        memset(a, 0, sizeof a);
        scanf("%d%d", &n, &m);
        int x, y;
        for(int i = 0; i < m; ++i){
            scanf("%d%d", &x, &y);
            vis[x] = true;
            a[x] = y;
            for(int j = 1; j <= x; ++j){
                a[j] = max(a[j], y);
            }
        }
        if(!vis[1]) a[1] = 100;
        if(!vis[2]) a[2] = min(100, a[1]);
        x = a[1]; y= a[2];
        int sum = 0;
        for(int i = 1; i <= n; ++i){
            sum += a[i];
        }
        //prln(sum);
        int ans = x+y;
        int temp = __gcd(ans, sum);
        //prln(temp);
        ans /= temp;
        sum /= temp;
        //for(int i = 1; i <= n; ++i){
            //pr(i);prln(a[i]);
        //}
        printf("%d/%d\n", ans, sum);
    }
	return 0;
}
