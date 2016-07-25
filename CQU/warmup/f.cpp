*************************************************************************
	> File Name: f.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月15日 星期五 18时13分44秒
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
char s[maxn];
char a[10][10];
int n, m;
bool get(char s[], char str[]){
    pr(s);prln(str);
    for(int i = 0; i < n; ++i){
        bool ff = true;
        for(int j = 0; j < m; ++j){
            if(s[i+j]!=str[j]){
                ff = false;
                pr(s[i+j]);pr(str[j]);
                pr(i);prln(j);
            }
        }
        pr(i);prln(ff);
        if(ff) return true;
    }
    return false;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

    int t;
    cin >> t;
    while(t--){
        bool ok = false, flag = false;
        scanf("%s%s", s, a[0]);
        for(int i = 0; i < 4; ++i){
            int cnt = 0;
            for(int j = 0; j < 4; ++j){
                if(j==i) continue;
                a[i+1][cnt++] = a[0][j];
            }
            a[i+1][cnt] = 0;
            prln(a[i+1]);
        }
        m = 4;
        n = strlen(s);
        ok = get(s, a[0]);
        m = 3;
        for(int i = 0; i < 4; ++i){
            flag |= get(s,a[i+1]);
        }
        pr(ok);prln(flag);
        if(ok){
            printf("good\n");
        }else if(flag){
            printf("almost good\n");
        }else{
            printf("none\n");
        }

    }
	return 0;
}
