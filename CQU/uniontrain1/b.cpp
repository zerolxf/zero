/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月02日 星期一 20时41分52秒
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
const int maxn = 5e6+100;
const int INF = 0x3f3f3f3f;
char s[maxn], t[maxn], ss[maxn];
int fs[maxn];
int lent, lens, lenss;
void getfail(char *str, int *fail){
    fail[0] = 0;
    fail[1] = 0;
    int j = 0;
    for(int i = 1; i < lens; ++i){
        j = fail[i];
        while(j && str[i] != str[j]) j = fail[j];
        fail[i+1] = (str[i] == str[j]?j+1:0); 
    }
}
void find(char *T, char *S, int *fail){
    int j = 0;
    for(int i = 0; i < lent; ++i){
        while(j && T[i] != S[j]) j = fail[j];
        if(T[i] == S[j]) ++j;
        if(j == lens){
            T[i-lens+1] = 0;
            j = 0;
        }
    }
}
void printT(char* T, char* b){
    for(int i = 0; i < lent; ++i){
        if(T[i] == 0){
            printf("%s", b);
            i+=lens-1;
        } else printf("%c", T[i]);
    }
    printf("\n");
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, m, kase;
    scanf("%d", &kase);
    while(kase--){
        scanf("%s%s%s", t, s, ss);
        lent = strlen(t);
        lens = strlen(s);
        lenss = strlen(ss);
        getfail(s, fs);
        find(t, s, fs);
        printT(t, ss);
    }
	return 0;
}
