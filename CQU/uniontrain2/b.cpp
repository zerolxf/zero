/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月13日 星期五 16时20分14秒
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
    ll num, x;
    Node (){}
    Node(ll _num, ll _x){
        num = _num;
        x = _x;
    }
}q[maxn];
ll dp[maxn];
ll x[maxn];
bool get(const Node& a, const Node &b, const ll& x){
    return b.num - a.num <= x*(b.x-a.x)*2;
}
bool get2(const Node& a, const Node& b, const Node& c){
    return (b.num - a.num)*(c.x - a.x) >= (c.num - a.num)*(b.x - a.x);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--){
        ll w;
        int n;
        scanf("%d%lld", &n, &w);
        for(int i = 1; i <= n; ++i){
            scanf("%lld", &x[i]);
        }
        int tail = -1,head = 0;
        dp[0] = 0;
        dp[1] = w;
        q[++tail] = Node(x[1]*x[1], x[1]);
        q[++tail] = Node(w+x[2]*x[2],x[2]);
        for(int i = 2; i <= n; ++i){
            while(head < tail && get(q[head], q[head+1], x[i])) head++;
            dp[i] = q[head].num + w + (x[i]*x[i]) - 2*x[i]*q[head].x;
            dp[i] = min(dp[i], dp[i-1] + w);
            Node qnum = Node(dp[i] + (x[i+1]*x[i+1]), x[i+1]);
            while(head < tail && get2(q[tail-1], q[tail], qnum)) tail--;
            q[++tail] = qnum;

        }
        printf("%lld\n", dp[n]);
    }
	return 0;
}
