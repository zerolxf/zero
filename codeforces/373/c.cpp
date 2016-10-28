/*************************************************************************
    > File Name: c.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月23日 星期五 21时34分20秒
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

char s[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

    int n, t;
    while(cin>>n>>t){
        scanf("%s", s+1);
        int len = strlen(s+1);
        
        int pos = len+1;
        for(int i = 1; i < len+1; ++i) if(s[i] == '.') pos = i;
        int first = len+1;
        for(int i = pos; i < len+1; ++i) if(s[i] >= '5'){
            first = i;
            break;
        }
        int cnt = t;
        s[0] = '0';
        for(int i = first; i > 0; --i){
            //prln(i);
            if(s[i]=='.'+1){
                s[i] = '.';
                s[i-1]++;
                //printf("s[i-1] %c\n",s[i-1]);
            }
            else if(s[i]>'9') {

                //printf("s[i-1] %c\n",s[i-1]);
                s[i-1]++;
                s[i] = '0';

                //printf("s[i-1] %c\n",s[i-1]);
            }
            if(s[i] != '.' && s[i] >= '5'&&cnt>0&&i>pos){
                s[i] = '0';
                s[i-1]++;
                cnt--;
            }

            //printf("s[i] = %c\n",s[i]);
        }
        int ed = first;
        for(int i = first; i > pos; --i){
            if(s[i]>'0') {
                break;
            }
            ed = i;
        }

        //prln(ed);
        if(s[0]=='1'){
            for(int i = 0; i < pos; ++i) printf("%c",s[i]);
             if(ed==pos+1) {
                printf("\n");
                break;
            }
            for(int i = pos; i < ed; ++i) printf("%c",s[i]);
            printf("\n");
            break;
        }else{

            for(int i = 1; i < pos; ++i) printf("%c",s[i]);
            if(ed==pos+1) {
                printf("\n");
                break;
            }
            for(int i = pos; i < ed; ++i) printf("%c",s[i]);
            printf("\n");

        }



    }

	return 0;
}
