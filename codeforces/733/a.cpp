/*************************************************************************
    > File Name: a.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月31日 星期一 22时01分52秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <ctime>


using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define repp(i,n,x) for(int i =x; i < n+x; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;

char s[maxn];
char ss[]="AEIOUY";
bool check(char xx){
    for(int i = 0; i < 6; ++i){
        if(xx == ss[i]) return true;
    }
    return false;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    int last = 0, ans = 1;
    scanf("%s", s+1);
    n = strlen(s+1);
    for(int i =1 ; i <= n; ++i){
        if(check(s[i])) {
            ans = max(ans, i-last);
            last = i;
        }
    }
    ans = max(ans, n+1-last);
    cout << ans << "\n";


	return 0;
}
