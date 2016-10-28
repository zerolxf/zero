/*************************************************************************
    > File Name: hdu5489.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月10日 星期三 00时31分21秒
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
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
int a[maxn], b[maxn], c[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t = 0, kase = 0, n = 0, l = 0;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &l);
        for(int i = 0; i < n; ++i){
            scanf("%d", &a[i]);
        }
        memset(b, 0x7f, sizeof b);
        int len = 0;
        for(int i = n-1; i >= 0; -- i){
            int pos = lower_bound(b, b+len, -a[i]) - b;
            b[pos] = -a[i];
            len = max(pos+1,len);
            c[i] = pos+1;
        }
        int ans = 0;;
        len = 0;
        memset(b, 0x7f, sizeof b);
        for(int i = l; i < n; ++i){
            int pos = lower_bound(b, b+len, a[i]) - b;
            ans = max(ans, pos+c[i]);
            pos = lower_bound(b, b+len,a[i-l]) - b;
            len = max(pos+1, len);
            b[pos] = a[i-l];
        }
        ans = max(len, ans);
        printf("Case #%d: %d\n", ++kase, ans);
    }
	return 0;
}
