/*************************************************************************
	> File Name: j.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月26日 星期二 19时23分39秒
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
    int a, v1, v2;
    while(cin >> a >> v1 >> v2){
        if(a == 0){
            printf("0.00000\n");
            continue;
        }else{
            if(v1<=v2){
                printf("Infinity\n");
            }else{
                double ans = 0;
                ans = a*1.0*v1/(v1*v1-v2*v2);
                printf("%.9f\n", ans);
            }
        }
    }

	return 0;
}
