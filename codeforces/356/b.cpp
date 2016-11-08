/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年06月09日 星期四 00时49分45秒
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
int cnt[maxn], a[maxn], n, x, c[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(cin >> n >> x){
        memset(cnt, 0, sizeof cnt);
        memset(c,0,sizeof c);
        int y;
        for(int i = 1; i <= n; ++i){
            cin >> y;
            cnt[abs(i-x)]+=y;
        }
        for(int i = 1; i <= n; ++i){
            c[abs(i-x)]++;
        }
        int ans = 0;
        for(int i = 0; i <= n; ++i){
            if(c[i]>0&&c[i]==cnt[i]) ans += c[i];
        }
        printf("%d\n",ans);
    }
	return 0;
}
