/*************************************************************************
    > File Name: l.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月11日 星期四 00时41分00秒
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
const int N = 5e4+10;
const int maxn = N*160;
const int INF = 0x3f3f3f3f;
int T[maxn];
int tot, ls[maxn], rs[maxn], c[maxn];
struct Line{
    int x,y;
    bool operator <(const Line& rhs)const {
        return (x==rhs.x&&y<rhs.y) || x < rhs.x;
    }
}line[N];
int build(int l, int r){
    int rt = tot++;
    c[rt] = 0;
    if(l!=r){
        int mid = (l+r)>>1;
        ls[rt] = build(l,mid);
        rs[rt] = build(mid+1, r);
    }
    return rt;
}
int update(int rt, int pos, int l, int r, int v){
    int newnode = tot++;
    c[newnode] = c[rt] + v;
    if(l!=r){
        int mid = (l+r) >>1;
        if(mid >= pos) {
            ls[newnode] = update(ls[rt], pos, l, mid, v);
            rs[newnode] = rs[rt];
        }else{
            rs[newnode] = update(rs[rt], pos, mid+1, r, v);
            ls[newnode] = ls[rt];
        }
    }
    return newnode;
}
int query(int rt, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return c[rt];
    }
    int mid = (l+r) >> 1;
    int ans = 0;
    if(mid >= ql) ans += query(ls[rt], l, mid, ql, qr);
    if(mid < qr) ans += query(rs[rt], mid+1, r, ql, qr);
    return ans;
}
vector<int> B[N+100];
int last[N+100];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    while(scanf("%d", &n) != EOF){
        if(n==0) break;
        int x = 0, y = 0;
        tot=0;
        memset(c,0,sizeof c);
        for(int i = 1; i <= N; ++i){
            B[i].clear();
        }
        for(int i = 0; i < n; ++i){
            scanf("%d%d", &x, &y);
            //line[i] = Line{x,y};
            B[x].push_back(y);
        }
        for(int i = 1; i <= N; ++i){
            sort(B[i].begin(), B[i].end());
            B[i].erase(unique(B[i].begin(), B[i].end()), B[i].end());
        }
        T[0] = build(1, N);
        memset(last, 0, sizeof last);
        bool ok = true;
        for(int i = 1; i <= N; ++i){
            if(!ok) break;
            int usiz = B[i].size();
            T[i] = T[i-1];
            if(usiz){
                //pr(i);prln(usiz);
            }
            for(int j = 0; j < usiz; ++j){
                int up = j==usiz-1?N+1:B[i][j+1];
                int down = j==0?0:B[i][j-1];
                //prln(i);
                //pr(B[i][j]);prln(last[B[i][j]]);
                //prln(T[i]);prln(T[last[B[i][j]]]);
                int num = query(T[i], 1, N, down+1, up-1) - query(T[last[B[i][j]]], 1, N, down+1, up-1);
                //prln(query(T[i], 1, N, down+1, up-1));
                //prln(num);
                if(num){
                    ok = false;
                    break;
                }
            }
            for(int j = 0; j < usiz; ++j){
                T[i] = update(T[i], B[i][j], 1, N, 1);
                last[B[i][j]] = i;
                //prln(i);
                //prln(T[i]);

            }
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }

	return 0;
}
