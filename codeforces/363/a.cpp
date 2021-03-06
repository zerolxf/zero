/*************************************************************************
	> File Name: a.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月19日 星期二 20时59分47秒
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

    char s[maxn];
    int a[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

    int n;
    while(cin >> n){
        scanf("%s", s+1);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        int ans = INF;
        for(int i = 2; i <= n; ++i){
            if(s[i] != s[i-1] && s[i] == 'L'){
                ans = min(ans,(a[i]-a[i-1])/2);
            }
        }
        if(ans == INF){
            printf("-1\n");
        }else cout << ans << "\n";
    }
	return 0;
}
