/*************************************************************************
    > File Name: d.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月10日 星期六 23时28分49秒
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
int b[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int sum, n;
    while(cin >> n >> sum){
        rep(i,n){
            cin>>a[i+1];
            b[i] = a[i+1]*(n-i);
        }
        sort(b, b+n);
        int ans = 0;
        rep(i,n){
            if(sum>=b[i]){
                ans++;
                sum-=b[i];
            }
        }
        cout << ans << "\n";
    }

	return 0;
}
