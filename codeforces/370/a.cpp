/*************************************************************************
    > File Name: a.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月11日 星期日 00时32分55秒
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

ll a[maxn];
ll b[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    while(cin>>n){
        a[n] = 0;
        rep(i,n){
            cin>>a[i];
            //scanf("%I64d",&a[i]);
        }
        for(int i = n-1; i >= 0; --i){
            ll ans = a[i] + a[i+1];
            b[i] = ans;
        }
        rep(i,n){
            cout<<b[i]<<" ";
        }
        cout<<"\n";
    }

	return 0;
}
