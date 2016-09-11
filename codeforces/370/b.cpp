/*************************************************************************
    > File Name: b.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月11日 星期日 01时05分36秒
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
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;

    char s[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    scanf("%s", s);
    int len = strlen(s);
    int a = 0, b = 0;
    rep(i,len){
        if(s[i] == 'U') a++;
        else if(s[i] == 'D') a--;
        else if (s[i] == 'L') b++;
        else b--;
    }
    if(abs(a+b)%2==1){
        printf("-1\n");
    }else{
        int ans = abs(abs(a)+abs(b))/2;

        cout<<ans<<"\n";
    }

	return 0;
}
