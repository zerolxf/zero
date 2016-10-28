/*************************************************************************
    > File Name: b.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月07日 星期日 09时26分59秒
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
int n, d;
int a[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int l;
    while(cin >> n >> d >> l){
        for(int i = 1; i <= n; ++i){
            a[i] = l;
        }
        int c = (n+1)/2, e = n/2;
        int ma = c*l-e*1, mi = c-e*l;
        if(d < mi || d > ma){
            cout << "-1\n";
            continue;
        }
        int sum = (n+1)/2*l - n/2*l;
        //prln(sum);
        for(int i = 1; i <= n; ++i){
            if(sum < d && !(i&1)){
                int mi = min(d-sum,l-1);
                sum += mi;
                a[i] -= mi;
            }
            if(sum > d && i&1){
                int mi = min(sum-d, l-1);
                sum -= mi;
                a[i] -= mi;
            }
        }
        for(int i = 1; i <= n; ++i){
            printf("%d ", a[i]);
        }
        printf("\n");



    }
	return 0;
}
