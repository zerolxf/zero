/*************************************************************************
	> File Name: l.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月14日 星期六 02时01分00秒
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
int a[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t,n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        double ans = 0;
        int b = 0, x;
        for(int i = 0; i < n; ++i){
            scanf("%d", &a[i]);
            if(a[i] > b) b = a[i];
        }
        x = b;
        bool ok = true;
        for(int i = 0; i < n; ++i){
            if(a[i] == 0) {
                ok = false;
                continue;
            }
            x = __gcd(x, a[i]);
        }
        int num = b/x;
        if(!ok) num++;
        ans = num-n;
        for(int i = 1; i <= num; ++i){
            ans = ans +num*1.0/i;
        }
        int temp = ans;
        printf("%d\n",temp);
    }
	return 0;
}
