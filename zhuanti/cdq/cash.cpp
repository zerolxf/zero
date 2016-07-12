/*************************************************************************
	> File Name: cash.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年07月06日 星期三 17时03分40秒
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
const double eps = 1e-9;
struct query{
    double q, a, b, k, r;
    int pos;
}q[maxn], nq[maxn]; 
double fabs(double x){
    return (x > 0)?x:-x;
}
struct Node{
    double x, y;
    bool operator < (const Node& rhs)const{
        return (x < rhs.x) || (fabs(x - rhs.x) < eps  && y < rhs.y+eps );
    }
}p[maxn], np[maxn];
int st[maxn];
double f[maxn];
int n, m;
double getk(int i, int j) {
    //if(i == 0) return -INF;
    //if(j == 0) return INF;
    if(fabs(p[i].x - p[j].x) <= eps) return -INF;
    return (p[i].y - p[j].y)/(p[i].x - p[j].x);
}
void slove(int l, int r){
    if(l == r) {
        f[l] = max(f[l], f[l-1]);
        p[l].y = f[l] / (q[l].a*q[l].r + q[l].b);
        p[l].x = p[l].y*q[l].r;
        return;
    }
    int m = (l + r) >> 1;
    int l1 = l, l2 = m+1;
    //q是排好序的,所以把排好序的分成两组还是排好序的
    //斜率递增
    for(int i = l; i <= r; ++i){
        if(q[i].pos <= m) nq[l1++] = q[i];
        else nq[l2++] = q[i];
    }
    for(int i = l; i <= r; ++i){
        q[i] = nq[i];
    }
    //先递归左边
    slove(l, m);

    //维护一个凸边
    int top = 0;
    for(int i = l; i <= m; ++i){
        //
       while(top >= 2 && getk(i, st[top]) + eps> getk(st[top], st[top-1])) top--;
        st[++top] = i;
    }
    
    int j = 1;
    //从头开始取
    //从右开始取,因为斜率从右往左递减,而凸边也是递减,当某边斜率大于当前斜率的时候,最左边不是最优剔除
    for(int i = r; i >= m+1; --i){
        while(j < top && q[i].k < getk(st[j], st[j+1]) + eps) ++j;
        f[q[i].pos] = max(f[q[i].pos], p[st[j]].x*q[i].a + p[st[j]].y*q[i].b);
    }
    slove(m+1, r);
    l1 = l, l2 = m+1;

    for(int i = l; i <= r; ++i){
        if((p[l1] < p[l2] || l2 > r) && l1 <= m)  np[i] = p[l1++];
        else np[i] = p[l2++];
    }
    for(int i = l; i <= r; ++i)
    {
        p[i] = np[i];
    }
}
bool cmp(const query& a, const query& b){
    return a.k < b.k;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    scanf("%d%lf", &n, &f[0]);
    for(int i = 1; i <= n; ++i){
        scanf("%lf%lf%lf", &q[i].a, &q[i].b, &q[i].r);
        q[i].k = -q[i].a/q[i].b;
        q[i].pos = i;
    }
    sort(q+1, q+1+n, cmp);
    slove(1, n);
    printf("%.3f\n", f[n]);
	return 0;
}
