/*************************************************************************
	> File Name: a.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月07日 星期六 23时04分12秒
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
int x[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    cin >> n;
        int last = 0;
        int ans = 0;
        for(int i = 0; i < n; ++i){
            scanf("%d", &x[i]);
            if(x[i]-last>15) {
                ans = last+15;
                break;
            }
            last = x[i];
        }
        if(!ans) ans = x[n-1]+15;
        ans = min(ans, 90);
        cout << ans << "\n";
	return 0;
}
