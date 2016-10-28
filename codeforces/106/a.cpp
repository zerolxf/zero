/*************************************************************************
	> File Name: a.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月05日 星期五 18时17分29秒
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
int a[maxn], k;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    cin >> k;
    for(int i = 0; i < 12; ++i){
        cin >> a[i];
    }
    sort(a,a+12);
    int ans = 0;
    int kk = 0;
    for(int i = 12-1; i >= 0; --i){
        if(ans < k){
            ans += a[i];
            kk++;
        }
    }
    if(ans<k){
        printf("-1\n");
    }else printf("%d\n", kk);
	return 0;
}
