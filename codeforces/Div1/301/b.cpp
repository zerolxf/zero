/*************************************************************************
    > File Name: b.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月29日 星期六 14时12分57秒
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
#define repp(i,n, x) for(int i = x; i<n+x;++i) 
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
int x[300], y[300];
int getdis(int i, int j){
    return abs(x[i]-x[j]) + abs(y[i] - y[j]);
}
ll dis[330][330];
ll a[330];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    ll n, d;
    cin >> n >> d;
    a[1] = a[n] = 0;
    repp(i,n-2,2){
        cin>>a[i];
    }
    repp(i,n,1){
        cin>>x[i]>>y[i];
    }
    memset(dis, 0x3f, sizeof  dis);
    repp(i,n,1){
        dis[i][i] = 0;
    }
    repp(i,n,1){
        repp(j,n,1){
            if(i==j) continue;
            dis[i][j] = getdis(i,j)*d - a[i];
        }
    }
    repp(k,n,1){
        repp(i,n,1){
            repp(j,n,1){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    cout << dis[1][n] << "\n";

	return 0;
}
