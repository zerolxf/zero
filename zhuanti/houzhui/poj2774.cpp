/*************************************************************************
	> File Name: poj2774.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月29日 星期五 09时00分03秒
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
char s[maxn];
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

int cmp_suffix(char* pattern, int p){
    return strncmp(pattern, s+sa[p], m);
}
int find(char *P){
    m = strlen(P);
    if(cmp_suffix(P,0) < 0) return -1;
    if(cmp_suffix(P,n-1) > 0) return 1;
    int l = 0, r = n-1;
    while(l < r){
        int mid = (l+r) >> 1;
        pr(l);prln(r);
        if(cmp_suffix(P,mid) > 0) l = mid+1;
        else r = mid;
    }
    return l;
}
int ran[maxn], h[maxn];
void calheight(char *r,int n)
{
     int i,j,k=0;
     for(i=1;i<=n;i++) ran[sa[i]]=i;
     for(i=0;i<n;h[ran[i++]]=k)
     for(k?k--:0,j=sa[ran[i]-1];r[i+k]==r[j+k];k++);
     return;
}
void getHeight(){
    for(int i = 1; i <= n; ++i) ran[sa[i]] = i;
    int k = 0;
    for(int i = 0; i < n; ++i){
        k = max(k-1, 0);
        //pr(i);pr(ran[i]-1);
        int j = sa[ran[i]-1];
        //prln(sa[ran[i]-1]);
        while(s[i+k] == s[j+k]) k++;
        h[ran[i]] = k;
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    scanf("%s", s);        
    int lens = strlen(s);
    scanf("%s", s+lens+1);
    s[lens] = 1;
    n = strlen(s);
    for(int i = 0; i < n; ++i) t1[i] = s[i];
    getSa(130);
    //calheight(s, n);
    getHeight();
    int ans = 0;
    for(int i = 2; i < n; ++i){
        //pr(i);prln(h[i]);
        if((sa[i]>lens&&sa[i-1]<lens) || (sa[i]<lens&&sa[i-1]>lens))
        ans = max(ans, h[i]);
    }
    cout << ans << "\n";
	return 0;
}
