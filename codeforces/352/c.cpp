/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月12日 星期四 00时56分40秒
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
bool vis[maxn];
struct Node{
    int x, y;
    double da, db, dc;
    bool operator < (const Node& rhs)const{
        return dc < rhs.dc;
    }
}node[maxn];
double ax, ay, bx, by, cx, cy;
double x[10], y[10];
double getdis(int id, int t) {
    double ans = 0;
    ans = (node[id].x-x[t])*(node[id].x -x[t]) + (node[id].y-y[t])*(node[id].y-y[t]);
    return sqrt(ans);
}
        int n;
double geta(double x) {
    double ans = x;
    int pos = n;
    for(int i = 0; i < n; ++i){
        if(!vis[i]) {
            if(node[i].da - node[i].dc < ans) {
                ans = node[i].da - node[i].dc;
                pos = i;
            }
        }
    }
    vis[pos] = true;
    return ans;
}
double getb(double x) {
    double ans = x;
    int pos = n;
    for(int i = 0; i < n; ++i){
        if(!vis[i]) {
            if(node[i].db - node[i].dc < ans) {
                ans = node[i].db - node[i].dc;
                pos = i;
            }
        }
    }
    vis[pos] = true;
    return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2]){
        cin >> n;
        for(int i = 0; i < n; ++i){
            scanf("%d%d", &node[i].x, &node[i].y);
            node[i].da = getdis(i,0);
            node[i].db = getdis(i,1);
            node[i].dc = getdis(i,2);
        }
        double ans = 0;
        if(n == 1) {
            ans += min(node[0].da,node[0].db) + node[0].dc;
            printf("%.9f\n", ans);
        }else {
            double sum = 0;
            for(int i = 0; i < n; ++i){
                sum += 2*node[i].dc;
            }
            memset(vis, 0, sizeof vis);
            double aa = geta(1e13);
            aa += getb(0);
            memset(vis, 0, sizeof vis);
            double bb = getb(1e13);
            bb += geta(0);
            sum += min(aa,bb);
            printf("%.12f\n", sum);
        }
    }
	return 0;
}
