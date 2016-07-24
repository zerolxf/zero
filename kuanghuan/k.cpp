/*************************************************************************
	> File Name: k.cpp
	> Author: liangxianfeng
	sumz > Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月24日 星期日 11时41分34秒
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
int sumx, sumy, sumz, x, y, z;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    while(cin >> n){
        for(int i = 0; i < n; ++i){
            cin >> x >> y >> z;
            sumx += x;
            sumy +=y;
            sumz += z;
        }
        if(sumx==0&&sumy==0&&sumz==0){
            printf("YES\n");
        }else printf("NO\n");
    }
	return 0;
}
