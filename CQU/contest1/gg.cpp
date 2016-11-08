/*************************************************************************
	> File Name: gg.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月18日 星期一 16时00分25秒
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
int a[maxn];
struct Q{
    int x, y, k;
    int id, type;
    Q(){}
    Q(int _x, int _y, int _k, int _id, int _type){
        x = _x;
        y = _y;
        k = _k;
        id = _id;
        type = _type;
    }
}q1[maxn], q2[maxn], q[maxn];
inline int lowerbit(int x){
    return x&(-x);
}
struct Bit{
    int n, b[maxn];
    void init(int _n){
         n = _n;
         memset(b,0, sizeof b);
    }
    void add(int i, int x){
        for(; i <= n; i += lowerbit(i)) b[i] += x;
    }
    int sum(int i){
        int ret = 0;
        for(; i; i -= lowerbit(i)) ret += b[i];
        return ret;
    }

}bit;
int ans[maxn];
void slove(int ql, int qr, int l, int r){
    if(ql > qr) return;
    if(l == r){
        for(int i = ql; i <= qr; ++i){
            if(q[i].type == 2){
                ans[q[i].id] = l;
            }
        }
        return;
    }
    int mid = (l+r) >> 1;
    int f = 0, g = 0;
    //pr(l);prln(r);
    //ql,qr是查询队列的区间
    //数值区间初始化0~INF
    //ql,qr是当前所处的数值区间
    for(int i = ql; i <= qr; ++i){
        if(q[i].type == 1){
            //这里q[i].x是原始值
            //q[i].y是修改数量+1或-1
            //q[i].id是修改位置
            //一个修改包含先删除在添加
            if(mid >= q[i].x){
                bit.add(q[i].id, q[i].y);
                q1[f++] = q[i];
            }else{
                q2[g++] = q[i];
            }
        }else{
            //这里bit下标是原来区间的位置
            //所以而值存的是左半边小于等于k数值的数量???
            //这里q[i].x和q[i].y表示查询的区间
            //q[i].k表示第k小
            //当前这里被更新的只有可以影响到当前区间查询的mid左边
            //正如上面更新所示
            //所以这里查询到的结果正是x-y在mid前有多少数
            //整个的过程下来,有着更新有着复原,但是影响当前结果的总是被提前执行不要担心
            //还有就是这里的k也会随着查询结果不断改变,k改变之后,原来操作复原也没事,相当于k记录下了信息
            //这里一定要注意!!!
            //不要老是把二分当成线段树的二分区间了,这里是二分答案二分值!!!
            //同一个处理下面的不在是区间相似,而是最终的答案或者值相似,即使区间很很大差别
            //比如两个查询和一个修改,次序分别是[1,5,3],[6,9,4]表示区间[1,5]查询第3小以及[6,9]下的第4小,修改是[2,+4],位置2增加4
            //那么如上所言,[1,5]和[6,9]查询的答案就会离4相对较近了,为什么?多思考
            int small = bit.sum(q[i].y) - bit.sum(q[i].x-1);
            if(small >= q[i].k) q1[f++] = q[i];
            else {
                q[i].k -= small;
                q2[g++] = q[i];
            }
        }
    }
    //还原操作
    for(int i = 0; i < f; ++i){
        if(q1[i].type == 1) bit.add(q1[i].id, -q1[i].y);
    }
    memcpy(q+ql, q1, f*sizeof(Q));
    memcpy(q+ql+f, q2, g*(sizeof(Q)));

    slove(ql, ql+f-1, l, mid);
    slove(ql+f, qr, mid+1, r);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, m;
    while(scanf("%d", &n) != EOF){
        int idx = 0, cnt = 0;
        bit.init(n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            q[++idx] = Q(a[i], 1, INF, i, 1);
         }
        scanf("%d", &m);
        int op, l, r, k;
        for(int i = 0; i < m; ++i){
            scanf("%d", &op);
            if(op == 1){
                scanf("%d%d", &l, &k);
                q[++idx] = Q(a[l], -1, INF,  l, 1);
                a[l] = k;
                q[++idx] = Q(a[l], 1, INF, l, 1);
            }else{
                scanf("%d%d%d", &l, &r, &k);
                q[++idx] = Q(l, r, k, ++cnt, 2);
            }
        }
        slove(1, idx, 0, INF);
        for(int i = 1; i <= cnt; ++i){
            printf("%d\n", ans[i]);
        }
    }
	return 0;
}
