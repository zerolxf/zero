/*************************************************************************
    > File Name: b.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月08日 星期六 20时36分10秒
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
int num[30][30];
int a[30][30];
int n, m;
bool init(int c1, int c2){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            a[i][j] = num[i][j];
        }
    }
    for(int i = 1; i <= n; ++i){
        swap(a[i][c1], a[i][c2]);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        int cnt = 0;
        for(int j = 1; j <= m; ++j){
            if(a[i][j] != j) cnt++;
        }
        if(cnt>2) return false;
        if(cnt==2) ans++;
    }
    return true;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(cin>>n>>m){
        for(int i =1 ; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                cin>>num[i][j];
            }
        }
        bool ok = false;
        if(init(0,0)) ok = true;
        for(int i = 1; i <= m; ++i){
            for(int j = i+1; j <= m; ++j){
                if(init(i,j)) ok = true;
            }
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }

	return 0;
}
