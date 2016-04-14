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
char ss[30][30]={"063","010", "093","079","106","103","119","011","127","107"};
int id[maxn];
char str[maxn];
ll c[maxn];
void getans(char s[]) {
	int len1 = 0, len2 = 0, len = 0;
	len = strlen(s);
	for(int i = 0; i  < len; ++i) {
		if(s[i] == '+') len1 = i;
		if(s[i] == '=') len2 = i;
	}
	ll aa = 0, bb = 0, cc, cnt = 0;
	for(int i = 0; i < len1; i+=3) {
		int x = (s[i+2]-'0') + 10*(s[i+1]-'0') + 100*(s[i]-'0');
		aa = aa*10+id[x];
	}
	for(int i = len1+1; i < len2; i+=3) {
		int x = (s[i+2]-'0') + 10*(s[i+1]-'0') + 100*(s[i]-'0');
		bb = bb*10+id[x];
	}
	cc = aa+bb;
	cnt = 0;
	while(cc) {
		c[cnt++] = cc%10;
		cc /= 10;
	}

	printf("%s", s);
	for(int i = cnt-1; i >= 0; --i) {
		printf("%s", ss[c[i]]);
	}
	printf("\n");
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
   // string ss[]={"063","010", "093","079","106","103","119","011","127","111"};
    int num[]={63,10,93,79,106,103,119,11,127,107};
    for(int i = 0; i< 10; ++i) {
    	id[num[i]] = i;
    }
   while( scanf("%s",str)!=EOF){
    	if(str[0] == 'B') break;
    	getans(str);
	}

    return 0;
}