/*************************************************************************
	> File Name: d.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月29日 星期五 23时32分43秒
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
ll a, b, k, d, t;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(cin >> d >> k >> a >> b >> t){
        ll mod = d%k;
        ll ans = 0;
        ll kk = d/k;
        if(d<=k){
            cout << d*a << "\n";
            return 0;
        }
        ans += k*a;
        kk--;
        d -= k;
        //pr(k);prln(kk);prln(b);
        //pr(k*kk*a+t*kk);
        if(k*kk*a+t*(kk)<=k*kk*b){
            ans += kk*k*a+t*(kk);
            //prln(11);
            if(t+mod*a<=mod*b){
                ans += t+mod*a;
                //prln(12);
                //prln(ans);
            }else ans += mod*b;
        }else{
            ans += d*b;
        }
        cout << ans <<"\n";
    }
	return 0;   
}
