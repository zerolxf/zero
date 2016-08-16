#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 4e5+1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)      //cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
char s[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    while(scanf("%s", s) != EOF){
        int len = strlen(s);
        prln(s);
        int l = -1, r = 0;
        s[len] = '.';
        int first = -1, second = -1;
        for(int i = 0; i < len; ++i){
            if(s[i] == '.') l = i;
            if(s[i] != '0' && s[i] != '.' && first!=-1) second = i;
            if(s[i] != '0' && s[i] != '.' && first==-1) first = i;

        }
        bool ok = true;
        r = len;
        for(int i = len-1; i>=0; --i){
            if(s[i]!='0'&&s[i]!='.') ok = false;
            if(s[i] == '0' && ok){
                r = i;
            }
        }
        if(l==-1) l = len;
        int ecnt = 0;
        ecnt = l - first-1;
        if(ecnt<0) ecnt = l-first;
        pr(l);pr(first);pr(second);prln(ecnt);
        if(first == -1){
            printf("0\n");
            continue;
        }
        if(second == -1){
            if(ecnt) printf("%cE%d\n",s[first],ecnt);
            else printf("%c\n", s[first]);
            continue;
        }

        printf("%c.",s[first]);
        for(int i = first+1; i < r; ++i){
            if(s[i]!='.')printf("%c", s[i]);
        }
        if(ecnt) printf("E%d",ecnt);
        printf("\n");
    }
    return 0;
}
