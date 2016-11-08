/*************************************************************************
    > File Name: i.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月07日 星期五 18时54分11秒
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

int x[maxn], y[maxn];
typedef pair<int,int> P;
vector<P> vt[5100];
int sum[1510][1510];
inline bool check(P& a, P&b){
    return sum[b.first][b.second] + sum[a.first-1][a.second-1] - sum[a.first-1][b.second] - sum[b.first][a.second-1]>=1;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c) != EOF){
        memset(sum, 0, sizeof sum);
        rep(i,a) scanf("%d", &x[i]);
        rep(i,b) scanf("%d", &y[i]);
        int xx, yy;
        for(int i = 0; i < c; ++i){
            scanf("%d%d", &xx, &yy);
            sum[xx+1][yy+1] = 1;
        }
        for(int i = 1; i < 1200; ++i){
            for(int j = 1; j < 1200; ++j){
                sum[i][j] += sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
            }
        }
        for(int i = 0; i < a; ++i){
            for(int j = 0; j < b; ++j){
                vt[x[i]-y[j]+1500].push_back(P(x[i]+1, y[j]+1));
            }
        }
        ll ans = 0;
        for(int i = 0; i < 5000; ++i){
            int siz = vt[i].size();
            int l = 0, r = 1;
            while(r < siz){
                while(r < siz && !check(vt[i][l], vt[i][r])) r++;
                ans += siz - r;
                //pr(i);pr(siz-r);pr(l);prln(r);
                l++;
                if(r<=l) r++;
            }
        }
        cout << ans << "\n";
    }
	return 0;
}
