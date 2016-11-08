/*************************************************************************
	> File Name: a.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年07月03日 星期日 12时55分41秒
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
char a[maxn], b[maxn], c[maxn];
int cnta, cntb, cntc;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(scanf("%s", s) != EOF){
        int len = strlen(s);
        int sum = 0;
        for(int i = 0; i < len; ++i){
            sum += s[i] -'0';
        }
        bool ok = true;
        if(sum%3!=0)
        {
            printf("-1\n");
            continue;
        }
        int x = 0;
        for(int i = len-1; i>=0; --i){
            int ma = s[i] - '0';
            if(x<sum/3) {
                if(x+ma>sum/3){
                    a[cnta++] = sum/3-x + '0';
                    s[i] -= sum/3-x;
                    x = sum/3;
                }
                else {
                    a[cnta++] = s[i];
                    s[i] = '0';
                    x += ma;
                }
            }
        }
        x = 0;
        for(int i = len-1; i>=0; --i){
            int ma = s[i] - '0';
            if(x<sum/3) {
                if(x+ma>sum/3){
                    b[cntb++] = sum/3-x + '0';
                    s[i] -= sum/3-x;
                    x = sum/3;
                }
                else {
                    b[cntb++] = s[i];
                    s[i] = '0';
                    x += ma;
                }
            }
        }
        x = 0;
        //prln(s);
        for(int i = len-1; i>=0; --i){
            int ma = s[i] - '0';
            if(x<sum/3) {
                if(x+ma>sum/3){
                    c[cntc++] = sum/3-x + '0';
                    s[i] -= sum/3-x;
                    x = sum/3;
                }
                else {
                    c[cntc++] = s[i];
                    x += ma;
                    s[i] = '0';
                }
        //        pr(i);prln(c[cntc-1]);
            }
        }
        for(int i = cnta-1; i >= 0; --i){
            printf("%c",a[i]);    
        }
        printf(" ");
        for(int i = cntb-1; i >= 0; --i){
            printf("%c",b[i]);    
        }
        printf(" ");
        for(int i = cntc-1; i >= 0; --i){
            printf("%c",c[i]);    
        }
        printf("\n");
    }
	return 0;
}
