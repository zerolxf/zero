#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 4e5+1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int dp[maxn], a[maxn];
bool in[maxn];
int n;
void dfs(){
    for(int i = 1; i <= n; ++i){
        dp[i] = INF;
        in[i] = false;
    }
    queue<int> q;
    q.push(1);
    dp[1] = 0;
    in[1] = true;
    while(q.size()){
        int u = q.front();
        q.pop();
        in[u] = false;
        if(u+1<=n){
            if(dp[u+1]>dp[u]+1){
                dp[u+1] = dp[u]+1;
                if(!in[u+1]){
                    in[u+1] = true;
                    q.push(u+1);
                }
            }
        }
        if(u-1<=n&&u-1>0){
            if(dp[u-1]>dp[u]+1){
                dp[u-1] = dp[u]+1;
                if(!in[u-1]){
                    in[u-1] = true;
                    q.push(u-1);
                }
            }
        }
        if(dp[a[u]] > dp[u]+1){
            dp[a[u]] = dp[u]+1;
            if(!in[a[u]]){
                in[a[u]] = true;
                q.push(a[u]);
            }
        }
    }
}
struct Node{
    int a, dis;
    Node(){}
    Node(int _a, int _dis){
    a = _a;
    dis = _dis;}
    bool operator < (const Node& rhs)const{
        return dis > rhs.dis;
    }
};
void dijstra(){

    dp[1] = 0;
    priority_queue<Node> pq;
    pq.push(Node(1,0));
    while(pq.size()){
        Node x = pq.top();pq.pop();
        int u = x.a;
        if(u+1<=n && dp[u+1]>dp[u]+1){
            dp[u+1] = dp[u]+1;
            pq.push(Node(u+1,dp[u+1]));
        }
        if(u-1>0 && dp[u-1]>dp[u]+1){
            dp[u-1] = dp[u]+1;
            pq.push(Node(u-1,dp[u-1]));
        }
        if(a[u]>u&&dp[a[u]] > dp[u]+1){
            dp[a[u]] = dp[u]+1;
            pq.push(Node(a[u],dp[a[u]]));
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif

    cin >> n;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            dp[i] = i-1;
        }
        dfs();
       //dijstra();
        printf("%d",dp[1]);
        for(int i = 2; i <= n; ++i){

            printf(" %d",dp[i]);
           // ans = min(ans, dp[i]);
        }
        printf("\n");


    return 0;
}
