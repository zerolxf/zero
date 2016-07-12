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
int x[maxn], y[maxn];
int ans , n;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    while(cin >> n){
        for(int i = 0; i < n; ++i){
            scanf("%d%d", &x[i], &y[i]);
        }
        int ans = 2;
        ans = min(ans,n);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i==j) continue;
                int tempans = 2;
                for(int k = 0; k < n; ++k){
                    if(k==i||k==j) continue;
                    if((y[k]-y[i])*(x[j]-x[i]) == (y[j] - y[i])*(x[k] - x[i])) tempans++;
                }
                ans = max(ans, tempans);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
