/*************************************************************************
	> File Name: g.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月15日 星期五 14时55分23秒
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
    if(y==0) return x;
    return gcd(y, x%y);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    cin >> t;
    while(t--){
        ll h , w, d;
        cin >> h >> w >> d;
        w--;h--;
        d--;
        bool ok = false;
        ll a = (h-d);
        if(a<=0) a = -a;
        if(a%(__gcd(2*w,2*h))==0) ok = true;
        ll dd = 2*w-d;
        a = (h-dd);
        if(a<=0) a = -a;
        if(a%(__gcd(2*w,2*h))==0) ok = true;
        if(ok) printf("Yes\n");
        else printf("No\n");
    }

	return 0;
}
