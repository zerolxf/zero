/*************************************************************************
	> File Name: d.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月15日 星期五 17时06分57秒
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
char s[200][200];
void draw(int x1, int y1, int x2, int y2, char ch) {
   for(int i = x1; i <= x2; ++i){
       for(int j = y1; j <= y2; ++j){
           s[i][j] = ch;
       }
   }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t, n, m, q;
    cin >> t;
    while(t--){
        scanf("%d%d%d", &n, &m, &q);
        draw(1,1,n,m,'.');
        int x1, x2, y1, y2;
        char ch[10];
        for(int i = 1; i <= q; ++i){
            scanf("%d%d%d%d%s",&x1,&y1,&x2,&y2,ch);
            draw(x1,y1,x2,y2,ch[0]);
        }

        for(int i = 1; i <= n; ++i){
            s[i][m+1]=0;
            printf("%s\n",(char*)(s[i]+1));
        }

    }
	return 0;
}
