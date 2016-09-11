/*************************************************************************
    > File Name: g.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月15日 星期一 13时30分44秒
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
#define pr(x) //cout << #x << " = " << x << " ";
#define prln(x)// cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
int vis[maxn];
int x, a, b, c;
int cntd;
int has[maxn];
typedef pair<int,int> Node;
vector<Node> last[maxn];
Node d[maxn];
int main(){
	freopen("generators.in","r",stdin);
	freopen("generators.out","w",stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    rep(i,n){
        scanf("%d%d%d%d", &x, &a, &b, &c);
        int lastnum = x;
        cntd = 0;
        d[cntd].first = x;
        d[cntd].second = cntd;
        cntd++;
        vis[x] = i+1;
        while(true){
            int now = a*lastnum+b;
            now = now%c;
            if(vis[now]==i+1) break;
            vis[now] = i+1;
            d[cntd].first = now;
            d[cntd].second = cntd;
            //pr(d[cntd].first);
            //prln(d[cntd].second);
            cntd++;
            lastnum = now;
        }
        sort(d, d+cntd);
        //for(int j = 0; j < cntd; ++j){
            //prln(j);
            //pr(d[j].first);prln(d[j].second);
        //}
        int m = 0;
        for(int j = cntd-1; j >= 0; --j){


            //pr(j);pr(d[j].second);
            //prln(d[j].first);
            if(m>=2) break;
            if(has[d[j].first%k] == i+1) continue;
            has[d[j].first%k] = i+1;
            last[i].push_back(d[j]);
            m++;
        }
    }
    ll ans = -1;
    ll temp =0;
    rep(i,n){
        temp += last[i][0].first;
    }
    int flag = -1;
    if(temp%k) {
        ans = max(ans, temp);
    }
    else{
        ll ttemp = temp;
        rep(i,n){
            if(last[i].size() >= 2){
                ttemp = temp-last[i][0].first+last[i][1].first;
                if(ttemp%k){
                    if(ttemp>ans){
                        ans = ttemp;
                        flag = i;
                    }
                }
            }
        }
    }
    if(ans==-1) {
        printf("-1\n");
        return 0;
    }
    printf("%lld\n",ans);
    rep(i,n){
        if(i==flag) printf("%d ",last[i][1].second);
        else printf("%d ",last[i][0].second);
    }
    printf("\n");


	return 0;
}
