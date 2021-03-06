/*************************************************************************
	> File Name: m.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月09日 星期一 13时15分32秒
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
double ans[10];
char s[1000];
string sz[]={"B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"}; 
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t, kase = 0;
    scanf("%d", &t);
    ans[0] = 1;
    ans[1] = 1000.0/1024;
    for(int i = 2; i < 9; ++i){
        ans[i] = ans[i-1]*ans[1];
    }
    while(t--){
        scanf("%s", s);
        int l = 0, r = 0;
        string str;
        int len = strlen(s);
        for(int i = 0; i < len; ++i){
            if(s[i] == '[') l = i;
            if(s[i] == ']') r = i;
        }
        for(int i = l+1; i < r; ++i){
            str += s[i];
        }
        int pos = 0;
        for(int i = 0; i < 9; ++i){
            if(str == sz[i]) pos = i;
        }
        printf("Case #%d: %.2f%\n", ++kase,(100.0 - ans[pos]*100));
    }
	return 0;
}
