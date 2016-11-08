/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年06月02日 星期四 00时55分52秒
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
const int MOD = 1e9+7;
char s[maxn];
int get(char x){
    if(x <= '9' && x >= '0') return x-'0';
    if(x <= 'Z' && x >= 'A') return x-'A'+10;
    if(x <= 'z' && x >= 'a') return x-'a'+36;
    if(x == '-') return 62;
    if(x == '_') return 63;
}
ll cnt[100];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    for(int i = 0; i < 64; ++i){
        int ans = 0;
        for(int j = 0; j < 64; ++j){
            for(int k = 0; k < 64; ++k){
                if((j&k) == i) ans++;
            }
        }
        cnt[i] = ans;
    }
    //cout << get('-') << "\n";
    //cout << get('_') << "\n";
    for(int i = 0; i <= 9; ++i){
        //prln(get('0'+i));
    }
    for(int i = 0; i < 26; ++i){
        //prln(get('a'+i));
    }

    for(int i = 0; i < 26; ++i){
        //prln(get('A'+i));
    }
   while( scanf("%s", s)!= EOF){
        int len = strlen(s);
        ll sum = 0;
       ll ans = 1;
        for(int i = 0; i < len; ++i){
//            sum = (sum*64) + get(s[i]);        
            ans = (ans*(cnt[get(s[i])]))%MOD;
  //          sum=sum%MOD;
        }
        cout << ans << "\n";
   }
	return 0;
}
