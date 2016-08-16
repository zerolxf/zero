/*************************************************************************
	> File Name: j.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月04日 星期四 09时41分10秒
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
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
const int N = 26;
int tot;
int n;
int c[maxn];
int lson[maxn], rson[maxn];
int update(int pos, int root, int val){
    int newnode = tot++, tmp = newnode;
    c[newnode] = c[root] + val;
    pr(pos);prln(c[newnode]);
    int l = 1, r = n;
    while(l < r){
        int mid = (l+r) >> 1;
        pr(l);prln(r);
        if(pos <= mid){
            lson[newnode] = tot++, rson[newnode] = rson[root];
            newnode = lson[newnode], root = rson[root];
            r = mid;
        }else{
            lson[newnode] = lson[root], rson[newnode] = tot++;
            newnode = rson[root], root = rson[root];
            l = mid+1;
        }
        pr(l);pr(r);
        c[newnode] = c[root] + val;
        prln(c[newnode]);
    }
    return tmp;
}
int T[maxn];
char s[maxn];
int nxt[maxn][26], last[maxn];
int siz;
int build(int l, int r){
    int root = tot++;
    c[root] = 0;
    if(l < r){
        int mid = (l+r) >> 1;
        lson[root] = build(l, mid);
        rson[root]= build(mid+1, r);
    }
    return root;
}
void insert(int num){
    scanf("%s", s);
    int len = strlen(s);
    int root = 0;
    T[num] = update(num, T[num], len);
    for(int i = 0; i < len; ++i){
        int cc = s[i] - 'a';
        int &u = nxt[root][cc];
        pr(i);
        prln(s[i]);
        if(u != -1){
            if(last[u]>0)
            T[num] = update(last[u], T[num], -1);
        }else{
            u = ++siz;
            for(int j = 0; j < 26; ++j){
                nxt[u][j] = -1;
            }
            //T[num] = update(last[u], T[num], -1);
        }
        root = u;
        last[u] = num;
    }
}
int query(int rt, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return c[rt];
    }
    int mid = (l+r) >> 1;
    int ans = 0;
    if(mid >= ql) ans += query(lson[rt], l, mid, ql, qr);
    if(mid < qr) ans += query(rson[rt], mid+1, r, ql, qr);
    return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    //int t;
    //scanf("%d", &t);
    while(scanf("%d", &n) != EOF){
        //scanf("%d", &n);
        siz = tot = 0;
        memset(last, 0, sizeof last);
        memset(nxt[0], -1, sizeof nxt[0]);
        T[0] = build(1, n);
        prln(T[0]);
        for(int i = 1; i <= n; ++i){
            T[i] = T[i-1];
            prln("*************");
            prln(i);
            prln(T[i]);
            insert(i);
            prln(T[i]);
            prln("--------------");
        }
        int q, l, r;
        scanf("%d", &q);
        int ans = 0;
        for(int i = 0; i <q ; ++i){
            scanf("%d%d", &l, &r);
            l = min((l+ans)%n,(r+ans)%n)+1;
            r = max((l+ans)%n,(r+ans)%n)+1;
            pr(l);prln(r);
            //l++;r++;
            ans = query(T[r], 1, n, l, r);
            printf("%d\n", ans);
        }

    }
	return 0;
}
