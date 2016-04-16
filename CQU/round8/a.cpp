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
const int maxn = 7e7;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))

char s[maxn];

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int ans = 0;
    while (gets(s)) {
    	int len = strlen(s);
    	for (int i = 0; i < len; ++i) {
    		if (isalpha(s[i])) {
    			s[i] = tolower(s[i]);
    		}
    	}

    	for (int i = 0; i < len - 3; ++i) {
    		if (s[i] == 'd') {
    			if (s[i + 1] == 'o' && s[i + 2] == 'g' && s[i + 3] == 'e') {
    				++ans;
    				i += 3;
    			}
    		}
    	}
    }
    printf("%d\n", ans);
    return 0;
}