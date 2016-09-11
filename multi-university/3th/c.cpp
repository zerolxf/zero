/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月26日 星期二 18时41分51秒
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

    int t, n, m;
    int op;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &op, &n, &m);
        n--;m--;
        if(n > m) swap(n, m);
        if(op == 1)
        {
            if(n%2==0&&m%2==0){
                printf("G\n");
            }else printf("B\n");
        }else if(op == 2){
            if(n==m){
                printf("G\n");
            }else printf("B\n");
        }else if(op == 3){
            if((n)%3==0&&m==n){
                printf("G\n");
            }else if((n-1)%3==0 && m-1==n){
              printf("B\n");
            }else printf("D\n");
        }else {
            if(n < m) swap(n,m);
            n = n - m;
            if(m == (int)(n*(1+sqrt(5)))/2){
                printf("G\n");
            }else printf("B\n");
        }
    }
	return 0;
}
