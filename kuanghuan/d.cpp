/*************************************************************************
	> File Name: d.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月24日 星期日 10时29分19秒
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
const int maxn = 1e7+100;
const int INF = 0x3f3f3f3f;
int prime[maxn];
bool vis[maxn];
int cntp;
void getprime(){
    memset(vis, 0, sizeof vis);
    cntp = 0;
    for(ll i = 2; i < maxn; ++i){
        if(!vis[i]){
            prime[cntp++] = i;
            //prln(i);
        }
        else continue;
        for(ll j = i*i; j < maxn; j+=i){
            vis[j] = true;
        }
    }
}
const ll MOD = 1e9+7;
ll x[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    //getprime();
    int n;
    cin >> n;
    //while(cin >> n){
        //for(int i = 0; i < 100;++i){
            //pr(i);prln(prime[i]);
        //}
        if(n==1){
            printf("1\n");
            return 0;
        }else if(n==2){
            printf("-1\n");
            return 0;
        }
        cout << MOD*2 << "\n" ;
        cout << MOD*3 << "\n";
        x[1] = MOD*2;
        x[2] = MOD*3;
        for(int i = 3; i <= n;i++){
            cout <<(ll)6*(i+3)  << "\n";
            x[i] = 6*(i+3);
        }
        bool ok = true;
        for(int i = 1; i <= n; ++i){
            for(int j = i+1; j <= n; ++j){
                if(__gcd(x[i],x[j]) == 1 || x[i]==x[j]){
                    pr(x[i]);prln(x[j]);
                    ok = false;
                }

            }
        }
    //}
    //for(int i = 1; i <= n; ++i){
        //for(int j = i+1; j <= n; ++j){
            //prln(__gcd(2*prime[cntp-1],3*prime[cntp-1]));
        //}
    //}
    //prln(__gcd(55, 11115));
	return 0;
}
