/*************************************************************************
    > File Name: b.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月31日 星期一 22时13分49秒
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
#include <ctime>


using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define repp(i,n,x) for(int i =x; i < n+x; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
int a[maxn], b[maxn], n;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    scanf("%d", &n);
    ll sum1 = 0, sum2 = 0;
    ll d1 = 0, index1 = 0;
    ll d2 = 0, index2 = 0;
    repp(i,n,1){
        scanf("%d%d", &a[i], &b[i]);
        if((a[i]-b[i])*2>d2){
            d2 = a[i] - b[i];
            d2*=2;
            index2 = i;
        }

        if((-a[i]+b[i])*2>d1){
            d1 = -a[i] + b[i];
            d1 *= 2;
            index1 = i;
        }
        sum1 += a[i];
        sum2 += b[i];
    }
    ll temp1 = abs(sum1-sum2+d1);
    ll temp2 = abs(sum2-sum1+d2);
    ll ma = abs(sum1-sum2);
    if(ma>=temp1&&ma>=temp2){
        printf("0\n");
    }else if(temp1>=temp2){
        cout << index1 << "\n";
    }else{

        cout << index2 << "\n";
    }



	return 0;
}
