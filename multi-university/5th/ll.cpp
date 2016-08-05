/*************************************************************************
	> File Name: ll.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月03日 星期三 10时29分30秒
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
ll sum[maxn];
int n;
int cntb;
void add(int x){
    for(int i = x; i <= cntb; i += i&(-i)) {
        sum[i] += 1;
    }
}
int get(int x){
    int ans = 0;
    for(int i = x; i > 0; i -= i&(-i)){
        ans += sum[i];
    }
    return ans;
}
int a[maxn], b[maxn], id[maxn];
void getid(){
    for(int i = 1; i <= n; ++i){
        b[i-1] = a[i];
    }
    sort(b, b+n);
    cntb = unique(b, b+n) - b;
    //prln(cntb);
    for(int i = 1; i <= n; ++i){
        id[i] = lower_bound(b, b+cntb, a[i]) - b+1;
    }
}
ll ls[maxn], lb[maxn], rs[maxn], rb[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(scanf("%d", &n) != EOF){
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        getid();
        //for(int i =1 ; i <= n; ++i){
            //pr(i);pr(id[i]);prln(a[i]);
        //}
        rep(i,n+1) sum[i] = 0;
        ll ans = 0;
        ll sum1 = 0, sum2 = 0;
        for(int i = 1; i <= n; ++i){
            ls[i] = get(id[i]-1);
            lb[i] = get(cntb) - get(id[i]);
            add(id[i]);
            sum1 += ls[i];
            sum2 += lb[i];
        }
        rep(i,n+1) sum[i] = 0;
        for(int i = n; i > 0; --i){
            rs[i] = get(id[i]-1);
            rb[i] = get(cntb) - get(id[i]);
            add(id[i]);
        }
        ans = sum1*sum2;
        for(int i = 1; i <= n; ++i){
            ans -= ls[i]*rs[i];
            ans -= rs[i]*rb[i];
            ans -= lb[i]*rb[i];
            ans -= lb[i]*ls[i];
        }
        printf("%lld\n",ans);

    }
	return 0;
}
