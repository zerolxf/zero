/*************************************************************************
	> File Name: n.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月24日 星期日 16时30分17秒
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
int dis[500][500];
struct Node{
    int x, y;
};
vector<Node> vt;
int d;
int dfs(int x, int y){
    if(dis[x][y] != -1) return dis[x][y];
    int vtsiz = vt.size();
    bool ok = false;
    for(int i = 0; i < vtsiz; ++i){
         int nx = x + vt[i].x;
         int ny = y + vt[i].y;
         //pr(nx);prln(ny);
         if((nx-200)*(nx-200)+(ny-200)*(ny-200)>d*d) continue;
         if(!dfs(nx, ny)) ok = true;
    }
    //prln(d);
    //pr(x);prln(y);prln(ok);
    dis[x][y] = ok;
    return ok;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    memset(dis, -1, sizeof dis);
    int x, y, n;
    cin >> x >> y >> n >> d;
    int nx, ny;
    for(int i = 0; i < n; ++i){
        cin >> nx >> ny;
        vt.push_back(Node{nx,ny});
    }
    int ans = dfs(x+200,y+200);
    if(ans) printf("Anton\n");
    else printf("Dasha\n");
	return 0;
}
