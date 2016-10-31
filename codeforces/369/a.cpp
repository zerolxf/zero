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
char s[1100][10];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    int n;
    bool ok = false;
    while(cin>>n){
        rep(i,n){
            scanf("%s",s[i]);
            if(ok) continue;
            if(s[i][0]==s[i][1]&&s[i][1]=='O') {
                ok = true;
                s[i][0] = s[i][1] = '+';
            }else if(s[i][3]=='O'&&s[i][4]=='O'){
                ok = true;
                s[i][3] = s[i][4] = '+';
            }
        }
    }
    if(ok){
        printf("Yes\n");
        rep(i,n){
            printf("%s\n",s[i]);
        }
    }else printf("No\n");
    return 0;
}
