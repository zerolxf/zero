/*************************************************************************
    > File Name: b.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月10日 星期六 22时47分06秒
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
typedef pair<int,int> P;
map<string,P> st;
bool vis[400][440];
int n, m;
P getpos(int x, int y){
    P ans(0,0);
    for(int i = y; i <= m; ++i) {
        if(!vis[x][i]) {
            return P(x,i);
        }
    }
    for(int i = x+1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(!vis[i][j]){
                return P(i,j);
            }
        }
    }
    return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int k;
    memset(vis,0,sizeof vis);
    while(cin>>n>>m>>k){
        string op, name;
        int x, y;
        rep(i,k){
            cin>>op;
            if(op[0] == '+'){
                cin>>x>>y>>name;
                P ans = getpos(x,y);
                if(ans.second==0&&ans.first==0) continue;
                vis[ans.first][ans.second] = true;
                st[name] = ans;
            }else{
                cin>>name;
                if(st.count(name)){
                    int x = st[name].first, y = st[name].second;
                    printf("%d %d\n", x, y);
                    vis[x][y] = false;
                    //pr(x);prln(y);
                    //prln(vis[x][y]);
                    st.erase(name);
                }else{
                    printf("-1 -1\n");
                }
            }
        }
    }
	return 0;
}
