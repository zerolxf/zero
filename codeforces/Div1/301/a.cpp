/*************************************************************************
    > File Name: a.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月28日 星期五 22时59分52秒
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

    int n, sum = 0, cnt = 0, cnt0 = 0;
    cin >> n;
    rep(i,n*2-1){
        cin >> a[i];        
        if(a[i] < 0) cnt++;
        else if(a[i] == 0) cnt0++;
        a[i] = abs(a[i]);
    }
    sort(a,a+2*n-1);
    int num = 0;
    if(cnt%2==0||cnt0||n%2==1) num = 0;
    else num = 1;
    rep(i,2*n-1){
        if(i < num) sum -= a[i];
        else sum += a[i];
    }
    cout << sum << "\n";
    
	return 0;
}
