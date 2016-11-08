/*************************************************************************
    > File Name: k.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月07日 星期日 13时10分37秒
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
int cnt[30];
char s[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int k, len;
    cin >> k;
    scanf("%s", s);
    len = strlen(s);
    memset(cnt,0,sizeof cnt);
    for(int i = 0; i < len; ++i){
        cnt[s[i]-'a']++;
    }
    bool ok = true;
    for(int i = 0; i < 26; ++i){
        if(cnt[i]%k==0){
            cnt[i] = cnt[i]/k;
        }else ok = false;
    }
    if(ok){
        for(int l = 0; l < k; ++l)
        for(int i = 0; i < 26; ++i){
            for(int j = 0; j < cnt[i]; ++j){
                printf("%c",'a'+i);
            }
        }
        printf("\n");
    }else{
        printf("-1\n");
    }
	return 0;
}
