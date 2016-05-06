/*************************************************************************
	> File Name: l.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月05日 星期四 20时34分02秒
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
int wa[maxn], wb[maxn], wv[maxn], c[maxn], t[maxn];
bool cmp(int *r, int a, int b, int j) {
    return r[a] == r[b] && r[a+j] == r[b+j];
}
void getSa(int *r, int *sa, int n, int m) {
    int i, j, p, *x = wa, *y = wb;
    for(i = 0; i < m; ++i) c[i] = 0;
    for(i = 0;i < n; ++i) c[x[i] = r[i]]++;
    for(i = 0; i < m-1; ++i) c[i+1] += c[i];
    for(i = n-1; i >= 0; --i) sa[--c[x[i]]] = i;
    for(j = 1, p = 1; p < n; m = p, j <<=1) {
        for(i = n-j, p = 0; i < n; i++) y[p++] = i;
        for(i = 0; i < n; ++i) if(sa[i] >= j) y[p++] = sa[i] - j;
        for(i = 0; i < n; ++i) wv[i] = x[y[i]];
        for(i = 0; i < m; ++i) c[i] = 0;
        for(i = 0; i < n; ++i) c[wv[i]]++;
        for(i = 0; i < m-1; ++i) c[i+1] += c[i];
        for(i = 0; i < n; ++i) sa[--c[y[i]]] = y[i];
        swap(x,y);
        x[sa[0]] = 0;
        for(i = 1, p = 1; i < n; ++i){
            x[sa[i]] = cmp(y, sa[i], sa[i-1], j)?p-1:p++;
        }
    }
}
int rank[maxn], height[maxn];
void getHeight(int *r, int *sa, int n) {
    int i, j, k = 0;
    for(int i = 1; i <= n; ++i) rank[sa[i]] = i;
    for(i = 0; i < n; height[rank[i++]] = k)
    for(k?k--:j = sa[rank[i]-1]; r[i+k] == r[j+k]; k++);
}
char ss[maxn];
int num[maxn];
int sa[maxn];
int a[maxn], pos[maxn], sum[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%s", ss);
        int len = strlen(ss);
        prln(ss);
        for(int i = 0; i < len; ++i) {
            num[i] = ss[i];
        }
        num[len] = 0;
        getSa(num, sa, len+1, 150);
        prln(ss);
        getHeight(num, sa, len);
        height[1] = 0;
        int now = 1;
        prln(now);
        for(int i = 0; i <= len; ++i) sum[i] = 0;
        a[0] = height[1];
        pos[0] = 1;
        ll ans = 0;
        for(ll i = len; i >= 1; --i) ans += (len-1)*i;
        for(int i = 2; i <= len; ++i){
            int p = lower_bound(a,a+now,height[i]) - a;
            pr(p);
            if(p >= now) {
                a[p] = height[i];
                sum[p] = sum[p-1] + height[i];
                ans -= 2*sum[p];
                pos[p] = i;
                now=p+1;
            }else {
                a[p] = height[i];
                ans -= 2*(sum[p-1]  + (i-pos[p]+1)*a[p]);
                now = p+1;
            }
        }
        printf("%lld\n", ans);
    }
	return 0;
}
