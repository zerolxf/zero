/*************************************************************************
	> File Name: l.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月03日 星期三 09时09分43秒
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
    int sum1, sum2, flag1, flag2, num;
    Node(){
        sum1 = 0;
        sum2 = 0;
        flag1 = 0;
        num = 0;
        flag2 = 0;
        //sum1 = sum1 = flag1 = flag2 = num = 0;
    }
    Node(int _sum1, int _sum2, int _flag1, int _flag2, int _num){
        sum1 = _sum1;
        sum2 = _sum2;
        flag1 = _flag1;
        flag2 = _flag2;
        num = _num;
    }
    Node operator + (const Node& rhs)const{
        Node ans;
        ans.sum1 = sum1 + rhs.sum1;
        ans.sum2 = sum2 + rhs.sum2;
        ans.num = num + rhs.num;
        ans.flag1 = 0, ans.flag2 = 0;
        return ans;
    }
}node[maxn];
void Update(int rt, ll flag1, ll flag2){
    node[rt].flag1 += flag1;
    node[rt].flag2 += flag2;
    node[rt].sum1 += node[rt].num*flag1;
    node[rt].sum2 += node[rt].num*flag2;
}
void print(const Node& rhs){
    pr(rhs.sum1);pr(rhs.sum2);pr(rhs.num);pr(rhs.flag1);prln(rhs.flag2);
}
void pushdown(int rt){
     if(node[rt].flag1 || node[rt].flag2){
         Update(rt<<1, node[rt].flag1, node[rt].flag2);
         Update(rt<<1|1, node[rt].flag1, node[rt].flag2);
         node[rt].flag1 = node[rt].flag2 = 0;
     }
}
void pushup(int rt){
    node[rt] = node[rt<<1] + node[rt<<1|1];
}
void update(int rt, int l, int r, int ql, int qr, int flag1, int flag2){
    if(ql>qr) return;
    if(ql <= l && r <= qr){
        //pr(l);pr(r);pr(flag1);pr(flag2);
        Update(rt, flag1, flag2);
        //pr(node[rt].sum1);prln(node[rt].sum2);
        return;
    }
    pushdown(rt);
    //prln("pushdown");
    //pr(l);prln(r);
     //print(node[rt<<1]);
     //print(node[rt<<1|1]);
     //prln("pushdownend");
     //cout<<"\n";
    int m = (l + r) >> 1;
    if(m >= ql) update(rt<<1, l, m, ql, qr, flag1, flag2);
    if(m < qr) update(rt<<1|1, m+1, r, ql, qr, flag1, flag2);

    //pr(l);prln(r);
    //pr(node[rt<<1].sum1);prln(node[rt<<1].sum2);
    //pr(node[rt<<1|1].sum1);prln(node[rt<<1|1].sum2);
    //pr(node[rt].sum1);prln(node[rt].sum2);
    pushup(rt);
}
void add(int rt, int l, int r, int o, int v, int sum1, int sum2){
    if(l == r){
        node[rt].num += v;
        node[rt].sum1 += sum1;
        node[rt].sum2 += sum2;
        //pr(l);pr(r);pr(sum1);pr(sum2);
        //Update(rt, flag1, flag2);
        //pr(node[rt].sum1);prln(node[rt].sum2);
        return;
    }
    pushdown(rt);
    int m = (l+r) >> 1;
    if(m >= o) add(rt<<1, l, m, o, v, sum1, sum2);
    else add(rt<<1|1, m+1, r, o, v, sum1, sum2);
    pushup(rt);
    //pr(l);prln(r);
    //pr(node[rt<<1].sum1);prln(node[rt<<1].sum2);
    //pr(node[rt<<1|1].sum1);prln(node[rt<<1|1].sum2);
    //pr(node[rt].sum1);prln(node[rt].sum2);
    //Update(rt, flag1, flag2);

}
Node query(int rt, int l, int r, int ql, int qr){
    if(ql > qr) return Node(0,0,0,0,0);
    if(ql <= l && r <= qr){
        //pr(l);pr(r);pr(node[rt].sum1);prln(node[rt].sum2);
        return node[rt];
    }
    pushdown(rt);
    //Node ans(0,0,0,0,0);
    Node ans;
    int m = (l+r) >> 1;
    if(m >= ql) ans = ans + query(rt<<1, l, m, ql, qr);
    if(m < qr) ans = ans + query(rt<<1|1, m+1, r, ql,qr);
    return ans;
}
int a[maxn], b[maxn], id[maxn];
int n, _n;
int cntb;
void getid(){
    sort(b, b+cntb);
    cntb = unique(b, b+cntb) - b;
    for(int i = 1; i <= n; ++i){
        id[i] = lower_bound(b, b+cntb, a[i]) - b + 1;
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(scanf("%d", &n) != EOF){
        cntb = n;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            b[i-1] = a[i];
        }
        getid();
        int _n = 1;
        //for(int i = 1; i <= n; ++i){
            //pr(i);pr(a[i]);prln(id[i]);
        //}
        while(_n < n) _n <<= 1;
        //prln(_n);
        for(int i = 0; i <= _n*2; ++i){
            node[i] = Node(0,0,0,0,0);
        }
        ll ans = 0;
        for(int i = 1; i <= n; ++i){
            //prln("QUERY1");
            Node qr = query(1, 1, _n, id[i]+1, n);
            //prln("QUERY2");
            Node ql = query(1, 1, _n, 1, id[i]-1);
            //prln("QUERY3");
            Node q = query(1, 1, _n, 1, _n);
            //pr(ans);
            //pr(ql.sum1);pr(ql.sum2);prln(ql.num);
            //pr(qr.sum1);pr(qr.sum2);prln(qr.num);
            ans += ql.num*(q.sum2/2) - ql.sum2;
            //pr(ans);
            ans += qr.num*(q.sum1/2) - qr.sum1;
            //pr(i);prln(ans);
            //ans %= MOD;
            //prln("UPDATE");
            //pr(id[i]);pr(ql.num);prln(qr.num);
            //pr(id[i]+1);prln(n);
            //pr(1);prln(id[i]-1);
            //prln("UPDATE1");
            //pr(1);prln(id[i]-1);
            update(1, 1, _n, 1, id[i]-1, 1, 0);
            //prln("UPDATE2");
            //pr(id[i]+1);prln(n);
            update(1, 1, _n, id[i]+1, n, 0, 1);
            //prln("ADD");
            //pr(ql.num);prln(qr.num);
            add(1, 1, _n, id[i], 1, ql.num, qr.num);
            //cout<<"\n";
            //cout<<"\n";
        }
        printf("%lld\n", ans);
    }
	return 0;
}
