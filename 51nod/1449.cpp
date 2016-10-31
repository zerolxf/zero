/*************************************************************************
    > File Name: 1449.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月31日 星期一 17时35分17秒
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
const int maxn = 2e5+100;
const int INF = 0x3f3f3f3f;
typedef pair<int,int> P;
vector<int> g[maxn];
int a[maxn];
int b[maxn];
int c[maxn];
int n;
void inithash(){
    for(int i = 1; i <= n; ++i){
        b[i-1] = a[i];
    }
    sort(b, b+n);
    int cntb = unique(b, b+n) - b;
    int temp = 0;
    for(int i = 1; i <= n; ++i){
        temp = lower_bound(b, b+cntb, a[i]) - b;
        a[i] = temp;
    }
}
ll get(int num){
    ll ans = 0;
    int ma = 0;
    memset(c, 0, sizeof c);
    for(int i = 0; i <= n; ++i){
        g[i].clear();
    }
    for(int i = 1; i <= n; ++i){
        int cnt = ++c[a[i]];
        if(cnt >= num){
            int last = cnt-num;
            ma = max(ma, g[a[i]][last]);
        }
        ans += ma;
        g[a[i]].push_back(i);
    }
    return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    ll k = 0;
    while(scanf("%d%lld", &n, &k) != EOF){
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        inithash();
        int l = 1, r = n;
        while(l < r){
            int mid = (l+r+1) >>1;
            if(get(mid) < k) r = mid-1;
            else l = mid;
        }
        printf("%d\n",l);
    }

	return 0;
}
