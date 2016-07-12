
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
#include<vector>

using namespace std;
const int maxn = 1e5+100;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
char s[maxn], s2[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    while(scanf("%s%s", s, s2) != EOF) {
        int len1 = strlen(s), len2 = strlen(s2);
        int i = 0, j = 0;
        while(j < len2) {
            if(s[i] == s2[j]) ++i;
            ++j;
            if(i == len1) break;
        }
        if(i == len1) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
