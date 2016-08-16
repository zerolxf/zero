/*************************************************************************
	> File Name: d.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月03日 星期三 17时15分59秒
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
const int N = 26;
struct Pstree{
    int nxt[maxn][27];
    int fail[maxn];
    int num[maxn];
    int cnt[maxn];
    int len[maxn];
    int s[maxn];
    int n;
    int p, last;
   int newnode(int x){
        for(int i = 0; i < N; ++i) nxt[p][i] = 0;
        len[p] = x;
        cnt[p] = 0;
        num[p] = 0;
        return p++;
    }
    void init(){
        p = 0;
        newnode(0);
        newnode(-1);
        last = 0;
        n = 0;
        s[n] = -1;
        fail[0] = 1;
    }
    int getfail(int pos){
        while(s[n-len[pos]-1] != s[n]) pos = fail[pos];
        return pos;
    }
    void add(int c){
        c -= 'a';
        s[++n] = c;
        int cur = getfail(last);
        if(!nxt[cur][c]){
            int now = newnode(len[cur] + 2);
            fail[now] = nxt[getfail(fail[cur])][c];
            nxt[cur][c] = now;
            num[now] = num[fail[now]] + 1;
        }
        last = nxt[cur][c];
        cnt[last]++;
    }
}pstree;

char s[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    scanf("%s", s);
    int len = strlen(s);
    pstree.init();
    for(int i = 0; i < len; ++i){
        pstree.add(s[i]);
        printf("%d ", pstree.p-2);
    }
    printf("\n");
	return 0;
}
