/*************************************************************************
	> File Name: d.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年06月02日 星期四 01时39分29秒
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
struct Node{
    int id, x, y, t;
    Node(){}
    Node(int _id, int _x, int _y, int _t){
        id = _id;
        x = _x;y=_y;
        t = _t;
    }
    bool operator <(const Node& rhs)const{
        return t  > rhs.t || (t==rhs.t&&id<rhs.id);
    }
};
int dis[400][400], id[400][400];

struct Nd{
    int x, y;
    Nd(){}
    Nd( int _x, int _y){
         x = _x, y = _y;
    }
};
struct Nnode{
    int id, x, y;
    Nnode(){}
    Nnode(int _id, int _x, int _y){
        id = _id, x = _x, y = _y;
    }
    bool operator <(const Nnode& rhs)const{
        return id < rhs.id;
    }
}a[maxn];
bool in[400][400];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    priority_queue<Node> q;
    int n, m, p;
    while(cin >> n >> m >> p){
        while(q.size()) q.pop();
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= m; ++j){
                dis[i][j] = INF;
            }
        }
        int cnt = 0;
        int srcx, srcy;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                scanf("%d",&id[i][j]);
                if(id[i][j] == p) srcx = i, srcy = j;
                a[cnt++] = Nnode(id[i][j], i, j);
            }
        }
        sort(a, a+cnt);
        //prln(cnt);
        Nnode temp1 = Nnode(1,0,0);
        q.push(Node(0, 0, 0, 0));
        queue<Nd> qq;
            int l = lower_bound(a,a+cnt,temp1)-a;
            int r = upper_bound(a,a+cnt,temp1)-a;
            //pr(l);prln(r);
            for(int i = l; i < r; ++i){
                   // prln(x.t+abs(x.x-a[i].x)+abs(x.y-a[i].y));
                if(abs(a[i].x)+abs(a[i].y)<dis[a[i].x][a[i].y]){
                    //prln(x.t+abs(x.x-a[i].x)+abs(x.y-a[i].y));
                    dis[a[i].x][a[i].y] = abs(a[i].x)+abs(a[i].y);
                    if(!in[a[i].x][a[i].y]){
                        qq.push(Nd(a[i].x, a[i].y));
                        in[a[i].x][a[i].y] = true;
                    }
                }
            }
        while(qq.size()){
            Nd xx = qq.front(); qq.pop();
            in[xx.x][xx.y] = false;
            Node x;
            x.id = id[xx.x][xx.y];
            x.t = dis[xx.x][xx.y];
            x.x = xx.x;x.y = xx.y;
            temp1.id = x.id+1;
            //prln(temp1.id);
            //pr(x.id);prln(x.t);
            int l = lower_bound(a,a+cnt,temp1)-a;
            int r = upper_bound(a,a+cnt,temp1)-a;
            //pr(l);prln(r);
            for(int i = l; i < r; ++i){
                   // prln(x.t+abs(x.x-a[i].x)+abs(x.y-a[i].y));
                if(x.t+abs(x.x-a[i].x)+abs(x.y-a[i].y)<dis[a[i].x][a[i].y]){
                    //prln(x.t+abs(x.x-a[i].x)+abs(x.y-a[i].y));
                    dis[a[i].x][a[i].y] = x.t + abs(x.x-a[i].x)+abs(x.y-a[i].y);
                    if(!in[a[i].x][a[i].y]) qq.push(Nd(a[i].x, a[i].y));
                }
            }
        }
        printf("%d\n", dis[srcx][srcy]);
    }
	return 0;
}
