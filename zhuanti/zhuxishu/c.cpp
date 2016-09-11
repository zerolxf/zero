/*************************************************************************
    > File Name: c.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月08日 星期一 19时16分56秒
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
const int maxn = 3e6+100;
const int INF = 0x3f3f3f3f;
int lson[maxn], rson[maxn], c[maxn], t[maxn];
int a[maxn];
int T[maxn];
int n;
int tcnt;
void inithash(){
    sort(t+1, t+1+tcnt);
    tcnt = unique(t+1, t+1+tcnt) - t-1;
}
int tot;
int getid(int x){
    int pos = lower_bound(t+1, t+1+tcnt, x) - t;
    return pos;
}
int build(int l, int r){
    if(l>r) return 0;
    int root = tot++;
    c[root] = 0;
    if(l!=r){
        int mid = (l+r) >> 1;
        lson[root] = build(l, mid);
        rson[root] = build(mid+1, r);
    }
    return root;
}
int update(int pos, int root, int val){
    int newnode = tot++;
    int tmp = newnode;
    c[newnode] = c[root] + val;
    int l = 1, r = tcnt;
    while(l < r){
        int mid = (l+r) >> 1;
        if(pos <= mid){
            lson[newnode] = tot++, rson[newnode]  = rson[root];
            newnode = lson[newnode], root = lson[root];
            r = mid;
        }else{
            lson[newnode] = lson[root], rson[newnode] = tot++;
            newnode = rson[newnode], root = rson[root];
            l = mid+1;
        }
        c[newnode] = c[root] + val;
    }
    return tmp;
}
int query(int pos, int lr, int rr){
    int ans = 0;
    int l = 1, r = tcnt;
    if(l>pos) return 0;
    if(r<=pos) return c[rr]-c[lr];
    //pr(l);prln(r);
    while(l < r){
        int mid = (l+r) >> 1;
        //pr(l);prln(r);
        //prln(mid);
        if(mid <= pos){
            //pr(l);prln(r);
            //pr(mid);pr(pos);pr(t[mid]);pr(t[pos]);pr(c[lson[rr]]);prln(c[lson[lr]]);
            ans += c[lson[rr]] - c[lson[lr]];
            lr = rson[lr];
            rr = rson[rr];
            l = mid+1;
        }else{
            lr = lson[lr];
            rr = lson[rr];
            r = mid;
            //if(l==r&&l<=pos) ans += c[rr] - c[lr];
        }
    }
    if(l==r&&l<=pos) ans += c[rr] - c[lr];
    return ans;
}
int qq[maxn][3];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int tt,  q, l, r, k;
    int kase = 0;
    scanf("%d", &tt);
    while(tt--){
        tot = 0;
        printf("Case %d:\n",++kase);
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            t[i] = a[i];
        }
        tcnt = n;
        //for(int i = 0; i < q; ++i){
            //scanf("%d%d%d", &qq[i][0], &qq[i][1], &qq[i][2]);
            //t[++tcnt] = qq[i][2];
        //}
        inithash();
        T[0] = build(1, tcnt);
        for(int i = 1; i <= n; ++i){
            int pos = getid(a[i]);
            T[i] = update(pos, T[i-1], 1);
        }
        for(int i = 0; i < q; ++i){
            scanf("%d%d%d", &l, &r, &k);
            //l = qq[i][0], r = qq[i][1], k = qq[i][2];
            l++,r++;
            int pos = getid(k);
            //if(pos == 1 && t[pos] != k){
                //printf("0\n");
                //continue;
            //}
            if(t[pos] != k || pos == tcnt+1) pos--;
            int ans = query(pos, T[l-1], T[r]);
            printf("%d\n",ans);
        }
    }
    

	return 0;
}
