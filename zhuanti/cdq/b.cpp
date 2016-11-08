/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月01日 星期一 15时21分39秒
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
    int d, p, g, r;
    bool operator < (const Node &rhs)const{
        return d < rhs.d;
    }
}q[maxn];
typedef pair<int,ll> P;
//P A[maxn], C[maxn];
ll f[maxn];
int n, d;
typedef pair<int, long long> PA;
PA A[111111], C[111111];
long long h(int j) {
    return f[j] + (long long)q[j].r - (long long)q[j].p - (long long)q[j].g * (long long)(q[j].d + 1);
}
//int slopecomp(PA a, PA b, PA c) {
    //long long xa = b.first - a.first;
    //long long xb = c.first - a.first;
    //long long ya = b.second - a.second;
    //long long yb = c.second - a.second;
    //double tmp = (double)xa * yb - (double)xb * ya;
    //return tmp < 0;
//}
double eps = 1e-8;
ll h2(int j){
    return (ll)f[j] + (ll)q[j].r - (ll)q[j].p - (ll)q[j].d*q[j].g - (ll)q[j].g;
}
bool small(const P& a, const P& b, const P& c){
    ll xa = b.first - a.first;
    ll xb = c.first - a.first;
    ll ya = b.second - a.second;
    ll yb = c.second - a.second;
    //double tmp = (double)xa * yb - (double)xb * ya;
    return   (double)xa * yb - (double)xb * ya< 0;
}
void solve(int ql, int qr){
     if(ql < qr){
         //pr(ql);prln(qr);
        int m = (ql + qr) >> 1;
        solve(ql, m);
        int a = 0;
        for(int i = ql; i <= m; ++i){
            //pr(i);pr(f[i]);prln(q[i].p);
            if(f[i] >= q[i].p){
                A[a++] = P(q[i].g, h2(i));
            }
        }
        sort(A, A+a);
        int b = 0;
        //prln(a);
        for(int i = 0; i < a; ++i){
            while(b > 1 && !small(C[b-1], C[b], A[i])) b--;
            C[++b] = A[i];
        }
        int bb = 0;
        //prln(b);
        for(int i = m+1; i <= qr; ++i){
            double a1, a2, b1, b2;
            ll x = q[i].d;
            while(bb < b){
                a1 = C[bb].first;
                a2 = C[bb+1].first;
                b1 = C[bb].second;
                b2 = C[bb+1].second;
                if(a1*x+b1>=a2*x+b2) break;
                bb++;
            }
            f[i] = max((ll)f[i], (ll)C[bb].first*x+C[bb].second);
        }
        solve(m+1, qr);
     }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    ll n, c, d;
    int kase = 0;
    while(cin >> n >> f[0] >> d){
        if(n==0&&f[0]==0&&d==0) break;
        for(int i = 1; i <= n; ++i){
            scanf("%d%d%d%d", &q[i].d, &q[i].p, &q[i].r, &q[i].g);
        }
        sort(q+1, q+n+1);
        n++;
        q[n].d = d+1;
        q[n].p = q[n].r = 0;
        q[n].g = 0;
        for(int i = 1; i <= n; ++i) f[i] = f[0];
        solve(0, n);
        printf("Case %d: %lld\n", ++kase, f[n]);
        
    }
	return 0;
}
