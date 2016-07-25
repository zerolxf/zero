/*************************************************************************
	> File Name: l.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月25日 星期一 15时52分26秒
 ************************************************************************/
#include<bitset>
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
bitset<maxn> dp[2][3], same[26]; 
char s[maxn], t[maxn];
int lens, lent;
void init(){
    for(int i = 0; i < 26; ++i){
        same[i].reset();
        for(int j = 0; j < lens; ++j){
            if(s[j] - 'a' == i){
                same[i][j] = 1;
            }
        }
    }
}
int ans[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int kase;
    scanf("%d", &kase);
    while(kase--){
        scanf("%d%d", &lens, &lent);
        scanf("%s", s);
        scanf("%s", t);
        for(int i = 0; i < 26; ++i){
            same[i].reset();
        }
        init();
        int now = 0, pre = 1;
        dp[now][0].reset();
        dp[now][1] = same[t[0] - 'a'];
        if(lent>1)dp[now][2] = same[t[1] - 'a'];
        for(int i = 1; i < lent; ++i){
            swap(now,pre);
            dp[now][0] = (dp[pre][2]<<1)&same[t[i-1]-'a'];
            dp[now][1] = ((dp[pre][0]|dp[pre][1])<<1)&same[t[i]-'a'];
            if(i<lent-1)
            dp[now][2] = ((dp[pre][0]|dp[pre][1])<<1)&(same[t[i+1]-'a']);
        }
        MEM(ans, 0);
        for(int i = 0; i < lens; ++i){
            if(i+lent-1>=0&&i+lent-1<lens) ans[i] = dp[now][0][i+lent-1] ;
            if(i+lent-1>=0&&i+lent-1<lens) ans[i] |= dp[now][1][i+lent-1];
        }
        for(int i = 0; i < lens; ++i){
            printf("%c",ans[i]+'0');
        }
        printf("\n");
    }
	return 0;
}
