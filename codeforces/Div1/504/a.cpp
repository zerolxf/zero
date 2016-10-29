/*************************************************************************
    > File Name: a.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月29日 星期六 19时28分26秒
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
#include <ctime>


using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define repp(i,n,x) for(int i =x; i < n+x; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
int cnt[maxn], sum[maxn];
typedef pair<int,int> P;
vector<P> ans;
void dfs(int u){
    if(cnt[u] == 1){
        cnt[u]--,cnt[sum[u]]--;
        sum[sum[u]] ^= u;
        ans.push_back(P(u,sum[u]));
        dfs(sum[u]);
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    while(cin >> n){
        rep(i,n){
            cin >> cnt[i] >> sum[i];
        }
        for(int i = 0; i < n; ++i){
            if(cnt[i] == 1){
                dfs(i);
            }
        }
        int siz = ans.size();
        printf("%d\n",siz);
        for(int i = 0; i < siz; ++i){
            printf("%d %d\n",ans[i].first, ans[i].second);
        }
    }

	return 0;
}
