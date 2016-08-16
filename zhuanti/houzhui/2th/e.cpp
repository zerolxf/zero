/*************************************************************************
	> File Name: e.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月31日 星期日 16时45分41秒
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
int f[maxn];
char s[maxn];
void getfail(){
    int len = strlen(s);
    f[0] = f[1] = 0;
    for(int i = 1; i < len; ++i){
        int j = f[i];
        while(j && s[j] != s[i]) j = f[j];
        f[i+1] = s[j] == s[i]?j+1:0;
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(scanf("%s", s) != EOF){
        if(s[0] == '.') break;
        int n = strlen(s);
        getfail();
        if(n%(n-f[n])==0){
            printf("%d\n",n/(n-f[n]));
        }else{
            printf("%d\n",1);
        }
    }
	return 0;
}
