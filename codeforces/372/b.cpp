/*************************************************************************
    > File Name: b.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月17日 星期六 21时51分04秒
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
bool vis[30];
char s[maxn];
bool check(int pos){
    if(pos<25) return false;
    memset(vis, 0, sizeof vis);
    int need = 26, cnt = 0;
    for(int i = pos; i > pos-26; --i){
        if(s[i]<='Z'&&s[i]>='A') {
            if(!vis[s[i]-'A']) need--,vis[s[i]-'A'] = true;
        }
        else cnt++;
    }
    if(cnt<need) return false;
    for(int i = pos; i > pos-26; --i){
        if(s[i]=='?'){
            //prln(i);
            for(int j = 0; j < 26; ++j){
                if(!vis[j]){
                    vis[j] = true;
                    s[i] = j+'A';
                    break;
                }
            }
        }
    }
    return true;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(scanf("%s", s) != EOF){
        int len = strlen(s);
        bool ok = false;
        for(int i = 0; i < len; ++i) {
            ok = ok || check(i);
        }
        if(!ok){
            printf("-1\n");
        }else{
            for(int i = 0; i < len; ++i){
                if(s[i] == '?'){
                    s[i] = 'A';
                }
            }
            printf("%s\n",s);
        }
    }

	return 0;
}
