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
const int maxn = 2e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
ll a, b, c;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
 #endif
    int n;
    char s[50];
    cin >> n;
    long long ans = 0;
    while(n--){
        cin >> s;
        if(s[0] == 'T') ans += 4;
        else if(s[0] == 'C') ans += 6;
        else if(s[0] == 'O') ans += 8;
        else if (s[0] == 'D') ans += 12;
        else if(s[0] == 'I') ans += 20;
    }
    cout << ans << endl;
    return 0;
}
