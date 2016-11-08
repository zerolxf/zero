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
char s[maxn];
string ss = "AHIMOoTUVvWwxXY";
bool vis[maxn];
bool link[300][300];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    //A H IM O o T U V v W w x X Y
    int len = ss.size();
    link['b']['d'] = true;
    link['d']['b'] = true;
    link['q']['p'] = true;
    link['p']['q'] = true;
    for(int i = 0; i < len; ++i){
        vis[ss[i]] = true;
    }
    while(cin >> s){
        int lenn = strlen(s);
        bool ok = true;
        for(int i = 0; i< lenn; ++i){
            if((s[i] == s[lenn-1-i]&&vis[s[i]]) || (s[i] != s[lenn-1-i]&&link[s[i]][s[lenn-1-i]])) continue;
            ok = false;
        }
        if(ok) printf("TAK\n");
        else printf("NIE\n");
    }
    return 0;
}
