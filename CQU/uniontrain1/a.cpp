/*************************************************************************
	> File Name: a.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年05月02日 星期一 19时57分50秒
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
const int maxn = 4e6+100;
const int INF = 0x3f3f3f3f;
int code[40];
struct Node{
    int l, r;
}node[maxn];
int ans, sz;
void build(int pos, int id, int x){
    if(pos == -1) return;
    int c = x & (1<<pos);
    if(c) {
        if(node[id].l == -1) {
            node[id].l = sz++;
        }
        build(pos-1, node[id].l, x);
    } else {
        if(node[id].r == -1){
            node[id].r = sz++;
        }
        build(pos-1, node[id].r, x);
    }
}
void dfs(int pos, int id, int x){
    if(pos == -1) {
        if(x > ans) ans = x;
        return;
    }
    int c = x & (1<<pos);
    if(c) {
        if(node[id].r != -1){
            dfs(pos-1, node[id].r, x);
        } else {
            if((ans&(1<<pos)) && ans >= x) return;
            dfs(pos-1, node[id].l, x^(1<<pos));
        }
    } else {
        if(node[id].l != -1){
            dfs(pos-1, node[id].l, x^(1<<pos));
        } else {
            if((ans&(1<<pos)) && ans >= x) return;
            dfs(pos-1, node[id].r, x);
        }
    }
}
 int a[maxn], b[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, m, t;
    sz = maxn;
    scanf("%d", &t);
    while(t--){
        for(int i = 0; i < sz; ++i){
            node[i].l = node[i].r = -1;
        }
        sz = 1;
        ans = 0;
        int x;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i){
            scanf("%d", &x);
            build(30, 0, x);
        }
        for(int i = 0; i < m; ++i){
            scanf("%d", &x);
            dfs(30, 0, x);
        }
        printf("%d\n", ans);
    }
	return 0;
}
