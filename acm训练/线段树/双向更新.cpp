
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
#include<vector>

using namespace std;
const int maxn = 1e5+100;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define lson rt<<1,l,m
#define rson rt<<1|1,m+1,r
#define ll long long
int addl[maxn], addr[maxn];
struct node{
    int preR, sufL, sub;
}sum[maxn<<2];

void pushup(int rt, int l, int r) {
    int m = l + r >>1;
    sum[rt].preR = sum[rt<<1].preR;
    if(sum[rt].preR >= m - l + 1) sum[rt].preR += sum[rt<<1|1].preR;
    sum[rt].sufL = sum[rt<<1|1].sufL;
    if(sum[rt].sufL >= r - m)     sum[rt].sufL += sum[rt<<1].sufL;
}
void update(int rt, int l, int r, int o, int v) {
    if(l == r) {
        sum[rt].preR = sum[rt].sufL = v;
        return ;
    }
    int m = l + r >>1;
    if(m >= o) update(lson, o, v);
    if(m <  o) update(rson, o, v);
    pushup(rt,l,r);
}
int query(int rt, int l, int r, int o) {
    if(l == r) return sum[rt].sufL;
    int m = l + r >>1;
    if(m-sum[rt<<1].sufL+1 <=o&&o<=m+sum[rt<<1|1].preR) return sum[rt<<1].sufL + sum[rt<<1|1].preR;
    else if(m < o) return query(rson, o);
    else return query(lson, o);
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int n, k, n_, x, ans;
    char op[10];
    while(cin >> n >> k) {
        stack<int> st;
        n_ = 1;
        while(n_ < n) n_ *= 2;
        for(int i = 1; i <= n; ++i) update(1, 1, n_, i, 1);
        if(n_ > n) update(1, 1, n_, n+1, 0);
        for(int i = 0; i < k; ++i) {
            scanf("%s", op);
            if(op[0] == 'D') {
                scanf("%d", &x);
                update(1, 1, n_, x, 0);
                st.push(x);
            } else if(op[0] == 'Q') {
                scanf("%d", &x);
                ans = query(1, 1, n_, x);
                cout << ans << endl;
            } else {
                x = st.top();
                update(1, 1, n_, x, 1);
                st.pop();
            }
        }
    }
    return 0;
}
