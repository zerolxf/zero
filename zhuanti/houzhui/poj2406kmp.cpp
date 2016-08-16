/*************************************************************************
	> File Name: poj2406kmp.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月29日 星期五 16时12分08秒
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
int fail[maxn];
char s[maxn];
int lens;
void getfail(){
    fail[0] = 0;
    fail[1] = 0;
    int j = 0;
    for(int i = 1; i < lens; ++i){
        j = fail[i];
        while(j&& s[i] != s[j]) j = fail[j];
        fail[i+1] = (s[i] == s[j])?j+1:0;
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(scanf("%s", s) != EOF){
        if(s[0] == '.'){
            break;
        }
        lens = strlen(s);
        getfail();
        int ans = 0;
        int n = lens;
        //for(int i = 0; i <= lens; ++i){
            //pr(i);prln(fail[i]);
        //}
        //prln(fail[n]);
        //cout<<fail[n]<<"\n";
        ans = n/(n-fail[n]);
        //cout<<ans<<"\n";
        if(n%(n-fail[n]) == 0)
        cout << ans << "\n";
        else cout << "1\n";

    }
	return 0;
}
