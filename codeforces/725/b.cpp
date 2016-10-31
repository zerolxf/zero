#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 4e5+1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
ll n;
char s;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    scanf("%I64d%c",&n,&s);
    ll ans = 0;
    ll x = 0;
   // if(n&1){
        if(s>='d') x='f'-s+1;
        else x = 3 + s-'a'+1;
   // }else{
    //    if(s>='d') x='f'-s+4;
    //    else x = s-'a'+1;
   // }
    //prln(x);
    //prln(3+s-'a'+1);
    ans = x;
    ans += n-1;
    ans += (n-1)/4*2*6;

    if(n%4==1){

    }else if(n%4==2){
        ans += 6;
    }else if(n%4==3){

    }else{
       ans += 6;
    }
    if(n%4==0||n%4==3) ans-=2;
    cout<<ans<<"\n";
    return 0;
}
