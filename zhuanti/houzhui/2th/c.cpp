/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月31日 星期日 15时44分48秒
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
#define rep1(i,n) for(int i =1; i <= n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
int sa[maxn], t1[maxn], t2[maxn], ran[maxn], h[maxn], c[maxn];
int n;
void getSa(int m){
    int *x = t1, *y = t2;
    n++;
    for(int i = 0; i <= m; ++i) c[i] = 0;
    for(int i = 0; i < n; ++i) c[x[i]]++;
    for(int i = 0; i < m; ++i) c[i+1] += c[i];
    for(int i = n-1; i >= 0; --i) sa[--c[x[i]]] = i;
    for(int k = 1; k <= n; k <<= 1){
        int p = 0;
        for(int i = n-k; i < n; ++i) y[p++] = i;
        for(int i = 0; i < n; ++i) if(sa[i] >= k) y[p++] = sa[i] - k;
        for(int i = 0; i < m; ++i) c[i] = 0;
        for(int i = 0; i < n; ++i) c[x[y[i]]]++;
        for(int i = 0; i < m; ++i) c[i+1] += c[i];
        for(int i = n-1; i >=0; --i) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for(int i = 1; i < n; ++i){
            x[sa[i]] = (y[sa[i]] == y[sa[i-1]] && y[sa[i]+k] == y[sa[i-1]+k])?p-1:p++;
        }
        if(p >= n) break;
        m = p;
    }
    --n;
}
char s[maxn];
void getHeight2(){
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

void getHeight(){
    for(int i = 1; i <= n; ++i) ran[sa[i]] = i;
    int k = 0;
    //prln(k);
    for(int i = 0; i < n; ++i){
        pr(i);
        if(k) --k;
        //prln(ran[i]-1);
        int j = sa[ran[i]-1];
        //prln(j);
        //prln(k);
        while(s[i+k] == s[j+k]) {
            ++k;
            //pr(i);prln(j);
            //pr(i+k);prln(j+k);
            //pr(s[i+k]);prln(s[j+k]);
            //prln(k);
        }
        h[ran[i]] = k;
    }
}
void solve(){
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        ans += n-sa[i]-h[i];
    }
    cout<<ans<<"\n";
}

int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%s", s);
        int lens = strlen(s);
        n = lens;
        //prln(s);
        for(int i = 0; i <= lens; ++i) t1[i] = s[i];
        getSa(130);
        //prln("SA");
        getHeight2();
        //prln("H");
        //for(int i = 0; i <= n; ++i){
            //pr(i);pr(sa[i]);prln(h[i]);
        //}
        solve();
    }
	return 0;
}
