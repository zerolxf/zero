/*************************************************************************
	> File Name: i.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月27日 星期三 19时26分13秒
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
const int maxn = 5100;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
struct Node{
    int len,num;
    Node(){}
    Node(int _len, int _num){
        len = _len;
        num = _num;
    }
    Node operator + (const Node& rhs){
        if(rhs.len+2 < len) return Node(len,num);
        if(rhs.len > len-2) {
            return rhs;
        }
        return Node(len, (num+rhs.num)%MOD);
    }
    void update(const Node& rhs){
        if(rhs.len+2 < len) return;
        if(rhs.len > len-2) {
            num = rhs.num;
            len = rhs.len+2;
            return ;
        }
        num += rhs.num;
        num = num%MOD;
        return ;
    }
}dp[maxn][maxn];
int a[maxn];
int n, m;
int b[maxn];
int nxt[maxn][maxn];
int pre[maxn][maxn];
int getid(int x){
    int pos = -1;
    pos = lower_bound(a, a+m, x) - a + 1;
    return pos;
}
void init(){
      for(int i = 1; i <= n+1; ++i){
            for(int j = 1; j <= m; ++j){
                if(b[i-1]==j){
                    pre[i][j] = i-1;
                }else pre[i][j] = pre[i-1][j];
            }
        }
        for(int i = n; i>=0; --i){
            for(int j = 1; j <= m; ++j){
                if(b[i+1]==j){
                    nxt[i][j] = i+1;
                }else nxt[i][j] = nxt[i+1][j];
            }
        }
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= n; ++j){
                dp[i][j] = Node(0,0);
            }
        }
}
void debug(){
    for(int i = 0; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            pr(i);pr(j);prln(nxt[i][j]);
        }
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(scanf("%d", &n) != EOF){
        for(int i = 1; i <= n; ++i){
            scanf("%d", &b[i]);
            a[i-1] = b[i];
        }
        sort(a, a+n);
        m = unique(a, a+n) - a;
        for(int i = 1; i <= n; ++i){
            b[i] = getid(b[i]);
        }
        init();
        memset(pre[0], 0, sizeof pre[0]);
        memset(nxt[n+1], 0, sizeof nxt[n+1]);
        for(int i = 0; i <= m; ++i){
            nxt[n+1][i] = n+1;
        }
        b[0] = 0;
        b[n+1] = 0;
        for(int i = n; i>=0; --i){
            for(int j = i; j <= n+1; ++j){
                if(i == j){
                    dp[i][j] = Node(1, 1);
                    continue;
                }
                if(b[i] != b[j]) continue;
                //pr(i);prln(j);
                dp[i][j] = Node(2,1);
                for(int k = b[i]; k>0; --k){
                    //pr(nxt[i][k]);prln(pre[j][k]);
                    //pr(dp[nxt[i][k]][pre[j][k]].num);
                    //prln(dp[nxt[i][k]][pre[j][k]].len);
                    if(nxt[i][k]>pre[j][k]) continue;
                    dp[i][j].update(dp[nxt[i][k]][pre[j][k]]);
                }
                //pr(dp[i][j].num);prln(dp[i][j].len);
            }
        }
        Node ans(0,0);
        //debug();
        for(int i = 1; i <= m; ++i){
            ans.update(dp[nxt[0][i]][pre[n+1][i]]);
        }
        cout << ans.len-2 << " " << ans.num << "\n";
    }
	return 0;
}
