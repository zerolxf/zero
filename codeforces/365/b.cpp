/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月04日 星期四 23时25分36秒
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
ll c[maxn], num[maxn], n, k;
ll sum[maxn];
int b[maxn];
int d[maxn];
bool vis[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(cin >> n >> k){
        ll ans = 0;
        MEM(sum,0);
        MEM(vis, 0);
        MEM(b,0);
        for(int i = 1; i <= n; ++i){
            scanf("%I64d", &c[i]);
        }
        ans=0;
        for(int i = n; i; --i){
            ans += c[i]*c[(i)%n+1];
            sum[i] = c[i] + sum[i+1];
        }
        //ans = sum[1]*2;
        //prln(ans);
        int x;
        for(int i = 1; i <= k; ++i){
            scanf("%d", &b[i]);
            vis[b[i]] = true;
        }
        MEM(d,0);
        for(int i = 1; i <= n; ++i){
            if(!vis[i]) d[i+1] = d[i] + c[i];
            else d[i+1] = d[i];
        }
        for(int i = 1; i <= k; ++i){
            ans += d[b[i]-1]*c[b[i]];
            ans += sum[b[i]+2]*c[b[i]];
            //pr(i);pr(b[i]);pr(d[b[i]-1]);pr(sum[b[i]+2]);prln(c[b[i]]);
        }
        if(vis[1]||vis[n]){
            ans -= c[1]*c[n];
        }
        cout<<ans<<"\n";

    }
	return 0;
}
