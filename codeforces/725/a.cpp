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
int a[maxn], n;
char s[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    cin >> n;
    scanf("%s",s+1);
    s[0] = '<';
    s[n+1] = '>';
    memset(a, 0, sizeof a);
    for(int i = 1; i <= n; ++i){
        if(s[i]=='<') a[i] = 1;
        else break;
    }
    for(int i = n; i >0;--i){
        if(s[i]=='>') a[i] = 1;
        else break;
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans += a[i];
    }
    cout<<ans<<"\n";
    return 0;
}
