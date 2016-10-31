/*************************************************************************
    > File Name: 1685.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月31日 星期一 11时47分54秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <ctime>


using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define repp(i,n,x) for(int i =x; i < n+x; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
int n;
struct BIT{
    ll c[2][maxn];
    int N = 0, offset = 0;
    void init(){
        memset(c, 0, sizeof c);
        N = 2*n+1;
        offset = n+1;
    }
    void add(int o, int x){
        x = offset + x;
        for(int i = x; i <= N; i += i&(-i)){
            c[o][i] += 1;
        }
    }

    ll sum(int o, int x){
        x = offset + x;
        ll ans = 0;
        for(int i = x; i > 0; i-= i&(-i)){
            ans += c[o][i];
        }
        return ans;
    }
}bit;
ll a[maxn];
ll binarysearch(ll num){
    ll ans = 0;
    int e = 0;
    bit.init();
    bit.add(0,0);
    for(int i = 1; i <= n; ++i){
        if(a[i]<num) --e;
        else ++e;
        bit.add(i&1, e);
        ans += bit.sum((i&1)^1,e-1);
    }
    return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    ll k;
    while(scanf("%d%lld",&n, &k) != EOF){
        for(int i = 1; i <= n; ++i){
            scanf("%lld", &a[i]);
        }
        ll l = 0, r = ((ll)1<<31);
        while(l < r){
            ll mid = (l+r+1) >> 1;
            if(binarysearch(mid) >= k) l = mid;
            else r = mid-1;
        }
        printf("%lld\n",l);
    }

	return 0;
}
