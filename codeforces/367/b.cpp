/*************************************************************************
    > File Name: b.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月12日 星期五 00时40分11秒
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
int a[maxn], x, n, m;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    cin >> n;
    rep(i,n){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    //rep(i,n){
        //cout<<a[i]<<" ";
    //}
    cin>>m;
    //prln(m);
    rep(i,m){
        //cin>>x;
        scanf("%d",&x);
        //prln(x);
        int ans = upper_bound(a,a+n,x)-a;
        //prln(ans);
        //prln(a[ans]);
        //ans = n-ans;
        printf("%d\n",ans);

    }

	return 0;
}
