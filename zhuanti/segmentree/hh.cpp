/*************************************************************************
	> File Name: hh.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月17日 星期日 10时03分15秒
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
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
struct Node{
    int first, last, sum, lazy, l, r;
    Node(){}
    Node(int _first, int _last, int _sum, int _lazy, int _l, int _r){
        first = _first;
        last = _last;
        sum = _sum;
        lazy = _lazy;
        l = _l;
        r = _r;
    }
}node[maxn];
void pushdown(int rt) {
    if(node[rt].l == node[rt].r) return;
    if(node[rt].lazy == 1){
        node[rt<<1].sum = node[rt<<1|1].sum = 0;
        node[rt<<1].first = node[rt<<1].last = node[rt<<1|1].first = node[rt<<1|1].last = -1;
        node[rt<<1].lazy = node[rt<<1|1].lazy = 1;
    }
    if(node[rt].lazy == -1){
        node[rt<<1].sum = node[rt<<1].r - node[rt<<1].l + 1;
        node[rt<<1|1].sum = node[rt<<1|1].r - node[rt<<1|1].l + 1;
        node[rt<<1].first = node[rt].l;
        node[rt<<1].last = node[rt].r;
        node[rt<<1|1].first = node[rt].l;
        node[rt<<1|1].last = node[rt].r;
        node[rt<<1].lazy = node[rt<<1|1].lazy = -1;
    }
    node[rt].lazy = 0;
}
void pushup(int rt){
    if(node[rt].l == node[rt].r) return;
    if(node[rt<<1].first!=-1) node[rt].first = node[rt<<1].first;
    else node[rt].first = node[rt<<1|1].first;
    if(node[rt<<1|1].last != -1) node[rt].last = node[rt<<1|1].last;
    else node[rt].last = node[rt<<1].last;
    node[rt].sum = node[rt<<1].sum + node[rt<<1|1].sum;
}
void build(int rt, int l, int r){
    node[rt].l = l;
    node[rt].r = r;
    node[rt].sum = r-l+1;
    node[rt].first = l;
    node[rt].last = r;
    node[rt].lazy = 0;
    //pr(rt);pr(node[rt].l);prln(node[rt].r);
    int m = (l+r)>>1;
    if(l==r) return;
    build(rt<<1, l, m);
    build(rt<<1|1, m+1, r);
}
int sum(int rt, int l, int r){
    if(l <= node[rt].l && node[rt].r <= r){
        return node[rt].sum;
    }
    pushdown(rt);
    int m = (node[rt].l + node[rt].r) >> 1;
    if(r <= m) return sum(rt<<1, l, r);
    else if(l > m) return sum(rt<<1|1, l, r);
    else{
        return sum(rt<<1, l, m) + sum(rt<<1|1, m+1, r);
    }
}
int query1(int rt, int l, int r){
    if(node[rt].l == l && node[rt].r == r){
        return node[rt].first;
    }
    pushdown(rt);
    int m = (node[rt].l + node[rt].r) >> 1;
    if(r <= m) return query1(rt<<1, l, r);
    else if(l > m) return query1(rt<<1|1, l, r);
    else{
        int ans = query1(rt, l, m);
        if(ans != -1) return ans;
        return query1(rt<<1|1, m+1, r);
    }
}
int query2(int rt, int l, int r){
    if(node[rt].l == l && node[rt].r == r){
        return node[rt].last;
    }
    pushdown(rt);
    int m = (node[rt].l + node[rt].r) >> 1;
    if(r <= m) return query1(rt<<1, l, r);
    else if(l > m) return query1(rt<<1|1, l, r);
    else{
        int ans = query2(rt, l, m);
        if(ans != -1) return ans;
        return query1(rt<<1|1, m+1, r);
    }
}
int n;
void update(int rt, int l, int r, int op){
    if(node[rt].l == l && node[rt].r == r){
        if(op == 1){
            node[rt].first = node[rt].last = -1;
            node[rt].sum = 0;
            node[rt].lazy = 1;
        }else if(op == -1){
            node[rt].first = node[rt].l;
            node[rt].last = node[rt].r;
            node[rt].sum = (node[rt].r - node[rt].l + 1);
            node[rt].lazy = -1;
        }
        return ;
    }
    pushdown(rt);
    int m = (node[rt].l + node[rt].r) >> 1;
    if(r <= m) update(rt<<1, l, m, op);
    else if(l > m) update(rt<<1|1, m+1, r, op);
    else{
        update(rt<<1, l, m, op);
        update(rt<<1|1, m+1, r, op);
    }
    pushup(rt);
}
int getpos(int A, int v){
    if(sum(1, A, n) == 0) return -1;
    if(sum(1, A, n) < v) return n;
    int l = A, r = n;
    int ans = A;
    while(l <= r){
        int mid = (l+r) >> 1;
        if(sum(1, 1, mid) >= v){
            ans = mid;
            r = mid-1;
        }else l = mid+1;
    }
    return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int m, t;
    cin >> t;
    while(t--){
        scanf("%d%d", &n, &m);
        build(1, 1, n);
        int l, r, v, op, A;
        update(1, 1, n, -1);
        for(int i = 0; i < m; ++i){
            scanf("%d%d%d", &op, &A, &v);
            if(op == 2){
                A++;v++;
                printf("%d\n", v-A+1+sum(1, A, v));
                update(1, A, v, -1);
            }else{
                int ans = getpos(A, v);
                prln(ans);
                if(ans == -1){
                    printf("Can not put any one.\n");
                }else{
                    l = query1(1, A, ans)-1;
                    r = query2(1, A, ans) - 1;
                    pr(l);prln(r);
                    printf("%d %d\n", l, r);
                    update(1, 1, ans, 1);
                }
            }

        }
    }
	return 0;
}
