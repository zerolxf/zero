/*************************************************************************
	> File Name: f.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年06月10日 星期五 19时02分00秒
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
int MOD = 72807249;
ll sum[maxn<<1];
int update(int rt, int l, int r,int o, int v){
    if(l == r){
        sum[rt] = v;
        return v;
    }
    int m = l + r >> 1;
    if(m >= o) update(rt<<1, l, m, o, v);
    else update(rt<<1|1, m+1, r, o, v);
    sum[rt] = sum[rt<<1] * sum[rt<<1|1] %MOD;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t, n, _n, x, o, v;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        _n = 1;
        while(_n < n) _n <<= 1;
        for(int i = 0; i <= _n*2; ++i){
            sum[i] = 1;
        }
        for(int i = 1; i <= n; ++i){
            scanf("%d", &x);
            if(x==1){
                scanf("%d", &v);
                update(1, 1, _n, i, v);
            }else{
                scanf("%d", &v);
                update(1, 1, _n, v, 1);
            }
            printf("%lld\n", sum[1]);
            
        }
    }
	return 0;
}
