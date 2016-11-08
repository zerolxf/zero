/*************************************************************************
	> File Name: f.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月05日 星期五 14时43分03秒
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
ll cnt[21][21];
ll ans, x;
ll d[21];
int mapos;
void dfs(int pos, ll cx, ll sum){
    if(pos == mapos){
        if(ans > sum || (ans == sum && x > cx)){
            //for(int i = 0; i < pos; ++i){
                //pr(i);prln(d[i]);
            //}
            //prln(sum);prln(x);
            ans = sum;
            x = cx;
        }
        return;
    }
    for(d[pos] = 0; d[pos] < 2; d[pos]++){
        ll nsum = sum; 
        for(int j = 0; j <= pos; ++j){
            if(d[pos]^d[j]){
                nsum -= cnt[pos][j];
            }else{
                nsum += cnt[pos][j];
            }
        }
        dfs(pos+1, (d[pos]<<pos)|cx, nsum);
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
        int n;
        //prln("************");
        scanf("%d", &n);
        MEM(d,0);
        MEM(cnt,0);
        int a = 0, b = 0;
        scanf("%d", &a);
        for(int i = 1; i < n; ++i){
            scanf("%d", &b);
            int high = 20;
            while(high >= 0 && ( (~(a^b))>>high )&1) --high;
            int mi = min(a,b);
            int ma = max(a,b);
            for(int j = high; j >= 0; --j){
                cnt[high][j] += ((ma>>j)&1) - ((mi>>j)&1);
            }
            a = b;
        }
        mapos = 20;
        while(mapos > 0 && !cnt[mapos-1][mapos-1]) --mapos;
        //prln(mapos);
        for(int i = 20; i >= 0; --i){
            for(int j = 0; j <= i; ++j){
                cnt[i][j] <<= j;
                //pr(i);pr(j);prln(cnt[i][j]);
            }
        }
        ans = 1e18;
        dfs(0,0,0);
        printf("%lld %lld\n", x, ans);
    }
	return 0;
}
