/*************************************************************************
	> File Name: b.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年06月11日 星期六 14时14分29秒
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
#define ll unsigned int
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
int s[maxn][12];
int n, m;
int num[100];
unsigned int ans;
void dfs(int pos){
    if(pos>0&&pos%2==0){
        int len = pos/2;
        bool ok = false;
        for(int i = 0; i < pos/2; ++i){
            if(num[i] != num[i+len]) {
                ok = true;
                break;
            }
        }
        if(!ok) return;
    }
    ans++;
    if(pos==n) {
        return;
    }
    for(int i = 0; i < m; ++i){
        num[pos] = i;
        dfs(pos+1);
    }
}
unsigned int ret(unsigned int x,unsigned int y){
    ll base = x;
    ll xans = 1;
    pr(x);pr(y);
    while(y){
        if(y&1) xans = xans*base;
        base=base*base;
        y>>=1;
    }
    prln(xans);
    return xans;
}
unsigned int dp[210];
int get(){
    dp[0] = 1;
    for(int i = 1; i <= n; ++i){
        dp[i] = dp[i-1]*m;
        if(i%2==0){
            dp[i]-=dp[i/2];
        }
    }
    unsigned int xans = 0;
    for(int i = 1; i <= n; ++i){
        xans += dp[i];
    }
    return xans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
  //  for(int i = 1; i <= 8; i++){
//        for(int j = 1; j <= 15; ++j){
            //if(i%2==1) continue;
            ans = 0;
            n=10;m=6;
            dfs(0);
            pr(n);pr(m);pr(ans-1);
            int temp = 1;
            for(int i = 1; i <= n; ++i){
                temp*=m;
            }
            //pr(temp);
            //pr(temp-ans+1);
            int x = temp-ans+1;
            int xx = ans-1;
            //pr(xx);prln(get());
            //pr(xx%m);pr(xx/m);
            //int y = xx/m;
            //int yy = -y+ret(m,n-1);
            //pr(yy);
            //pr(yy%(m+1));prln(yy/m);
            //while(cin >> n >> m){
        n = 14;
        for(int i = 1; i <= 7;++i){
            m = i;
            ans = 0;
            dfs(0);
            unsigned int temp = ans;
            ans = 0;
            pr(i);pr(temp);
                ans = get();
            pr(ans);
            pr(-ans+temp);
            pr((n/2)-2);
            ans += ret(m,(n/2)-2)-m+1;
            prln(ans);
        }
      //  }
    //}
	return 0;
}
