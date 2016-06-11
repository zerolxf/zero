/*************************************************************************
	> File Name: e.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年06月10日 星期五 18时54分45秒
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
int a[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    int n, k;
    scanf("%d", &t);
    while(t--){
        map<int,int> l, r;
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; ++i){
            scanf("%d", &a[i]);
            r[a[i]]++;
        }
        ll ans = 0;
        for(int i = 0; i < n; ++i){
            r[a[i]]--;
            if(a[i]%k==0)ans += r[a[i]*k]*l[a[i]/k];
            l[a[i]]++;
        }
        printf("%lld\n", ans);
    }
	return 0;
}
