/*************************************************************************
	> File Name: k.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月21日 星期四 23时49分58秒
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

int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int a, b;
    int t, n, x;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        a = 0, b = 0;
        for(int i = 0; i < n; ++i){
            scanf("%d", &x);
            a += x&1;
            b += x/2;
        }
        if(a)printf("%d\n", b/a*2+1);
        else printf("%d\n",b*2);
    }
	return 0;
}
