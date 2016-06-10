/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年06月10日 星期五 17时41分56秒
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
const int maxn = 8e5+100;
const int INF = 0x3f3f3f3f;
int sum[maxn], add[maxn];
void pushdown(int rt, int l, int r){
    if(add[rt]){
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        int m = l + r >> 1;
        sum[rt<<1] += (m-l+1)*add[rt];
        sum[rt<<1|1] += (r-m)*add[rt];
        add[rt] = 0;
    }
}
void update(int rt, int l, int r, int ql, int qr, int v){
    if(ql <= l && r <= qr){
        add[rt] += v;
        sum[rt] += (r-l+1)*v;
        return;
    }
    pushdown(rt, l, r);
    int m = l + r >> 1;
    if(m >= ql) update(rt<<1, l, m, ql, qr, v);
    if(m < qr) update(rt<<1|1, m+1, r, ql, qr, v);
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
int query(int rt, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return sum[rt];
    }
    pushdown(rt, l, r);
    int m = l + r >> 1;
    int ans = 0;
    if(m >= ql) ans += query(rt<<1, l, m, ql, qr);
    if(m < qr) ans += query(rt<<1|1, m+1, r, ql, qr);
    return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    int n, _n, x, a, b, c, m, ans;
    int opp;
    string op;
    cin >> t;
    while(t--){
        cin >> n;
        _n = 1;
        while(_n < n) _n = _n << 1;
        for(int i = 0; i <= _n*2; ++i) sum[i] = add[i] = 0;
        cin >> op;
        cin >> op;
        if(op[0] == '1'){
            cin >> m;
            for(int i = 0; i < m; ++i){
                scanf("%d%d%d", &opp, &a, &b);
                if(opp==0) update(1, 1, _n, a, a, b);
                else {
                    ans = query(1, 1, _n, a, b);
                    printf("%d\n",ans);
                }
            }
        }
        cin >> op;
        cin >> op;
        if(op[0] == '2'){
            for(int i = 0; i <= _n*2; ++i) sum[i] = add[i] = 0;
            cin >> m;
            for(int i = 0; i < m; ++i){
                scanf("%d", &opp);
                if(opp==0){
                    scanf("%d%d%d", &a, &b, &c);
                    update(1, 1, _n, a, b, c);
                }else{
                    scanf("%d", &a);
                    ans = query(1, 1, _n, a, a);
                    printf("%d\n",ans);
                }
            }
        }
    }
	return 0;
}
