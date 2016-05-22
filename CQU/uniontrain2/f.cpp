/*************************************************************************
	> File Name: f.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月14日 星期六 19时37分51秒
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
ll dp[2][maxn];
struct Node{
    ll num, pos;
    Node(){}
    Node(ll _num, ll _pos){
        num = _num;
        pos = _pos;
    }
}q[maxn];
ll b[maxn], a[maxn], t[maxn];
bool get(const Node& a, const Node& b){
    return a.num < b.num;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int kase, m, d;
    ll n;
    scanf("%d", &kase);
    while(kase--){
        scanf("%lld%d%d", &n, &m, &d);
        for(int i = 1; i <= m; ++i){
            scanf("%lld%lld%lld", &a[i], &b[i], &t[i]);
        }
        int now = 0, pre = 1;
        memset(dp, 0, sizeof dp);
        int tail = -1, head = 0;
        ll ma = n, last = 0;
        for(int i = 1; i <= m; ++i){
            swap(now,pre);
            ma = min(n, (t[i] - last)*d+1);
            tail=-1;head =0;
            for(int j = 1; j <= ma; ++j) {
                Node nw = Node(dp[pre][j],j);
                while(head <= tail && get(q[tail], nw)) tail--;
                q[++tail] = nw;
            }
            ma = (t[i] - last)*d;
            for(int j = 1; j <= n; ++j){
                if(j+ma<=n) {
                    Node nw = Node(dp[pre][j+ma], j+ma);
                    while(head <= tail && get(q[tail], nw)) tail--;
                    q[++tail] = nw;
                }
                while(head <= tail && abs(q[head].pos - j) > ma) head++;
                dp[now][j] = q[head].num + b[i] - abs(a[i] - j);
            }
            last = t[i];
        }
        ll ans = -INF;
        for(int i = 1; i <= n; ++i){
            ans = max(ans, dp[now][i]);
        }
        cout << ans << "\n";
    }
	return 0;
}
