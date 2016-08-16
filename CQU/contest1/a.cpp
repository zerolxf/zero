/*************************************************************************
	> File Name: a.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月18日 星期一 20时28分00秒
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
const int maxn = 2e3+100;
const int INF = 0x3f3f3f3f;
int tree[maxn][maxn], t[maxn];
pair<int,int> a[maxn];
bool cmp(const pair<int,int> x, const pair<int,int> y){
    if(x.first != y.first) return x.first > y.first;
    return x.second < y.second;
}
int n;
int cnt;
void add(int x, int y, int v){
    for(; y <= cnt; y += y&(-y)) tree[x][y] = max(tree[x][y], v);
}
int query(int x, int y){
    int ret = 0;
    for(; y; y -= y&(-y)) ret = max(tree[x][y], ret);
    return ret;
}
void slove(){
    cnt = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d%d", &a[i].first, &a[i].second);
        t[cnt++] = a[i].second;
    }
    sort(t, t+cnt);
    cnt = unique(t, t+cnt) - t;
    for(int i = 1; i <= n; ++i){
        a[i].second = lower_bound(t, t+cnt, a[i].second) - t + 1;
    }
    sort(a+1, a+1+n, cmp);
    memset(tree, 0, sizeof tree);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= cnt; ++j) t[j] = query(j, a[i].second)+1;
        //pr(i);pr(a[i].first);prln(a[i].second);
        for(int j = 1; j <= cnt; ++j){
            //pr(i);pr(j);prln(t[j]);
            add(j, a[i].second, t[j]);
            add(a[i].second, j, t[j]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= cnt; ++i){
        ans = max(ans, query(i,cnt));
    }
    printf("%d\n", ans);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--){
        slove();
    }
	return 0;
}
