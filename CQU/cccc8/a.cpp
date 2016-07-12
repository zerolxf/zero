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
bool vis[maxn];
int a[maxn];
int n;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    while(cin >> n){
        scanf("%d", &a[0]);
        for(int i = 0;i <= n; ++i){
            vis[i] = 0;
        }
        for(int i = 1;i < n; ++i){
            scanf("%d", &a[i]);
            int x = abs(a[i]-a[i-1]);
            if(x<n&&x>0) vis[x] = true;
        }
        bool ok = true;
        for(int i = 1;i < n; ++i){
            if(!vis[i]) ok = false;
        }
        if(ok) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }
    return 0;
}
