/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月15日 星期五 16时19分00秒
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
ll MOD;
char a[maxn], b[maxn];
struct Bignum{
    ll a, b;
    ll c;
    Bignum(){
        a = b = 0;
    }
    Bignum(ll x){
        a = 0;b = x;
    }
    Bignum operator *(const int& mul)const{
        Bignum ans;
        ll add = b*mul/MOD;
        ans.b = b*mul%MOD;
        ans.a = (a*mul+add)%MOD;
        return ans;
    }
    Bignum operator +(const int& mul)const{
        Bignum ans;
        ll add = (b+mul)/MOD;
        ans.b = (b+mul)%MOD;
        ans.a = a+add;
        return ans;
    }
    void out(){
        if(a) printf("%lld",a);
        int cntb = 0;
        ll bb = b;
        while(bb){
            cntb++;
            bb/=10;
        }
        if(a)
        for(int i = cntb; i<18;++i){
            printf("0");
        }
        printf("%lld\n",b);
    }
};
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, lena,lenb;
    int t;
    MOD = 1;
    for(int i = 0; i < 60; ++i){
        MOD = MOD*2;    
    }
    MOD = 1e9+7;
    cin >> t;
    while(t--){
        scanf("%d", &n);
        scanf("%s",a);
        scanf("%s",b);
        lena = strlen(a), lenb = strlen(b);
        Bignum c;
        bool ok = true;
        c.b  = 1;
        ll ans = 1;
        for(int i = 0; i < lena; ++i){
            if(b[i]=='0'&&a[i]=='1') ok = false;
            if(b[i]==a[i]&&a[i]=='1') {
                c = c*2;
                ans = (ans*2)%MOD;
            }
        }
        if(ok) cout << ans << "\n";
        else printf("IMPOSSIBLE\n");
    }
	return 0;
}
