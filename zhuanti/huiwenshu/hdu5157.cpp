/*************************************************************************
	> File Name: hdu5157.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月04日 星期四 08时47分39秒
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
const int N = 26;
struct Pstree{
    int nxt[maxn][26];
    int s[maxn];
    int len[maxn];
    int num[maxn];
    int cnt[maxn];
    int ans[maxn];
    int fail[maxn];
    int p, n, last;
    int addnode(int x){
        for(int i = 0; i < N; ++i) nxt[p][i] = 0;
        len[p] = x;
        cnt[p] = num[p] = ans[p] = 0;
        return p++;
    }
    void init(){
        last = n = p = 0;
        addnode(0);
        addnode(-1);
        fail[0] = 1;
        s[n] = -1;
    }
    int getfail(int x){
        while(s[n-len[x]-1] != s[n]) x = fail[x];
        return x;
    }
    int add(int c){
        c -= 'a';
        s[++n] = c;
        int cur = getfail(last);
        if(!nxt[cur][c]){
            int now = addnode(len[cur] + 2);
            fail[now] = nxt[getfail(fail[cur])][c];
            nxt[cur][c] = now;
            num[now] = num[fail[now]] + 1; 
        }
        last = nxt[cur][c];
        cnt[last]++;
        return num[last];
    }
}ptree;
char s[maxn];
int l[maxn];
ll r[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(scanf("%s", s) != EOF) {
        int lens = strlen(s);
        ptree.init();
        for(int i = 0; i < lens; ++i){
            l[i+1] = ptree.add(s[i]);
            //pr(i);prln(l[i+1]);
        }
        ptree.init();
        for(int i = lens-1; i >= 0; --i){
            r[i+1] = ptree.add(s[i]);
            //pr(i);prln(r[i+1]);
        }
        for(int i = 1; i < lens; ++i){
            //l[i+1] += l[i];
        }
        for(int i = lens; i > 1; --i){
            r[i-1] += r[i];
        }
        ll ans = 0;
        for(int i = 1; i < lens; ++i){
            //pr(l[i]);prln(r[i+1]);
            ans += (ll)l[i]*r[i+1];
        }
        printf("%lld\n", ans);

    }
	return 0;
}
