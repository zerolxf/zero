/*************************************************************************
	> File Name: poj2406.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月29日 星期五 15时03分08秒
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
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
int prime[2000];
int vis[maxn];
int pcnt;
int kase;
void getprime(int n){
    int m = sqrt(n+0.5);
    pcnt = 0;
    for(int i = 1; i <= m; ++i){
        if(n%i==0){
            prime[pcnt++] = i;
            vis[i] = kase;
            if(vis[n/i] != kase){
                prime[pcnt++] = n/i;
            }
        }
    }
    sort(prime, prime+pcnt);
}
int t1[maxn], t2[maxn], c[maxn], ran[maxn], h[maxn];
int n;
int sa[maxn];
void getSa(int m){
    int *x = t1, *y = t2;
    n++;
    for(int i = 0; i < m; ++i) c[i] = 0;
    for(int i = 0; i < n; ++i) c[x[i]]++;
    for(int i = 0; i < m; ++i) c[i+1] += c[i];
    for(int i = n-1; i >= 0; --i) sa[--c[x[i]]] = i;
    for(int k = 1; k <= n; k <<= 1){
        int p = 0;
        for(int i = n-k; i < n; ++i) y[p++] = i;
        for(int i = 0; i < n; ++i) if(sa[i] >= k) y[p++] = sa[i]-k;
        for(int i = 0; i < m; ++i) c[i] = 0;
        for(int i = 0; i < n; ++i) c[x[y[i]]]++;
        for(int i = 0; i < m; ++i) c[i+1] += c[i];
        for(int i = n-1; i >= 0; --i){
            sa[--c[x[y[i]]]] = y[i];
        }
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for(int i = 1; i < n; ++i){
            x[sa[i]] = (y[sa[i]] == y[sa[i-1]] && y[sa[i]+k] == y[sa[i-1]+k])?p-1:p++;
        }
        if(p >= n) break;
        m = p;
    }
    n--;
}
char s[maxn];
void getHeight(){
    for(int i = 1; i <= n; ++i) ran[sa[i]] = i;
    int k = 0;
    for(int i = 0; i < n; ++i){
        if(k) --k;
        int j = sa[ran[i] - 1];
        //prln(j);
        while(s[i+k] == s[j+k]) k++;
        h[ran[i]] = k;
    }
}
int dp[maxn][22];
void getST(){
    for(int i = 1; i <= n; ++i) dp[i][0] = h[i];
    for(int j = 1; (1<<j) <= n; ++j){
        for(int i = 1; i + (1<<j) - 1 <= n; ++i){
            dp[i][j] = min(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
        }
    }
}
int getquery(int l, int r){
    if(l-1==r) return -1;
    int k = 0;
    while(1<<(k+1) <= (r-l+1)) ++k;
    //prln(k);
    //pr(l);pr(r);
    //pr(dp[l][k]);prln(dp[r-(1<<k)+1][k]);
    return min(dp[l][k], dp[r-(1<<k)+1][k]);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(scanf("%s", s) != EOF ){
        if(s[0] == '.') break;
        ++kase;
        int lens = strlen(s);
        n = lens;
        for(int i = 0; i <= n; ++i) t1[i] = s[i];
        getprime(n);
        //prln("ok");
        getSa(130);
        //prln("ok");
        getHeight();
        //prln("ok");
        getST();
        //prln("ok");
        int ans = 1;
        //for(int i = 0; i <= n; ++i){
            //pr(i);pr(sa[i]);pr(ran[i]);prln(h[i]);
        //}
        for(int i = 0; i < pcnt; ++i){
            int l = INF, r = 0;
            //pr(i);pr(prime[i]);
            int temp = n/prime[i];
            //prln(temp);
            for(int j = 0; j*temp < n; ++j){
                //pr(j*prime[i]);
                l = min(l, ran[j*temp]);
                r = max(r, ran[j*temp]);
                //prln(ran[j*prime[i]]);
            }
            int q = getquery(l+1, r);
            //pr(l);prln(r);
            //prln(q);prln(temp);
            //prln(ans);
            if(q >= n/prime[i] || q == -1) {
                ans = prime[i];
            }
        }
        printf("%d\n", ans);
    }
	return 0;
}
