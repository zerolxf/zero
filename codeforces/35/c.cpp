/*************************************************************************
    > File Name: c.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月10日 星期六 23时14分18秒
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
int dis[2100][2100];
typedef pair<int,int> P;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    memset(dis, 0x3f, sizeof dis);
    int k, n, m;
    queue<P> q;
    while(cin>>n>>m>>k){
        rep(i,k){
            int x, y;
            cin>>x>>y;
            q.push(P(x,y));
            dis[x][y] = 0;
        }
        while(q.size()){
            P u = q.front(); q.pop();
            for(int i = 0; i < 4; ++i){
                int nx = u.first + dx[i];
                int ny = u.second + dy[i];
                if(nx<=0||nx>n||ny<=0||ny>m) continue;
                if(dis[nx][ny]>dis[u.first][u.second]+1){
                    dis[nx][ny] = dis[u.first][u.second]+1;
                    q.push(P(nx,ny));
                }
            }
        }
        P ans(1,1);
        int ma = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(dis[i][j]>=ma){
                    ma = dis[i][j];
                    ans = P(i,j);
                }
            }
        }
        //prln(ma);
        printf("%d %d\n", ans.first, ans.second);
        
    }

	return 0;
}
