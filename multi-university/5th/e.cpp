/*************************************************************************
	> File Name: e.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月03日 星期三 18时20分29秒
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
const int N = 27;
typedef pair<int,int> P;
const int MOD = 1e9+7;
struct Pstree{
    int nxt[maxn][26];
    int fail[maxn];
    int num[maxn];
    int len[maxn];
    int ans[maxn];
    char s[maxn];
    int last, n, p;
    int newnode(int x){
        for(int i = 0; i < N; ++i){
            nxt[p][i] = 0;
        }
        len[p] = x;
        num[p] = 0;
        ans[p] = 0;
        return p++;
    }
    void init(){
        p = 0;
        n = 0;
        last = 0;
        newnode(0);
        newnode(-1);
        s[n] = 255; 
        fail[0] = 1;
    }
    int getfail(int x){
        while(s[n-len[x]-1] != s[n]) x = fail[x];
        return x;
    }
    P add(int c){
        c -= 'a';
        s[++n] = c;
        int cur =  getfail(last);
        if(!nxt[cur][c]){
            int now = newnode(len[cur]+2);
            fail[now] = nxt[getfail(fail[cur])][c];
            nxt[cur][c] = now;
            num[now] =  num[fail[now]] + 1;
            ans[now] = ans[fail[now]] + len[cur]+2;
            ans[now] %= MOD;
        }
        last = nxt[cur][c];
        return P(num[last], ans[last]);
    }
}pstree;
char s[maxn];
int lnum[maxn];
int lans[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    while(scanf("%s", s) != EOF){
        n = strlen(s);
        pstree.init();
        for(int i = 0; i < n; ++i){
            P ans = pstree.add(s[i]);
            lnum[i+1] = ans.first;
            lans[i+1] = ans.second;
        }
        pstree.init();
        ll cnt = 0;
        for(int i = n-1; i > 0; --i){
            P ans = pstree.add(s[i]);
            cnt += ((ll)(i+1)*lnum[i] - (ll)lans[i])%MOD*((ll)((ll)i*ans.first%MOD) + ans.second)%MOD;
            cnt %= MOD;


        }
        cnt = (cnt%MOD+MOD)%MOD;
        printf("%lld\n", cnt);
    }
	return 0;
}
