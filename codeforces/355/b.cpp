/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年06月02日 星期四 00时46分26秒
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

int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, h, k;
    ll ans = 0;
    while(cin >> n >> h >> k){
        int x, last = 0;
        ll ans = 0;
        for(int i = 0; i < n; ++i){
            scanf("%d",&x);
            if(x+last<=h) {
                ans += (x+last)/k;
                last = (x+last)%k;
            }else{
                if(last) ans++;
                ans += x/k;
                last = x%k;
            }
        }
        if(last) ans++;
        cout << ans << "\n";
    }
	return 0;
}
