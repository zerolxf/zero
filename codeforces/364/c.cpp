/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月23日 星期六 01时17分23秒
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
#define pr(x) //cout << #x << " = " << x << " ";
#define prln(x)// cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
map<char,int> mp;
int cnt;
int getid(char x){
    if(mp.count(x)) return mp[x];
    mp[x] = ++cnt;
    return cnt;
}
char s[maxn];
int vis[maxn];
int a[maxn];
int l[60][maxn];
bool check(int x, int y){
    //bool ok = true;
    for(int i = 1; i <= cnt; ++i){
        if(l[i][y]-l[i][x-1]<1){
            pr(l[i][y]);prln(l[i][x-1]);
            pr(x);pr(y);
            prln(i);
            return false;
            
        }
    }
    return true;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    while(cin >> n){
        scanf("%s", s+1);

        prln(n);
        memset(vis, 0, sizeof vis);
        for(int i = 1; i <= n; ++i){
            vis[s[i]] = true;
        }

        prln(n);
        cnt = 0;
        for(int i = 0; i < 200; ++i){
            if(vis[i]) {
                vis[i] = ++cnt;
                prln(i);
                prln(cnt);
                prln(vis[i]);
            }
        }
        for(int i = 0; i < 60; ++i){
            l[i][0] = 0;
        }
        prln(n);
        for(int i = 1; i <= n; ++i){
            a[i] = vis[s[i]];
            prln(a[i]);
            for(int j = 1; j <= cnt; ++j){
                if(a[i] == j){
                    l[j][i] = l[j][i-1]+1;
                }else{
                    l[j][i] = l[j][i-1];
                }
            }
        }
        prln(n);
        int ans = n;
        for(int i = 1; i <= n; ++i){
            int r = n;
            int lll = i;
            while(lll < r){
                //pr(lll);prln(r);
                int  m = (lll+r)>>1;
                if(check(i,m)) r = m;
                else lll = m+1;
            }
            pr(i);prln(lll);
            prln(check(i,lll));
            if(check(i,lll))ans = min(ans, lll-i+1);
        }
        //prln(cnt);
        cout << ans << "\n";

        

    }
	return 0;
}
