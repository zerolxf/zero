/*************************************************************************
    > File Name: a.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月16日 星期五 19时29分08秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 200+100;
const int INF = 0x3f3f3f3f;
char s[maxn][maxn];
string str[maxn];
struct Node{
    int id;
    bool operator  < (const Node& rhs){
        return str[id] < str[rhs.id];
    }
    Node(){}
    Node(int _id){
        id = _id;
    }
}node[maxn];
int v[maxn];
int dp[maxn][maxn];
bool vis[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, m;
    while(cin >> n >> m){
        for(int i = 0; i < n; ++i){
            scanf("%s", s[i]);
        }
        int ans = 0;
        memset(vis, 0 , sizeof vis);
       for(int j = 0; j < m; ++j){
           bool ok = true;
           bool big[maxn];
           memset(big, 0, sizeof big);
           for(int i = 0; i < n-1; ++i){
               if(vis[i]) continue;
               if(s[i][j] < s[i+1][j]){
                   big[i] = true;
               }else if (s[i][j] > s[i+1][j]) {
                   ok = false;
                 }
           }
           if(!ok){
               ans++;
               continue;
           }
           for(int i = 0; i < n-1; ++i){
               if(big[i]) vis[i] = true;
           }
       }
       cout << ans << endl;
    }

	return 0;
}
