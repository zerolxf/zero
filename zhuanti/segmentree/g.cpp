/*************************************************************************
	> File Name: g.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年07月13日 星期三 09时12分11秒
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
#define sqr(x) ((x)*(x))
#define pr(x)// cout << #x << " = " << x << " ";
#define prln(x)// cout << #x << " = " << x <<  endl; 
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
const int MOD = 1e4+7;
struct Node{
    int add, mul, cov, sum1, sum2, sum3;
    Node(const Node& rhs){
        add = rhs.add;
        mul = rhs.mul;
        cov = rhs.cov;
            sum1 = rhs.sum1;
            sum2 = rhs.sum2;
            sum3 =  rhs.sum3;
    }
    
    Node(){
        add = 0; mul = 1; cov = -1; 
        sum1 = sum2 = sum3 = 0;
    }
    Node(ll _sum1, ll _p2, ll _p3){
        sum1 = _sum1;
        sum2 = _p2;
        sum3 = _p3;
    }
    Node operator + (const Node& rhs)const{
        return Node((sum1+rhs.sum1)%MOD, (sum2+rhs.sum2)%MOD, (sum3+rhs.sum3)%MOD); 
    }
}node[maxn];
void getnode(Node& c, const Node& a, const Node& b){
    c.sum1 = (a.sum1 + b.sum1)%MOD;
    c.sum2 = (a.sum2 + b.sum2)%MOD;
    c.sum3 = (a.sum3 + b.sum3)%MOD;
}
void Update_cov(int rt, int l, int r, ll cov) {

    node[rt].cov = cov%MOD;
    ll m = r-l+1;
    node[rt].add = 0, node[rt].mul = 1;
    node[rt].sum1 = m*cov%MOD;
    node[rt].sum2 = m*cov %MOD *cov%MOD;
    node[rt].sum3 = m*cov %MOD *cov %MOD *cov %MOD;
}
void pushdowncov(int rt, int l, int r){
    if(node[rt].cov != -1) {
        int m = (l+r) >> 1;
        Update_cov(rt<<1, l, m, node[rt].cov);
        Update_cov(rt<<1|1, m+1, r, node[rt].cov);
        node[rt].cov = -1;
    }
}
void Update_add(int rt, int l, int r, ll add){
    //pushdowncov(rt, l, r);
    add = add%MOD;
    node[rt].add = (node[rt].add + add)%MOD;
    ll m = r-l+1;
    node[rt].sum3 = (node[rt].sum3%MOD + 3*add*node[rt].sum2%MOD + 3*add*add%MOD *node[rt].sum1 + m*add%MOD*add%MOD*add%MOD)%MOD;
    node[rt].sum2 = (node[rt].sum2 + 2*add*node[rt].sum1 + m*add%MOD*add%MOD)%MOD;
    node[rt].sum1 = (node[rt].sum1 + m*add%MOD)%MOD;
}

void Update_mul(int rt, int l, int r, ll mul){
    //pushdowncov(rt, l, r);
    mul = mul%MOD;
    node[rt].mul = node[rt].mul*mul%MOD;
    node[rt].add = (node[rt].add *mul)%MOD;
    node[rt].sum1 = (node[rt].sum1 * mul)%MOD;
    node[rt].sum2 = (node[rt].sum2 * mul %MOD *mul)%MOD;
    node[rt].sum3 = (node[rt].sum3 * mul %MOD *mul %MOD *mul) %MOD;
}


void pushdownadd(int rt, int l, int r){
    if(node[rt].add != 0){
        int m = (l+r)>>1;
        Update_add(rt<<1, l, m, node[rt].add);
        Update_add(rt<<1|1, m+1, r, node[rt].add);
        node[rt].add = 0;
    }
}
void pushdownmul(int rt, int l, int r){
    if(node[rt].mul != 1){
       int m = (l+r)>>1;
        Update_mul(rt<<1, l, m, node[rt].mul);
        Update_mul(rt<<1|1, m+1, r, node[rt].mul);
        node[rt].mul = 1;
    }
}
void pushdown(int rt, int l, int r){
    if(node[rt].cov != -1){
        pushdowncov(rt, l, r);
    }
    if(node[rt].mul != 1){
        pushdownmul(rt, l, r);
    }
    if(node[rt].add != 0){
        pushdownadd(rt, l, r);
    }
}
void update(int rt, int l, int r, int ql, int qr, ll v, int op){
    pr(rt);pr(l);pr(r);pr(ql);pr(ql);pr(v);prln(op);
    if(ql <= l && r <= qr){
        if(op == 3) Update_cov(rt, l, r, v);
        else if(op == 2) Update_mul(rt, l, r, v);
        else if(op == 1) Update_add(rt, l, r, v);
        return;
    }
    pushdown(rt, l, r);
    int m = (l+r) >> 1;
    if(m >= ql) update(rt<<1, l, m, ql, qr, v, op);
    if(m < qr) update(rt<<1|1, m+1, r, ql, qr, v, op);
    getnode(node[rt], node[rt<<1], node[rt<<1|1]);
    pr(rt);pr(l);pr(r);pr(node[rt].sum1);pr(node[rt].sum2);prln(node[rt].sum3);


}
Node query(int rt, int l, int r, int ql, int qr){
    //pr(rt);pr(l);pr(r);pr(ql);prln(qr);
    if(ql <= l && r <= qr){
        //prln("end");
        //pr(l);pr(r);
        //pr(rt);pr(node[rt].sum1);pr(node[rt].sum2);prln(node[rt].sum3);
        return node[rt];
    }
    pushdown(rt, l, r);
    Node ans(0,0,0);
    int m = (l+r) >> 1;
    if(m >= ql) {
        //pr("lson");
        ans = ans + query(rt<<1, l, m, ql, qr);
        //prln(ans.sum1);
    }
    
    if(m < qr) {
        //pr("rson");
        ans = ans + query(rt<<1|1, m+1, r, ql, qr);
        //prln(ans.sum1);
    }
    //pr(rt);pr(ans.sum1);pr(ans.sum2);prln(ans.sum3);
    return ans;
}
ll xx[100];
void updatexx(int op, int x, int y, int v){
    if(op==1) {
        for(int i = x; i<=y;++i){
            xx[i]+=v;
            xx[i] = xx[i]%MOD;
        }
    }
    if(op==2) {
        for(int i = x; i<=y;++i){
            xx[i]*=v;
            xx[i] = xx[i]%MOD;
        }
    }
    if(op==3) {
        for(int i = x; i<=y;++i){
            xx[i]=v;
            xx[i] = xx[i]%MOD;
        }
    }
}
void show(int x, int y){
    ll sum[4];
    prln("show");
    for(int i = x; i <= y; ++i){
        pr(i);prln(xx[i]);
    }
    prln("show");
    sum[0] = sum[1] = sum[2] = sum[3] = 0;
    for(int i = x; i <= y; ++i){
        sum[1] += xx[i];
        sum[2] += xx[i]*xx[i]%MOD;
        sum[3] += xx[i]*xx[i]%MOD*xx[i]%MOD;
        sum[1]%=MOD;
        sum[2]%=MOD;
        sum[3]%=MOD;
    }
    //pr(sum[1]);pr(sum[2]);prln(sum[3]);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
    freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    Node init;
    int n, _n, m;
    while(scanf("%d%d", &n, &m) != EOF) {
        prln("*******************");

        if(n==0&&m==0) break;
        _n = 1;
        while(_n < n) _n <<= 1;
        update(1, 1, _n, 1, _n, 0, 3);
        //prln("*******************");
        //for(int i = 0; i <= _n*2; ++i){
            //node[i] = init;
        //}
        Node ans;
    //    ans = query(1, 1, _n, 1, n);
        int op, x, y, v;
        for(int i = 0; i < m; ++i){
            scanf("%d%d%d%d", &op, &x, &y, &v);
            //pr(x);pr(y);pr(v);prln(op);
            if(op != 4) update(1, 1, _n, x, y, v, op);
            else{
                ans = query(1, 1, _n, x, y);
                int xx = 0;
                if(v==1) xx = ans.sum1;
                if(v==2) xx = ans.sum2;
                if(v==3) xx = ans.sum3;
                printf("%d\n", xx);
            }
                //updatexx(op,x,y,v);
                //show(1,10);
            //prln("*******************~~~~~~~~~~~~~~~~~");
        }
    }
    //prln("xxxx");
	return 0;
}
