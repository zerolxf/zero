
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
#define ll long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define root 1,n,1
ll sum[maxn<<1];
void push_up(int rt) {
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void update(int o, int v, int l, int r, int rt) {
    if(l == r) {
        sum[rt] += v;
        return;
    }
    int m = l + r >> 1;
    if(m >= o) update(o, v, lson);
    else update(o, v, rson);
    push_up(rt);
}
int query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) return sum[rt];
    int m = l + r >> 1;
    int ret = 0;
    if(L <= m) ret += query(L, R, l, m, rt<<1);
    if(m < R) ret += query(L, R, m+1, r, rt<<1|1);
    return ret;
}
void build(int l,int r,int rt){
    if(l==r) {
        int x;
        scanf("%d",&x);
        sum[rt]=x;
        return;
    }
    int m=l+r>>1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    push_up(rt);
    return;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int t, n, x, l, r, kase = 0;cin >> t;
    while(t--) {
        printf("Case %d:\n", ++kase);
        char op[10];
        cin >> n;
        build(1, n, 1);
        while(true){
            char op[10];
            int l,r;
            scanf("%s",op);
            if(op[0]=='E') break;
            if(op[0]=='A'){
                int x,y;
                scanf("%d%d",&x,&y);
                update(x,y,root);
            }
            if(op[0]=='Q'){
                int x,y;
                scanf("%d%d",&x,&y);
                int ans=query(x,y,root);
                printf("%d\n",ans);
            }
            if(op[0]=='S'){
                int x,y;
                scanf("%d%d",&x,&y);
                update(x,-y,root);
            }
        }
    }
    return 0;
}
