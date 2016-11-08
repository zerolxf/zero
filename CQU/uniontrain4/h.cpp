/*************************************************************************
	> File Name: h.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年06月16日 星期四 20时33分35秒
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
const ll INF = 1e13;
struct Node{
    ll lsum, rsum, ans, sum;
    Node(){
        lsum = rsum = ans = sum = 0;
    }
    Node(ll _l, ll _r, ll _ans, ll _sum){
        lsum = _l;
        rsum = _r;
        ans = _ans;
        sum = _sum;
    }
    Node operator + (const Node& rhs)const{
        Node x;
        ll temp;

        temp = max(lsum, sum+rhs.lsum);
        x.lsum = temp;

        temp = max(rhs.rsum, rhs.sum + rsum);
        x.rsum = temp;

        x.sum = sum + rhs.sum;

        temp = max(ans, rhs.ans);
        temp = max(temp, rsum+rhs.lsum);
        x.ans = temp;
        return x;
    }
}sum[maxn<<1];
Node query(int rt, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return sum[rt];
    }
    int m = l + r >> 1;
    if(m >= ql && m < qr) return query(rt<<1, l, m, ql, qr) + query(rt<<1|1, m+1, r, ql, qr);
    else if(m >= ql) return query(rt<<1, l, m, ql, qr);
    else if(m < qr) return query(rt<<1|1, m+1, r, ql, qr);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t, n, _n, x, l, r, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        int _n = 1;
        while(_n < n) _n <<= 1;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &x);
            sum[i+_n-1] = Node(x, x, x, x);
        }
        for(int i = n+1; i <= _n; ++i){
            sum[i+_n-1] = Node(-INF, -INF, -INF, -INF);
        }
        for(int i = _n-1; i; --i){
            sum[i] = sum[i<<1] + sum[i<<1|1];
        }
        for(int i = 0; i < m; ++i){
            scanf("%d%d", &l, &r);
            Node ans = query(1, 1, _n, l, r);
            printf("%lld\n", ans.ans);
        }
    }
	return 0;
}
