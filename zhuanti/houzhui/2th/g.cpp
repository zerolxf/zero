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
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 1e5+100;
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
    for(int i = 0; i <= n; ++i) ran[sa[i]] = i;
    int k = 0;
    h[n] = 0;
    for(int i = 0; i < n; ++i){
        if(k) --k;
        int j = sa[ran[i]-1];
        while(s[j+k] == s[i+k]) k++;
        h[ran[i]] = k;
    }
}
int dp[maxn][20];

void ST(){

    for(int i = 1; i <= n; ++i){
        dp[i][0] = h[i];
    }
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
    int k = 0;
    while((1<<(k+1)) <= (r-l+1)) ++k;
    return min(dp[l][k], dp[r-(1<<k)+1][k]);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    int kase = 0;
    while(scanf("%s", s) != EOF){
        if(s[0] == '#') break;
        n = strlen(s);
        for(int i = 0; i <= n; ++i) t1[i] = s[i];
        getSa(130);
        getHeight();
        ST();
        int ans = 1;
        int pos = sa[1], len = 1;
        for(int k = 1; k <= n/2; ++k){
            for(int j = k; j < n; j+=k){
                int L = get(ran[j-k], ran[j]);
                //if(L<k) continue;
                //pr(k);pr(j-k);prln(j);
                //prln(L);
                int ma = L/k+1;

                int need = k-L%k;
                int nowpos = j-k;
                //pr(ma);pr(need);prln(nowpos);
                if(j-k-need>=0){
                    //prln(j-k-need);
                    //pr(j-k-need);prln(j-k);
                    int x = get(ran[j-k-need], ran[j-need]);
                    //prln(x);
                    if(x >= k){ 
                        ma++;
                        //prln("success");
                        nowpos = j-k-need;
                    }
                }
                int cnt = 0;
                for(int m = j-k-1; m >= 0 && m > j-k-k && s[m]==s[m+k]; --m){
                    cnt++;
                    if(cnt==need) nowpos = m;
                    else if(ran[nowpos]>ran[m]) nowpos = m;

                }
                if(ma > ans || (ma==ans&&ran[nowpos]<ran[pos])){
                    //prln(nowpos);
                    //prln(k);
                    //prln(ma);
                    ans = ma;
                    len = k;
                    pos = nowpos;
                }
                j += (ma-1)*k;

            }
        }
        printf("Case %d: ",++kase);
        if(ans<2){
            pos = sa[1];
            len = 1;
            ans = 1;
        }
        for(int i = pos; i < pos+len*ans; ++i){
            printf("%c", s[i]);
        }
        printf("\n");
    }
	return 0;
}
