/*************************************************************************
	> File Name: h.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月14日 星期六 00时14分48秒
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
const int maxn = 2e5+100;
const int INF = 0x3f3f3f3f;
int cnt[maxn], num[maxn];
int kase, m;
unsigned long long dp[maxn>>6];
int a[100], b[100];
int q[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t, n;
    ll k;
    scanf("%d", &t);
    while(t--){
        scanf("%d%lld", &n, &k);
        for(int i = 0; i < n; ++i){
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; ++i){
            scanf("%d", &b[i]);
        }
        int p = 0;
        for(int i= 0; i < n; ++i){
            ll base = a[i], cnt = 1;
            while(cnt <= b[i]) {
                if(cnt*base <= k){
                    q[p++] = cnt*base;
                }
                b[i] -= cnt;
                cnt<<=1;
            }
            if(b[i] > 0 && base*b[i] <= k){
                q[p++] = base*b[i];
            }
        }
        int sz = (k>>6)+1;
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for(int i = 0; i < p; ++i){
            int x = q[i]>>6, y = q[i]&63;
            for(int j = 0; j <= sz; ++j){
                if(x+j>sz) break;
                dp[x+j] = dp[x+j] | (dp[j] << y);
                if(y) dp[x+j+1] = dp[x+j+1] | (dp[j] >> (64-y));
            }
        }
        int x = k >> 6, y = k&63;
        bool ok = false;
        if(dp[x] & (1<<y)) ok = true;
        if(ok) printf("yes\n");
        else printf("no\n");
    }
	return 0;
}
