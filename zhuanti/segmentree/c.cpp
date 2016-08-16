/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年07月13日 星期三 09时26分10秒
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
const int maxn = 2e6+1e5;
const int INF = 0x3f3f3f3f;
struct Node{
    ll num;
    ll sum;
    Node(){}
    Node(ll _num, ll _sum){
        num = _num;
        sum = _sum;
    }
}node[maxn];
Node get(const Node& a, const Node& b){
    return Node(a.num+b.num, a.sum+b.sum);
}
int add[maxn], n, m;
void pushdown(int rt){
    if(add[rt]){
        add[rt<<1] = add[rt<<1|1] = add[rt];
        node[rt<<1] = node[rt<<1|1] = Node(0,0);
        add[rt] = 0;
    }
}
void update(int rt, int l, int r, int o, ll v) {
    if(l == r){
        node[rt].num += v;
        node[rt].sum += v*(ll)l;
        return;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if(m >= o) update(rt<<1, l, m, o, v);
    else update(rt<<1|1, m+1, r, o, v);
    node[rt] = get(node[rt<<1], node[rt<<1|1]);
}

void update2(int rt, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr){
        add[rt] = true;
        node[rt] = Node(0,0);
        return ;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if(m >= ql) update2(rt<<1, l, m, ql, qr);
    if(m < qr) update2(rt<<1|1, m+1, r, ql, qr);
    node[rt] = get(node[rt<<1], node[rt<<1|1]);
}
Node query(int rt, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return node[rt];
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    Node ans(0,0);
    if(m >= ql) ans = get(ans, query(rt<<1, l, m, ql, qr));
    if(m < qr) ans = get(ans, query(rt<<1|1, m+1,r, ql, qr));
    return ans;
}
Node query(int rt, int l, int r, int n){
    if(l==r){
        return Node(n,(ll)n*l);
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if(node[rt<<1].num >= n) return query(rt<<1, l, m, n);
    return get(node[rt<<1], query(rt<<1|1, m+1, r, n-node[rt<<1].num));
}
void clear(int rt, ll l, int r, int n){
    if(l==r){
        node[rt].num -= n;
        node[rt].sum = (ll)node[rt].num*l;
        return;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if(node[rt<<1].num >= n){
        clear(rt<<1, l, m, n);
    }else{
        add[rt<<1] = 1;
        clear(rt<<1|1, m+1, r, n-node[rt<<1].num);
        node[rt<<1] = Node(0,0);
    }
    node[rt] = get(node[rt<<1], node[rt<<1|1]);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    char op[10];
    ll t;
    int _n = 1, n;
    while(_n < 1e6) _n <<= 1;
    for(int i = 0; i <= _n*2; ++i){
        node[i] = Node(0,0);
        add[i] = 0;
    }
    while(scanf("%s%d%lld", op, &n, &t) != EOF){
        if(op[0] == 'A') {
            update(1, 1, _n, t, n);
        }else{
            Node ans;
            if(node[1].num<n){
                printf("UNHAPPY\n");
            }else{
                ans = query(1, 1, _n, n);
                if(ans.sum > t){
                    printf("UNHAPPY\n");
                }else{
                    printf("HAPPY\n");
                    clear(1, 1, _n, n);
                }
            }
            continue;
            ll l = 1, r = 1e6+1;
            ans = query(1, 1, _n, 1, r);
            if(ans.num < n || n > t){
                printf("UNHAPPY\n");
                continue;
            }
            if(ans.num > n){
                printf("HAPPY\n");
                update(1, 1, _n, l, -n);
                continue;
            }
            while(l < r-1){
                int m = (l+r) >> 1;
                ans = query(1, 1, _n, 1, m);
                if(ans.num <= n) l = m;
                else r = m; 
            }
            continue;
            Node lnode = query(1, 1, _n, 1, l);
            ll need = n - lnode.num;
            ll sum = lnode.sum;
            if(need>0) sum += need*r;
            if(sum > t) printf("UNHAPPY\n");
            else{
                printf("HAPPY\n");
                if(need>0)update(1, 1, _n, r, -need);
                update2(1, 1, _n, 1, l);
            }
        }
    }
	return 0;
}
