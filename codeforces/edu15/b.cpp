/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月29日 星期五 23时07分34秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;

int a[maxn], sum[maxn];
map<ll,int> mp;
ll base[33];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    base[0] = 1;
    for(int i = 1; i <= 32; ++i){
        base[i] = base[i-1]*2;
    }
    while(cin >> n){
        mp.clear();
        ll ans = 0;
        for(int i = 0; i < n; ++i){
            scanf("%d", &a[i]);
            for(int j = 0; j <= 32; ++j){
                ans += mp[base[j]-a[i]];
            }
            mp[a[i]]++;
        }
        cout << ans << "\n";
    }
	return 0;
}
