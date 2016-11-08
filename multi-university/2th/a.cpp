/*************************************************************************
	> File Name: a.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月21日 星期四 20时21分14秒
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
ll gcd(ll x, ll y){
    if(y == 0) return x;
    return gcd(y, x%y);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    ll sum = 0, ssum = 0;
    ll n;
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
        ll x;
        sum = ssum = 0;
        for(int i = 0; i < n; ++i){
            scanf("%lld", &x);
            if(x<0) x=-x;
            sum += x;
            ssum += x*x;
        }
        //prln(ssum);prln(sum);
        ll ans = ssum*n-sum*sum;
        ll temp = gcd(ans, n);
        ans /= temp;
        n /= temp;
        printf("%lld/%lld\n",ans,n);
    }
	return 0;
}
