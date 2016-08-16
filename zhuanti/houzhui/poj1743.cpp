/*************************************************************************
	> File Name: poj1743.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月29日 星期五 16时34分13秒
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
const int maxn = 2e6+100;
const int INF = 0x3f3f3f3f;
int s[maxn];
int sa[maxn], t1[maxn], t2[maxn], c[maxn];
int n;
char p[maxn];
void getSa(int m){
    n++;
    int *x = t1, *y = t2;
    for(int i = 0; i < m; ++i) c[i] = 0;
    for(int i = 0; i < n; ++i) c[x[i]]++;
    for(int i = 0; i < m; ++i) c[i+1] += c[i];
    for(int i = n-1; i >= 0; --i) {
        sa[--c[x[i]]] = i;
    }
    for(int k = 1; k < n; k <<= 1){
        int p = 0;
        for(int i = n-k; i < n; ++i) y[p++] = i;
        for(int i = 0; i < n; ++i) if(sa[i] >= k) y[p++] = sa[i] - k;
        for(int i = 0; i < m; ++i) c[i] = 0;
        for(int i = 0; i < n; ++i) c[x[y[i]]]++;
        for(int i = 0; i < m; ++i) c[i+1] += c[i];
        for(int i = n-1; i>=0; --i){
            sa[--c[x[y[i]]]] = y[i];
        }
        swap(x, y);
        p = 1, x[sa[0]] = 0;
        for(int i = 1; i < n; ++i){
            x[sa[i]] = y[sa[i]] == y[sa[i-1]] && y[sa[i]+k] == y[sa[i-1]+k]?p-1:p++;
        }
        if(p >= n) break;
        m = p;

    }
    n--;
}
int m;
int ran[maxn], h[maxn];

bool find(int len){
    int ma = 0, mi = INF;
    for(int i = 1; i <= n; ++i){
        while(i <= n && h[i] < len) ++i;
        if(i>n) return false;
        ma = sa[i-1];
        mi = sa[i-1];
        while(i <= n && h[i] >= len){
            ma = max(ma, sa[i]);
            mi = min(mi, sa[i]);
            ++i;
        }
        if(ma - mi >= len) return true;
    }
    return false;
}

int ss[maxn];
void getHeight(){
    for(int i = 1; i <= n; ++i) ran[sa[i]] = i;
    int k = 0;
    for(int i = 0; i < n; ++i){
        k = max(k-1, 0);
        //pr(i);pr(ran[i]-1);
        int j = sa[ran[i]-1];
        //prln(sa[ran[i]-1]);
        while(ss[i+k] == ss[j+k]) k++;
        h[ran[i]] = k;
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(scanf("%d", &n) != EOF){
        if(n==0) break;
        for(int i = 0; i < n; ++i){
            scanf("%d", s+i);
            ss[i] = s[i];
        }
        n--;
        for(int i = 0; i < n; ++i){
            ss[i] = ss[i+1] - ss[i]+90;
        }
        ss[n] = 0;
        for(int i = 0; i<=n;++i){
            t1[i] = ss[i];
        }
        getSa(210);
        getHeight();
        int l = 0, r = n;
        while(l < r){
            int mid = (l+r+1) >> 1;
            //pr(mid);
            if(find(mid)) l = mid;
            else r = mid-1;
        }
        if(l < 4) {
            printf("0\n");
        }else {
            printf("%d\n", l+1);
        }

    }
	return 0;
}
