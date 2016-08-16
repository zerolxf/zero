/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月01日 星期一 18时44分08秒
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
double a, b, c, d, e;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(cin >> a >> b >> c >> d >> e){
        double ad = a*c;
        double bd = 0;
        if(a>=b){
            cout<<"0\n";
            continue;
        }
        int ans = 0;
        while(ad < e){
            double t = (ad-bd)/(b-a);
            ad += a*t;
            bd += b*t;
            if(ad < e){
                ad += (bd/b+d)*a;
                bd = 0;
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
	return 0;
}
