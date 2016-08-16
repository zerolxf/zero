/*************************************************************************
	> File Name: poj3294.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月29日 星期五 11时02分55秒
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
int k;
int sa[maxn], t1[maxn], t2[maxn], c[maxn], h[maxn], ran[maxn];
int n;
void getSa(int m){
    int *x = t1, *y = t2;
    n++;
    for(int i = 0; i < m; ++i) c[i] = 0;
    for(int i = 0; i < n; ++i) c[x[i]]++;
    for(int i = 0; i < m; ++i) c[i+1] += c[i];
    for(int i = n-1; i >= 0; --i){
        sa[--c[x[i]]] = i;
    }
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
        swap(x, y);
        x[sa[0]] = 0;
        p = 1;
        for(int i = 1; i < n; ++i){
            x[sa[i]] = (y[sa[i]] == y[sa[i-1]] && y[sa[i]+k] == y[sa[i-1]+k])?p-1:p++;
        }
        if(p >= n) break;
        m = p;
    }
    --n;
}
char s[maxn], ss[110][maxn];
void getHeight(){
    for(int i = 1; i <= n; ++i) ran[sa[i]] = i;
    int k = 0;
    for(int i = 0; i <= n; ++i){
        if(k) k--;
        int j = sa[ran[i]-1];
        while(s[i+k] == s[j+k]) k++;
        h[ran[i]] = k;
    }
}
int vis[maxn], ans[maxn];
int pos[maxn];
int anscnt = 0;
int find(int mid, int k, int mi){
    memset(vis, 0, sizeof vis);
    int x = 0;
    int flag = 0;
    pr(mid);pr(k);prln(mi);
   for(int i = 1; i <= n; ++i){
       while(i <= n && h[i] < mid) ++i;
       prln(i);
       if(i>n) break;
       int siz = 0;
       flag = i;
       while(i <= n && h[i] >= mid){
            for(int j = 0; j < k; ++j){
                if(sa[i] >= pos[j] && sa[i]+mid <= pos[j+1] && vis[j] != flag){
                    vis[j] = flag;
                    pr(i);prln(sa[i]);
                    siz++;
                }
                if(sa[i-1] >= pos[j] && sa[i-1]+mid <= pos[j+1] && vis[j] != flag){
                    vis[j] = flag;
                    pr(i);prln(sa[i-1]);
                    siz++;
                }
            }
            ++i;
       }
       pr(flag);pr(siz);
       prln(mi);
       if(siz > mi){
           pr(x);prln(flag);
           ans[x++] = sa[flag];
           siz = 0;
       }

   }
   return x;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    scanf("%d", &k);    
    int kase = 0;
    while(scanf("%d", &k) != EOF && k){
        pos[0] = 0;
        for(int i = 0; i < k; ++i){
            scanf("%s", ss[i]);
        }
        int lens = strlen(ss[0]);
        pos[0] = 0;
        if(kase++) printf("\n");
        prln(lens);
        for(int i = 0; i < k; ++i){
            memcpy(s+pos[i], ss[i], lens);
            pos[i+1] = pos[i]+lens;
        }
        for(int i = 0; i <= k; ++i){
            pr(i);prln(pos[i]);
        }
        n = lens*k;
        s[n] = 0;
        for(int i = 0; i <= n; ++i) t1[i] = s[i];
        prln(s);
        getSa(140);
        prln(s);
        prln("1");
        getHeight();
        for(int i = 0; i <= n; ++i){
            pr(i);pr(sa[i]);prln(h[i]);
        }
        prln("1");
        int l = 0, r = lens;
        while(l < r){
            int mid = (l+r+1) >> 1;
            pr(l);prln(r);
            if(find(mid, k, k/2)) l = mid;
            else r = mid-1;
        }
        if(l) {
            //printf("%d\n",l);
            int cnt = find(l, k, k/2);
            for(int i = 0; i < cnt; ++i){
                for(int j = 0; j < l; ++j)
                printf("%c", s[ans[i]+j]);
                printf("\n");
            }
        }
        else printf("?\n");
    }
	return 0;
}
