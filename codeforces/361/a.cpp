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
int a[maxn], n, m;
char s[maxn];
bool num[20];
bool flag[10];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    int n;
    string ss;
    while(cin >> n >> ss){
        for(int i = 0; i < n; ++i){
            num[ss[i]-'0']=true;
        }
        if(num[0]||num[7]||num[9]) flag[3] = true;
        if(num[1]||num[2]||num[3]) flag[1] = true;
        if(num[1]||num[4]||num[7]) flag[0] = true;
        if(num[3]||num[6]||num[9]) flag[2] = true;
        if(flag[3]&&flag[2]&&flag[1]&&flag[0]||(num[0]&&flag[1])) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
