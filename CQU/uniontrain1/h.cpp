/*************************************************************************
	> File Name: hh.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月10日 星期二 09时27分41秒
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
int len[10];
int pos[10];
char ch[5] = "ATGC";
char s[10][10];
int maxdepth, n;
bool dfs(int depth, int *pp) {
    if(depth > maxdepth) return false;
    int p[9];
    int sum = 0;
    for(int i = 0; i < n; ++i) p[i] = pp[i], sum+=len[i]-pp[i];
    if(sum==0) return true;
    for(int i = 0; i < 4; ++i){
        sum = 0;
        for(int j = 0; j < n; ++j){
            p[j] = pp[j];
            while(p[j] < len[j] && s[j][p[j]] == ch[i]) 
            {
                p[j]++,sum++;break;
            }
        }
        if(sum) if(dfs(depth+1, p)){
            return true;
        }
    }
    return false;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        maxdepth = 1;
        for(int i = 0; i < n; ++i){
            scanf("%s", s[i]);
            len[i] = strlen(s[i]);
            if(len[i] > maxdepth) maxdepth = len[i];
        }
        for(; ; maxdepth++){
            for(int i = 0; i < n; ++i) pos[i] = 0;
            if(dfs(0,pos)) break;
        }
        printf("%d\n", maxdepth);
    }
	return 0;
}
