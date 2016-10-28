/*************************************************************************
	> File Name: e.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月30日 星期六 00时42分35秒
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
    ll mi, sum, fa;
    void update(const Node& rhs){
        mi = min(mi, rhs.mi);
        sum = sum + rhs.sum;

    }
    Node(){
         mi = sum = 0;
    }
    Node(ll _x, ll _y){
        mi = _x;
        sum = _y;
    }
}dp[maxn][50];
int fa[maxn], v[maxn];
int n;
void St(){
    for(int i = 1; i <= n; ++i){
        dp[i][0] = Node()
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

	return 0;
}
