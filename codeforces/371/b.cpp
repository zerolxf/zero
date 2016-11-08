/*************************************************************************
    > File Name: b.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月14日 星期三 00时41分30秒
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

int a[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    n = 1e9+1e9;
    while(cin>>n){
        rep(i,n){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int cnta = unique(a, a+n) - a;
        bool ok = true;
        if(cnta>=4) ok = false;
        else if(cnta==3){
            if(a[0]+a[2]==a[1]*2){
                ok = true;
            }else ok = false;
        }else if(cnta==2){
            //if((a[0]+a[1])%2) ok = false;
        }else ok = true;
        if(ok) cout<<"YES\n";
        else printf("NO\n");

    }

	return 0;
}
