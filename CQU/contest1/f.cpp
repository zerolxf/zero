/*************************************************************************
	> File Name: f.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月18日 星期一 16时32分19秒
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
int n;
const int MOD = 2015;
struct Rec{
    int a[55][55];
    Rec(){
        memset(a, 0, sizeof a);
        for(int i = 0; i <= n; ++i){
            a[i][i] = 1;
        }
    }
    Rec(int x){

        memset(a, 0, sizeof a);
    }
    Rec operator *(const Rec& rhs)const{
        Rec ans(0);
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                for(int k = 1; k <= n; ++k){
                    ans.a[i][j] = (a[i][k]*rhs.a[k][j] + ans.a[i][j])%MOD;
                }
            }
        }
        return ans;
    }
}init;
int getans(Rec x, ll y){
    Rec ans;
    while(y){
        if(y&1) ans = ans*x;
        x = x*x;
        y >>= 1;
    }
    ll cnt = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cnt = (cnt + ans.a[i][j])%MOD;
        }
    }
    return cnt;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        int k;
        Rec x(0);
        for(int i = 1; i <= n; ++i){
             scanf("%d", &k);
             int y;
             for(int j = 0; j < k; ++j){
                 scanf("%d", &y);
                x.a[i][y] = 1;
             }
        }
        ++n;
        for(int i = 1; i <= n; ++i) x.a[n][i] = 1;
        int ans = getans(x, m-1);
        ans = (ans)%MOD;
        printf("%d\n", ans);
    }
	return 0;
}
