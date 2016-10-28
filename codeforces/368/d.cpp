#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 2e7+1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int T[N], ls[maxn], rs[maxn], c[maxn], flag[maxn];
int tot;
int newrt(int rt){
    int newnode = tot++;
    ls[newnode] = ls[rt];
    rs[newnode] = rs[rt];
    c[newnode] = c[rt];
    flag[newnode] = flag[rt];
}
int pushdown(int rt, int l, int r){
    if(flag[rt]){

        int newnode = tot++;
        ls[newnode] = newrt(ls[rt]);
        rs[newnode] = newrt(rs[rt]);
        int lls = ls[newnode], rrs = rs[newnode];
        flag[lls] = flag[lls]^flag[rt];
        flag[rrs] = flag[rrs]^flag[rt];
        int mid = (l+r)>>1;
        if(flag[rt]&1){
            c[lls] = (mid-l+1)-c[lls];
            c[rrs] = (r-mid)-c[rrs];
        }
        return newnode;
    }
    return rt;
}
int update(int rt, int l, int r, int pos, int v){
    if(l == r){
        int newnode = newrt(rt);
        c[newnode] = c[newnode] + v;
        if(c[newnode] < 0) c[newnode] = 0;
        if(c[newnode] > 1) c[newnode] = 1;
    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif

    return 0;
}
