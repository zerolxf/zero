/*************************************************************************
    > File Name: h.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月12日 星期一 17时06分07秒
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
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;

int mi[maxn];
struct Node{
    int mi, pos;
    bool operator  < (const Node& rhs)const{
         return mi < rhs.mi;
    }
}node[maxn];
int a[maxn];
void build(int rt, int l, int r){
    if(l == r){
        node[rt] = Node{a[l], l};
        return;
    }
    int mid = (l + r) >> 1;
    build(rt<<1, l, mid);
    build(rt<<1|1, mid+1, r);
    node[rt] = min(node[rt<<1], node[rt<<1|1]);
}
Node query(int rt, int l, int r, int ql, int qr, int v){
    //pr(rt);pr(l);pr(r);pr(ql);pr(qr);prln(v);
    if(l > r) return Node{INF, INF};
    if(node[rt].mi > v) return Node{INF,INF};
    if(l == r){
        return Node{a[l], l};
    }
    int mid = (l + r) >> 1;
    if(mid >= qr) return query(rt<<1, l, mid, ql, qr, v);
    else if(mid < ql) return query(rt<<1|1, mid+1, r, ql, qr, v);
    else{
        int mid = (l + r) >> 1;
        Node ans = query(rt<< 1, l, mid, ql, mid, v);
        if(ans.pos != INF) return ans;
        return query(rt<<1|1, mid+1, r, mid+1, qr, v);
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    int t;
    cin >> t;
    while(t--){
        cin>>n;
        for(int i = 0; i < n; ++i){
            cin >> a[i+1];
        }
        build(1, 1, n);
        int q;
        int  l, r;
        scanf("%d", &q);
        for(int i = 0; i < q; ++i){
            scanf("%d %d",&l, &r);
            int ans = a[l];
            l++;
            while(l <= r){
                 Node pos = query(1, 1, n, l, r, ans);
                 if(pos.pos > r) break;
                 l = pos.pos + 1;
                 ans = ans%a[pos.pos];
                 if(ans==0) break;
            }
            printf("%d\n", ans);

        }
    }

	return 0;
}
