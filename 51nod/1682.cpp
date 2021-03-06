/*************************************************************************
    > File Name: 1682.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月30日 星期日 21时56分28秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <ctime>


using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define repp(i,n,x) for(int i =x; i < n+x; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
int n;
ll a[maxn];
int cnt[maxn*2];
int ans[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(scanf("%d", &n) != EOF){
        memset(ans,0,sizeof ans);
        for(int i = 1; i <= n; ++i){
            scanf("%lld", &a[i]);
        }
        for(int i = 1; i <= n; ++i){
            memset(cnt, 0, sizeof cnt);
            int e = 0;
            cnt[n] = 1;
            for(int j = i-1; j > 0; --j){
               if(a[j] < a[i]) e--; 
               else e++;
               cnt[n+e]++;
            }
            e = 0;
            ans[i] = cnt[n];
            for(int j = i+1; j <= n; ++j){
                if(a[j] < a[i]) e--;
                else e++;
                ans[i] += cnt[n-e];
            }
        }
        for(int i = 1; i <= n; ++i){
            printf("%d%c",ans[i],i==n?'\n':' ');
        }
    }
	return 0;
}
