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
char s[maxn];
int q[maxn], tail, top;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    while(scanf("%s", s)!=EOF) {
    	int ans = 0;bool ok = true;
    	top = 0; tail= -1;
    	for(int i = 0; i < n; ++i) {
    		if(s[i]=='*') {
    			tail[++tail] = 500;
    		} else if(s[i] >='A' && s[i] <= 'Z') {
    			tail[++tail] = -(s[i] - 'A' + 1);
    		} else{
    			q[++tail] = s[i] -'a' + 1;
    		}
    	}
    }
    return 0;
}