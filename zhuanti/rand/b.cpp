#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include <queue>

using namespace std;
const int maxn = 4e5+1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int w[maxn], v[maxn], r[maxn], x[maxn], y[maxn], h[maxn], sa[maxn], c[maxn];
char s[maxn];
void getSa(int n, int m){
    //w是关键字,v第二关键字,r是排名,
    rep(i,n) c[i] = 0;
    rep(i,n) c[x[i]=s[i]]++;
    rep(i,m) c[i+1] += c[i];
    rep(i,n) sa[--c[x[i]]] = i;
    for(int k = 1; k <= n; k <<= 1){
        int p = 0;

        for(int i = n-k; i < n; ++i) y[p++] = i;
        for(int i = 0; i < n; ++i) if(sa[i] >= k) y[p++] = sa[i] - k;

        for(int i = 0; i < m; ++i) c[i] = 0;
        for(int i = 0; i < n; ++i) c[x[y[i]]]++;
        for(int i = 0; i < m; ++i) c[i+1] += c[i];

        for(int i = n-1; i >= 0; --i){
            sa[--c[x[y[i]]]] = y[i];
        }

        swap(x,y);
        x[sa[0]] = 0;
        p = 1;

        for(int i = 1; i < n; ++i){
            x[sa[i]] = (y[sa[i]] == y[sa[i-1]] && y[sa[i]+k] == y[sa[i-1]+k])?p-1:p++;
        }
        if(p >= n) break;
        m = p;
    }


}


void getHeight(int n){
    int i, j, k = 0;
    rep(i, n+1) r[sa[i]] = i;
    for(int i = 0; i < n; ++i){
        if(k) k--;
        j = sa[r[i]-1];
        while(s[i+k] == s[j+k]) ++k;
        //注意详细看训练指南那个图,那个图是从位置i和他排名的而前一个位置k比较
        //然后推出位置i+1和他k+1的关系,h[rank[x]] >= h[rank[x-1]]-1;
        h[r[i]] = k;
    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    int n, m;
    while(scanf("%s", s) != EOF){
        n = strlen(s);
        m = 128;

        getSa(n+1, 128);
        getHeight(n);
        int ans = n;
        int t = r[0];
        int x = n;
        while(t < n){
            x = min(x, h[t+1]);
            ans += x;
            t++;
        }
        t = r[0];
        x = n;
        while(t > 1){
            x = min(x, h[t]);
            ans += x;
            t--;
        }
        printf("%d\n",ans%256);
    }
    return 0;
}
