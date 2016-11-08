/*************************************************************************
    > File Name: d.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016?08?15? ??? 14?30?23?
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
double x[maxn], y[maxn];
double dis[1100][1100];
inline double getdis(int i, int j){
    double dis = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
    return sqrt(dis);
}

typedef pair<double,double> Node;


double dd[2][maxn];
double ansx[maxn], ansy[maxn];
double w;
int n;
Node node[maxn];
struct Nnode{
    double dis;
    int id, flag;
    Nnode(){}
    Nnode(double _dis, int _id, int _flag){
        dis = _dis;
        id = _id;
        flag = _flag;
    }
    bool operator < (const Nnode& rhs)const{
        return dis > rhs.dis;
    }
};
void spfa(){
    for(int i = 1; i <= n; ++i){
        node[i].first = x[i];
        node[i].second = y[i];
    }
    sort(node+1,node+n+1);
    for(int i = 1; i <= n; ++i){
        x[i] = node[i].first;
        y[i] = node[i].second;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; ++j){
            dis[i][j] = dis[j][i] = getdis(i,j);
        }
    }
   /* for(int i = 1; i <= n; ++i){
        dd[0][i] = x[i];
        dd[1][i] = w-x[i];
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            dd[0][i] = min(dd[0][i], max(dis[i][j], dd[0][j]));
        }
    }
    for(int i = n; i > 0; --i){
        for(int j = n; j > i; --j){
            dd[1][i] = min(dd[1][i], max(dis[i][j], dd[1][j]));
        }
    }*/
    double ans = w/2;
    double xx = w/2,yy=0;
   /* for(int i = 1; i <= n; ++i){
        double temp = max(x[i]/2, dd[1][i]);
        if(temp < ans){
            ans = min(ans, temp);
            xx = x[i]/2;
            yy = y[i];
        }
        temp = max((w-x[i])/2, dd[0][i]);
        if(temp < ans){
            ans = min(ans, temp);
            xx = (x[i]+w)/2;
            yy = y[i];
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            double ddd = max(dd[0][i], dd[1][j]);
            ddd = max(ddd, dis[i][j]/2);
            if(ddd<ans){
                xx = (x[i]+x[j])/2;
                yy = (y[i]+y[j])/2;
                ans = ddd;
            }
        }
    }*/
    priority_queue<Nnode> pq;
    for(int i = 1; i <= n; ++i){
        dd[0][i] = x[i];
        dd[1][i] = x[i]/2;
        ansx[i] = x[i]/2;
        ansy[i] = y[i];
        pq.push(Nnode(dd[0][i], i, 0));
        pq.push(Nnode(dd[1][i], i, 1));
    }
    dd[1][n+1] = 1e18;
    while(pq.size()){
        Nnode uu = pq.top(); pq.pop();
        if(uu.id==n+1){
            printf("%.3f %.3f\n", ansx[n+1], ansy[n+1]);
            return;
        }
        if(uu.flag == 0){
            for(int i = 1; i <= n; ++i){
                double temp = max(dd[0][uu.id], dis[uu.id][i]);
                if(temp < dd[0][i]){
                    dd[0][i] = temp;
                    pq.push(Nnode{temp, i, 0});
                }
                temp = max(dd[0][uu.id], dis[uu.id][i]/2);
                if(temp < dd[1][i]){
                    dd[1][i] = temp;
                    ansx[i] = (x[i] + x[uu.id])/2;
                    ansy[i] = (y[i] + y[uu.id])/2;
                    pq.push(Nnode{temp, i, 1});
                }
            }
            double temp = max(dd[0][uu.id], (w-x[uu.id])/2);
            if(temp < dd[1][n+1]){
                dd[1][n+1] = temp;
                ansx[n+1] = (w+x[uu.id])/2;
                ansy[n+1] = y[uu.id];
                pq.push(Nnode{temp, n+1, 1});
            }

        }
        else{
            for(int i = 1; i <= n; ++i){
                double temp = max(dd[1][uu.id], dis[uu.id][i]);
                if(temp < dd[1][i]){
                    dd[1][i] = temp;
                    ansx[i] = ansx[uu.id];
                    ansy[i] = ansy[uu.id];
                    pq.push(Nnode{temp, i, 1});
                }
            }
            double temp = max(dd[1][uu.id], (w-x[uu.id]));
            if(temp < dd[1][n+1]){
                dd[1][n+1] = temp;
                ansx[n+1] = ansx[uu.id];
                ansy[n+1] = ansy[uu.id];
                pq.push(Nnode{temp, n+1, 1});
            }
        }
    }

    printf("%.3f %.3f\n",xx,yy);
}
int main(){
    freopen("froggy.in","r",stdin);
    freopen("froggy.out","w",stdout);
    cin >> w >> n;
    for(int i = 1; i <= n; ++i){
       cin>>x[i]>>y[i];
    }
    spfa();
    return 0;
}
