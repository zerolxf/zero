/*************************************************************************
	> File Name: f.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月31日 星期日 21时47分11秒
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
#define pr(x) //cout << #x << " = " << x << " ";
#define prln(x) //cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
int sa[maxn], t1[maxn], t2[maxn], c[maxn], h[maxn];
int n;
void getSa(int m){
    int *x = t1, *y = t2;
    n++;
    for(int i = 0; i <= m; ++i) c[i] = 0;
    for(int i = 0; i < n; ++i) c[x[i]]++;
    for(int i = 0; i < m; ++i) c[i+1] += c[i];
    for(int i = 0; i < n; ++i) sa[--c[x[i]]] = i;
    for(int k = 1; k <= n; k <<= 1){
        int p =0;
        for(int i = n-k; i < n; ++i) y[p++] = i;
        for(int i = 0; i < n; ++i) if(sa[i] >= k) y[p++] = sa[i]- k;
        for(int i = 0; i <= m; ++i) c[i+1] = 0;
        for(int i = 0; i < n; ++i) c[x[y[i]]]++;
        for(int i = 0; i < m; ++i) c[i+1] += c[i];
        for(int i = n-1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        x[sa[0]] = 0;
        p = 1;
        for(int i = 1; i < n; ++i){
            x[sa[i]] = (y[sa[i]] == y[sa[i-1]] && y[sa[i]+k] == y[sa[i-1]+k])?p-1:p++;
        }
        if(p >= n) break;
        m = p;
    }
    n--;
}
char s[maxn];
int ran[maxn];
void getHeight(){
    for(int i = 1; i <= n; ++i) ran[sa[i]] = i;
    int k = 0;
    for(int i = 0; i < n; ++i){
        if(k) --k;
        int j = sa[ran[i]-1];
        while(s[j+k] == s[i+k]) k++;
        h[ran[i]] = k;
    }
}
int dp[65537][20];

void ST(){
    for(int j = 1; (1<<j) <= n; ++j){
        for(int i = 1; i+(1<<j)-1<=n; ++i){
            dp[i][j] = min(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
        }
    }
}
int get(int l, int r){
    if(l>r) swap(l,r);
    if(l==r) return 0;
    l++;
    //pr(l);prln(r);
    int k = 0;
    while((1<<(k+1)) <= (r-l+1)) ++k;
    //prln(k);
    //prln(dp[l][k]);
    return min(dp[l][k], dp[r-(1<<k)+1][k]);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        char ss[3];
        for(int i = 0; i < n; ++i){
            scanf("%s", ss);
            s[i] = ss[0];
            t1[i] = s[i];
        }
        s[n] = 0;t1[n] = 0;
        getSa(130);
        getHeight();
        for(int i = 1; i <= n; ++i){
            dp[i][0] = h[i];
            pr(i);pr(sa[i]);prln(h[i]);
        }
        ST();
        prln(s);
        int ans = 0;
        for(int k = 1; k <= n; ++k){
            prln("*****************===*************");
            for(int j = k; j < n; j+=k){
                int l = 0;
                prln(k);
                pr(ran[j-k]);prln(ran[j]);
                pr(j-k);prln(j);
                while(j < n && get(ran[j-k], ran[j]) < k) {
                    int mi = get(ran[j-k], ran[j]);
                    pr(j-k);pr(j);prln(mi);
                    j+=k;
                }
                l = j-k;
                prln(l);
                if(j >= n) break;
                while(j < n && get(ran[j-k], ran[j]) >= k) j+=k;
                int L = j - l;
                int r = 0;
                if(j != n) r = get(ran[j-k], ran[j]);
                int lneed = k-r;
                int ls = l-lneed;
                prln(ls);prln(lneed);
                if(ls>=0&&ls+k<=n){
                    pr(ls);pr(l);pr(ran[ls]);prln(ran[l]);
                    int temp =get(ran[ls], ran[ls+k]);
                    prln(temp);
                    if(get(ran[ls], ran[ls+k]) >=lneed) L += k;
                }
                pr(k);pr(l);pr(j);prln(L/k);
                ans = max(ans, L/k);
            }
        }
        cout << ans << "\n";
    }
	return 0;
}
