/*************************************************************************
    > File Name: i.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月07日 星期日 15时39分08秒
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
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
int dis[20][20];
typedef pair<int,int> Node;
Node node[maxn];
char s[30][30];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dis[30][30];
int n, m;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(scanf("%d%d", &n, &m) != EOF){
        int len = 0;
        Node ed(0,0);
        for(int i = 1; i <= n; ++i){
            scanf("%s", s[i]+1);
            for(int j = 1; j <= m; ++j){
                if(s[i][j] == '@') ed = Node(i,j);
                if(s[i][j] >= '0' && s[i][j] <= '9'){
                    int num = s[i][j] - '0';
                    len = max(len, num);
                    node[num] = Node(i,j);
                }
            }
        }
        for(int i = 0; i <= 20; ++i){
            for(int j = 0; j <= 20; ++j){
                dis[i][j] = INF;
            }
        }
        queue<Node> q;
        q.push(ed);
        dis[ed.first][ed.second] = 0;
        while(q.size()){
            Node u = q.front();
            q.pop();
            for(int i = 0; i < 4; ++i){
                int nx = dx[i] + u.first;
                int ny = dy[i] + u.second;
                if(nx>=1&&nx<=n&&ny>=1&&ny<=m){
                    if(dis[nx][ny]>dis[u.first][u.second]){
                    
                }
            }
        }
    }
	return 0;
}
