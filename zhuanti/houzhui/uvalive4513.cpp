/*************************************************************************
	> File Name: uvalive4513.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月29日 星期五 14时16分51秒
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
int t2[maxn], t1[maxn], h[maxn], ran[maxn], c[maxn];
int n, sa[maxn];
void getSa(int m){
    int *x = t1, *y = t2;
    for(int i = 0; i <= m; ++i) c[i] = 0;
    for(int i = 0; i < n; ++i) c[x[i]]++;
    for(int i = 0; i < m; ++i) c[i+1] += c[i];
    for(int i = n-1; i>=0; --i){
        sa[--c[x[i]]] = i;
    }
    for(int k = 1; k <= n; k <<= 1){
        int p = 1;
         for(int i = n-k; i < n; ++i) y[p++] = i;
         for(int i = 0; i < n; ++i) if(sa[i] >= k) y[p++] = sa[i]-k;
         for(int i = 0; i < m; ++i) c[i]= 0;
         for(int i = 0; i < n; ++i) c[x[y[i]]]++;
         for(int i = 0; i < m; ++i) c[i+1] += c[i];
         for(int i = n-1; i >= 0; --i){
             sa[--c[x[y[i]]]] = y[i];
         }
         swap(x,y);
         x[sa[0]] = 0;
         p = 1;
         for(int i = 1; i <= n; ++i){
             x[sa[i]] = (y[sa[i]] == y[sa[i-1]] && y[sa[i]+k] == y[sa[i-1]+k]) ?p-1:p++;
         }
         if(p >= n) break;
         m = p;
    }
}
int m;
char s[maxn];
void getHeight(){
    for(int i = 1; i <= n; ++i) ran[sa[i]] = i;
    int k = 0;
    for(int i = 1; i <= n; ++i){
        if(k) k--;
        int j = ran[i]-1;
        while(s[i+k] == s[j+k]) k++;
        h[ran[i]] = k;
    }

}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int m, len;
    while(scanf("%d", &m) != EOF && m){
        scanf("%s", s);

    }
	return 0;
}
