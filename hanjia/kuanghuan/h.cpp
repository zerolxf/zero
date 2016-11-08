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
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
char a[maxn], s[maxn];
int cnt;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    cnt = 0;
    a[0] = ' ';
    scanf("%s", s+1);
    int n = strlen(s+1);
    //prln(n);
    for(int i = 1; i <= n; ++i) {
    	//pr(a[cnt]);prln(s[i]);
    	if(a[cnt] == s[i]) {
    		cnt--;
    	} else a[++cnt] = s[i];
    }

    if(cnt==0) cout << "Yes\n";
    else printf("No\n");
    return 0;
}