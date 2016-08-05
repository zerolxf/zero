/*************************************************************************
	> File Name: j.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月04日 星期四 19时48分57秒
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
ll p, q;
int dfs(ll x, ll ma, ll k){
    if(x<=0) return max(q-k,(ll)0);
    //if(x == 0) return 0;
    //prln(x);
    ll ans1 = 0, ans2 = 0;
    if(x-q >= ma) {
        ans1 =  dfs(x-ma, ma*2, k)+1;
        return ans1;
    }
    else{
        if(x<=q) return max(q-x-k,(ll)0);
        ans1 = dfs(x-ma, ma*2, k)+1;
        ans2 = dfs(x-1, 2, k+1)+2;
        //prln(x);pr(ans1);prln(ans2);
        return min(ans1, ans2);
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%lld%lld", &p, &q);
        if(q>=p){
            printf("%lld\n", q-p);
            
        }else{
            ll ans = dfs(p, 1, 0);
            printf("%lld\n", ans);
        }
    }
	return 0;
}
