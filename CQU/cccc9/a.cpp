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
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    int n;
    char s[10];
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%s", s);
        int len = strlen(s);
        int pos = 0;
        for(int i = 0; i < len; ++i){
            if(s[i] == ':') pos = i;
        }
        int l = 0, r = 0;
        for(int i = 0;i < pos; ++i){
            l = l*10+s[i] - '0';
        }
        for(int i = pos+1; i < len; ++i){
            r = r*10+s[i] - '0';
        }
        //pr(l);prln(r);
        if(r==0){
            if(l<12) l += 12;
            else l -= 12;
            printf("%d\n",l);
        }else printf("0\n");
    }
    return 0;
}
