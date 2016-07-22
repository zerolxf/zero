/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月20日 星期三 12时49分17秒
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
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
#define ll long long 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
const int N = 1100;
char s[1234][1234];
bool vis[maxn];

int cntl[N][N], cntr[N][N];
inline ll getans(const ll &x, const ll &y){
    return x*y*(x+y)/2;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    ll n, m, t;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld%lld", &n, &m);
        int x = 0;
        memset(cntr[0], 0, sizeof cntr[0]);
        for(int i = 0; i <= n; ++i){
            cntl[i][0] = 0;
        }
        long long cnt = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%s", s[i]+1);
            for(int j = 1; j <= m; ++j){
                if(s[i][j] == '#') x = 1;
                else x = 0;
                cnt += 1-x;
                cntl[i][j] = cntl[i][j-1]+x;
                cntr[i][j] = cntr[i-1][j]+x;
            }
        }
        cnt = (long long)n*m - cnt;
        long long ans = 0;
        long long add = 0;
        ll a, b, c, d;
        //prln(cnt);
        for(ll i = 1; i <= n; ++i){
            for(ll j = 1; j <= m; ++j){
                a = i-1;b=j;
                if(s[i][j] == 'G'){
                    add += (long long)cntl[i][j-1]*(cntl[i][m]-cntl[i][j])*2;
                    add += (long long)cntr[i][j-1]*(cntr[i][m]-cntr[i][j])*2;
                    ans -= getans(i,j-1);
                    ans -= getans(n-i,j);
                    ans -= getans(i-1,n-j+1);
                    ans -= getans(n-i+1,n-j);
                    //ans -= i*(j-1)*(i+j+1)/2;zuoshang
                    //ans -= (n-i+1)*(n-j)*(n-i+1+n-j+2)/2;youxia
                    //ans -= (n-i)*j*(n-i+j+2)/2;左下
                    //ans -= (n-j+1)*(i-1)*(n-j+1+i-1+2)/2;
                }
                else{
                    ans += getans(i,j-1);
                    ans += getans(n-i,j);
                    ans += getans(i-1,n-j+1);
                    ans += getans(n-i+1,n-j);
                    //ans += i*(j-1)*(i+j+1)/2;zuoshang
                    //ans += (n-i+1)*(n-j)*(n-i+1+n-j+2)/2;youxia
                    //ans += (n-i)*j*(n-i+j+2)/2;左下
                    //ans += (n-j+1)*(i-1)*(n-j+1+i-1+2)/2;
                }

                a= getans(i,j-1);
                b= getans(n-i,j);
                c= getans(i-1,n-j+1);
                d= getans(n-i+1,n-j);
                //pr(i);pr(j);prln(ans);
                //pr(a);pr(b);pr(b);prln(d);
            }
        }
        //prln(ans);
        //prln(add);
        cnt = cnt + (cnt*(cnt+1)/2);
        //prln(cnt);
        ans = ans+add;
        double xxx = 0;
        if(cnt>0) xxx = ans*1.0/cnt;
        else xxx = 0;
        printf("%.4f\n",xxx);
        
        
    }
	return 0;
}
