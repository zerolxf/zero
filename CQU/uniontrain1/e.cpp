/*************************************************************************
	> File Name: e.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月04日 星期三 16时10分44秒
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
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char mp[610][610];
struct Node{
    int x, y;
    Node(){}
    bool operator == (const Node& rhs)const{
        return x== rhs.x&&y==rhs.y;
    }
    Node(int _x, int _y){
        x = _x; y = _y;
    }
};
int k, n, m;
Node node[155];
int dis[660][660], d[160][160];
int cnt;
bool bfs(int id){
    queue<Node> q;
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= m; ++j){
            dis[i][j] = INF;
        }
    }
    q.push(node[id]);
    dis[node[id].y][node[id].x] = 0;
    while(q.size()){
        Node u = q.front(); q.pop();
        for(int i = 0; i < 4; ++i){
            int nx = u.x + dx[i];
            int ny = u.y + dy[i];
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(mp[ny][nx] == 'W') continue;
            if(dis[ny][nx] > dis[u.y][u.x] + 1){
                dis[ny][nx] = dis[u.y][u.x] + 1;
                q.push(Node(nx,ny));
            }
        }
    }
    for(int i = 0; i < cnt; ++i){
        if(dis[node[i].y][node[i].x] >= k) d[id][i] = INF;
        else d[id][i] = dis[node[i].y][node[i].x];
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    int src, des;
    while(t--){
        scanf("%d%d%d", &n, &m, &k);
        cnt = 0;
        for(int i = 0; i < n; ++i){
            scanf("%s", mp[i]);
            for(int j = 0; j < m; ++j){
                if(mp[i][j] == 'S') src = cnt;
                if(mp[i][j] == 'E') des = cnt;
                if(mp[i][j] != 'W' && mp[i][j] != '.') node[cnt++] = Node(j,i);
            }
        }
        for(int i = 0; i < cnt; ++i) bfs(i);
        for(int k = 0; k < cnt; ++k){
            for(int i = 0; i < cnt; ++i){
                for(int j = 0; j < cnt; ++j){
                    if(d[i][k] + d[k][j] <= d[i][j]) d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
        if(d[src][des] < INF) printf("%d\n", d[src][des]);
        else printf("Poor RunningPhoton!\n" );
        
    }
	return 0;
}
