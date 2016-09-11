/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月18日 星期一 11时22分46秒
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
const int maxn = 3e6;
const int INF = 0x3f3f3f3f;
int a[maxn], t[maxn];
int n, m, tot;
int T[maxn], lson[maxn], rson[maxn], c[maxn];
void inithash(){
    for(int i = 1; i <= n; ++i){
        t[i] = a[i];
    }
    sort(t+1, t+1+n);
    m = unique(t+1,t+1+n)-t-1;
}
int build(int l, int r){
    int root = tot++;
    c[root] = 0;
    if(l!=r){
        int mid = (l+r) >> 1;
        lson[root] = build(l,mid);
        rson[root] = build(mid+1,r);
    }
    return root;
}
int gethash(int x){
    return lower_bound(t+1, t+1+m, x) - t;
}
int update(int root, int pos, int val){
    int newroot = tot++, tmp  = newroot;
    c[newroot] = c[root] + val;
    int l = 1, r = m;
    while(l < r){
        int mid = (l+r) >> 1;
        //pr(l);prln(r);
        if(pos <= mid){
            lson[newroot] = tot++; rson[newroot] = rson[root];
            newroot = lson[newroot]; root = lson[root];
            r = mid;
        }else{
            rson[newroot] = tot++; lson[newroot] = lson[root];
            newroot = rson[newroot]; root = rson[root];
            l = mid+1;
        }
        c[newroot] = c[root] + val;
    }
    return tmp;
}
int query(int lr, int rr, int k){
    int l = 1, r = m;
    while(l < r){
        int mid = (l+r) >> 1;
        //pr(l);prln(r);
        if(c[lson[lr]] - c[lson[rr]] >= k){
            r = mid;
            lr = lson[lr];
            rr = lson[rr];
        }else{
            l = mid + 1;
            k -= c[lson[lr]] - c[lson[rr]];
            lr = rson[lr];
            rr = rson[rr];
        }
    }
    return l;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int q;
    int kase = 0;
    scanf("%d", &kase);
    //int t, kase = 0;
    //scanf("%d", &t)
    while(kase--){
        scanf("%d%d", &n, &q);
        tot = 0;
        //pr(n);prln(q);
        
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        inithash();
        T[n+1] = build(1,m);
        for(int i = n; i; --i){
            int pos = gethash(a[i]);
            T[i] = update(T[i+1], pos, 1);
        }
        while(q--){
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            //pr(k);
            k = (r-l+1)-k+1;
            //prln(k);
            printf("%d\n", t[query(T[l], T[r+1], k)]);
        }
    }
	return 0;
}
