/*************************************************************************
    > File Name: a.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月10日 星期六 22时29分11秒
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
int num[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int a;
    cin >> a;
    int x, y;
    rep(i,3){
        num[i+1] = i+1;
    }

    rep(i,3){
        cin>>x>>y;
        swap(num[x],num[y]);
    }
    int ans = 1;
    rep(i,3){
        if(num[i+1]==a) ans = i+1;
    }
    cout<<ans<<"\n";


	return 0;
}
