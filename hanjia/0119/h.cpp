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
const int maxn = 5e6+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
char ss[maxn];
int q[maxn], vis[maxn], top, tail;
bool isemoticons(char ch) {
	if(ch == ',' || ch == '(' || ch == ')' || ch == '-' || ch == ':' || ch == ';')
    	return true;
    return false;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    string s;
    getline(cin,s);
    int n = s.size();
    tail = 0;int cnt = 0; int ans = 0;
    for(int i = 0; i < n; ++i) {
    	if(isemoticons(s[i])) {
    		ss[tail++] = s[i];
    	}
    }
    ss[tail] = '\n';
    int lens = strlen(ss);
    for(int i = 0; i < lens; ++i) {
    	if(ss[i] == '(' || ss[i]==')') {
    		ans++;
    	}
    	if(ss[i] =='('&&ss[i+1]==')') {
    		--ans;
    		i++;
    	}
    }
    printf("%d\n", ans);
    return 0;
}