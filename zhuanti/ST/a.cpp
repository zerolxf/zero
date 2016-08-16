/*************************************************************************
	> File Name: a.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月30日 星期六 19时25分25秒
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
struct Node{
    int mi, ma;
    Node(){}
    Node(int _mi, int _ma){
        mi = _mi;
        ma = _ma;
    }
}dp[maxn][32];

Node update(const Node& a, const Node& b){
    return Node(min(a.mi, b.mi), max(a.ma, b.ma));
}
int n;
void init(){
    for(int j = 1; (1<<j) <= n; ++j){
        for(int i = 1; i +(1<<(j-1))<=n; ++i){
            dp[i][j] = update(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
        }
    }
}
Node query(int l, int r){
    int k = 0;
    while((1<<(k+1)) <= (r-l+1)) ++k;
    return update(dp[l][k], dp[r-(1<<k)+1][k]);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int q;
    while(scanf("%d%d", &n, &q) != EOF){
        for(int i = 1; i <= n; ++i){
            scanf("%d", &dp[i][0].mi);
            dp[i][0].ma = dp[i][0].mi;
            //pr(dp[i][0].mi);
        }
        init();
        while(q--){
            int l, r;
            scanf("%d%d", &l, &r);
            Node ans = query(l,r);
            cout << ans.ma-ans.mi<<"\n";
        }
    }
	return 0;
}
