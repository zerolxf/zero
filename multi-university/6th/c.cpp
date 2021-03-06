/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月04日 星期四 20时22分27秒
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
ll sg(ll x){
    if(x==0) return 0;
    if(x%8==0) return x-1;
    if(x%8==7) return x+1;
    return x;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        ll ans = 0;
        ll x;
        for(int i = 0; i < n; ++i){
            scanf("%lld",&x);
            ans = ans^sg(x);
        }
        if(ans){
            printf("First player wins.\n");
        }else{
            printf("Second player wins.\n");
        }
    }
	return 0;
}
