/*************************************************************************
	> File Name: h.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月07日 星期六 17时20分56秒
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
bool vis[100];
int depth;
char s[10][30];
int len[10];
int n;
int kk;
int dfs(int pos, int now, int id, int cnt) {
    if(cnt > depth) return false;
    if(id==n-1&&now==len[id]){
        return cnt;
    } else if(now==len[id]) {
        return dfs(0,0,id+1,cnt);
    } else {
        for(int i = 0; i < kk;++i){
            int npos = i*4+s[id][now];
            int temp = s[id][now];
            if(pos<npos && npos<kk*4){
                if(vis[npos]) {
                    int ans = dfs(npos, now+1, id, cnt);
                    if(ans){
                        return ans;
                    }
                }else {
                    vis[npos] = true;
                    int ans = dfs(npos, now+1, id, cnt+1);
                    if(ans){
                        return ans;
                    } 
                    vis[npos] = false;
                }
            }
        }
    }
    return false;
}
int ok(int x) {
    depth = x;
    memset(vis,0,sizeof vis);
    int ans = dfs(-1, 0, 0, 0);
    return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
  //  freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    kk = 10;
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            scanf("%s", s[i]);
            len[i]  =strlen(s[i]);
            for(int j = 0; j < len[i]; ++j){
                if(s[i][j] == 'A')  s[i][j] = 0;
                else if(s[i][j] == 'C') s[i][j] = 1;
                else if(s[i][j] == 'G') s[i][j] = 2;
                else s[i][j] = 3;
            }
        }
        int l = 1, r = kk*4,m;
        int ans;
        while(l < r) {
            m = (l+r)>>1;
            ans = ok(m);
            if(ans) r = ans;
            else l = m+1;
        }
        printf("%d\n", l);
    }
	return 0;
}
