/*************************************************************************
	> File Name: i.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月24日 星期日 14时16分52秒
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
const int maxn = 4e6+100;
const int INF = 0x3f3f3f3f;
int sum[maxn];
int cnt1, cnt2;
int query(int rt, int l, int r, int ql, int qr){
    //pr(rt);pr(l);pr(r);pr(ql);prln(qr);
    //if(r>l) return 0;
    if(ql <= l && r <= qr){
        return sum[rt];
    }
    int ans = 0;
    int m = (l+r) >> 1;
    //pr(rt);pr(l);pr(r);pr(ql);prln(qr);
    //prln(m);
    //if(cnt1++>=50) return 0;
    if(m >= ql) ans = max(ans, query(rt<<1, l, m, ql, qr));
    if(m < qr) ans = max(ans, query(rt<<1|1, m+1, r, ql, qr));
    return ans;
}
void update(int rt, int l, int r, int ql, int qr, int v){
    //pr(rt);pr(l);pr(r);pr(ql);prln(qr);
    //pr(rt);pr(l);prln(r);
    if(ql <= l && r <= qr){
        sum[rt] = v;
        return;
    }
    int m = (l+r) >> 1;
    //prln(m);
    //pr(rt);pr(l);pr(r);pr(ql);prln(qr);
    //if(cnt2++>=50) return ;
    if(m >= ql) update(rt<<1, l, m, ql, qr, v);
    if(m<qr)update(rt<<1|1, m+1, r, ql, qr, v);
    sum[rt] = max(sum[rt<<1], sum[rt<<1|1]);
}
int a[maxn], b[maxn], n;
int pos[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    cin >> n;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }

    for(int i = 1; i <= n; ++i){
        scanf("%d", &b[i]);
        pos[b[i]] = i;
    }
    int _n = 1;
    while(_n < n) _n <<= 1;
    for(int i = 0; i <= _n*2; ++i){
        sum[i] = 0;
    }
    
    for(int i = 1; i<= n; ++i){
        int x = query(1, 1, _n, pos[a[i]], n);
        //prln(pos[a[i]]);
        //prln(x);
        update(1, 1, _n, pos[a[i]], pos[a[i]], x+1);
    }
    int ans = query(1, 1, _n, 1, n);
    cout << ans << "\n";
	return 0;
}
