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
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
#define rep(i,n) for(int i = 0; i < n; ++i)
int sa[maxn], ran[maxn];
char c[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, t;
    cin >> t;
    while(t--) {
        cin >> n;
        rep(i,n) scanf("%d",ran+i+1);
        rep(i,n) sa[ran[i+1]] = i+1;
        sa[n+1] = 0;
        sa[n+2] = 0;
        ran[0] = n+1;
        c[n+1] = 0;
        bool ok = true;
        char ch = 'a';
        for(int i = 1; i <= n; ++i){
            if(c[ran[i-1]] == ch) {
                if(sa[ran[i-1]+1] > sa[ran[i]+1]){
                    ch++;
                }
            }
            if(ch > 'z') break;
            c[ran[i]] = ch;
        }
        if(ch > 'z') ok = false;
        if(ok) printf("%s\n",c+1);
        else printf("-1\n");
    }
    return 0;
}
