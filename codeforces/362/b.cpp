/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月15日 星期五 00时45分39秒
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
char s[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(scanf("%s", s) != EOF){
        int len = strlen(s);
        int nump = len, nume = 0;
        for(int i = 0; i < len; ++i){
            if(s[i] == '.') nump = i;
            if(s[i] == 'e') nume = i;
        }
        //prln(s);
        nump = min(nume,nump);
        int a = s[0] - '0';
        int b = 0;
        for(int i = nume+1; i < len;++i){
            b = b*10+s[i]-'0';
        }
        if(b==0){
            if(nump+2==nume&&s[nump+1]=='0'){
                for(int i = 0; i < nump; ++i){
                    printf("%c",s[i]);

                }
                cout << "\n";
                continue;
            }
            for(int i = 0; i < nume; ++i){
                printf("%c",s[i]);
            }
            printf("\n");
            continue;
        }
        for(int i = nume; i < len+1000;++i){
            s[i] = '0';
        }
        s[len+1000]=0;
        s[nump] = '.';
        int ma = max(nump+b+1,nume);
        //pr(nump);pr(nume);prln(ma);
        //if(a!=0){
            for(int i = 0; i < ma; ++i){
                if(i==0&&s[i]=='0') continue;
                if(s[i]=='.') continue;
                if(i==nump+b+1){
                    printf(".");
                }
                printf("%c",s[i]);
            }
        //}
        printf("\n");
    }
	return 0;
}
