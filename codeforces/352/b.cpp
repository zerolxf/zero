/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月12日 星期四 00时40分29秒
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

bool vis[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    char s[maxn];
    int len;
        cin >> len;
        scanf("%s",s);
        int ans = 0;
        for(int i = 0; i < len; ++i){
            if(vis[s[i]]) ans++;
           vis[s[i]]=true;
        }
        if(len>26) printf("-1\n");
        else printf("%d\n",ans);
	return 0;
}
