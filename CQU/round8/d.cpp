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
const int maxn = 2e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))

bool vis[26][26][26][26];
char s[500100];
int t[4];

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    s[0] = 'z', s[1] = 'z', s[2] = 'z';
    t[0] = 25, t[1] = 25, t[2] = 25;
    int cnt = 3;
	int num[4];
    while (1) {
    	for (int i = 0; i < 3; ++i) num[i] = t[i];
    	bool flag = 1;
    	for (int i = 0; i < 26; ++i) {
    		if (!vis[num[0]][num[1]][num[2]][i]) {
    			vis[num[0]][num[1]][num[2]][i] = 1;
    			t[3] = i;
    			s[cnt++] = 'a' + i;
    			flag = 0;
    			break;
    		}
    	}
    	for (int i = 0; i < 3; ++i) t[i] = t[i + 1];
    	if (flag) break;
    }
    int n;
    while (~scanf("%d", &n)) {
    	if (n > cnt) printf("Impossible\n");
    	else {
    		for (int i = 0; i < n; ++i) printf("%c", s[i]);
    		printf("\n");
    	}
    }
    return 0;
}