/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月07日 星期六 23时16分03秒
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
int n, m;
int a[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
        cin >> n >> m;
        int x, y;
        int ans = 0;
        bool ok = true;
        int b1 = INF, b2 = 0;
        for(int i = 0; i < m; ++i){
            scanf("%d%d", &x, &y);
            if(x < y) swap(x,y);
            if(a[x] ==2 || a[y] == 1) {
                ok = false;
                break;
            }else {
                b1 = min(b1, x);
                b2 = max(b2,y);
                a[x] = 1;
                a[y] = 2;
            }
        }
        int a1 = 0, a2 = 0;
        if(b1 <= b2) ok = false;
        for(int i = 1; i <= n; ++i){
            if(a[i] == 0 && i >= b2 && i <= b1) ans++;
            else if(a[i] == 1 || i > b1) a1++;
            else a2++;
        }
        if(a1==0) ans--;
        if(a2==0) ans--;
        if(ans < 0 || !ok) {
            printf("0\n");
        } else printf("%d\n", ans+1);
	return 0;
}
