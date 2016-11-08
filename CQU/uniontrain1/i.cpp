/*************************************************************************
	> File Name: i.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月04日 星期三 19时57分47秒
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
int dis[55][55][4][5];
char mp[55][55];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int n, m;
struct Node{
    int x, y, d, c;
    Node(){};
    Node(int _x, int _y, int _d, int _c){
        x = _x;
        y = _y;
        c = _c;
        d = _d;
    }
};
void bfs(int x, int y){
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= m; ++j){
            for(int l = 0; l < 4; ++l){
                for(int k = 0; k < 5; ++k){
                    dis[i][j][l][k] = INF;
                }
            }
        }
    }
    queue<Node> q;
    dis[y][x][0][0] = 0;
    q.push(Node(x,y,0,0));
    int nx, ny, nc, nd;
    while(q.size()){
        Node u = q.front(); q.pop();
        for(int i = 3; i < 6; ++i){
            nd = (u.d+i)%4;
            nx = u.x + dx[nd];
            ny = u.y + dy[nd];
            nc = (u.c+1)%5;
            int temp = 1;
            if(i == 4) {
                temp = 0;
            } else {
                if(dis[u.y][u.x][nd][u.c] > dis[u.y][u.x][u.d][u.c]+1){
                   dis[u.y][u.x][nd][u.c] = dis[u.y][u.x][u.d][u.c]+1;
                   q.push(Node(u.x,u.y,nd,u.c));
                }
            }
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(mp[ny][nx] == '#') continue;
            if(i==4)
            if(dis[ny][nx][nd][nc] > dis[u.y][u.x][u.d][u.c] + 1 + temp){
                dis[ny][nx][nd][nc] = dis[u.y][u.x][u.d][u.c] + 1 + temp;
                q.push(Node(nx,ny,nd,nc));
            }
        }
    }
}
void print() {
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int x = INF;
            for(int l = 0; l < 4; ++l){
                for(int k = 0; k < 5; ++k){
                    x = min(x, dis[i][j][l][k]);
                }
            }
            if(x!=INF){
                pr(x);
            } else pr(-1);
        }
            printf("\n");
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        int sx,sy,ex,ey;
        for(int i = 0; i < n; ++i){
            scanf("%s", mp[i]);
            for(int j = 0; j < m; ++j){
                if(mp[i][j] == 'S') {
                    sx = j; sy = i;
                }
                if(mp[i][j] == 'T'){
                    ex = j;ey = i;
                }
            }
        }
        bfs(sx,sy);
        int ans = INF;
    //    print();
        for(int i = 0; i < 4; ++i){
            ans = min(ans, dis[ey][ex][i][0]);
        }
        if(ans < INF) printf("%d\n",ans);
        else printf("-1\n");
    }
	return 0;
}
