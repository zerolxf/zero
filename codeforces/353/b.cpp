/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月17日 星期二 00时43分57秒
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
ll n;
bool getok(ll x){
    return x >=1 && x <= n;
}
struct Node{
    ll l, r;
    Node(){}
    Node(ll _l, ll _r){
        l = _l;r = _r;
    }
    Node operator + (const Node& rhs)const{
        return Node(max(l,rhs.l),min(r,rhs.r));
    }
};
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    ll a, b, c, d;
    while(cin >> n >> a >> b >> c >> d){
        ll x = 0;
        for(int i = 1; i <= n; ++i){
            Node x1 = Node(a+b+i+1,a+b+i+n);
            Node x2 = Node(a+c+i+1,a+c+i+n);
            Node x3 = Node(d+b+i+1,d+b+i+n);
            Node x4 = Node(c+d+i+1,c+d+i+n);
            Node ans = x1 + x2 + x3 +x4;
            if(ans.l>ans.r) continue;
            x += ans.r-ans.l+1;
        }
        cout << x << "\n";
    }
	return 0;
}
