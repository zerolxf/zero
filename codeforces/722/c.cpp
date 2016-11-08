/*************************************************************************
    > File Name: c.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月01日 星期六 23时39分04秒
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
ll dpl[maxn], dpr[maxn];
ll ans[maxn];
ll a[maxn], b[maxn];
int p[maxn];
int find(int x){
    return p[x] == x?x:find(p[x]);
}

int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    cin>>n;
    memset(dpl, -1, sizeof dpl);
    memset(dpr, -1, sizeof dpr);
    rep(i,n){
        cin>>a[i+1];
    }
    rep(i,n){
        cin>>b[i];
        dpl[i] = dpr[i] = -1;
    }
    for(int i = 0; i <= n; ++i){
        p[i] = i;
    }
    dpl[n] = dpr[n] = -1;
    dpl[n+1] = dpr[n+1] = -1;
    ans[n-1] = 0;
    ll temp = 0;
    for(int i = n-1; i > 0; --i){
        dpl[b[i]] = dpr[b[i]] = a[b[i]];
        p[i] = i;
        if(dpl[b[i]-1] != -1) {
            int u = find(b[i]-1);
            dpl[b[i]] = max(dpl[b[i]], dpl[u] + a[b[i]]);
            p[u] = b[i];
        }
        if(dpr[b[i]+1] != -1) {
            int u = find(b[i]+1);
            dpr[b[i]] = max(dpr[b[i]], dpr[u] + a[b[i]]);
            p[u] = b[i];
        }
        temp = max(temp, dpl[b[i]] + dpr[b[i]] - a[b[i]]);
        ans[i-1] = temp;
    }
    rep(i,n){
        //printf("%I64d\n", ans[i]);
        cout << ans[i] << "\n";
    }



	return 0;
}
